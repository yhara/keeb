/* Copyright 2021 yohewi
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEFAULT,
    _2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DEFAULT] = LAYOUT(
      KC_KP_7,    KC_KP_8,    KC_KP_9,    _______,   _______, \
      KC_KP_4,    KC_KP_5,    KC_KP_6,    LT(_2,KC_ENT),    _______, \
      KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_UP,   _______, \
      KC_KP_0,    KC_LEFT, KC_DOWN, KC_RIGHT,   _______ ),
//      KC_KP_0,    KC_COMM, KC_DOT, KC_SLSH,   _______ ),

    [_2] = LAYOUT(
      _______, _______, _______,  _______,  _______, \
      _______, _______, _______,  _______,  _______, \
      _______, _______, _______,  _______,  _______, \
      RESET, _______, _______,  _______,  _______ ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_BSPC);
        } else {
            tap_code(KC_BTN1);
        }
    }
    return true;
};
