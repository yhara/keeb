/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

enum combos {
  PQ_SP,
  WE_ESC,
  WR_TAB,
  UI_BSPC,
  UO_ENT,
  //EI_KANA,
  //WO_EISU,
  OP_KAN,
};
const uint16_t PROGMEM pq_combo[] = {KC_P, KC_Q, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};
//const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
//const uint16_t PROGMEM wo_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
combo_t key_combos[] = {
  [PQ_SP] = COMBO(pq_combo, MO(5)),
  [WE_ESC] = COMBO(we_combo, KC_ESC),
  [WR_TAB] = COMBO(wr_combo, KC_TAB),
  [UI_BSPC] = COMBO(ui_combo, KC_BSPC),
  [UO_ENT] = COMBO(uo_combo, KC_ENT),
  //[EI_KANA] = COMBO(ei_combo, KC_LNG1),
  //[WO_EISU] = COMBO(wo_combo, KC_LNG2),
  [OP_KAN] = COMBO(op_combo, JP_ZKHK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
	       KC_Q,         KC_W,          KC_E,          KC_R,       KC_T,           KC_Y,          KC_U,       KC_I,         KC_O,         KC_P,
	       LCTL_T(KC_A), LT(2,KC_S),  LT(1,KC_D),  LT(4,KC_F),     LT(6,KC_G),           KC_H,          KC_J,       LT(1,KC_K), LT(2,KC_L),     RCTL_T(KC_SCLN),
	       LSFT_T(KC_Z), KC_X,          KC_C,       LALT_T(KC_V),  KC_NO,LT(3,KC_SPC),            RALT_T(KC_B),KC_N,         KC_M,        RSFT_T(KC_SLSH) 
	),

  // Symbols
  [1] = LAYOUT(
               KC_EXLM,      JP_AT  ,       KC_HASH,       KC_DLR ,    KC_PERC,        JP_CIRC,       JP_AMPR,    KC_MINS,      JP_UNDS,      JP_ASTR,
	       JP_TILD,      JP_PIPE,       JP_EQL,        JP_YEN,     JP_GRV,         JP_QUOT,       JP_DQUO,    KC_NO,        KC_NO,      JP_COLN,
	       _______,      _______,       _______,       _______,    KC_NO,_______,                 JP_PLUS,    KC_COMM,      KC_DOT,       JP_QUES
	),

    
  // Numbers
  [2] = LAYOUT(
	       KC_F1,        KC_F2,         KC_F3,         KC_F4,      KC_F5,          KC_F6,         KC_F7,      KC_F8,        KC_F9,        KC_F10,
	       KC_1,         KC_2,          KC_3,          KC_4,       KC_5,           KC_6,          KC_7,       KC_8,         KC_9,         KC_0,
	       KC_MINS,      _______,       _______,       JP_COLN,    KC_NO,_______,                 JP_PLUS,    KC_COMM,      KC_DOT,       KC_SLSH
	),

  // Cursor
  [3] = LAYOUT(
	       KC_ESC,       KC_TAB ,       KC_END,        _______,    _______,        _______,       _______,    KC_TAB,      _______,      KC_BSPC,
	       KC_HOME,      _______,       KC_DEL,        KC_PGDN,    _______,        KC_LEFT,       KC_DOWN,    KC_UP,        KC_RGHT,      _______,
	       _______,      _______,       _______,       _______,    KC_NO,KC_TRNS,                KC_PGUP,    _______,      KC_ENT ,      _______
	),

  // Parens
  [4] = LAYOUT(
	       _______,      _______,       _______,       _______,    _______,        _______,       _______,    JP_LPRN,      JP_RPRN,      _______,
	       _______,      _______,       _______,       KC_TRNS,    _______,        _______,       JP_LCBR,    JP_LBRC,      JP_RBRC,      JP_RCBR,
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
	       KC_MINS,      KC_COMM,       KC_DOT,        JP_PLUS,    _______,_______,               KC_1,    KC_2,      KC_3,      KC_SLSH
	),	
	
};

