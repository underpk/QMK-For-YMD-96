/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ymd96.h"
#include "action_layer.h"
#include "rgblight.h"
#include "quantum.h"

#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1

// My Custom Name
#define CTL_BSPC RCTL(KC_BSPC)
#define SHOW_TIME LALT(RGUI(KC_D))
#define WIN_KC_BSLS GUI_T(KC_BSLS)

enum {
  CT_CLN = 0
};




void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RCTL);
    register_code (KC_PSCR);
  } else {
    register_code (KC_PSCR);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RCTL);
    unregister_code (KC_PSCR);
  } else {
    unregister_code (KC_PSCR);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 // 2 PrintCreen CTRL PrintScreen
 [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
 // 3 ESC ALT F4

 // 2 WIN Explorer

 // 2 END Mute
 
 // 2 HOME Pause
 
 
 
 
 
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
	*  .----------------------------------------------------------------------------------------------------------------------------------.      .
	*  | Ctrl  |  Win  |  Alt  |                  Space                    		    |  LAlt  |  RCtrl | Left | Down  | Right|   0  |   .  |  ter | 11 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*/
	
    [_DEFLT] = KEYMAP(
	
		KC_ESC,  	KC_F1,  	KC_F2,  	KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  	KC_F10, 	KC_F11,       		KC_F12,     KC_PSCR, TD(CT_CLN),    KC_NUMLOCK, 	KC_HOME, KC_END, 	KC_PGUP, \
		KC_GRV, 	KC_1,   	KC_2,  	 	KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   	KC_0,   	KC_MINS,      		KC_EQL,     KC_BSPACE,         	    KC_DELETE,  	KC_KP_SLASH,      	KC_KP_ASTERISK, KC_PGDN, 			\
		KC_TAB,  	KC_Q,   	KC_W,   	KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   	KC_P,   	KC_LBRC,      		KC_RBRC,    WIN_KC_BSLS,        	KC_P7,      	KC_P8,           	KC_P9,          KC_PMNS, 			\
		LT(_RAISE, 	KC_CAPS), 	KC_A,   	KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   	KC_L,   	KC_SCLN,KC_QUOT,                KC_ENT,          	    KC_P4,      	KC_P5,            	KC_P6,          KC_PPLS, 			\
		KC_LSFT, 	LT(_RAISE, KC_Z),   	KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, 	KC_DOT, 	LT(_RAISE, KC_SLSH),            KC_RSFT,				KC_UP,  	  	KC_P1,      		KC_P2, 			KC_P3,		KC_PENT,\
		KC_LCTL, 	KC_LGUI,	KC_LALT,                            KC_SPC,                       		KC_RALT,    KC_RCTL, 						KC_LEFT, 				KC_DOWN, 	  	KC_RGHT, 	  		KC_P0,   	  	KC_PDOT 			\
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
	*  .----------------------------------------------------------------------------------------------------------------------------------.      .
	*  |       |       |       |                                      		        |        |        |      |       |     |      |   .  |      | 12 keys
	*  .-----------------------------------------------------------------------------------------------------------------------------------------.
	*/
	
	
	[_RAISE] = KEYMAP(
			______,  RGB_M_P,  RGB_M_B,  RGB_M_R, 		RGB_M_SW,  RGB_M_SN,  RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_TOG,  BL_TOGG, ______,  ______,  ______,  ______,  RGB_TOG,  KC_MPLY,  KC_MUTE,  KC_VOLU, \
			______,  ______,  ______,  ______,  	______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_VOLD, \
			______,  KC_HOME,  KC_UP,  KC_END,  	RCTL(KC_BSPC),  SHOW_TIME,  ______,  	______,  KC_HOME,  KC_UP,  KC_UP,  KC_END,  RCTL(KC_BSPC),  ______,  ______,  ______,  ______,  ______, \
			______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  	______,  ______,  ______,  ______,    KC_LEFT,  KC_DOWN,  KC_DOWN,  KC_RGHT, ______, ______,  ______,  ______,  ______, \
			______,  ______,  ______,  ______,  	______,  ______,  ______,  ______,  ______,  ______,  ______,      ______,  ______,  ______,  ______,  ______,  \
		    ______,  ______,  ______,                              ______,                        ______,  ______,  ______,  RGB_HUI,  ______,  RGB_HUD,  ______,  ______  \
	)

	
};
