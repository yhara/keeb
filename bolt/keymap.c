#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
               KC_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
         CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        LSFT_T(KC_TAB),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_MPLY,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
               KC_BSPC,  KC_LALT,          KC_LGUI, LT(2,KC_LANG2),        LT(3,KC_SPC),LT(1,KC_LANG1),            KC_LEFT, KC_DOWN, KC_RGHT
             ),
    [1] = LAYOUT(
               _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9  , KC_F10 , _______,
               _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
               _______,  KC_F11,  KC_F12,  KC_NO,   KC_NO ,  KC_NO ,           _______, JP_COLN, JP_PLUS, _______, _______, _______, _______,
               _______,  _______,                   _______, _______,          _______, _______,                   KC_NO,   KC_NO,   RESET
             ),
    [2] = LAYOUT(
                ALT_TAB, KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                 JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
                KC_NO  , JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                  JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
                _______, KC_NO  , KC_NO  , KC_SLSH, S(KC_INS), KC_SLSH,     KC_NO,    JP_DQUO ,JP_PLUS, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
                RESET  , KC_NO  ,                   KC_TRNS, KC_NO  ,       KC_SPC,   KC_TRNS,                   KC_NO  , KC_NO  , KC_NO
             ),
    [3] = LAYOUT(
                _______,_______,_______,KC_END, _______, _______,                     RGB_TOG,RGB_M_SN, RGB_M_P, _______, KC_NUM , KC_BSPC, \
                _______,KC_HOME,_______,KC_DEL, KC_PGDN, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
                _______,_______,_______,_______,_______, KC_PGUP,           KC_NO,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
                _______,_______,                _______, _______,           KC_SPC,   _______,                   _______, _______, _______
             ),
};

//
// Alt-Tab for Windows
//
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case ALT_TAB:
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
        return false;
    }
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
