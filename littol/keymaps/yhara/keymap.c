/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
	       KC_Q,         KC_W,          KC_E,          KC_R,       KC_T,           KC_Y,          KC_U,       KC_I,         KC_O,         KC_P,
	       KC_A,         LCTL_T(KC_S),  LALT_T(KC_D),  KC_F,       KC_G,           KC_H,          KC_J,       RALT_T(KC_K), RCTL_T(KC_L), LT(3, KC_QUOT),
	       LSFT_T(KC_Z), KC_X,          KC_C,          KC_V,       LT(1, KC_BSPC), LT(2, KC_SPC), KC_B,       KC_N,         KC_M,         RSFT_T(KC_DOT) 
	),

  [1] = LAYOUT(
	       KC_1,         KC_2,          KC_3,          KC_4,       KC_5,           KC_6,          KC_7,       KC_8,         KC_9,         KC_0,
	       KC_GRV,       KC_MINS,       KC_EQL,        KC_TRNS,    KC_TRNS,        KC_LEFT,       KC_DOWN,    KC_UP,        KC_RGHT,      KC_SCLN,
	       KC_TRNS,      KC_LBRC,       KC_RBRC,       KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,    KC_TRNS,      KC_TRNS,      RSFT_T(KC_COMM)
	),

    
  [2] = LAYOUT(
	       LSFT(KC_1),   LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4), LSFT(KC_5),     LSFT(KC_6),    LSFT(KC_7), LSFT(KC_8),   LSFT(KC_9),   LSFT(KC_0),
	       LSFT(KC_GRV), LSFT(KC_MINS), LSFT(KC_EQL),  KC_TRNS,    KC_TRNS,        KC_HOME,       KC_PGDN,    KC_PGUP,      KC_END,       KC_BSLS,
	       KC_TRNS,      LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,    KC_TRNS,      KC_TRNS,      RSFT_T(KC_SLSH)
	),

    
  [3] = LAYOUT(
	       KC_F1,        KC_F2,         KC_F3,         KC_F4,      KC_F5,          KC_F6,         KC_F7,      KC_F8,        KC_F9,        KC_F10,
	       KC_F11,       KC_F12,        KC_F13,        KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_PSCR,    KC_SCRL,      KC_PAUS,      KC_TRNS,
	       QK_BOOT,      KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_DEL,         KC_TRNS,       KC_INS,     KC_CAPS,      KC_TRNS,      KC_TRNS
	),
};

enum combos {
  WE_ESC,
  SD_TAB,
  XC_LGUI,
  IO_BSPC,
  KL_ENT,
  NM_DEL,
  COMBO_LENGTH
};

//uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};

combo_t key_combos[] = {
  [WE_ESC] = COMBO(we_combo, KC_ESC),
  [SD_TAB] = COMBO(sd_combo, KC_TAB),
  [XC_LGUI] = COMBO(xc_combo, KC_LGUI),
  [IO_BSPC] = COMBO(io_combo, KC_BSPC),
  [KL_ENT] = COMBO(kl_combo, KC_ENT),
  [NM_DEL] = COMBO(nm_combo, KC_DEL)
};
