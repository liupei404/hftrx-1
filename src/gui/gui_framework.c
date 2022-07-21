/* $Id$ */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//
// Touch GUI от RA4ASN

#include "hardware.h"
#include "board.h"
#include "audio.h"

#include "src/display/display.h"
#include "formats.h"

#include <string.h>
#include <math.h>
#include "src/touch/touch.h"

#include "keyboard.h"
#include "src/display/fontmaps.h"
#include "mslist.h"
#include "codecs.h"

#include "src/gui/gui.h"
#include "src/gui/gui_user.h"
#include "src/gui/gui_system.h"
#include "src/gui/gui_structs.h"
#include "src/gui/gui_settings.h"

#if WITHTOUCHGUI

static void update_gui_elements_list(void);
window_t * get_win(uint8_t window_id);
void close_window(uint_fast8_t parent);
void open_window(window_t * win);
void close_all_windows(void);
uint_fast8_t check_for_parent_window(void);

static btn_bg_t btn_bg [] = {
	{ 130, 35, },
	{ 100, 44, },
	{ 86, 44, },
};
enum { BG_COUNT = ARRAY_SIZE(btn_bg) };

static gui_t gui = { 0, 0, TYPE_DUMMY, NULL, CANCELLED, 0, 0, 0, 0, 0, };
static gui_element_t gui_elements [GUI_ELEMENTS_ARRAY_SIZE];
static uint_fast8_t gui_element_count = 0;
static button_t close_button = { 0, 0, CANCELLED, BUTTON_NON_LOCKED, 0, 0, NO_PARENT_WINDOW, NON_VISIBLE, INT32_MAX, "btn_close", "", };

/* Text fields SET
 *
 * TF_CLEAR: 	nothing
 * TF_WRITE: 	char * string, COLORMAIN_T color
 * TF_COORDS: 	uint_fast16_t x, uint_fast16_t y
 * TF_VISIBLE: 	uint_fast8_t visible
 */

void set_property(const uint8_t window_id, element_type_t type, const char * name, ...)
{
	ASSERT(window_id < WINDOWS_COUNT);

	va_list arg;
	window_t * win = get_win(window_id);
	va_start(arg, name);

	switch (type)
	{
	case TYPE_TEXT_FIELD:
	{
		text_field_t * tf = find_gui_element(TYPE_TEXT_FIELD, win, name);
		uint_fast8_t operation = va_arg(arg, uint_fast8_t);

		if (operation == TF_CLEAR)
		{
			tf->index = 0;
			memset(tf->string, 0, tf->h_str * sizeof(tf_entry_t));
		}
		else if (operation == TF_WRITE)
		{
			char * str = va_arg(arg, char *);
			COLORMAIN_T color = va_arg(arg, COLORMAIN_T);

			tf_entry_t * rec = &  tf->string [tf->index];
			strncpy(rec->text, str, TEXT_ARRAY_SIZE - 1);
			rec->color_line = color;
			tf->index ++;
			tf->index = tf->index >= tf->h_str ? 0 : tf->index;
		}
		else if (operation == TF_COORDS)
		{
			tf->x1 = va_arg(arg, uint_fast16_t);
			tf->y1 = va_arg(arg, uint_fast16_t);

			if (tf->font)
			{
				tf->w = tf->font->width * tf->w_sim;
				tf->h = tf->font->height * tf->h_str;
			}
			else
			{
				tf->w = SMALLCHARW2 * tf->w_sim;
				tf->h = SMALLCHARH2 * tf->h_str;
			}
			ASSERT(tf->w < WITHGUIMAXX);
			ASSERT(tf->h < WITHGUIMAXY - window_title_height);
		}
		else if (operation == TF_VISIBLE)
		{
			tf->visible = va_arg(arg, uint_fast8_t) != 0;
		}

		break;
	}

	default:
		break;
	}

	va_end(arg);
}

/* Text fields GET
 *
 * TF_SIZE: 	uint_fast16_t * w, uint_fast16_t * h
 * TF_COORDS:  	uint_fast16_t * x, uint_fast16_t * y
 * TF_VISIBLE: 	uint_fast8_t * visible
 */

void get_property(const uint8_t window_id, element_type_t type, const char * name, ...)
{
	ASSERT(window_id < WINDOWS_COUNT);

	va_list arg;
	window_t * win = get_win(window_id);
	va_start(arg, name);

	switch (type)
	{
	case TYPE_TEXT_FIELD:
	{
		text_field_t * tf = find_gui_element(TYPE_TEXT_FIELD, win, name);
		uint_fast8_t operation = va_arg(arg, uint_fast8_t);

		if (operation == TF_SIZE)
		{
			uint_fast16_t * w = va_arg(arg, uint_fast16_t *);
			uint_fast16_t * h = va_arg(arg, uint_fast16_t *);

			if (tf->font)
			{
				tf->w = tf->font->width * tf->w_sim;
				tf->h = tf->font->height * tf->h_str;
			}
			else
			{
				tf->w = SMALLCHARW2 * tf->w_sim;
				tf->h = SMALLCHARH2 * tf->h_str;
			}
			ASSERT(tf->w < WITHGUIMAXX);
			ASSERT(tf->h < WITHGUIMAXY - window_title_height);

			* w = tf->w;
			* h = tf->h;
		}
		else if (operation == TF_COORDS)
		{
			uint_fast16_t * x = va_arg(arg, uint_fast16_t *);
			uint_fast16_t * y = va_arg(arg, uint_fast16_t *);

			* x = tf->x1;
			* y = tf->y1;
		}
		else if (operation == TF_VISIBLE)
		{
			uint_fast8_t * visible = va_arg(arg, uint_fast8_t *);

			* visible = tf->visible;
		}


		break;
	}

	default:
		break;
	}

	va_end(arg);
}

void gui_set_encoder2_rotate (int_fast8_t rotate)
{
	if (rotate != 0)
	{
		// информация о вращении 2-го энкодера направляется только в активное окно
		if (check_for_parent_window() == NO_PARENT_WINDOW)
			put_to_wm_queue(get_win(WINDOW_MAIN), WM_MESSAGE_ENC2_ROTATE, rotate);
		else
			put_to_wm_queue(get_win(gui.win [1]), WM_MESSAGE_ENC2_ROTATE, rotate);
	}
}

void dump_queue(window_t * win)
{
	if (! win->queue.size)
		return;

	PRINTF("dump WM queue window '%s'\n", win->name);

	if (win->queue.size == WM_MAX_QUEUE_SIZE)
		PRINTF("WM stack full!\n");

	for (uint_fast8_t i = 0; i < win->queue.size; i ++)
	{
		switch(win->queue.data[i].message)
		{
		case WM_MESSAGE_UPDATE:
			PRINTF("%d: WM_MESSAGE_UPDATE\n", i);
			break;

		case WM_MESSAGE_ACTION:
			PRINTF("%d: WM_MESSAGE_ACTION: element type - %d, action - %d\n", i, win->queue.data[i].type, win->queue.data[i].action);
			break;

		case WM_MESSAGE_ENC2_ROTATE:
			PRINTF("%d: WM_MESSAGE_ENC2_ROTATE: direction - %d\n", i, win->queue.data[i].action);
			break;

		case WM_MESSAGE_KEYB_CODE:
			PRINTF("%d: WM_MESSAGE_KEYB_CODE: code - %d\n", i, win->queue.data[i].action);
			break;

		default:
			PRINTF("%d: unknown message type! - \n", i, win->queue.data[i].message);
			break;
		}
	}
}

