/*
Copyright 2022 aki27

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
#include <stdio.h>
#include "quantum.h"
#include "keymap_japanese.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _CURSOR = 3,
    _TRACKBALL = 4
};


#define EISU_L LT(1, KC_LANG2)  // lower
#define KANA_R LT(2, KC_LANG1)  // raise
#define CUR_SPC LT(3, KC_SPC)    // cursor
#define SPC_ALT ALT_T(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
CTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LT(_TRACKBALL,KC_ENT),
LSFT_T(KC_TAB),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
                        KC_LALT, KC_LGUI,   EISU_L,  SPC_ALT, KC_MS_BTN1,             KC_MS_BTN2,    SCRL_MO, CUR_SPC, KANA_R,  KC_1,
                                                                 KC_MS_WH_UP, KC_MPLY,  KC_MS_WH_DOWN, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_LOWER] = LAYOUT(
      _______, KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                                       JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
      KC_NO  , JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                                        JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
      RESET  , KC_NO  , KC_NO  , KC_SLSH, S(KC_INS), KC_SLSH,                                     JP_DQUO ,JP_PLUS, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
                        _______, _______, _______,  _______,  KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                 RGB_HUI, KC_MS_BTN3,  RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_RAISE] = LAYOUT(
      _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______,  KC_F11,  KC_F12,  KC_NO,   KC_NO ,  KC_NO ,                                       JP_COLN, JP_PLUS, _______, _______, _______, _______,
                        _______, _______, _______,  _______,  KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_CURSOR] = LAYOUT(
      _______,_______,_______,KC_END, _______, _______,                                           RGB_TOG,RGB_M_SN, _______, _______, _______, KC_BSPC,
      _______,KC_HOME,_______,KC_DEL, KC_PGDN, _______,                                           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
      _______,_______,_______,_______,_______, KC_PGUP,                                           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,
                        _______, _______, _______,  _______,  KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [_TRACKBALL] = LAYOUT(
      XXXXXXX, RESET  , XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        _______, _______, _______,  _______,  KC_MS_BTN4,             KC_MS_BTN5, _______, _______, _______, _______,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}


/*
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int8_t degree = 45;
    int8_t x_rev, y_rev;
    x_rev =  + mouse_report.x * cos(degree) + mouse_report.y * sin(degree);
    y_rev =  - mouse_report.x * sin(degree) + mouse_report.y * cos(degree);
    if (isScrollMode) {
        mouse_report.h = x_rev;
        #ifdef COCOT_DRAGSCROLL_INVERT
                // Invert vertical scroll direction
                mouse_report.v = -y_rev;
        #else
                mouse_report.v = y_rev;
        #endif
        // mouse_report.v = y_rev;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }
    return mouse_report;
}
*/

int hue_fst = -1;
int sat_fst = -1;
int val_fst = -1;


layer_state_t layer_state_set_user(layer_state_t state) {
    hue_fst = rgblight_get_hue();
    sat_fst = rgblight_get_sat();
    val_fst = rgblight_get_val();

    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        // rgblight_sethsv_range( 0, 0, 0, 0, 2);
        rgblight_sethsv_range(hue_fst, sat_fst, val_fst, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
  return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

