/* Copyright 2022 ziptyze
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

enum layer_names {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _CURSOR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    *                                                                              ╱⎺⎺⎺⎺╲
    *                                                                             |RGBTOG|
    *                                                                              ╲⎽⎽⎽⎽╱ 
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Adjust| Ctrl | Alt  | GUI  |Lower |   Space     |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_BASE] =  LAYOUT_ortho_4x12 (
                                                                                                           RGB_TOG,
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F ,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  LSFT_T(KC_TAB),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
  KC_BSPC,KC_DEL,KC_LALT,KC_LGUI,LT(_LOWER,KC_LNG2),ALT_T(KC_SPC), LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LNG1),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT \
    ),

    /* Lower
    *                                                                              ╱⎺⎺⎺⎺╲
    *                                                                             | MUTE |
    *                                                                              ╲⎽⎽⎽⎽╱ 
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_ortho_4x12 (
                                                                                                                 KC_MUTE,
  KC_NO  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
  KC_NO  , S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
  KC_NO  , KC_NO  , KC_NO  , KC_SLSH , KC_SLSH, KC_SLSH,  JP_DQUO , JP_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),JP_UNDS,
  QK_BOOT  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  ,  KC_TRNS, KC_NO  , JP_LCBR, JP_RCBR, KC_NO  , KC_NO
    ),

    /* Raise
    *                                                                              ╱⎺⎺⎺⎺╲
    *                                                                             | MUTE |
    *                                                                              ╲⎽⎽⎽⎽╱ 
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      | Mute |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_ortho_4x12 (
                                                                                                           KC_MUTE,
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_TRNS, \
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, \
  QK_BOOT,   _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,     QK_BOOT 
    ),

    /* Adjust (Lower + Raise)
    *                                                                              ╱⎺⎺⎺⎺╲
    *                                                                             | MUTE |
    *                       v-----------------------RGB CONTROL------------------v ╲⎽⎽⎽⎽╱ 
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------| 
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      | Mute |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_CURSOR] = LAYOUT_ortho_4x12 (
                                                                                                           KC_MUTE,
  KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC, \
  KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO, \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
  KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO  , KC_TRNS,  KC_TRNS, KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]   =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [_LOWER]   =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    [_CURSOR]  =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) }
};
#endif