// WM_MESSAGE_ACTION: 		element_type_t type, uintptr_t element_ptr, int action
// WM_MESSAGE_ENC2_ROTATE:  int_fast8_t rotate
// WM_MESSAGE_KEYB_CODE:	int_fast8_t keyb_code
// WM_MESSAGE_UPDATE: 		nothing
// WM_MESSAGE_CLOSE: 		nothing
uint_fast8_t put_to_wm_queue(window_t * win, wm_message_t message, ...)
{
	if (win->queue.size >= WM_MAX_QUEUE_SIZE)
		return 0;					// очередь переполнена, ошибка

	//dump_queue(win);

	va_list arg;

	switch (message)
	{
	case WM_MESSAGE_ACTION:
	{
		va_start(arg, message);

		uint_fast8_t type = va_arg(arg, uint_fast8_t);
		uintptr_t ptr = va_arg(arg, uintptr_t);
		int_fast8_t action = va_arg(arg, int_fast8_t);

		va_end(arg);

		uint_fast8_t ind = win->queue.size ? (win->queue.size - 1) : 0;
		if (win->queue.data [ind].message == WM_MESSAGE_ACTION && win->queue.data [ind].type == type && win->queue.data [ind].action == action)
			return 1;
		else
		{
			win->queue.data [win->queue.size].message = WM_MESSAGE_ACTION;
			win->queue.data [win->queue.size].type = (element_type_t) type;
			win->queue.data [win->queue.size].ptr = ptr;
			win->queue.data [win->queue.size].action = action;
			win->queue.size ++;
		}

		return 1;
	}
		break;

	case WM_MESSAGE_ENC2_ROTATE:
	{
		va_start(arg, message);
		int_fast8_t r = va_arg(arg, int_fast8_t);
		va_end(arg);

		uint_fast8_t ind = win->queue.size ? (win->queue.size - 1) : 0;				// если первое в очереди сообщение - WM_MESSAGE_ENC2_ROTATE,
		if (win->queue.data [ind].message == WM_MESSAGE_ENC2_ROTATE)				// просуммировать текущее и новое значения поворота,
		{																			// иначе добавить новое сообщение
			win->queue.data [ind].action += r;
		}
		else
		{
			win->queue.data [win->queue.size].message = WM_MESSAGE_ENC2_ROTATE;
			win->queue.data [win->queue.size].type = (element_type_t) UINT8_MAX;
			win->queue.data [win->queue.size].ptr = UINTPTR_MAX;
			win->queue.data [win->queue.size].action = r;
			win->queue.size ++;
		}

		return 1;
	}
		break;

	case WM_MESSAGE_KEYB_CODE:
	{
		va_start(arg, message);

		win->queue.data [win->queue.size].message = WM_MESSAGE_KEYB_CODE;
		win->queue.data [win->queue.size].type = (element_type_t) UINT8_MAX;
		win->queue.data [win->queue.size].ptr = UINTPTR_MAX;
		win->queue.data [win->queue.size].action = va_arg(arg, int_fast8_t);
		win->queue.size ++;

		va_end(arg);

		return 1;
	}
		break;

	case WM_MESSAGE_UPDATE:
	{
		uint_fast8_t ind = win->queue.size ? (win->queue.size - 1) : 0;
		if (win->queue.data [ind].message != WM_MESSAGE_UPDATE)		// предотвращение дублей сообщения WM_MESSAGE_UPDATE
		{
			win->queue.data [win->queue.size].message = WM_MESSAGE_UPDATE;
			win->queue.data [win->queue.size].type = (element_type_t) UINT8_MAX;
			win->queue.data [win->queue.size].ptr = UINTPTR_MAX;
			win->queue.data [win->queue.size].action = INT8_MAX;
			win->queue.size ++;
		}
	}
		return 1;
		break;

	case WM_MESSAGE_CLOSE:
	{
		uint_fast8_t ind = win->queue.size ? (win->queue.size - 1) : 0;
		if (win->queue.data [ind].message != WM_MESSAGE_CLOSE)		// предотвращение дублей сообщения WM_MESSAGE_CLOSE
		{
			win->queue.data [win->queue.size].message = WM_MESSAGE_CLOSE;
			win->queue.data [win->queue.size].type = (element_type_t) UINT8_MAX;
			win->queue.data [win->queue.size].ptr = UINTPTR_MAX;
			win->queue.data [win->queue.size].action = INT8_MAX;
			win->queue.size ++;
		}
	}
		return 1;
		break;

	case WM_NO_MESSAGE:
	default:
		return 0;
		break;
	}

	PRINTF("put_to_wm_queue: no valid type of messages found\n");
	ASSERT(0);
	return 0;
}

wm_message_t get_from_wm_queue(window_t * win, uint_fast8_t * type, uintptr_t * ptr, int_fast8_t * action)
{
	if (! win->queue.size)
		return WM_NO_MESSAGE;							// очередь сообщений пустая

	win->queue.size --;

	* type = win->queue.data [win->queue.size].type;
	* ptr = win->queue.data [win->queue.size].ptr;
	* action = win->queue.data [win->queue.size].action;

//	if (win->window_id != WINDOW_MAIN)
//		PRINTF("get_from_wm_queue: win - %s, message - %d, size - %d\n", win->name, win->queue.data [win->queue.size].message, win->queue.size);

	wm_message_t m = win->queue.data [win->queue.size].message;

	win->queue.data [win->queue.size].message = WM_NO_MESSAGE;		// очистить текущую запись
	win->queue.data [win->queue.size].type = TYPE_DUMMY;
	win->queue.data [win->queue.size].ptr = 0;
	win->queue.data [win->queue.size].action = 0;

	return m;
}

void clean_wm_queue (window_t * win)
{
	win->queue.size = 0;
	memset(win->queue.data, 0, sizeof win->queue.data);
}

/* Запрос на обновление состояния элементов GUI */
void gui_update(void)
{
	put_to_wm_queue(get_win(WINDOW_MAIN), WM_MESSAGE_UPDATE);	// главное окно всегда нужно обновлять

	uint_fast8_t win2 = check_for_parent_window();
	if (win2 != NO_PARENT_WINDOW)								// если открыто второе окно,
	{
		put_to_wm_queue(get_win(win2), WM_MESSAGE_UPDATE);		// добавить сообщение на обновление в его очередь
	}
}

/* Сброс данных трекинга тачскрина */
void reset_tracking(void)
{
	gui.vector_move_x = 0;
	gui.vector_move_y = 0;
}

/* Получить относительные координаты перемещения точки касания экрана */
void get_gui_tracking(int_fast16_t * x, int_fast16_t * y)
{
	* x = gui.vector_move_x;
	* y = gui.vector_move_y;
}

/* Возврат ссылки на запись в структуре по названию и типу окна */
void * find_gui_element(element_type_t type, window_t * win, const char * name)
{
	switch (type)
	{
	case TYPE_BUTTON:
		for (uint_fast8_t i = 0; i < win->bh_count; i ++)
		{
			button_t * bh = & win->bh_ptr [i];
			if (! strcmp(bh->name, name))
				return (button_t *) bh;
		}
		PRINTF("find_gui_element: button '%s' not found\n", name);
		ASSERT(0);
		return NULL;
		break;

	case TYPE_LABEL:
		for (uint_fast8_t i = 0; i < win->lh_count; i ++)
		{
			label_t * lh = & win->lh_ptr [i];
			if (! strcmp(lh->name, name))
				return (label_t *) lh;
		}
		PRINTF("find_gui_element: label '%s' not found\n", name);
		ASSERT(0);
		return NULL;
		break;

	case TYPE_SLIDER:
		for (uint_fast8_t i = 0; i < win->sh_count; i ++)
		{
			slider_t * sh = & win->sh_ptr [i];
			if (! strcmp(sh->name, name))
				return (slider_t *) sh;
		}
		PRINTF("find_gui_element: slider '%s' not found\n", name);
		ASSERT(0);
		return NULL;
		break;

	case TYPE_TOUCH_AREA:
		for (uint_fast8_t i = 0; i < win->ta_count; i ++)
		{
			touch_area_t * ta = & win->ta_ptr [i];
			if (! strcmp(ta->name, name))
				return (touch_area_t *) ta;
		}
		PRINTF("find_gui_element: touch_area '%s' not found\n", name);
		ASSERT(0);
		return NULL;
		break;

	case TYPE_TEXT_FIELD:
		for (uint_fast8_t i = 0; i < win->tf_count; i ++)
		{
			text_field_t * tf = & win->tf_ptr [i];
			if (! strcmp(tf->name, name))
				return (text_field_t *) tf;
		}
		PRINTF("find_gui_element: text_field '%s' not found\n", name);
		ASSERT(0);
		return NULL;
		break;

	default:
		PRINTF("find_gui_element: undefined type %d\n", type);
		ASSERT(0);
		return NULL;
	}
}

/* Получение ширины метки в пикселях  */
uint_fast8_t get_label_width(const label_t * const lh)
{
	if (lh->font_size == FONT_LARGE)
		return strlen(lh->text) * SMALLCHARW;
	else if (lh->font_size == FONT_MEDIUM)
		return strlen(lh->text) * SMALLCHARW2;
	else if (lh->font_size == FONT_SMALL)
		return strlen(lh->text) * SMALLCHARW3;
	return 0;
}

/* Получение высоты метки в пикселях  */
uint_fast8_t get_label_height(const label_t * const lh)
{
	if (lh->font_size == FONT_LARGE)
		return SMALLCHARH;
	else if (lh->font_size == FONT_MEDIUM)
		return SMALLCHARH2;
	else if (lh->font_size == FONT_SMALL)
		return SMALLCHARH3;
	return 0;
}

/* Установки статуса основных кнопок */
/* При DISABLED в качестве необязательного параметра передать указатель на активную кнопку или NULL для блокирования всех */
void footer_buttons_state (uint_fast8_t state, ...)
{
	window_t * win = get_win(WINDOW_MAIN);
	va_list arg;
	button_t * bt = NULL;
	uint_fast8_t is_name;
	static uint_fast16_t bitmask_locked_buttons = 0;

	if (state == DISABLED)
	{
		va_start(arg, state);
		bt = va_arg(arg, button_t *);
		va_end(arg);
	}

	if (state == DISABLED && bt != NULL)
		bitmask_locked_buttons = 0;

	for (uint_fast8_t i = 0; i < win->bh_count; i ++)
	{
		button_t * bh = & win->bh_ptr [i];

		if (state == DISABLED && bt != NULL)
			bitmask_locked_buttons |= bh->is_locked << i;

		if (state == DISABLED)
		{
			bh->state = bh == bt ? CANCELLED : DISABLED;
			bh->is_locked = bh->state == CANCELLED ? BUTTON_LOCKED : BUTTON_NON_LOCKED;
		}
		else if (state == CANCELLED && gui.win [1] == NO_PARENT_WINDOW)
		{
			bh->state = CANCELLED;
			bh->is_locked = ((bitmask_locked_buttons >> i) & 1) ? BUTTON_LOCKED : BUTTON_NON_LOCKED;
		}
	}
}

