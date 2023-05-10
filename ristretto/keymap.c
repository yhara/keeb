/* Copyright 2021 Brandon Lewis
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum layers {
	_BASE,
	_RAISE,
	_LOWER,
	_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
		KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T              , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
	   CTL_T(KC_ESC), KC_A    , KC_S    , KC_D    , KC_F    , KC_G              , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , LT(_ADJUST,KC_ENT) ,
	  LSFT_T(KC_TAB), KC_Z    , KC_X    , KC_C    , KC_V    , KC_B              , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_MINS  ,
	    KC_BSPC , KC_DEL  , KC_LALT , KC_LGUI,LT(_LOWER,KC_LANG2),ALT_T(KC_SPC)  , KC_MPLY , LT(_ADJUST,KC_SPC), LT(_RAISE,KC_LANG1),KC_LEFT , KC_DOWN, KC_UP , KC_RGHT
	),
	[_RAISE] = LAYOUT(
                KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_TRNS, \
                KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
                _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, \
                _______, _______, _______, _______, _______, _______,       KC_SPC,   _______, _______, KC_NO,   KC_NO,   KC_NO,     RESET \
	),
        
	[_LOWER] = LAYOUT(
                KC_AT  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                 JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
                KC_NO  , JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                  JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
                KC_NO  , KC_NO  , KC_NO  , KC_SLSH, S(KC_INS), KC_SLSH,                 JP_DQUO ,JP_PLUS, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
                RESET  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  ,       KC_SPC,   KC_TRNS, KC_NO  , JP_LCBR, JP_RCBR, KC_NO  , KC_NO
	),
	[_ADJUST] = LAYOUT(
                _______,_______,_______,KC_END, _______, _______,                     _______, _______, _______, _______, _______, KC_BSPC, \
                _______,KC_HOME,_______,KC_DEL, KC_PGDN, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
                _______,_______,_______,_______,_______, KC_PGUP,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
                _______,_______,_______,_______,_______, _______,           KC_SPC,   _______, _______, _______ , _______, _______, _______
	),
};


//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
}

#define RISTRETTO_LEN 9
int ristretto_ct = 0;
static uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    ristretto_ct = (ristretto_ct + 1) % RISTRETTO_LEN;
    key_timer = timer_read();
  }
  return true;
}

#define RISTRETTO "Ristretto"
bool oled_task_user(void) {
  if (timer_elapsed(key_timer) > 10000) {
    fade_display();
  } else {
    oled_set_cursor(0, 0);
    switch (ristretto_ct) {
      case 0: oled_write_P(PSTR("Ristretto"), false); break;
      case 1: oled_write_P(PSTR("istretto"), false); break;
      case 2: oled_write_P(PSTR("stretto"), false); break;
      case 3: oled_write_P(PSTR("tretto"), false); break;
      case 4: oled_write_P(PSTR("retto"), false); break;
      case 5: oled_write_P(PSTR("etto"), false); break;
      case 6: oled_write_P(PSTR("tto"), false); break;
      case 7: oled_write_P(PSTR("to"), false); break;
      case 8: oled_write_P(PSTR("o"), false); break;
    }
    //  const char *s = RISTRETTO + ristretto_ct;
    //  oled_write_P(PSTR(&RISTRETTO[ristretto_ct]), false);
    //  => error: invalid initializer
    for (int i=0; i<8; i++) {
      oled_write_P(PSTR(RISTRETTO), false);
    }
  }
  return false;
}

//OLED_SCROLL_TIMEOUT

