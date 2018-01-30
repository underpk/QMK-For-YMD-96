#include "ymd96.h"
#include "action_layer.h"
#include "rgblight.h"

// Add this line to make tap dance works
#include "quantum.h"

#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif

#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1

// My Custom Name
#define CTL_BSPC 	RCTL(KC_BSPC)
#define SHOW_TIME 	LALT(RGUI(KC_D))
#define WIN_KC_BSLS GUI_T(KC_BSLS)
#define RAISE_CAPS 	LT(_RAISE, KC_CAPS)
#define RAISE_Z 	LT(_RAISE, KC_Z)
#define RAISE_SLSH 	LT(_RAISE, KC_SLSH)

enum {
	CT_PRN = 0,
	WIN_EXP,
	ALT_TASK,
	HOME_PREV,
	END_NEXT,
	MIN_MUTE
};

 // 2 PrintCreen CTRL PrintScreen
void dance_prn_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_PSCR);
  } else {
	register_code (KC_RCTL);
    register_code (KC_PSCR);
  }
}

void dance_prn_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_PSCR);
  } else {
    unregister_code (KC_RCTL);
    unregister_code (KC_PSCR);
  }
} 

// 2 WIN Explorer
void dance_winexp_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LGUI);
  } else {
	register_code (KC_LGUI);
    register_code (KC_E);
  }
}

void dance_winexp_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LGUI);
  } else {
    unregister_code (KC_LGUI);
    unregister_code (KC_E);
  }
}

// 3 ALT TASK MANAGER
void dance_taskmgr_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code (KC_LALT);
  } else {
	register_code (KC_LSFT);
    register_code (KC_LCTL);
    register_code (KC_ESC);
  }
}