/* Установка статуса элементов после инициализации */
void elements_state (window_t * win)
{
	ASSERT(win != NULL);
	int debug_num = 0;

	button_t * b = win->bh_ptr;
	if (b != NULL)
	{
		for (uint_fast8_t i = 0; i < win->bh_count; i ++)
		{
			button_t * bh = & b [i];
			if (win->state)
			{
				if (bh->is_long_press && bh->is_repeating)
				{
					PRINTF("ERROR: invalid combination of properties 'is_long_press' and 'is_repeating' on button %s\n", bh->name);
					ASSERT(0);
				}
				ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
				gui_elements [gui_element_count].link = bh;
				gui_elements [gui_element_count].win = win;
				gui_elements [gui_element_count].type = TYPE_BUTTON;
				gui_element_count ++;
				debug_num ++;
			}
			else
			{
				debug_num --;
				gui_element_count --;
				bh->visible = NON_VISIBLE;
				ASSERT(gui_element_count >= gui.footer_buttons_count);
			}
		}
	}

	label_t * l = win->lh_ptr;
	if(l != NULL)
	{
		for (uint_fast8_t i = 0; i < win->lh_count; i ++)
		{
			label_t * lh = & l [i];
			if (win->state)
			{
				ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
				gui_elements [gui_element_count].link = lh;
				gui_elements [gui_element_count].win = win;
				gui_elements [gui_element_count].type = TYPE_LABEL;
				gui_element_count ++;
				debug_num ++;
			}
			else
			{
				debug_num --;
				gui_element_count --;
				lh->visible = NON_VISIBLE;
				ASSERT(gui_element_count >= gui.footer_buttons_count);
			}
		}
	}

	slider_t * s = win->sh_ptr;
	if(s != NULL)
	{
		for (uint_fast8_t i = 0; i < win->sh_count; i ++)
		{
			slider_t * sh = & s [i];
			if (win->state)
			{
				ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
				gui_elements [gui_element_count].link = (slider_t *) sh;
				gui_elements [gui_element_count].win = win;
				gui_elements [gui_element_count].type = TYPE_SLIDER;
				gui_element_count ++;
				debug_num ++;
			}
			else
			{
				debug_num --;
				gui_element_count --;
				sh->visible = NON_VISIBLE;
				ASSERT(gui_element_count >= gui.footer_buttons_count);
			}
		}
	}

	touch_area_t * t = win->ta_ptr;
	if(t != NULL)
	{
		for (uint_fast8_t i = 0; i < win->ta_count; i ++)
		{
			touch_area_t * ta = & t [i];
			if (win->state)
			{
				ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
				gui_elements [gui_element_count].link = (touch_area_t *) ta;
				gui_elements [gui_element_count].win = win;
				gui_elements [gui_element_count].type = TYPE_TOUCH_AREA;
				gui_element_count ++;
				debug_num ++;
			}
			else
			{
				debug_num --;
				gui_element_count --;
				ta->visible = NON_VISIBLE;
				ASSERT(gui_element_count >= gui.footer_buttons_count);
			}
		}
	}

	text_field_t * tf = win->tf_ptr;
	if(tf != NULL)
	{
		for (uint_fast8_t i = 0; i < win->tf_count; i ++)
		{
			text_field_t * tff = & tf [i];
			if (win->state)
			{
				ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
				gui_elements [gui_element_count].link = (text_field_t *) tff;
				gui_elements [gui_element_count].win = win;
				gui_elements [gui_element_count].type = TYPE_TEXT_FIELD;
				gui_element_count ++;
				debug_num ++;
				tff->string = (tf_entry_t *) calloc(tff->h_str, sizeof(tf_entry_t));
				GUI_MEM_ASSERT(tff->string);
				tff->index = 0;
			}
			else
			{
				debug_num --;
				gui_element_count --;
				tff->visible = NON_VISIBLE;
				free(tff->string);
				tff->string = NULL;
				ASSERT(gui_element_count >= gui.footer_buttons_count);
			}
		}
	}

	// инициализировать системную кнопку закрытия окна, если разрешено
	if(win->is_close)
	{
		if (win->state)
		{
			close_button.x1 = win->w - window_close_button_size + 1;
			close_button.y1 = 1;
			close_button.w = window_close_button_size - 3;
			close_button.h = window_close_button_size - 3;
			close_button.parent = win->window_id;
			close_button.visible = VISIBLE;
			close_button.state = CANCELLED;

			ASSERT(gui_element_count < GUI_ELEMENTS_ARRAY_SIZE);
			gui_elements [gui_element_count].link = (button_t *) & close_button;
			gui_elements [gui_element_count].win = win;
			gui_elements [gui_element_count].type = TYPE_CLOSE_BUTTON;
			gui_element_count ++;
			debug_num ++;
		}
		else
		{
			debug_num --;
			gui_element_count --;
			close_button.visible = NON_VISIBLE;
			ASSERT(gui_element_count >= gui.footer_buttons_count);
		}
	}
//	PRINTF("line %d: %s gui_element_count: %d %+d\n", __LINE__, win->name, gui_element_count, debug_num);
	clean_wm_queue(win);
}

/* Возврат id parent window */
uint_fast8_t check_for_parent_window(void)
{
	return gui.win [1];
}

/* Закрыть все окна (обработчик системной кнопки закрытия окна) */
void close_all_windows(void)
{
	close_window(DONT_OPEN_PARENT_WINDOW);
	footer_buttons_state(CANCELLED);
	hamradio_set_lockmode(0);
	hamradio_disable_keyboard_redirect();
	gui_user_actions_after_close_window();
}

/* Освободить выделенную память в куче и обнулить счетчики элементов окна */
static void free_win_ptr (window_t * win)
{
	free(win->bh_ptr);
	free(win->lh_ptr);
	free(win->sh_ptr);
	free(win->ta_ptr);
	free(win->tf_ptr);

	win->bh_count = 0;
	win->lh_count = 0;
	win->sh_count = 0;
	win->ta_count = 0;
	win->tf_count = 0;

	win->bh_ptr = NULL;
	win->lh_ptr = NULL;
	win->sh_ptr = NULL;
	win->ta_ptr = NULL;
	win->tf_ptr = NULL;
//	PRINTF("free: %d %s\n", win->window_id, win->name);
}

/* Установка признака видимости окна */
void close_window(uint_fast8_t parent_action) // 0 - не открывать parent window, 1 - открыть
{
	if(gui.win [1] != NO_PARENT_WINDOW)
	{
		window_t * win = get_win(gui.win [1]);
		win->state = NON_VISIBLE;
		elements_state(win);

		if (put_to_wm_queue(win, WM_MESSAGE_CLOSE))
			win->onVisibleProcess();
		else
			dump_queue(win);

		free_win_ptr(win);
		gui.win [1] = NO_PARENT_WINDOW;

		if (win->parent_id != NO_PARENT_WINDOW && parent_action)	// При закрытии child window открыть parent window, если есть и если разрешено
		{
			open_window(get_win(win->parent_id));
		}
		gui_user_actions_after_close_window();
	}
}

/* Открыть окно */
void open_window(window_t * win)
{
	if (win->parent_id != NO_PARENT_WINDOW && gui.win [1] == win->parent_id)	// Если открыто parent window, закрыть его и оставить child window
	{
		close_window(0);
	}

	win->state = VISIBLE;
	win->first_call = 1;
	gui.win [1] = win->window_id;
}

