#ifndef GUI_USER_H_INCLUDED
#define GUI_USER_H_INCLUDED

#include "hardware.h"

#if WITHTOUCHGUI

#include "src/gui/gui.h"
#include "src/gui/gui_structs.h"

#if WITHGUISTYLE_COMMON				// версия GUI для разрешения 800х480

enum {
	WINDOW_MAIN,					// постоянно отображаемые кнопки внизу экрана
	WINDOW_MODES,					// переключение режимов работы, видов модуляции
	WINDOW_AF,						// регулировка полосы пропускания фильтров выбранного режима
	WINDOW_FREQ,					// прямой ввод частоты
	WINDOW_MENU,					// системное меню
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
	WINDOW_GUI_SETTINGS,				// настройки интерфейса GUI
	WINDOW_FT8,

	WINDOWS_COUNT
};

#elif WITHGUISTYLE_MINI 				// версия GUI для разрешения 480x272

enum {
	WINDOW_MAIN,
	WINDOW_MAIN_MENU,
	WINDOW_MENU,
	WINDOW_BANDS,
	WINDOW_FREQ,
	WINDOW_RECEIVE,
	WINDOW_MODES,
	WINDOW_AF,

	WINDOWS_COUNT
};

#endif /* WITHGUISTYLE_COMMON */

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

typedef struct {
	uint_fast16_t step;
	char label [10];
} val_step_t;

#define GET_FROM_WM_QUEUE	uint_fast8_t type;	\
							int_fast8_t action;	\
							uintptr_t ptr;		\
							switch (get_from_wm_queue(win, & type, & ptr, & action))

#endif /* WITHTOUCHGUI */
#endif /* GUI_USER_H_INCLUDED */
