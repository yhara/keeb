#include QMK_KEYBOARD_H
#include "keymap_japanese.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _CURSOR,
    _MEDIA,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  KANA,
  EISU,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F ,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_MEDIA,KC_ENT), \
      LSFT_T(KC_TAB),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
      KC_BSPC,KC_DEL,KC_LALT,KC_LGUI,LT(_LOWER,KC_LNG2),ALT_T(KC_SPC), LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LNG1),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT
      ),
  [_LOWER] = LAYOUT_ortho_4x12(
      KC_NO  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
      KC_NO  , S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
      KC_NO  , KC_NO  , KC_NO  , KC_SLSH , S(KC_INS), KC_SLSH,  JP_DQUO , JP_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),JP_UNDS,
      QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
  [_RAISE] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_TRNS, \
      KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   QK_BOOT
      ),
  [_CURSOR] =  LAYOUT_ortho_4x12(
      KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC, \
      KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO, \
      KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),
  [_MEDIA] =  LAYOUT_ortho_4x12(
      _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_M_B, RGB_M_SW,  _______,_______, _______, _______, _______, _______,   
      _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R, RGB_M_SN,  _______,_______, _______, _______, _______, _______,   
      _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, RGB_M_K,   _______,_______, _______, _______, _______, _______,   
      _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
      ),
};

// https://github.com/monksoffunk/qmk_firmware/blob/zinc_RGB_matrix/keyboards/zinc/rev1/rev1.c
#ifdef RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_SPLIT_RIGHT
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 24, 25, 26, 27, 28, 29 },
  { 35, 34, 33, 32, 31, 30 },
  { 36, 37, 38, 39, 40, 41 },
  { 47, 46, 45, 44, 43, 42 },
  {  0,  1,  2,  3,  4,  5 },
  { 11, 10,  9,  8,  7,  6 },
  { 12, 13, 14, 15, 16, 17 },
  { 23, 22, 21, 20, 19, 18 }
}, {
  // LED Index to Physical Position
{ 114,   0 }, { 133,   0 }, { 153,   0 }, { 172,   0 }, { 191,   0 }, { 210,   0 },
{ 214,  21 }, { 195,  21 }, { 176,  21 }, { 157,  21 }, { 138,  21 }, { 119,  21 },
{ 124,  43 }, { 143,  43 }, { 162,  43 }, { 181,  43 }, { 200,  43 }, { 219,  43 },
{ 224,  64 }, { 205,  64 }, { 186,  64 }, { 167,  64 }, { 148,  64 }, { 129,  64 },
{   0,   0 }, {  19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,   0 },
{ 100,  21 }, {  81,  21 }, {  62,  21 }, {  43,  21 }, {  24,  21 }, {   5,  21 },
{  10,  43 }, {  29,  43 }, {  48,  43 }, {  67,  43 }, {  86,  43 }, { 105,  43 },
{ 110,  64 }, {  91,  64 }, {  71,  64 }, {  52,  64 }, {  33,  64 }, {  14,  64 }
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 1,
  1, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 1,
  1, 1, 1, 1, 1, 1,
  1, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 1,
  1, 4, 4, 4, 4, 4,
  1, 1, 1, 1, 1, 1
} };
#else
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {  0,  1,  2,  3,  4,  5 },
  { 11, 10,  9,  8,  7,  6 },
  { 12, 13, 14, 15, 16, 17 },
  { 23, 22, 21, 20, 19, 18 },
  { 24, 25, 26, 27, 28, 29 },
  { 35, 34, 33, 32, 31, 30 },
  { 36, 37, 38, 39, 40, 41 },
  { 47, 46, 45, 44, 43, 42 }
}, {
  // LED Index to Physical Position
{   0,   0 }, {  19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,   0 },
{ 100,  21 }, {  81,  21 }, {  62,  21 }, {  43,  21 }, {  24,  21 }, {   5,  21 },
{  10,  43 }, {  29,  43 }, {  48,  43 }, {  67,  43 }, {  86,  43 }, { 105,  43 },
{ 110,  64 }, {  91,  64 }, {  71,  64 }, {  52,  64 }, {  33,  64 }, {  14,  64 },
{ 114,   0 }, { 133,   0 }, { 153,   0 }, { 172,   0 }, { 191,   0 }, { 210,   0 },
{ 214,  21 }, { 195,  21 }, { 176,  21 }, { 157,  21 }, { 138,  21 }, { 119,  21 },
{ 124,  43 }, { 143,  43 }, { 162,  43 }, { 181,  43 }, { 200,  43 }, { 219,  43 },
{ 224,  64 }, { 205,  64 }, { 186,  64 }, { 167,  64 }, { 148,  64 }, { 129,  64 }
}, {
  // LED Index to Flag
  1, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 1,
  1, 4, 4, 4, 4, 4,
  1, 1, 1, 1, 1, 1,
  4, 4, 4, 4, 4, 1,
  1, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 1,
  1, 1, 1, 1, 1, 1,
} };
#endif
#endif