/* Расчет экранных координат окна */
/* при mode = WINDOW_POSITION_MANUAL_SIZE в качестве необязательных параметров передать xmax и ymax */
void calculate_window_position(window_t * win, uint_fast8_t mode, ...)
{
	uint_fast16_t title_length = strlen(win->title) * SMALLCHARW;
	uint_fast16_t xmax = 0, ymax = 0, shift_x, shift_y, x_start, y_start;
	win->size_mode = mode;

	switch (mode)
	{
	case WINDOW_POSITION_MANUAL_SIZE:
		{
			va_list arg;
			va_start(arg, mode);
			xmax = va_arg(arg, uint_fast16_t);
			ymax = va_arg(arg, uint_fast16_t);
			va_end(arg);
		}
		break;

	case WINDOW_POSITION_MANUAL_POSITION:
		{
			va_list arg;
			va_start(arg, mode);
			x_start = va_arg(arg, uint_fast16_t);
			y_start = va_arg(arg, uint_fast16_t);
			va_end(arg);
		}
		// no break

	case WINDOW_POSITION_FULLSCREEN:
	case WINDOW_POSITION_AUTO:
		{
			if (win->bh_ptr != NULL)
			{
				for (uint_fast8_t i = 0; i < win->bh_count; i++)
				{
					const button_t * bh = & win->bh_ptr [i];
					xmax = (xmax > bh->x1 + bh->w) ? xmax : (bh->x1 + bh->w);
					ymax = (ymax > bh->y1 + bh->h) ? ymax : (bh->y1 + bh->h);
					ASSERT(xmax < WITHGUIMAXX);
					ASSERT(ymax < WITHGUIMAXY);
				}
			}

			if (win->lh_ptr != NULL)
			{
				for (uint_fast8_t i = 0; i < win->lh_count; i++)
				{
					const label_t * lh = & win->lh_ptr [i];
					xmax = (xmax > lh->x + get_label_width(lh)) ? xmax : (lh->x + get_label_width(lh));
					ymax = (ymax > lh->y + get_label_height(lh)) ? ymax : (lh->y + get_label_height(lh));
					ASSERT(xmax < WITHGUIMAXX);
					ASSERT(ymax < WITHGUIMAXY);
				}
			}

			if (win->tf_ptr != NULL)
			{
				for (uint_fast8_t i = 0; i < win->tf_count; i++)
				{
					const text_field_t * tf = & win->tf_ptr [i];
					xmax = (xmax > tf->x1 + tf->w) ? xmax : (tf->x1 + tf->w);
					ymax = (ymax > tf->y1 + tf->h) ? ymax : (tf->y1+ tf->h);
					ASSERT(xmax < WITHGUIMAXX);
					ASSERT(ymax < WITHGUIMAXY);
				}
			}

			if (win->sh_ptr != NULL)
			{
				for (uint_fast8_t i = 0; i < win->sh_count; i++)
				{
					const slider_t * sh = & win->sh_ptr [i];
					if (sh->orientation)	// ORIENTATION_HORIZONTAL
					{
						xmax = (xmax > sh->x + sh->size + sliders_w) ? xmax : (sh->x + sh->size + sliders_w);
						ymax = (ymax > sh->y + sliders_h * 2) ? ymax : (sh->y + sliders_h * 2);
					}
					else					// ORIENTATION_VERTICAL
					{
						xmax = (xmax > sh->x + sliders_w * 2) ? xmax : (sh->x + sliders_w * 2);
						ymax = (ymax > sh->y + sh->size + sliders_h) ? ymax : (sh->y + sh->size + sliders_h);
					}
					ASSERT(xmax < WITHGUIMAXX);
					ASSERT(ymax < WITHGUIMAXY);
				}
			}
		}
		break;

	default:

		break;
	}

	// Выравнивание массива оконных элементов по центру окна
	shift_x = edge_step;
	shift_y = (title_length ? window_title_height : 0) + edge_step;

	if (win->bh_ptr != NULL)
	{
		for (uint_fast8_t i = 0; i < win->bh_count; i++)
		{
			button_t * bh = & win->bh_ptr [i];
			bh->x1 += shift_x;
			bh->y1 += shift_y;
			ASSERT(bh->x1 + bh->w < WITHGUIMAXX);
			ASSERT(bh->y1 + bh->h < WITHGUIMAXY);
		}
	}

	if (win->lh_ptr != NULL)
	{
		for (uint_fast8_t i = 0; i < win->lh_count; i++)
		{
			label_t * lh = & win->lh_ptr [i];
			lh->x += shift_x;
			lh->y += shift_y;
			ASSERT(lh->x + get_label_width(lh) < WITHGUIMAXX);
			ASSERT(lh->y + get_label_height(lh) < WITHGUIMAXY);
		}
	}

	if (win->tf_ptr != NULL)
	{
		for (uint_fast8_t i = 0; i < win->tf_count; i++)
		{
			text_field_t * tf = & win->tf_ptr [i];
			tf->x1 += shift_x;
			tf->y1 += shift_y;
			ASSERT(tf->x1 + tf->w < WITHGUIMAXX);
			ASSERT(tf->y1 + tf->h < WITHGUIMAXY);
		}
	}

	if (win->sh_ptr != NULL)
	{
		for (uint_fast8_t i = 0; i < win->sh_count; i++)
		{
			slider_t * sh = & win->sh_ptr [i];
			sh->x += shift_x;
			sh->y += shift_y;
//			ASSERT(sh->x < WITHGUIMAXX);
//			ASSERT(sh->y < WITHGUIMAXY);
		}
	}

	if (mode == WINDOW_POSITION_FULLSCREEN)
	{
		const window_t * win_main = get_win(WINDOW_MAIN);
		const uint_fast8_t h = win_main->bh_ptr[0].h;

		win->x1 = 0;
		win->y1 = 0;
		win->w = WITHGUIMAXX;
		win->h = WITHGUIMAXY - FOOTER_HEIGHT;
	}
	else if (mode == WINDOW_POSITION_MANUAL_POSITION)
	{
		win->x1 = x_start;
		win->y1 = y_start;
		win->w = xmax > title_length ? (xmax + edge_step * 2) : (title_length + edge_step * 2);
		win->h = ymax + shift_y + edge_step;
		if (win->x1 + win->w >= WITHGUIMAXX)
			win->x1 = WITHGUIMAXX - win->w - 1;

		ASSERT(win->x1 + win->w < WITHGUIMAXX);
		ASSERT(win->y1 + win->h < WITHGUIMAXY);
	}
	else
	{
		win->w = xmax > title_length ? (xmax + edge_step * 2) : (title_length + edge_step * 2);
		win->w = (win->is_close && win->w < title_length + window_close_button_size * 2) ? (win->w + window_close_button_size) : win->w;
		win->h = ymax + shift_y + edge_step;
		win->y1 = ALIGN_Y - win->h / 2;

		switch (win->align_mode)
		{
		case ALIGN_LEFT_X:
			if (ALIGN_LEFT_X - win->w / 2 < 0)
				win->x1 = 0;
			else
				win->x1 = ALIGN_LEFT_X - win->w / 2;
			break;

		case ALIGN_RIGHT_X:
			if (ALIGN_RIGHT_X + win->w / 2 > WITHGUIMAXX)
				win->x1 = WITHGUIMAXX - win->w;
			else
				win->x1 = ALIGN_RIGHT_X - win->w / 2;
			break;

		case ALIGN_CENTER_X:
		default:
			win->x1 = ALIGN_CENTER_X - win->w / 2;
			break;
		}

		ASSERT(win->x1 + win->w < WITHGUIMAXX);
		ASSERT(win->y1 + win->h < WITHGUIMAXY);
	}

	win->draw_x1 = win->x1 + edge_step;
	win->draw_y1 = win->y1 + edge_step + (title_length ? window_title_height : 0);
	win->draw_x2 = win->x1 + win->w - edge_step;
	win->draw_y2 = win->y1 + win->h - edge_step;

	win->title_align = TITLE_ALIGNMENT_LEFT;

	//PRINTF("%d %d %d %d\n", win->x1, win->y1, win->h, win->w);
	elements_state(win);
}

void window_set_title_align(window_t * win, title_align_t align)
{
	ASSERT(win != NULL);
	win->title_align = align;
}

/* Передать менеджеру GUI код нажатой кнопки на клавиатуре */
void gui_put_keyb_code (uint_fast8_t kbch)
{
	// перенаправить код нажатой аппаратной кнопки в активное окно
	if (check_for_parent_window() == NO_PARENT_WINDOW)
		put_to_wm_queue(get_win(WINDOW_MAIN), WM_MESSAGE_KEYB_CODE, kbch);
	else
		put_to_wm_queue(get_win(gui.win [1]), WM_MESSAGE_KEYB_CODE, kbch);
}

/* Удаление пробелов в конце строки */
void remove_end_line_spaces(char * str)
{
	size_t i = strlen(str);
	if (i == 0)
		return;

	for (; -- i > 0;)
	{
		if (str [i] != ' ')
			break;
	}
	str [i + 1] = '\0';
}

/* Удаление пробелов в начале строки */
const char * remove_start_line_spaces(const char * str)
{
	size_t len = strlen(str);
	uint_fast8_t i = 0;

	if (len == 0)
		return NULL;

	for (; i < len; i ++)
	{
		if (str[i] != ' ')
			break;
	}

	if (i >= len)
		return NULL;
	else
		return str + i;
}

