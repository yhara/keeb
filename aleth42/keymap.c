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
#include "keymap_jp.h"

// DONT FORGET TO UPDATE COMBO_COUNT in config.h when adding a new combo
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  comb_keys_Enter = {KC_J, KC_O, COMBO_END},
  comb_keys_BackSpace = {KC_J, KC_I, COMBO_END},
  comb_keys_Tab = {KC_W, KC_R, COMBO_END},
  comb_keys_Kana = {KC_G, KC_J, COMBO_END},
  comb_keys_Eisu = {KC_G, KC_H, COMBO_END},
  comb_keys_Escape = {KC_W, KC_E, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO( comb_keys_Enter, KC_ENT ),
  COMBO( comb_keys_BackSpace, KC_BSPC ),
  COMBO( comb_keys_Tab, KC_TAB ),
  COMBO( comb_keys_Kana, KC_LANG1 ),
  COMBO( comb_keys_Eisu, KC_LANG2 ),
  COMBO( comb_keys_Escape, KC_ESC ),
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    MACRO1,
    ALT_TAB,
    SALT_TAB,
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
     * | Tab|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | ;  |
     * |-----------------------------------------------------------|
     * |Ctl/Esc|  A |  S |  D |  F |  G |  H |  J |  K |  L | Ent  |
     * |-----------------------------------------------------------|
     * |Sft/Tab |  Z |  X |  C |  V |  B |  N |  M |  , |  . |fn(-)|
     * |-----------------------------------------------------------|
     * | TAB  | LAlt|Gui/T|  lower/eisu|  spc/cursor|raise/k|TAB| / |
     * `-----------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_SCLN,
 CTL_T(KC_ESC),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT,
 LSFT_T(KC_TAB),KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  LT(_ADJUST, KC_MINS),
        KC_TAB , KC_LALT   , GUI_T(KC_TAB), LT(_LOWER, KC_LANG2),   LT(_ADJUST, KC_SPC), LT(_RAISE,KC_LANG1), KC_TAB, KC_SLSH
        ),

 /* Lower Layer
     * ,-----------------------------------------------------------.
     * |    |  ! |  @ |  # |  $ |  % |  ^ |  & |  ( | )  | *  | }  |
     * |-----------------------------------------------------------|
     * |        | ~  |Pipe| =  |  \ |  `  | ' | { | [ | ] |   :    |
     * |-----------------------------------------------------------|
     * |          |    |    |    |    |Bspc| " | +  |  < |  > | _  |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             |    | ?  |  _   |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT(
        _______, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_CIRC, JP_AMPR, JP_LPRN,JP_RPRN, JP_ASTR,JP_RCBR,
	_______,S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN,  JP_GRV , JP_QUOT, JP_LCBR ,JP_LBRC,JP_RBRC, JP_COLN,
	_______, _______, _______, _______, _______, KC_BSPC, JP_DQT , JP_PLUS,S(KC_COMM),S(KC_DOT),JP_UNDS,
	_______, _______, _______, _______, _______,_______, S(KC_SLSH), JP_UNDS
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
	RESET  , _______, _______, _______, _______, _______, KC_TRNS, _______
	),

	/* Adjust Layer
     * ,-----------------------------------------------------------.
     * |Mute|    |    | End|    |    |    |    |SA(Tab)|A(Tab)|^z[ | BS |
     * |-----------------------------------------------------------|
     * |       |Home|    | Del |    |    |Left|Down|Up  |Right|    |
     * |-----------------------------------------------------------|
     * |          |Reset|   |    |    |    |    |   |   |    |     |
     * |-----------------------------------------------------------|
     * |Reset|    |     |           |             |     |    |     |
     * `-----------------------------------------------------------'
      */
    [_ADJUST] = LAYOUT(
        KC_MUTE, _______, _______, KC_END , _______, _______, _______, _______, SALT_TAB, ALT_TAB, MACRO1, KC_BSPC,
	_______, KC_HOME, _______, KC_DEL , _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,  _______,
	_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______,  _______,
	RESET,   _______, _______, _______, _______, _______, _______, _______
	),
};

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case MACRO1:
        SEND_STRING(SS_LCTRL("z")"[");
        return false;
      case ALT_TAB:
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
        return false;
      case SALT_TAB:
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
        return false;
    }
  }
  return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left encoder */
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                  if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                  }
                  cmd_tab_timer = timer_read();
                  tap_code16(KC_TAB);
                } else {
                  if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                  }
                  cmd_tab_timer = timer_read();
                  tap_code16(S(KC_TAB));
                }
                break;
            case _ADJUST:
                if (clockwise) {
                    tap_code(KC_SPC);
                } else {
                    tap_code(KC_BSPC);
                }
                break;
            case _RAISE:
                if (clockwise) {
                  tap_code(KC_PGDN);
                } else {
                  tap_code(KC_PGUP);
                }
                break;
        }

    } else if (index == 1) { /* Right encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_cmd_tab_active = false;
    }
  }
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
