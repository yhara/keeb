/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

enum combos {
  CB_STAB,
  CB_TAB,
};
const uint16_t PROGMEM stab_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_W, KC_R, COMBO_END};
combo_t key_combos[] = {
  [CB_STAB] = COMBO(stab_combo, S(KC_TAB)),
  [CB_TAB] = COMBO(tab_combo, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
	       LT(2,KC_Q),   KC_W,          KC_E,          KC_R,       KC_T,                KC_Y,          KC_U,       KC_I,         KC_O,         LT(5,KC_P),
	       LCTL_T(KC_A), LT(1,KC_S),  LT(4,KC_D),     LT(6,KC_F),  KC_G,                KC_H,          KC_J,       KC_K,    LT(1,KC_L),     RCTL_T(KC_SCLN),
	       LSFT_T(KC_Z), KC_X,          KC_C,       LALT_T(KC_V),  KC_NO,LT(3,KC_SPC),            RALT_T(KC_B),    KC_N,         KC_M,        RSFT_T(KC_MINS) 
	),

  // Symbols
  [1] = LAYOUT(
           KC_EXLM,      JP_AT  ,       KC_HASH,       KC_DLR ,    KC_PERC,        JP_CIRC,       JP_AMPR,    JP_LPRN,      JP_RPRN,      JP_ASTR,
	       JP_TILD,      JP_PIPE,       JP_EQL,        JP_YEN,     JP_GRV,         JP_QUOT,       JP_DQUO,    JP_QUES,      KC_SLSH,      JP_COLN,
	       _______,      _______,       _______,       KC_SLSH,    KC_NO,_______,                 JP_PLUS,    KC_COMM,      KC_DOT,       JP_UNDS
	),

  // Fn
  [2] = LAYOUT(
	       _______,      _______,       _______,       _______,    _______,        KC_F12,         KC_F7,    KC_F8,      KC_F9,      KC_0,
	       _______,      _______,       _______,       _______,    KC_TRNS,        KC_F11,         KC_F4,    KC_F5,      KC_F6,      JP_COLN,
	       KC_MINS,      KC_COMM,       KC_DOT,        JP_PLUS,    _______,KC_F10   ,               KC_F1,    KC_F2,      KC_F3,      KC_SLSH
	),

  // Cursor
  [3] = LAYOUT(
	       KC_ESC,       KC_TAB ,       KC_END,        _______,    _______,        _______,       _______,    KC_LNG2,      KC_LNG1,      KC_BSPC,
	       KC_HOME,     S(KC_TAB),      KC_DEL,        KC_PGDN,    KC_PGUP,        KC_LEFT,       KC_DOWN,    KC_UP,        KC_RGHT,      KC_ENT,
	       _______,      _______,       _______,       S(KC_INS),    KC_NO,KC_TRNS,                KC_ENT,    _______,      KC_ENT ,      _______
	),

  // Paren
  [4] = LAYOUT(
	       _______,      _______,       _______,       _______,    _______,        _______,       _______,    JP_LPRN,      JP_RPRN,      _______,
	       _______,      _______,       KC_TRNS,       _______,    _______,        _______,       JP_LCBR,    JP_LBRC,      JP_RBRC,      JP_RCBR,
	       _______,      _______,       _______,       _______,    _______,_______,               _______,    S(KC_COMM),   S(KC_DOT),    _______
	),
	
  // Special
  [5] = LAYOUT(
	       KC_TRNS,      _______,       _______,       _______,    _______,        _______,       _______,    JP_LPRN,      JP_RPRN,      KC_TRNS,
	       _______,      _______,       _______,       _______,    _______,        _______,       _______,    _______,      _______,      _______,
	       QK_BOOT,      _______,       _______,       _______,    _______,_______,               _______,    _______,      _______,      _______
	),
	
  // Num2
  [6] = LAYOUT(
	       _______,      _______,       _______,       _______,    _______,        _______,       KC_7,    KC_8,      KC_9,      KC_0,
	       _______,      _______,       _______,       _______,    KC_TRNS,        KC_BSPC,       KC_4,    KC_5,      KC_6,      JP_COLN,
	       KC_MINS,      KC_COMM,       KC_DOT,        JP_PLUS,    _______,KC_0   ,               KC_1,    KC_2,      KC_3,      KC_SLSH
	),	
	
};

