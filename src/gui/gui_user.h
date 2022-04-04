#ifndef GUI_USER_H_INCLUDED
#define GUI_USER_H_INCLUDED

#include "hardware.h"

#if WITHTOUCHGUI

#include "src/gui/gui.h"
#include "src/gui/gui_structs.h"

enum {
	WINDOW_MAIN,					// постоянно отображаемые кнопки внизу экрана
	WINDOW_MODES,					// переключение режимов работы, видов модуляции
	WINDOW_AF,						// регулировка полосы пропускания фильтров выбранного режима
	WINDOW_FREQ,					// прямой ввод частоты
	WINDOW_MENU,					// системное меню
	WINDOW_MENU_PARAMS,
	WINDOW_UIF,						// быстрое меню по нажатию заранее определенных кнопок
	WINDOW_SWR_SCANNER,				// сканер КСВ по диапазону
	WINDOW_AUDIOSETTINGS,			// настройки аудиопараметров
	WINDOW_AP_MIC_EQ,				// эквалайзер микрофона
	WINDOW_AP_REVERB_SETT,			// параметры ревербератора
	WINDOW_AP_MIC_SETT,				// настройки микрофона
	WINDOW_AP_MIC_PROF,				// профили микрофона (заготовка окна)
	WINDOW_TX_SETTINGS,				// настройки, относящиеся к режиму передачи
	WINDOW_TX_VOX_SETT,				// настройки VOX
	WINDOW_TX_POWER,				// выходная мощность
	WINDOW_OPTIONS,					// различные настройки
	WINDOW_UTILS,					// измерения и т.д.
	WINDOW_BANDS,					// выбор диапазона
	WINDOW_MEMORY,					// ячейки памяти
	WINDOW_DISPLAY,					// настройки отображения
	WINDOW_RECEIVE,					// настройки приема
	WINDOW_NOTCH,					// ручной режекторый фильтр
	WINDOW_GUI_SETTINGS,			// настройки интерфейса GUI
#if WITHFT8
	WINDOW_FT8,						// FT8 декодер
#endif /* #if WITHFT8 */
	WINDOW_INFOBAR_MENU,			// инфобар
	WINDOW_AF_EQ,					// НЧ эквалайзер (тест)
#if defined (RTC1_TYPE)
	WINDOW_TIME,					// настройка времени и даты
#endif /* defined (RTC1_TYPE) */
	WINDOWS_KBD,					// экранная клавиатура
	WINDOWS_KBD_TEST,
	WINDOWS_RLE_TEST,

	WINDOWS_COUNT
};

void gui_user_actions_after_close_window(void);

enum {
	MENU_OFF,
	MENU_GROUPS,
	MENU_PARAMS,
	MENU_VALS,

	MENU_COUNT
};

typedef struct {
	uint8_t first_id;			// первое вхождение номера метки уровня
	uint8_t last_id;			// последнее вхождение номера метки уровня
	uint8_t num_rows;			// число меток уровня
	uint8_t count;				// число значений уровня
	int8_t selected_str;		// выбранная строка уровня
	int8_t selected_label;		// выбранная метка уровня
	uint8_t add_id;				// номер строки уровня, отображаемой первой
	menu_names_t menu_block [MENU_ARRAY_SIZE];	// массив значений уровня меню
} menu_t;

typedef struct {
	char name [TEXT_ARRAY_SIZE];
	uint16_t menupos;
	uint8_t exitkey;
} menu_by_name_t;

enum {
	TYPE_BP_LOW,
	TYPE_BP_HIGH,
	TYPE_AFR,
	TYPE_IF_SHIFT
};

enum {
	TYPE_NOTCH_FREQ,
	TYPE_NOTCH_WIDTH
};

enum {
	TYPE_DISPLAY_SP_TOP,
	TYPE_DISPLAY_SP_BOTTOM,
	TYPE_DISPLAY_WF_TOP,
	TYPE_DISPLAY_WF_BOTTOM
};

typedef struct {
	uint_fast8_t updated;
	uint_fast8_t select;
	int8_t change;
} bp_var_t;

typedef bp_var_t notch_var_t;
typedef bp_var_t display_var_t;
typedef bp_var_t power_var_t;

typedef struct {
	uint_fast16_t step;
	char label [10];
} val_step_t;

#define GET_FROM_WM_QUEUE	uint_fast8_t type;	\
							int_fast8_t action;	\
							uintptr_t ptr;		\
							switch (get_from_wm_queue(win, & type, & ptr, & action))

enum {
	enc2step_default = 1,
	freq_swipe_step_default = 3,
	freq_swipe_enable_default = 0,
	micprofile_default = UINT8_MAX,
	tune_powerdown_enable_default = 1,
	tune_powerdown_value_default = WITHPOWERTRIMATU
};

#if GUI_SHOW_INFOBAR

enum {
	infobar_1st_str_y = 125,
	infobar_2nd_str_y = 145,
	infobar_num_places = 8,
	infobar_label_width = 100
};

#define INFOBAR_EMPTY 			0x80
#define INFOBAR_NOACTION		0x40
#define INFOBAR_NOACTION_POS	6
#define INFOBAR_VALID_MASK		0x3F

enum {
	INFOBAR_AF,
	INFOBAR_ATT,
	INFOBAR_IF_SHIFT,
	INFOBAR_SPAN,
	INFOBAR_VOLTAGE,
	INFOBAR_CPU_TEMP,
	INFOBAR_2ND_ENC_MENU,
	INFOBAR_TX_POWER,
	INFOBAR_AF_VOLUME,
	INFOBAR_DNR,
};

#endif /* GUI_SHOW_INFOBAR */

#endif /* WITHTOUCHGUI */
#endif /* GUI_USER_H_INCLUDED */
