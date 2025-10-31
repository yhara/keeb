/*
Copyright 2024 Nachie

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
#include "os_detection.h"
#include "keymap_japanese.h"

#ifdef OLED_ENABLE
void render_key_status_or_logo(void);
void render_current_layer(void);
void render_current_wpm(void);
#endif

os_variant_t current_platform;

enum layer_names {
    _BASE, // Default Layer
    _FN, // Fn Layer 1
    _FN2, // Fn Layer 2
    _FN3, // Fn Layer 3
    _CHGAPP
};

enum custom_keycode {
    JWRDL = QK_KB_0,
    JWRDR,
    SWRDL,
    SWRDR,
    TABL,
    TABR,
    DSKTPL,
    DSKTPR,
    CHGAPP,
    PRVAPP,
    NXTAPP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HOME:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LGUI);
                tap_code(KC_LEFT);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_HOME);
            }
            break;
        case KC_END:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LGUI);
                tap_code(KC_RIGHT);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_END);
            }
            break;
        case KC_PGUP:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LGUI);
                tap_code(KC_UP);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        case KC_PGDN:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LGUI);
                tap_code(KC_DOWN);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        case KC_NUM_LOCK:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LSFT);
                tap_code(KC_CLEAR);
                unregister_mods(MOD_LSFT);
            } else {
                tap_code(KC_NUM_LOCK);
            }
            break;
        case KC_SCROLL_LOCK:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LCTL);
                tap_code(KC_F14);
                unregister_mods(MOD_LCTL);
            } else {
                tap_code(KC_SCROLL_LOCK);
            }
            break;
        case KC_PRINT_SCREEN:
            if (record->event.pressed && current_platform == OS_MACOS) {
                register_mods(MOD_LSFT);
                register_mods(MOD_LGUI);
                tap_code(KC_5);
                unregister_mods(MOD_LGUI);
                unregister_mods(MOD_LSFT);
            } else {
                tap_code(KC_PRINT_SCREEN);
            }
            break;
        case JWRDL:
            if (record->event.pressed) {
                (current_platform == OS_MACOS) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_LEFT);
                (current_platform == OS_MACOS) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case JWRDR:
            if (record->event.pressed) {
                (current_platform == OS_MACOS) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_RIGHT);
                (current_platform == OS_MACOS) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case SWRDL:
            if (record->event.pressed) {
                register_mods(MOD_LSFT);
                (current_platform == OS_MACOS) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_LEFT);
                (current_platform == OS_MACOS) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
                unregister_mods(MOD_LSFT);
            } else {
            }
            break;
        case SWRDR:
            if (record->event.pressed) {
                register_mods(MOD_LSFT);
                (current_platform == OS_MACOS) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_RIGHT);
                (current_platform == OS_MACOS) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
                unregister_mods(MOD_LSFT);
            } else {
            }
            break;
        case TABL:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                register_mods(MOD_LSFT);
                tap_code(KC_TAB);
                unregister_mods(MOD_LSFT);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case TABR:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                tap_code(KC_TAB);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case DSKTPL:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                register_mods(MOD_LGUI);
                (current_platform == OS_LINUX) ? tap_code(KC_UP) : tap_code(KC_LEFT);
                unregister_mods(MOD_LGUI);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case DSKTPR:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                register_mods(MOD_LGUI);
                (current_platform == OS_LINUX) ? tap_code(KC_DOWN) : tap_code(KC_RGHT);
                unregister_mods(MOD_LGUI);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
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

#ifndef HAPTIC_ENABLE
    #define HF_TOGG _______
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY */
	[_BASE] = LAYOUT(
		KC_ESC,                                        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
		KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
 LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_SCLN),
 LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_MINS),
		KC_LCTL, KC_LALT, CHGAPP, LT(1,KC_LNG2),   LT(3, KC_SPC),  LT(2,KC_LNG1), KC_RGUI, KC_SLSH),

	[_FN] = LAYOUT(
		KC_ESC,                                        KC_1, KC_2, KC_3, KC_4,
      KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR,   _______,
      S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, 
      PRVAPP  , NXTAPP  , KC_NO ,  KC_SLSH, KC_NO,  JP_DQUO, JP_PLUS, JP_QUES, JP_RCBR, JP_UNDS,
		_______, _______, _______, _______, _______, _______, _______, JP_QUES),

	[_FN2] = LAYOUT(
		KC_ESC,                                        QK_BOOTLOADER, QK_REBOOT, QK_DEBUG_TOGGLE, QK_CLEAR_EEPROM,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   _______,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     
        KC_F11,  KC_F12,  KC_NO,   KC_SLSH,   KC_NO,   JP_COLN,   JP_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, 
		_______, _______, _______, _______, _______, _______, _______, _______),

	[_FN3] = LAYOUT(
		KC_ESC,                                        KC_1, KC_2, KC_3, KC_NUM,
      KC_ESC  ,KC_TAB   ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC  ,  KC_BSPC,
      KC_HOME, S(KC_TAB),KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_ENT  ,
  C(S(KC_TAB)),C(KC_TAB),KC_NO  ,S(KC_INS)  , KC_PGUP,  KC_NO  , KC_ENT  , KC_NO  , KC_NO  , KC_NO, 
		_______, _______, _______, _______, _______, _______, _______, _______),
        
	[_CHGAPP] = LAYOUT(
	  KC_NO,                                        DT_PRNT, DT_DOWN, DT_UP, RGB_TOG,
      NXTAPP  ,KC_NO  ,KC_NO, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  _______,
      PRVAPP , KC_NO  ,KC_NO, KC_NO, KC_NO  ,  KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO  ,
      PRVAPP,   KC_NO  ,KC_NO  , KC_NO  , KC_NO,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO, 
		_______, _______, _______, _______, _______, _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
        [_FN]   =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
        [_FN2] 	=  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
        [_FN3]  =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
        [_CHGAPP]  =  { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) },
    };
