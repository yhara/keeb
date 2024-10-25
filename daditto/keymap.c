// Copyright 2021 ◤◢◤◢◤◢◤◢ (@yynmt)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "keymap_japanese.h"

#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
  #include "audio.h"
  float my_song[][2] = SONG(E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7));
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _CURSOR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                                                                                                                             KC_1, KC_2,
      KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,            KC_NO,
      CTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F ,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, KC_NO,
      LSFT_T(KC_TAB),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,          KC_NO,
      KC_BSPC,KC_DEL,KC_LALT,LT(_LOWER,KC_LNG2),LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LNG1),        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT
    ), 
  [_LOWER] = LAYOUT(
                                                                                                                    CK_DOWN, CK_UP,
      KC_NO  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,          CK_ON,
      KC_NO  , S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,          KC_NO,
      KC_NO  , KC_NO  , KC_NO  , KC_SLSH , S(KC_INS), KC_SLSH,  JP_DQUO , JP_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),JP_UNDS, KC_NO,
      QK_BOOT  , KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
      ),
  [_RAISE] = LAYOUT(
                                                                                                                    KC_NO, KC_NO,
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_TRNS,         KC_NO,
      KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS,         KC_NO,
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,         KC_NO,
      _______, _______, _______,   _______,  _______,     _______,    _______, _______, _______, QK_BOOT 
      ),
  [_CURSOR] = LAYOUT(
                                                                                                                    KC_3, KC_4,
      KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC,          KC_NO,
      KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO,            KC_NO,
      KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,         KC_NO,
      _______, _______, _______,   _______,  _______,     _______,    _______, _______, _______,
      ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        keypos_t key;
        if (clockwise) {
            key.row = 3;
            key.col = 5;
        } else {
            key.row = 3;
            key.col = 4;
        }
        uint8_t  layer   = layer_switch_get_layer(key);
        uint16_t keycode = keymap_key_to_keycode(layer, key);
        tap_code16(keycode);
#ifdef AUDIO_ENABLE
        PLAY_SONG(my_song);
#endif
    }
    return false;
}

#ifdef AUDIO_ENABLE
void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}
#endif

void keyboard_post_init_user(void) {
#ifdef AUDIO_ENABLE
    audio_on();
#endif
}