void dance_taskmgr_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    unregister_code (KC_LALT);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_LCTL);
    unregister_code (KC_ESC);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
	
	[CT_PRN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_prn_finished, dance_prn_reset),
	[WIN_EXP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_winexp_finished, dance_winexp_reset),
	[ALT_TASK] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_taskmgr_finished, dance_taskmgr_reset),
	[HOME_PREV]  = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_MPRV),
	[END_NEXT]  = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_MNXT),
	[MIN_MUTE]  = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_MUTE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	/* Layer 0, default layer
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |Print | Print+ 	 |NumLck| Home | End  | PgUp | 19 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |  ~`  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |    0 |    - |    = |    BkSpc   		 | END  |   /  |   *  | PgDn | 18 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |    P |    { |    } |     \   		 |  7   |   8  |   9  |   -  | 18 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |   Caps   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |    ; |   '  |     Return    		 |  4   |   5  |   6  |   +  | 17 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |    LShft     |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |       RShft    |  Up   |  1   |   2  |   3  |  En  | 17 keys
	*  .--------------------/--------------------------------------------------------------------------------------------------------------.      .
	*  | Ctrl  |  Win  |  Alt  |                  Space                    		    |  LAlt  |  RCtrl | Left | Down  | Right|   0  |   .  |  ter | 11 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*/
	
    [_DEFLT] = KEYMAP(
	
		KC_ESC,  	KC_F1,  	KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,  	KC_F10, 	KC_F11,     KC_F12,     KC_PSCR, 	 TD(CT_PRN),  KC_NUMLOCK,   TD(HOME_PREV), TD(END_NEXT), 	KC_PGUP, 	\
		KC_GRV, 	KC_1,   	KC_2,  	 KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   	KC_0,   	KC_MINS,    KC_EQL,     KC_BSPACE,   KC_DELETE,   KC_KP_SLASH,  KC_KP_ASTERISK,    	KC_PGDN, 	\
		KC_TAB,  	KC_Q,   	KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   	KC_P,   	KC_LBRC,    KC_RBRC,    WIN_KC_BSLS, KC_P7,       KC_P8,        KC_P9,             	TD(MIN_MUTE), 	\
		RAISE_CAPS, KC_A,   	KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   	KC_SCLN,	KC_QUOT,    KC_ENT,      			 KC_P4,       KC_P5,       	KC_P6,      		KC_PPLS, 	\
		KC_LSFT, 	RAISE_Z,   	KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, 				RAISE_SLSH, KC_RSFT,	KC_UP,  	 KC_P1,       KC_P2, 		KC_P3,		 		KC_PENT,	\
		KC_LCTL, 	TD(WIN_EXP),	TD(ALT_TASK),                            KC_SPC,                       	KC_RALT,    KC_RCTL, 	KC_LEFT, 	KC_DOWN, 	 KC_RGHT, 	  KC_P0,   	 	KC_PDOT 						\
	),

		/* Layer 1, _RAISE layer
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |      |      |      |      |      |      |      |      |      |      |      |      |      |     |       	 |     |      |      |      | 19 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |      |      |      |      |      |      |      |      |      |      |      |      |      |          		 |     |      |      |      | 18 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |         |      |      |      |      |      |      |      |      |      |      |      |      |         		 |     |      |      |      | 18 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |          |      |      |      |      |      |      |      |      |      |      |      |             		 |     |      |      |      | 17 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*  |              |      |      |      |      |      |      |      |      |      |      |                |       |     |      |      |      | 17 keys
	*  .---------------------------------------------------------------------------------------------------------------------------------.      .
	*  |       |       |       |                                      		        |        |        |      |       |     |      |      |      | 11 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*/
	
		/* BLANK LAYER
	[_BLANK] = KEYMAP(
		______,  	______,  	______,   ______, 	______,  		______,   	______,   ______,   ______,   ______, 	 ______,    ______,  ______,   ______,  ______,  	 		  ______,    ______,  ______,  ______, 	\
		______,  	______,  	______,   ______,  	______,  		______,  	______,   ______,  	______,   ______, 	 ______,  	______,  ______,   ______,  					  ______,    ______,  ______,  ______,	\
		______,  	______,  	______,   ______,  	______,  		______, 	______,   ______,  	______,   ______, 	 ______,  	______,  ______,   ______,  					  ______,    ______,  ______,  ______, 	\
		______, 	______,  	______,   ______, 	______,  		______,  	______,   ______,   ______,   ______, 	 ______,	______,  ______,  					  			  ______,    ______,  ______,  ______, 	\
		______, 	______,  	______,   ______,  	______,  		______, 	______,   ______,  	______,   ______, 	 ______,    ______,  								______,	  ______,    ______,  ______,  ______,  \
		______,  	______,  	______,                         				______,                        					 			 ______,   ______,   ______, 	______,   ______,    ______,  ______  			\
	)  			
	*/
	
	[_RAISE] = KEYMAP(
		______,  	RGB_M_P,  	RGB_M_B,  RGB_M_R, 	RGB_M_SW,  		RGB_M_SN,   RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_TOG,  BL_TOGG,    ______,  ______,   ______,  ______,  			  RGB_TOG,   KC_MPLY,  KC_MUTE,  KC_VOLU, 	\
		______,  	______,  	______,   ______,  	______,  		______,  	______,   ______,  	______,   ______, 	______,  	______,  ______,   ______,  			 		  ______,    ______,   ______,   KC_VOLD,	\
		______,  	KC_HOME,  	KC_UP,    KC_END,  	CTL_BSPC,  		SHOW_TIME,  ______,   ______,  	KC_HOME,  KC_UP,  	KC_UP,  	KC_END,  CTL_BSPC, ______,  			  		  ______,    ______,   ______,   ______, 	\
		______, 	KC_LEFT,  	KC_DOWN,  KC_RGHT,  ______,  		______,  	______,   ______,   KC_LEFT,  KC_DOWN,  KC_DOWN, 	KC_RGHT, ______,    						  	  ______,    ______,   ______,   ______, 	\
		______, 	______,  	______,   ______,  	______,  		______, 	______,   ______,  	______,   ______, 	______,     ______,  							   ______,	  ______,    ______,   ______, 	 ______,  	\
		______,  	______,  	______,                            				______,                        								 ______,   ______,  RGB_HUI,   ______,    RGB_HUD,   ______,   ______  				\
	)
};