/* Отрисовка кнопки */
static void draw_button(const button_t * const bh)
{
	PACKEDCOLORMAIN_T * bg = NULL;
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();
	window_t * win = get_win(bh->parent);
	uint_fast8_t i = 0;
	static const char delimeters [] = "|";
	uint_fast16_t x1 = win->x1 + bh->x1;
	uint_fast16_t y1 = win->y1 + bh->y1;

	if ((x1 + bh->w >= WITHGUIMAXX) || (y1 + bh->h >= WITHGUIMAXY))
	{
		PRINTF("%s %s x+w: %d y+h: %d\n", bh->name, bh->text, x1 + bh->w, y1 + bh->h);
		ASSERT(0);
	}

	btn_bg_t * b1 = NULL;
	do {
		if (bh->h == btn_bg [i].h && bh->w == btn_bg [i].w)
		{
			b1 = & btn_bg [i];
			break;
		}
	} while ( ++i < BG_COUNT);

	// если не найден заполненный буфер фона по размерам, программная отрисовка
	if (b1 == NULL || GUI_SOFTWARE_RENDERING)
	{
		PACKEDCOLORMAIN_T c1, c2;
		c1 = bh->state == DISABLED ? COLOR_BUTTON_DISABLED : (bh->is_locked ? COLOR_BUTTON_LOCKED : COLOR_BUTTON_NON_LOCKED);
		c2 = bh->state == DISABLED ? COLOR_BUTTON_DISABLED : (bh->is_locked ? COLOR_BUTTON_PR_LOCKED : COLOR_BUTTON_PR_NON_LOCKED);
#if GUI_OLDBUTTONSTYLE
		colpip_rect(fr, DIM_X, DIM_Y, x1, y1, x1 + bh->w, y1 + bh->h - 2, bh->state == PRESSED ? c2 : c1, 1);
		colpip_rect(fr, DIM_X, DIM_Y, x1, y1, x1 + bh->w, y1 + bh->h - 1, COLORMAIN_GRAY, 0);
		colpip_rect(fr, DIM_X, DIM_Y, x1 + 2, y1 + 2, x1 + bh->w - 2, y1 + bh->h - 3, COLORMAIN_BLACK, 0);
#else
		colmain_rounded_rect(fr, DIM_X, DIM_Y, x1, y1, x1 + bh->w, y1 + bh->h - 2, button_round_radius, bh->state == PRESSED ? c2 : c1, 1);
		colmain_rounded_rect(fr, DIM_X, DIM_Y, x1, y1, x1 + bh->w, y1 + bh->h - 1, button_round_radius, COLORMAIN_GRAY, 0);
		colmain_rounded_rect(fr, DIM_X, DIM_Y, x1 + 2, y1 + 2, x1 + bh->w - 2, y1 + bh->h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */
	}
	else
	{
		if (bh->state == DISABLED)
			bg = b1->bg_disabled;
		else if (bh->is_locked && bh->state == PRESSED)
			bg = b1->bg_locked_pressed;
		else if (bh->is_locked && bh->state != PRESSED)
			bg = b1->bg_locked;
		else if (! bh->is_locked && bh->state == PRESSED)
			bg = b1->bg_pressed;
		else if (! bh->is_locked && bh->state != PRESSED)
			bg = b1->bg_non_pressed;
#if GUI_OLDBUTTONSTYLE
		colpip_plot((uintptr_t) fr, GXSIZE(DIM_X, DIM_Y), fr, DIM_X, DIM_Y, x1, y1, (uintptr_t) bg, GXSIZE(bh->w, bh->h), bg, bh->w, bh->h);
#else
		PACKEDCOLORMAIN_T * src = NULL, * dst = NULL, * row = NULL;
		for (uint16_t yy = y1, yb = 0; yy < y1 + bh->h; yy ++, yb ++)
		{
			ASSERT(yy < WITHGUIMAXY);
			ASSERT(yb < WITHGUIMAXY);
			row = colmain_mem_at(bg, b1->w, b1->h, 0, yb);
			if (* row == GUI_DEFAULTCOLOR)										// если в первой позиции строки буфера не прозрачный цвет,
			{																	// скопировать ее целиком, иначе попиксельно с проверкой
				for (uint16_t xx = x1, xb = 0; xx < x1 + bh->w; xx ++, xb ++)
				{
					src = colmain_mem_at(bg, b1->w, b1->h, xb, yb);
					if (* src == GUI_DEFAULTCOLOR)
						continue;
					dst = colmain_mem_at(fr, DIM_X, DIM_Y, xx, yy);
					memcpy(dst, src, sizeof(PACKEDCOLORMAIN_T));
				}
			}
			else
			{
				dst = colmain_mem_at(fr, DIM_X, DIM_Y, x1, yy);
				memcpy(dst, row, b1->w * sizeof(PACKEDCOLORMAIN_T));
//				colpip_plot((uintptr_t) fr, GXSIZE(DIM_X, DIM_Y), fr, DIM_X, DIM_Y, x1, yy, (uintptr_t) row, GXSIZE(b1->w, 1), row, b1->w, 1);
			}
		}
#endif /* GUI_OLDBUTTONSTYLE */
	}

#if GUI_OLDBUTTONSTYLE
	uint_fast8_t shift = bh->state == PRESSED ? 1 : 0;
#else
	uint_fast8_t shift = 0;
#endif /* GUI_OLDBUTTONSTYLE */

	if (strchr(bh->text, delimeters [0]) == NULL)
	{
		/* Однострочная надпись */
#if WITHALTERNATIVEFONTS
		UB_Font_DrawPString(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (getwidth_Pstring(bh->text, & FONT_BUTTONS))) / 2,
					shift + y1 + (bh->h - FONT_BUTTONS.height) / 2, bh->text, & FONT_BUTTONS, COLORMAIN_BLACK);
#else
		colpip_string2_tbg(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (strwidth2(bh->text))) / 2,
				shift + y1 + (bh->h - SMALLCHARH2) / 2, bh->text, COLORMAIN_BLACK);
#endif /* WITHALTERNATIVEFONTS */
	}
	else
	{
		/* Двухстрочная надпись */
		uint_fast8_t j = (bh->h - SMALLCHARH2 * 2) / 2;
		char buf [TEXT_ARRAY_SIZE];
		strcpy(buf, bh->text);
		char * text2 = strtok(buf, delimeters);
#if WITHALTERNATIVEFONTS
		UB_Font_DrawPString(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (getwidth_Pstring(text2, & FONT_BUTTONS))) / 2,
				shift + y1 + j, text2, & FONT_BUTTONS, COLORMAIN_BLACK);

		text2 = strtok(NULL, delimeters);
		UB_Font_DrawPString(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (getwidth_Pstring(text2, & FONT_BUTTONS))) / 2,
				shift + bh->h + y1 - FONT_BUTTONS.height - j, text2, & FONT_BUTTONS, COLORMAIN_BLACK);
#else
		colpip_string2_tbg(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (strwidth2(text2))) / 2,
				shift + y1 + j, text2, COLORMAIN_BLACK);

		text2 = strtok(NULL, delimeters);
		colpip_string2_tbg(fr, DIM_X, DIM_Y, shift + x1 + (bh->w - (strwidth2(text2))) / 2,
				shift + bh->h + y1 - SMALLCHARH2 - j, text2, COLORMAIN_BLACK);
#endif /* WITHALTERNATIVEFONTS */
	}
}

/* Отрисовка слайдера */
static void draw_slider(slider_t * sl)
{
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();
	window_t * win = get_win(sl->parent);

	if (sl->orientation)		// ORIENTATION_HORIZONTAL
	{
		if (sl->value_old != sl->value)
		{
			uint_fast16_t mid_w = sl->y + sliders_width / 2;
			sl->value_p = sl->x + sl->size * sl->value / 100;
			sl->y1_p = mid_w - sliders_w;
			sl->x1_p = sl->value_p - sliders_h;
			sl->y2_p = mid_w + sliders_w;
			sl->x2_p = sl->value_p + sliders_h;
			sl->value_old = sl->value;
		}
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x, win->y1 + sl->y,  win->x1 + sl->x + sl->size, win->y1 + sl->y + sliders_width, COLORMAIN_BLACK, 1);
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x, win->y1 + sl->y,  win->x1 + sl->x + sl->size, win->y1 + sl->y + sliders_width, COLORMAIN_WHITE, 0);
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x1_p, win->y1 + sl->y1_p,  win->x1 + sl->x2_p, win->y1 + sl->y2_p, sl->state == PRESSED ? COLOR_BUTTON_PR_NON_LOCKED : COLOR_BUTTON_NON_LOCKED, 1);
		colmain_line(fr, DIM_X, DIM_Y, win->x1 + sl->value_p, win->y1 + sl->y1_p,  win->x1 + sl->value_p, win->y1 + sl->y2_p, COLORMAIN_WHITE, 0);
	}
	else						// ORIENTATION_VERTICAL
	{
		if (sl->value_old != sl->value)
		{
			uint_fast16_t mid_w = sl->x + sliders_width / 2;
			sl->value_p = sl->y + sl->size * sl->value / 100;
			sl->x1_p = mid_w - sliders_w;
			sl->y1_p = sl->value_p - sliders_h;
			sl->x2_p = mid_w + sliders_w;
			sl->y2_p = sl->value_p + sliders_h;
			sl->value_old = sl->value;
		}
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x + 1, win->y1 + sl->y + 1, win->x1 + sl->x + sliders_width - 1, win->y1 + sl->y + sl->size - 1, COLORMAIN_BLACK, 1);
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x, win->y1 + sl->y, win->x1 + sl->x + sliders_width, win->y1 + sl->y + sl->size, COLORMAIN_WHITE, 0);
		colpip_rect(fr, DIM_X, DIM_Y, win->x1 + sl->x1_p, win->y1 + sl->y1_p, win->x1 + sl->x2_p, win->y1 + sl->y2_p, sl->state == PRESSED ? COLOR_BUTTON_PR_NON_LOCKED : COLOR_BUTTON_NON_LOCKED, 1);
		colmain_line(fr, DIM_X, DIM_Y, win->x1 + sl->x1_p, win->y1 + sl->value_p, win->x1 + sl->x2_p, win->y1 + sl->value_p, COLORMAIN_WHITE, 0);
	}
}