#endif

#ifdef OLED_ENABLE
    #ifdef DYNAMIC_MACRO_ENABLE
        bool macro1;
        bool macro1rec;
        bool macro2;
        bool macro2rec;
        bool prevEnabled;
        uint8_t prevRGBmode;

        void render_dynamic_macro_status(int col, int line){
            oled_set_cursor(col,line);
            macro1rec ? oled_write(PSTR("DM1"), macro1) : oled_write(PSTR("      "),false);
            oled_set_cursor(col,line+1);
            macro2rec ? oled_write(PSTR("DM2"), macro2) : oled_write(PSTR("      "),false);
        }

        //direction indicates which macro it is, with 1 being Macro 1, -1 being Macro 2, and 0 being no macro.
        bool dynamic_macro_record_start_user(int8_t direction){
            prevEnabled = rgb_matrix_is_enabled();
            if (!prevEnabled) { rgb_matrix_enable(); }
            prevRGBmode = rgb_matrix_get_mode();
            rgb_matrix_mode(RGB_MATRIX_BREATHING);
            switch(direction){
                case 1:
                    macro1 = false;
                    macro1rec = true;
                    break;
                case -1:
                    macro2 = false;
                    macro2rec = true;
                    break;
                default:
                    macro1 = false;
                    macro2 = false;
                    macro1rec = false;
                    macro2rec = false;
                    break;
            }
            return true;
        }

        bool dynamic_macro_record_end_user(int8_t direction){
            prevEnabled ? rgb_matrix_mode(prevRGBmode) : rgb_matrix_disable();
            switch(direction){
                case 1:
                    macro1 = true;
                    break;
                case -1:
                    macro2 = true;
                    break;
                default:
                    macro1 = false;
                    macro2 = false;
                    break;
            }
            return true;
        }
    #endif

    // OLED setup for bongocat
    #define IDLE_FRAMES 5
    #define IDLE_SPEED 30
    #define TAP_FRAMES 2
    #define TAP_SPEED 40
    #define ANIM_FRAME_DURATION 200
    #define ANIM_SIZE 512

    static long int oled_timeout = 600000; // 10 minutes
    bool gui_on = true;
    char wpm_str[10];
    uint32_t anim_timer = 0;
    uint32_t anim_sleep = 0;
    uint8_t current_idle_frame = 0;
    uint8_t current_tap_frame = 0;

    bool rerender_platform = false;

    /* static void render_logo(void) {
        static const char PROGMEM logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
        };

        oled_write(logo, false);
    } */

    static void render_anim(void) {
        // Idle animation
        static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 16, 8,  8,  4,  4, 4, 8, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 100, 130, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 56, 4, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1,   1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 16, 8,  8,  4,  4, 4, 8, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 100, 130, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 56, 4, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1,   1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 64, 64, 64, 64, 32, 32,  32, 32, 16, 8,  4,  2,  2,  4, 24, 96, 128, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 194, 1, 1, 2, 2, 4, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96, 96, 0, 129, 130, 130, 132, 8, 16, 32, 64, 128, 0, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 25, 6, 0, 0, 0, 0, 0, 0, 0, 24,  24,  24, 27, 3,  0,  64, 160, 34, 36, 20, 18, 18, 18, 11, 8, 8,  8,  8,   5, 5, 9, 9, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8, 8, 8, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0,   0,   0,   0,   0, 0,  0,  0,  0,   0, 0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  8,  4,  2,  2, 2, 4, 56, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 226, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        };

        // Prep animation
        static const char PROGMEM prep[][ANIM_SIZE] = {

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0,  0, 0, 0,   128, 64,  64,  32,  32, 32, 32, 16, 16, 16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 129, 128, 128, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 24, 6, 5, 152, 153, 132, 195, 124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 4, 4, 4, 4, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 0,   0,   0,   0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0,   0,  0, 0, 0,  0,  0, 0,   0,   0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        };

        // Typing animation
        static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0,  0, 0, 0,   128, 64,  64, 32,  32, 32, 32, 16, 16, 16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  248, 248, 248, 248, 0,  0,   0,   0,   0,   128, 128, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 129, 128, 128, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 1, 2, 4, 8, 16, 32, 67, 135, 7, 1, 0, 184, 188, 190, 159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 24, 6, 5, 152, 153, 132, 67, 124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16,  17,  15,  1,   61, 124, 252, 252, 252, 252, 252, 60, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 0,   0,   0,   0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   1,   3,   3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,  225, 0,   0,   1,   1,   2,  2,  1, 0, 0, 0, 0, 128, 128, 0,   0,   0,   0,   0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 0, 0, 0, 0, 0,   0,  0,  0,  1,  1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 4, 4, 4, 4, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 122, 122, 121, 121, 121, 121, 57, 49, 2, 2, 4, 4, 8, 8,   8,   136, 136, 135, 128, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0,   0,  0, 0, 0,  0,  0, 0,   0,   0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

        };

        void animation_phase(void) {
            if (get_current_wpm() <= IDLE_SPEED) {
                current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
                oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
            }

            if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
                oled_write_raw_P(prep[0], ANIM_SIZE);
            }

            if (get_current_wpm() >= TAP_SPEED) {
                current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
                oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
            }
        }

        if (get_current_wpm() != 000) {
            oled_on();

            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }

            anim_sleep = timer_read32();
        } else {
            if (timer_elapsed32(anim_sleep) > oled_timeout) {
                oled_off();
            } else {
                if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                    anim_timer = timer_read32();
                    animation_phase();
                }
            }
        }
    }

    void render_keylock_status(led_t led_state) {
        bool caps_state = (led_state.caps_lock || is_caps_word_on());
        oled_write(PSTR("CAPS"), caps_state);
        oled_write(PSTR(" "), false);
        oled_write(PSTR("NUM"), led_state.num_lock);
        oled_write(PSTR(" "), false);
        oled_write(PSTR("SCRL"), led_state.scroll_lock);
        //oled_write_ln_P(PSTR(" "), false);
    }

    void render_mod_status(uint8_t modifiers) {
        oled_write(PSTR("SH"), (modifiers & MOD_MASK_SHIFT));
        oled_write(PSTR(" "), false);
        (current_platform == OS_MACOS || current_platform == OS_IOS)  ? oled_write(PSTR("CMD"), (modifiers & MOD_MASK_GUI)) : oled_write(PSTR("CT"), (modifiers & MOD_MASK_CTRL));
        oled_write(PSTR(" "), false);
        (current_platform == OS_MACOS || current_platform == OS_IOS) ? oled_write(PSTR("OPT"), (modifiers & MOD_MASK_ALT)) : oled_write(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
        oled_write(PSTR(" "), false);
        (current_platform == OS_MACOS || current_platform == OS_IOS) ? oled_write(PSTR("CT"), (modifiers & MOD_MASK_CTRL)) : oled_write(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
    }

    void render_key_status_or_logo(){
        led_t led_state = host_keyboard_led_state();
        uint8_t mod_state = (get_mods()|get_oneshot_mods());
        if ( //!led_state.num_lock &&   // This always returns true on my environment (why?)
            !led_state.caps_lock && !led_state.scroll_lock
        && !(mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_ALT) && !(mod_state & MOD_MASK_CTRL) && !(mod_state & MOD_MASK_GUI)) {
            render_anim();
            rerender_platform = false;
        } else {
            oled_clear();
            oled_render();
            oled_set_cursor(0,0);
            render_keylock_status(led_state);
            oled_set_cursor(0,1);
            render_mod_status(mod_state);
            rerender_platform = true;
        }

    }

    void render_current_layer(){
        switch (get_highest_layer(layer_state)) {
                case 0:
                    oled_write(PSTR("BASE"), false);
                    break;
                case 1:
                    oled_write(PSTR("SYM"), false);
                    break;
                case 2:
                    oled_write(PSTR("NUM"), false);
                    break;
                case 3:
                    oled_write(PSTR("CUR"), false);
                    break;
                case 4:
                    oled_write(PSTR("APP"), false);
                    break;
                default:
                    oled_write(PSTR("L?"), false);    // Should never display, here as a catchall
        }
    }

    void render_current_wpm(){
        oled_write_P(PSTR("WPM "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
    }

    void render_platform_status(int col, int line) {
        /* Show Ctrl-Gui Swap options */
        static const char PROGMEM logo[][5][3] = {
            {{0x9B, 0x9C, 0}, {0xbb, 0xbc, 0}}, //Android
            {{0x99, 0x9A, 0}, {0xb9, 0xba, 0}}, //Linux
            {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}, //Windows
            {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, //Mac/iOS
            {{0x9D, 0x9E, 0}, {0xbd, 0xbe, 0}}, //Empty Placeholder
        };
        current_platform = detected_host_os();
        switch (current_platform) {
            /*case OS_ANDROID: //Android
                oled_set_cursor(col,line);
                oled_write(logo[0][0], false);
                oled_set_cursor(col,line+1);
                oled_write(logo[0][1], false);
                break;*/
            case OS_LINUX: //Linux
                oled_set_cursor(col,line);
                oled_write(logo[1][0], true);
                oled_set_cursor(col,line+1);
                oled_write(logo[1][1], true);
                keymap_config.swap_lctl_lgui = false;
                keymap_config.swap_rctl_rgui = false;
                break;
            case OS_WINDOWS: //Windows
                oled_set_cursor(col,line);
                oled_write(logo[2][0], false);
                oled_set_cursor(col,line+1);
                oled_write(logo[2][1], false);
                keymap_config.swap_lctl_lgui = false;
                keymap_config.swap_rctl_rgui = false;
                break;
            case OS_MACOS: //Mac
                oled_set_cursor(col,line);
                oled_write(logo[3][0], true);
                oled_set_cursor(col,line+1);
                oled_write(logo[3][1], true);
                keymap_config.swap_lctl_lgui = true;
                keymap_config.swap_rctl_rgui = true;
                break;
            case OS_IOS: //iOS
                oled_set_cursor(col,line);
                oled_write(logo[3][0], false);
                oled_set_cursor(col,line+1);
                oled_write(logo[3][1], false);
                keymap_config.swap_lctl_lgui = true;
                keymap_config.swap_rctl_rgui = true;
                break;
            default: //OS_UNSURE or not configured
                oled_set_cursor(col,line);
                oled_write(logo[4][0], false);
                oled_set_cursor(col,line+1);
                oled_write(logo[4][1], false);
                break;
        }
        rerender_platform = false;
    }

    bool oled_task_user(void) {
        render_key_status_or_logo();
        oled_set_cursor(0,2);
        render_current_wpm();

        #ifdef DYNAMIC_MACRO_ENABLE
         //   render_dynamic_macro_status(18,2);
        #endif
        oled_set_cursor(0,3);
        render_current_layer();

        return false;
    }

#endif

