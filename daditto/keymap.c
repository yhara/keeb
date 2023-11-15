// Copyright 2021 ◤◢◤◢◤◢◤◢ (@yynmt)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
  #include "audio.h"
  float my_song[][2] = SONG(E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7));
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                                                                            KC_1, KC_2,
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, CK_TOGG,
        KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_NO,
        KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, MO(_FN), MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT(
                                                                            KC_3, KC_4,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
    )
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