/* Заполнение буферов фонов кнопок при инициализации GUI */
static void fill_button_bg_buf(btn_bg_t * v)
{
	PACKEDCOLORMAIN_T * buf;
	uint_fast8_t w, h;

	w = v->w;
	h = v->h;
	size_t s = GXSIZE(w, h) * sizeof (PACKEDCOLORMAIN_T);

	v->bg_non_pressed = 	(PACKEDCOLORMAIN_T *) malloc(s);
	GUI_MEM_ASSERT(v->bg_non_pressed);
	v->bg_pressed = 		(PACKEDCOLORMAIN_T *) malloc(s);
	GUI_MEM_ASSERT(v->bg_pressed);
	v->bg_locked = 			(PACKEDCOLORMAIN_T *) malloc(s);
	GUI_MEM_ASSERT(v->bg_locked);
	v->bg_locked_pressed = 	(PACKEDCOLORMAIN_T *) malloc(s);
	GUI_MEM_ASSERT(v->bg_locked_pressed);
	v->bg_disabled = 		(PACKEDCOLORMAIN_T *) malloc(s);
	GUI_MEM_ASSERT(v->bg_disabled);

	buf = v->bg_non_pressed;
#if GUI_OLDBUTTONSTYLE
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLOR_BUTTON_NON_LOCKED, 1);
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLORMAIN_GRAY, 0);
	colpip_rect(buf, w, h, 2, 2, w - 3, h - 3, COLORMAIN_BLACK, 0);
#else
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, GUI_DEFAULTCOLOR, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLOR_BUTTON_NON_LOCKED, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLORMAIN_GRAY, 0);
	colmain_rounded_rect(buf, w, h, 2, 2, w - 3, h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */

	buf = v->bg_pressed;
#if GUI_OLDBUTTONSTYLE
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLOR_BUTTON_PR_NON_LOCKED, 1);
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLORMAIN_GRAY, 0);
	colmain_line(buf, w, h, 2, 3, w - 3, 3, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 2, 2, w - 3, 2, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 3, 3, 3, h - 3, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 2, 2, 2, h - 2, COLORMAIN_BLACK, 0);
#else
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, GUI_DEFAULTCOLOR, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLOR_BUTTON_PR_NON_LOCKED, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLORMAIN_GRAY, 0);
	colmain_rounded_rect(buf, w, h, 2, 2, w - 3, h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */

	buf = v->bg_locked;
#if GUI_OLDBUTTONSTYLE
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLOR_BUTTON_LOCKED, 1);
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLORMAIN_GRAY, 0);
	colpip_rect(buf, w, h, 2, 2, w - 3, h - 3, COLORMAIN_BLACK, 0);
#else
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, GUI_DEFAULTCOLOR, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLOR_BUTTON_LOCKED, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLORMAIN_GRAY, 0);
	colmain_rounded_rect(buf, w, h, 2, 2, w - 3, h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */

	buf = v->bg_locked_pressed;
#if GUI_OLDBUTTONSTYLE
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLOR_BUTTON_PR_LOCKED, 1);
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLORMAIN_GRAY, 0);
	colmain_line(buf, w, h, 2, 3, w - 3, 3, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 2, 2, w - 3, 2, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 3, 3, 3, h - 3, COLORMAIN_BLACK, 0);
	colmain_line(buf, w, h, 2, 2, 2, h - 2, COLORMAIN_BLACK, 0);
#else
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, GUI_DEFAULTCOLOR, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLOR_BUTTON_PR_LOCKED, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLORMAIN_GRAY, 0);
	colmain_rounded_rect(buf, w, h, 2, 2, w - 3, h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */

	buf = v->bg_disabled;
#if GUI_OLDBUTTONSTYLE
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLOR_BUTTON_DISABLED, 1);
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, COLORMAIN_GRAY, 0);
	colpip_rect(buf, w, h, 2, 2, w - 3, h - 3, COLORMAIN_BLACK, 0);
#else
	colpip_rect(buf, w, h, 0, 0, w - 1, h - 1, GUI_DEFAULTCOLOR, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLOR_BUTTON_DISABLED, 1);
	colmain_rounded_rect(buf, w, h, 0, 0, w - 1, h - 1, button_round_radius, COLORMAIN_GRAY, 0);
	colmain_rounded_rect(buf, w, h, 2, 2, w - 3, h - 3, button_round_radius, COLORMAIN_BLACK, 0);
#endif /* GUI_OLDBUTTONSTYLE */
}

/* Инициализация GUI */
void gui_initialize (void)
{
	uint_fast8_t i = 0;
	window_t * win = get_win(WINDOW_MAIN);
	win->x1 = 0;
	win->y1 = 0;
	win->w = WITHGUIMAXX - 1;
	win->h = WITHGUIMAXY - FOOTER_HEIGHT - 1;

	open_window(win);
	gui.win [1] = NO_PARENT_WINDOW;
	gui.footer_buttons_count = win->bh_count;

	do {
		fill_button_bg_buf(& btn_bg [i]);
	} while ( ++i < BG_COUNT) ;
}

/* Обновление данных в массиве элементов открытых окон */
static void update_gui_elements_list(void)
{
	for (uint_fast8_t i = 0; i < gui_element_count; i ++)
	{
		gui_element_t * p = & gui_elements [i];
		if (p->type == TYPE_BUTTON || p->type == TYPE_CLOSE_BUTTON)
		{
			button_t * bh = (button_t *) p->link;
			p->x1 = (bh->x1 - touch_area_enlarge) < 0 ? 0 : (bh->x1 - touch_area_enlarge);
			p->x2 = (bh->x1 + bh->w + touch_area_enlarge) > WITHGUIMAXX ? WITHGUIMAXX : (bh->x1 + bh->w + touch_area_enlarge);
			p->y1 = (bh->y1 - touch_area_enlarge) < 0 ? 0 : (bh->y1 - touch_area_enlarge);
			p->y2 = (bh->y1 + bh->h + touch_area_enlarge) > WITHGUIMAXY ? WITHGUIMAXY : (bh->y1 + bh->h + touch_area_enlarge);
			p->state = bh->state;
			p->visible = bh->visible;
			p->is_trackable = 0;
			p->is_long_press = bh->is_long_press;
			p->is_repeating = bh->is_repeating;
		}
		else if (p->type == TYPE_LABEL)
		{
			label_t * lh = (label_t *) p->link;
			p->x1 = (lh->x - touch_area_enlarge) < 0 ? 0 : (lh->x - touch_area_enlarge);
			p->x2 = (lh->x + get_label_width(lh) + touch_area_enlarge) > WITHGUIMAXX ? WITHGUIMAXX : (lh->x + get_label_width(lh) + touch_area_enlarge);
			p->y1 = (lh->y - get_label_height(lh) - touch_area_enlarge) < 0 ? 0 : (lh->y - get_label_height(lh) - touch_area_enlarge);
			p->y2 = (lh->y + get_label_height(lh) * 2 + touch_area_enlarge) > WITHGUIMAXY ? WITHGUIMAXY : (lh->y + get_label_height(lh) * 2 + touch_area_enlarge);
			p->state = lh->state;
			p->visible = lh->visible;
			p->is_trackable = lh->is_trackable;
			p->is_long_press = 0;
			p->is_repeating = 0;
		}
		else if (p->type == TYPE_SLIDER)
		{
			slider_t * sh = (slider_t *) p->link;
			p->x1 = (sh->x1_p - touch_area_enlarge) < 0 ? 0 : (sh->x1_p - touch_area_enlarge);
			p->x2 = (sh->x2_p + touch_area_enlarge) > WITHGUIMAXX ? WITHGUIMAXX : (sh->x2_p + touch_area_enlarge);
			p->y1 = (sh->y1_p - touch_area_enlarge) < 0 ? 0 : (sh->y1_p - touch_area_enlarge);
			p->y2 = (sh->y2_p + touch_area_enlarge) > WITHGUIMAXY ? WITHGUIMAXY : (sh->y2_p + touch_area_enlarge);
			p->state = sh->state;
			p->visible = sh->visible;
			p->is_trackable = 1;
			p->is_long_press = 0;
			p->is_repeating = 0;
		}
		else if (p->type == TYPE_TOUCH_AREA)
		{
			touch_area_t * ta = (touch_area_t *) p->link;
			p->x1 = (ta->x1) < 0 ? 0 : (ta->x1);
			p->x2 = (ta->x1 + ta->w) > WITHGUIMAXX ? WITHGUIMAXX : (ta->x1 + ta->w);
			p->y1 = (ta->y1) < 0 ? 0 : (ta->y1);
			p->y2 = (ta->y1 + ta->h) > WITHGUIMAXY ? WITHGUIMAXY : (ta->y1 + ta->h);
			p->state = ta->state;
			p->visible = ta->visible;
			p->is_trackable = ta->is_trackable;
			p->is_long_press = 0;
			p->is_repeating = 0;
		}
		else if (p->type == TYPE_TEXT_FIELD)
		{
			text_field_t * tf = (text_field_t *) p->link;
			p->x1 = (tf->x1) < 0 ? 0 : (tf->x1);
			p->x2 = (tf->x1 + tf->w) > WITHGUIMAXX ? WITHGUIMAXX : (tf->x1 + tf->w);
			p->y1 = (tf->y1) < 0 ? 0 : (tf->y1);
			p->y2 = (tf->y1 + tf->h) > WITHGUIMAXY ? WITHGUIMAXY : (tf->y1 + tf->h);
			p->state = tf->state;
			p->visible = tf->visible;
			p->is_trackable = 0;
			p->is_long_press = 0;
			p->is_repeating = 0;
		}
	}
}

