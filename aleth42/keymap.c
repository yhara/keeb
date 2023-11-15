/* Copyright 2020 monksoffunk
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

// DONT FORGET TO UPDATE COMBO_COUNT in config.h when adding a new combo
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  comb_keys_Enter = {KC_J, KC_O, COMBO_END},
  comb_keys_BackSpace = {KC_J, KC_I, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO( comb_keys_Enter, KC_ENT ),
  COMBO( comb_keys_BackSpace, KC_BSPC ),
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    MACRO1,
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Default Layer
     * ,-----------------------------------------------------------.
     * | Tab|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS  |
     * |-----------------------------------------------------------|
     * |Ctl/Esc|  A |  S |  D |  F |  G |  H |  J |  K |  L | ;    |
     * |-----------------------------------------------------------|
     * |Sft/Tab |  Z |  X |  C |  V |  B |  N |  M |  , |  . |fn(-)|
     * |-----------------------------------------------------------|
     * | TAB  | LAlt|Gui/T|  lower/eisu|  spc/cursor|raise/k|ENT| / |
     * `-----------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,
 CTL_T(KC_ESC),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,
 LSFT_T(KC_TAB),KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  LT(_ADJUST, KC_MINS),
        KC_TAB , KC_LALT   , GUI_T(KC_TAB), LT(_LOWER, KC_LNG2),   LT(_ADJUST, KC_SPC), LT(_RAISE,KC_LNG1), KC_ENT, KC_SLSH
        ),

 /* Lower Layer
     * ,-----------------------------------------------------------.
     * |    |  ! |  @ |  # |  $ |  % |  ^ |  & |  ( | )  | *  | }  |
     * |-----------------------------------------------------------|
     * |        | ~  |Pipe| =  |  \ |  `  | ' | { | [ | ] |   :    |
     * |-----------------------------------------------------------|
     * |          |    |    | ?  | /  |    | " | +  |  < |  > | _  |
     * |-----------------------------------------------------------|
     * |RST  |    |     |           |             |    | ?  |  _   |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
        _______, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_LPRN,JP_RPRN, JP_ASTR,JP_RCBR,
	_______,S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN,  JP_GRV , JP_QUOT, JP_LCBR ,JP_LBRC,JP_RBRC, JP_COLN,
	_______, _______, _______, S(KC_SLSH), KC_SLSH, _______, JP_DQUO , JP_PLUS,S(KC_COMM),S(KC_DOT),JP_UNDS,
	QK_BOOT, _______, _______, _______, _______,_______, S(KC_SLSH), JP_UNDS
	),

	/* Raise Layer
     * ,-----------------------------------------------------------.
     * |F12 | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |
     * |-----------------------------------------------------------|
     * |       |  1  |  2 |  3 |  4 |   5 | 6 | 7 | 8 | 9 |  0     |
     * |-----------------------------------------------------------|
     * |          |    |    |    |    |    |    | :  | , | .  | /  |
     * |-----------------------------------------------------------|
     * |RESET|    |     |           |             |     |  - |     |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT(
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  
        _______, _______, _______, _______, _______, _______, _______, JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,
	QK_BOOT  , _______, _______, _______, _______, _______, KC_TRNS, _______
	),

	/* Adjust Layer
     * ,-----------------------------------------------------------.
     * |Mute|    |    | End|    |    |    |SA(Tab)|A(Tab)|^z[ | BS |
     * |-----------------------------------------------------------|
     * |       |Home|    | Del |    | BS |Left|Down|Up  |Right|    |
     * |-----------------------------------------------------------|
     * |          |     |   |    |    |    |    |ENT|   |    |     |
     * |-----------------------------------------------------------|
     * |Reset|    |     |           |             |     |    |     |
     * `-----------------------------------------------------------'
      */
    [_ADJUST] = LAYOUT(
        KC_MUTE, _______, _______, KC_END , _______, _______, _______, _______, _______, _______, MACRO1, KC_BSPC,
	_______, KC_HOME, _______, KC_DEL , _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,  _______,
	_______, _______,   _______, _______, _______, _______, _______, KC_ENT, _______, _______,  _______,
	QK_BOOT,   _______, _______, _______, _______, _______, _______, _______
	),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case MACRO1:
        SEND_STRING(SS_LCTL("z")"[");
        return false;
    }
  }
  return true;
};
