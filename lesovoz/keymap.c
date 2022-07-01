/* Copyright 2022 Yutaka Hara
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
#include "keymap_japanese.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P,
 CTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, CTL_T(KC_SCLN),
 SFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, SFT_T(KC_MINS),
      KC_TAB,KC_BSPC,KC_LGUI,LT(2,KC_LANG2),ALT_T(KC_SPC),        LT(3,KC_SPC),LT(1,KC_LANG1),KC_ENT,KC_DEL,KC_SLSH),

  [1] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9  , KC_F10 ,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   
      KC_F11,  KC_F12,  KC_NO,   KC_NO ,  KC_NO ,                    JP_COLN, JP_PLUS, _______, _______, _______,
      _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ),

    [2] = LAYOUT(
                KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                 JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR,
                JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                  JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN,
                KC_NO  , KC_NO  , KC_SLSH, KC_SLSH, KC_SLSH,                 JP_DQUO, JP_PLUS, JP_LABK, JP_RABK, JP_UNDS,
                RESET  , _______, _______, _______, _______,                 _______, _______, JP_RCBR, _______, JP_QUES),
    [3] = LAYOUT(
                _______,_______,KC_END, _______, _______,                     _______, _______, _______, _______, _______,
                KC_HOME,_______,KC_DEL, KC_PGDN, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BTN2,
                _______,_______,_______,_______, KC_PGUP,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1,
                _______,_______,_______,_______, _______,                     _______, _______, _______, _______, _______),
};

//
// LED
//

// LED animation on startup
#define INITIAL_INTERVAL 800
#define INTERVAL_MUL 0.9
#define MINIMUM_INTERVAL 10
bool led1 = true;
int interval = INITIAL_INTERVAL;
void swap_led(void) {
  writePin(LED1, led1);
  writePin(LED2, !led1);
  led1 = !led1;
}
uint32_t led_anim(uint32_t trigger_time, void *cb_arg) {
  interval *= INTERVAL_MUL;
  if (interval < MINIMUM_INTERVAL) {
    writePin(LED1, false);
    writePin(LED2, false);
    return 0;
  } else {
    swap_led();
    return interval;
  }
}
void keyboard_post_init_user(void) {
  swap_led();
  defer_exec(INITIAL_INTERVAL, led_anim, NULL);
}

// Turn on LED2 when layer is changed
layer_state_t layer_state_set_user(layer_state_t state) {
  writePin(LED1, state);
  writePinLow(LED2);
  return state;
}

// Turn on LED1 when certain key is pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ENT:
    case KC_BSPC:
    case KC_DEL:
      writePinLow(LED1);
      writePin(LED2, record->event.pressed);
      break;
  }
  return true;
}

//
// COMBO KEYS
//

// DONT FORGET TO UPDATE COMBO_COUNT in config.h when adding a new combo
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  comb_keys_Enter = {KC_J, KC_O, COMBO_END},
  comb_keys_BackSpace = {KC_J, KC_I, COMBO_END},
  comb_keys_Tab = {KC_W, KC_R, COMBO_END},
  comb_keys_Escape = {KC_W, KC_E, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO( comb_keys_Enter, KC_ENT ),
  COMBO( comb_keys_BackSpace, KC_BSPC ),
  COMBO( comb_keys_Tab, KC_TAB ),
  COMBO( comb_keys_Escape, KC_ESC ),
};

