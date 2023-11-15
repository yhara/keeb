/*
Copyright 2022 sporewoh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x10(
      KC_Q, KC_W, KC_E, KC_R, KC_T,                               KC_Y, KC_U, KC_I, KC_O, KC_P,
 CTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,                             KC_H, KC_J, KC_K, KC_L, CTL_T(KC_SCLN),
 SFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,                             KC_N, KC_M, KC_COMM, KC_DOT, SFT_T(KC_MINS),
      KC_TAB,KC_BSPC,KC_LGUI,LT(2,KC_LNG2),ALT_T(KC_SPC),        LT(3,KC_SPC),LT(1,KC_LNG1),KC_ENT,KC_DEL,KC_SLSH),
  
  [1] = LAYOUT_ortho_4x10(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9  , KC_F10 ,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   
      KC_F11,  KC_F12,  KC_NO,   KC_NO ,  KC_NO ,                    JP_COLN, JP_PLUS, _______, _______, _______,
      _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ),

  [2] = LAYOUT_ortho_4x10(
                KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                 JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR,
                JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                  JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN,
                KC_NO  , KC_NO  , KC_NO, S(KC_SLSH),KC_SLSH,                 JP_DQUO, JP_PLUS, JP_LABK, JP_RABK, JP_UNDS,
                QK_BOOT, _______, _______, _______, _______,                 _______, _______, JP_RCBR, _______, JP_QUES),

  [3] = LAYOUT_ortho_4x10(
                KC_ESC, _______,KC_END, _______,  KC_TAB,                     _______, _______, _______, _______, _______,
                KC_HOME,_______,KC_DEL, KC_PGDN, KC_BSPC,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_BTN2,
                _______,_______,_______,_______, KC_PGUP,                     _______, KC_ENT , _______, _______, _______,
                _______,_______,_______,_______, _______,                     _______, _______, _______, _______, _______),
};