/* Системный обработчик слайдера в момент его перемещения */
static void slider_process(slider_t * sl)
{
	int v = sl->value + roundf((sl->orientation ? gui.vector_move_x : gui.vector_move_y) / sl->step);
	if (v >= 0 && v <= sl->size / sl->step)
		sl->value = v;
	reset_tracking();
}

/* Рассчитать размеры текстового поля */
void textfield_update_size(text_field_t * tf)
{
	ASSERT(tf != NULL);
	if (tf->font)
	{
		tf->w = tf->font->width * tf->w_sim;
		tf->h = tf->font->height * tf->h_str;
	}
	else
	{
		tf->w = SMALLCHARW2 * tf->w_sim;
		tf->h = SMALLCHARH2 * tf->h_str;
	}
	ASSERT(tf->w < WITHGUIMAXX);
	ASSERT(tf->h < WITHGUIMAXY - window_title_height);
}

/* Добавить строку в текстовое поле */
void textfield_add_string(text_field_t * tf, const char * str, COLORMAIN_T color)
{
	ASSERT(tf != NULL);

	tf_entry_t * rec = &  tf->string [tf->index];
	strncpy(rec->text, str, TEXT_ARRAY_SIZE - 1);
	rec->color_line = color;
	tf->index ++;
	tf->index = tf->index >= tf->h_str ? 0 : tf->index;
}

/* Очистить текстовое поле */
void textfield_clean(text_field_t * tf)
{
	ASSERT(tf != NULL);
	tf->index = 0;
	memset(tf->string, 0, tf->h_str * sizeof(tf_entry_t));
}

/* Селектор запуска функций обработки событий */
static void set_state_record(gui_element_t * val)
{
	ASSERT(val != NULL);
	switch (val->type)
	{
		case TYPE_CLOSE_BUTTON:
			close_all_windows();
			break;

		case TYPE_BUTTON:
		{
			ASSERT(val->link != NULL);
			button_t * bh = (button_t *) val->link;
			gui.selected_type = TYPE_BUTTON;
			gui.selected_link = val;
			bh->state = val->state;
			if (bh->state == RELEASED || bh->state == LONG_PRESSED || bh->state == PRESS_REPEATING)
			{
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_BUTTON, bh, bh->state == LONG_PRESSED ? LONG_PRESSED : PRESSED))
					dump_queue(val->win);
			}
		}
			break;

		case TYPE_LABEL:
		{
			ASSERT(val->link != NULL);
			label_t * lh = (label_t *) val->link;
			gui.selected_type = TYPE_LABEL;
			gui.selected_link = val;
			lh->state = val->state;
			if (lh->state == RELEASED)
			{
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_LABEL, lh, PRESSED))
					dump_queue(val->win);
			}
			else if (lh->state == PRESSED && lh->is_trackable)
			{
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_LABEL, lh, MOVING))
					dump_queue(val->win);
			}
		}
			break;

		case TYPE_SLIDER:
		{
			ASSERT(val->link != NULL);
			slider_t * sh = (slider_t *) val->link;
			gui.selected_type = TYPE_SLIDER;
			gui.selected_link = val;
			sh->state = val->state;
			if (sh->state == PRESSED)
			{
				slider_process(sh);
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_SLIDER, sh, PRESSED))
					dump_queue(val->win);
			}
		}
			break;

		case TYPE_TOUCH_AREA:
		{
			ASSERT(val->link != NULL);
			touch_area_t * ta = (touch_area_t *) val->link;
			gui.selected_type = TYPE_TOUCH_AREA;
			gui.selected_link = val;
			ta->state = val->state;
			if (ta->state == RELEASED)
			{
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_TOUCH_AREA, ta, PRESSED))
					dump_queue(val->win);
			}
			else if (ta->state == PRESSED && ta->is_trackable)
			{
				if (! put_to_wm_queue(val->win, WM_MESSAGE_ACTION, TYPE_TOUCH_AREA, ta, MOVING))
					dump_queue(val->win);
			}
		}
			break;

		case TYPE_TEXT_FIELD:
			break;

		default:
		{
			PRINTF("set_state_record: undefined type\n");
			ASSERT(0);
		}
			break;
	}
}

/* GUI state mashine */
static void process_gui(void)
{
	uint_fast16_t tx, ty;
	static uint_fast16_t x_old = 0, y_old = 0, long_press_counter = 0;
	static gui_element_t * p = NULL;
	static window_t * w = NULL;
	const uint_fast8_t long_press_limit = 20;
	static uint_fast8_t is_long_press = 0;		// 1 - долгое нажатие уже обработано
	static uint_fast8_t is_repeating = 0, repeating_cnt = 0;

	if (board_tsc_getxy(& tx, & ty))
	{
		gui.last_pressed_x = tx;
		gui.last_pressed_y = ty;
		gui.is_touching_screen = 1;
//		PRINTF(PSTR("last x/y=%d/%d\n"), gui.last_pressed_x, gui.last_pressed_y);
		update_gui_elements_list();
	}
	else
	{
		gui.is_touching_screen = 0;
		gui.is_after_touch = 0;
	}

	if (gui_element_count == 0)
		return;

	if (gui.state == CANCELLED && gui.is_touching_screen && ! gui.is_after_touch)
	{
		ASSERT(gui_element_count != 0);
		for (int i = gui_element_count - 1; i >= 0; i --)
		{
			ASSERT(i < ARRAY_SIZE(gui_elements));
			p = & gui_elements [i];
			w = p->win;
			ASSERT(w != NULL);
			uint_fast16_t x1 = p->x1 + w->x1, y1 = p->y1 + w->y1;
			uint_fast16_t x2 = p->x2 + w->x1, y2 = p->y2 + w->y1;

			if (x1 < gui.last_pressed_x && x2 > gui.last_pressed_x && y1 < gui.last_pressed_y && y2 > gui.last_pressed_y
					&& p->state != DISABLED && p->visible == VISIBLE)
			{
				gui.state = PRESSED;
				is_long_press = 0;
				is_repeating = 0;
				long_press_counter = 0;
				break;
			}
		}
	}

	if (gui.is_tracking && ! gui.is_touching_screen)
	{
		gui.is_tracking = 0;
		reset_tracking();
		x_old = 0;
		y_old = 0;
	}

	if (gui.state == PRESSED)
	{
		ASSERT(p != NULL);
		if (p->is_trackable && gui.is_touching_screen)
		{
			gui.vector_move_x = x_old ? gui.vector_move_x + gui.last_pressed_x - x_old : 0; // проверить, нужно ли оставить накопление
			gui.vector_move_y = y_old ? gui.vector_move_y + gui.last_pressed_y - y_old : 0;

			if (gui.vector_move_x != 0 || gui.vector_move_y != 0)
			{
				gui.is_tracking = 1;
//				PRINTF(PSTR("move x: %d, move y: %d\n"), gui.vector_move_x, gui.vector_move_y);
			}

			p->state = PRESSED;
			set_state_record(p);

			x_old = gui.last_pressed_x;
			y_old = gui.last_pressed_y;
		}
		else if (w->x1 + p->x1 < gui.last_pressed_x && w->x1 + p->x2 > gui.last_pressed_x &&
				 w->y1 + p->y1 < gui.last_pressed_y && w->y1 + p->y2 > gui.last_pressed_y && ! gui.is_after_touch)
		{
			if (gui.is_touching_screen)
			{
				ASSERT(p != NULL);
				p->state = PRESSED;

				if (is_repeating)
				{
					repeating_cnt ++;
					if (repeating_cnt > autorepeat_delay)
					{
						repeating_cnt = 0;
						p->state = PRESS_REPEATING;		// для запуска обработчика нажатия
						set_state_record(p);
					}
				}
				else
					set_state_record(p);

				if (p->is_long_press)
				{
					if(gui.state != LONG_PRESSED && ! is_long_press)
						long_press_counter ++;

					if(long_press_counter > long_press_limit)
					{
						long_press_counter = 0;
						gui.state = LONG_PRESSED;
					}
				}
				else if (p->is_repeating)
				{
					if (! is_repeating)
						long_press_counter ++;

					if(long_press_counter > long_press_limit)
					{
						long_press_counter = 0;
						repeating_cnt = 0;
						is_repeating = 1;
					}
				}

			}
			else
				gui.state = RELEASED;
		}
		else
		{
			ASSERT(p != NULL);
			gui.state = CANCELLED;
			p->state = CANCELLED;
			set_state_record(p);
			gui.is_after_touch = 1; 	// точка непрерывного касания вышла за пределы выбранного элемента, не поддерживающего tracking
		}
	}

	if (gui.state == RELEASED)
	{
		ASSERT(p != NULL);
		p->state = RELEASED;			// для запуска обработчика нажатия
		if(! is_long_press)				// если было долгое нажатие, обработчик по короткому не запускать
			set_state_record(p);
		p->state = CANCELLED;
		set_state_record(p);
		gui.is_after_touch = 0;
		gui.state = CANCELLED;
		gui.is_tracking = 0;
	}
	else if (gui.state == LONG_PRESSED)
	{
		p->state = LONG_PRESSED;		// для запуска обработчика нажатия
		set_state_record(p);
		p->state = PRESSED;
		gui.state = PRESSED;
		is_long_press = 1;				// долгое нажатие обработано
	}
}

