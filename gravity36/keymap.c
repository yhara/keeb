// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "os_detection.h"
os_variant_t current_platform;

#include "keymap_japanese.h"

enum layer_names {
    _BASE, // Default Layer
    _FN, // Fn Layer 1
    _FN2, // Fn Layer 2
    _FN3, // Fn Layer 3
    _CHGAPP,
    _BOOT,
};

enum custom_keycode {
    CHGAPP = QK_KB_0,
    PRVAPP,
    NXTAPP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
 LT(_BOOT,KC_Q),  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, LT(_BOOT,KC_P),
 LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_SCLN),
 LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_MINS),
        LALT_T(KC_SPC), LT(1,KC_LNG2), CHGAPP,   KC_NO, LT(3, KC_SPC), LT(2,KC_LNG1)
    ),
    
    [1] = LAYOUT(
      KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR,   
      S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, 
      PRVAPP  , NXTAPP  , KC_NO ,  KC_SLSH,   KC_NO, JP_DQUO, JP_PLUS, JP_QUES, JP_RCBR, JP_UNDS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    [2] = LAYOUT(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     
        KC_F11,  KC_F12,  KC_NO,   KC_SLSH, KC_NO,   JP_COLN, JP_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    [3] = LAYOUT(
      KC_ESC  ,KC_TAB   ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC  ,
      KC_HOME, S(KC_TAB),KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT  ,
  C(S(KC_TAB)),C(KC_TAB),KC_NO  ,S(KC_INS)  , KC_PGUP,  KC_NO  , KC_ENT  , KC_NO  , KC_NO  , KC_NO, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
        
    [_CHGAPP] = LAYOUT(
      NXTAPP  ,KC_NO  ,KC_NO, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
      PRVAPP , KC_NO  ,KC_NO, KC_NO, KC_NO  ,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO  ,
      KC_NO,   KC_NO  ,KC_NO  , KC_NO  , KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	
    [_BOOT] = LAYOUT(
      KC_TRNS  ,KC_NO  ,KC_NO, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS  ,
      KC_NO , KC_NO  ,KC_NO, KC_NO, KC_NO  ,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO  ,
      KC_NO,   KC_NO  ,KC_NO  , KC_NO  , KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO, 
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CHGAPP:
            if (record->event.pressed) {
                (current_platform == OS_MACOS) ? register_mods(MOD_LGUI) : register_mods(MOD_LALT);
                layer_move(_CHGAPP);
            } else {
                (current_platform == OS_MACOS) ? unregister_mods(MOD_LGUI) : unregister_mods(MOD_LALT);
                layer_move(_BASE);
            }
            break;
        case PRVAPP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;
        case NXTAPP:
            if (record->event.pressed) {
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
};