/* Запуск state mashine и отрисовка элементов GUI */
void gui_WM_walktrough(uint_fast8_t x, uint_fast8_t y, dctx_t * pctx)
{
	uint_fast8_t alpha = DEFAULT_ALPHA; // на сколько затемнять цвета
	char buf [TEXT_ARRAY_SIZE];
	uint_fast8_t str_len = 0;
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();

	process_gui();

	for(uint_fast8_t i = 0; i < WIN_GUI_COUNT; i ++)
	{
		if (gui.win [i] == NO_PARENT_WINDOW)
			break;

		const window_t * const win = get_win(gui.win [i]);
		uint_fast8_t f = win->first_call;

		if (win->state == VISIBLE)
		{
			// при открытии окна рассчитываются экранные координаты самого окна и его child элементов
			if (! f)
			{
				if (win->window_id != WINDOW_MAIN)
				{
					ASSERT(win->w > 0 || win->h > 0);
#if GUI_TRANSPARENT_WINDOWS
					display_transparency(win->x1, strcmp(win->title, "") ? (win->y1 + window_title_height) :
							win->y1, win->x1 + win->w - 1, win->y1 + win->h - 1, alpha);
#else
					colpip_fillrect(fr, DIM_X, DIM_Y, win->x1, strcmp(win->title, "") ? (win->y1 + window_title_height) :
							win->y1, win->w, win->h, GUI_WINDOWBGCOLOR);
#endif /* GUI_TRANSPARENT_WINDOWS */
				}
			}

			// запуск процедуры фоновой обработки для окна
			win->onVisibleProcess();

			if (! f)
			{
				// вывод заголовка окна
				if (strcmp(win->title, ""))
				{
					uint16_t title_lenght = strlen(win->title) * SMALLCHARW;
					uint16_t xt = 0;

					switch(win->title_align)
					{
					case TITLE_ALIGNMENT_LEFT:

						xt = win->x1 + window_title_indent;

						break;

					case TITLE_ALIGNMENT_RIGHT:

						xt = win->x1 + win->w - title_lenght - window_title_indent - (win->is_close ? window_close_button_size : 0);

						break;

					case TITLE_ALIGNMENT_CENTER:

						xt = win->x1 + win->w / 2 - title_lenght / 2;

						break;

					default:

						PRINTF("alignment value %d incorrect for window %s\n", win->title_align, win->title);
						ASSERT(0);

						break;
					}

					colpip_fillrect(fr, DIM_X, DIM_Y, win->x1, win->y1, win->w, window_title_height, GUI_WINDOWTITLECOLOR);
					colpip_string_tbg(fr, DIM_X, DIM_Y, xt, win->y1 + 5, win->title, COLORMAIN_BLACK);
				}

				// отрисовка принадлежащих окну элементов
				for (uint_fast8_t i = 0; i < gui_element_count; i ++)
				{
					gui_element_t * p = & gui_elements [i];

					if (p->type == TYPE_BUTTON)
					{
						button_t * bh = (button_t *) p->link;
						if (bh->visible && bh->parent == win->window_id)
							draw_button(bh);
					}
					else if (p->type == TYPE_CLOSE_BUTTON)
					{
						button_t * bh = (button_t *) p->link;
						if (bh->visible && bh->parent == win->window_id)
						{
							colpip_rect(fr, DIM_X, DIM_Y, win->x1 + bh->x1, win->y1 + bh->y1,
									win->x1 + bh->x1 + bh->w,  win->y1 + bh->y1 + bh->h, COLORMAIN_BLACK, 0);
							colmain_line(fr, DIM_X, DIM_Y, win->x1 + bh->x1, win->y1 + bh->y1,
									win->x1 + bh->x1 + bh->w, win->y1 + bh->y1 + bh->h, COLORMAIN_BLACK, 0);
							colmain_line(fr, DIM_X, DIM_Y, win->x1 + bh->x1, win->y1 + bh->y1 + bh->h,
									win->x1 + bh->x1 + bh->w, win->y1 + bh->y1, COLORMAIN_BLACK, 0);
						}
					}
					else if (p->type == TYPE_LABEL)
					{
						label_t * lh = (label_t *) p->link;
						if (lh->visible && lh->parent == win->window_id)
						{
							if (lh->font_size == FONT_LARGE)
								colpip_string_tbg(fr, DIM_X, DIM_Y,  win->x1 + lh->x, win->y1 + lh->y, lh->text, lh->color);
							else if (lh->font_size == FONT_MEDIUM)
								colpip_string2_tbg(fr, DIM_X, DIM_Y, win->x1 + lh->x, win->y1 + lh->y, lh->text, lh->color);
							else if (lh->font_size == FONT_SMALL)
								colpip_string3_tbg(fr, DIM_X, DIM_Y, win->x1 + lh->x, win->y1 + lh->y, lh->text, lh->color);
						}
					}
					else if (p->type == TYPE_SLIDER)
					{
						slider_t * sh = (slider_t *) p->link;
						if (sh->visible && sh->parent == win->window_id)
							draw_slider(sh);
					}
					else if (p->type == TYPE_TEXT_FIELD)
					{
						text_field_t * tf = (text_field_t *) p->link;
						if (tf->visible && tf->parent == win->window_id)
						{
							int_fast8_t j = tf->index - 1;
							for (uint8_t i = 0; i < tf->h_str; i ++)
							{
								uint_fast8_t pos = tf->direction ? (tf->h_str - i - 1) : i;
								j = j < 0 ? (tf->h_str - 1) : j;

								if (tf->font)
								{
									UB_Font_DrawString(fr, DIM_X, DIM_Y, win->x1 + tf->x1, win->y1 + tf->y1 + tf->font->height * pos,
											tf->string[j].text, tf->font, tf->string[j].color_line);
								}
								else
								{
									colpip_string2_tbg(fr, DIM_X, DIM_Y, win->x1 + tf->x1, win->y1 + tf->y1 + SMALLCHARH2 * pos,
											tf->string[j].text, tf->string[j].color_line);
								}

								j --;
							}
						}
					}
				}
			}
		}
	}
}

// *************************************

void gui_drawstring(window_t * win, uint_fast16_t x, uint_fast16_t y, const char * str, font_size_t font, COLORMAIN_T color)
{
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();

	const uint_fast16_t x1 = x + win->draw_x1;
	const uint_fast16_t y1 = y + win->draw_y1;

	ASSERT(x1 < win->draw_x2);
	ASSERT(y1 < win->draw_y2);

	if (font == FONT_LARGE)
		colpip_string_tbg(fr, DIM_X, DIM_Y,  x1, y1, str, color);
	else if (font == FONT_MEDIUM)
		colpip_string2_tbg(fr, DIM_X, DIM_Y, x1, y1, str, color);
	else if (font == FONT_SMALL)
		colpip_string3_tbg(fr, DIM_X, DIM_Y, x1, y1, str, color);
}

uint_fast16_t gui_get_window_draw_width(window_t * win)
{
	return win->draw_x2 - win->draw_x1;
}

uint_fast16_t gui_get_window_draw_height(window_t * win)
{
	return win->draw_y2 - win->draw_y1;
}

// Нарисовать линию в границах окна
void gui_drawline(window_t * win, uint_fast16_t x1, uint_fast16_t y1, uint_fast16_t x2, uint_fast16_t y2, COLORMAIN_T color)
{
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();

	const uint_fast16_t xn = x1 + win->draw_x1;
	const uint_fast16_t yn = y1 + win->draw_y1;
	const uint_fast16_t xk = x2 + win->draw_x1;
	const uint_fast16_t yk = y2 + win->draw_y1;

	ASSERT(xn < win->draw_x2);
	ASSERT(xk < win->draw_x2);
	ASSERT(yn < win->draw_y2);
	ASSERT(yk < win->draw_y2);

	colmain_line(fr, DIM_X, DIM_Y, xn, yn, xk, yk, color, 1);
}

void gui_drawrect(window_t * win, uint_fast16_t x1, uint_fast16_t y1, uint_fast16_t x2, uint_fast16_t y2, COLORMAIN_T color, uint_fast8_t fill)
{
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();

	const uint_fast16_t xn = x1 + win->draw_x1;
	const uint_fast16_t yn = y1 + win->draw_y1;
	const uint_fast16_t xk = x2 + win->draw_x1;
	const uint_fast16_t yk = y2 + win->draw_y1;

	ASSERT(xn < win->draw_x2);
	ASSERT(xk < win->draw_x2);
	ASSERT(yn < win->draw_y2);
	ASSERT(yk < win->draw_y2);

	colpip_rect(fr, DIM_X, DIM_Y, xn, yn, xk, yk, color, fill);
}

void gui_drawpoint(window_t * win, uint_fast16_t x1, uint_fast16_t y1, COLORMAIN_T color)
{
	PACKEDCOLORMAIN_T * const fr = colmain_fb_draw();

	const uint_fast16_t xp = x1 + win->draw_x1;
	const uint_fast16_t yp = y1 + win->draw_y1;


	ASSERT(xp < win->draw_x2);
	ASSERT(xp < win->draw_x2);

	colpip_point(fr, DIM_X, DIM_Y, xp, yp, color);
}

#endif /* WITHTOUCHGUI */
