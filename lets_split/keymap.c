#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"
#include "sendstring_jis.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _CURSOR 1
#define _MEDIA 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          SEND_STRING(SS_LCTRL("z")"[");
          break;
      }
    return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/Esc|  A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter/MDIA|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift/_|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Alt  |  Alt | Cmd  |Eisu/L|Sp/CUR|Sp/CUR|Kana/R| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_MEDIA, KC_ENT), \
  LSFT_T(JP_UNDS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
  LT(_ADJUST,KC_LEFT),ALT_T(KC_DOWN),ALT_T(KC_UP),GUI_T(KC_RIGHT),LT(_LOWER,KC_LANG2),LT(_CURSOR,KC_SPC), LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LANG1),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT \
),

/* CURSOR
 * ,-----------------------------------------.    ,------------------------------------------.
 * |      |      |      | End  |      |      |    |      |      |      |      | ^z[  | BkSp  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      | Home |      | Del  |PgDn  |      |    | Left | Down | Up   | Right|      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      | PgUp |    |      |      | ^z[  |      |      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      |CURSOR|    |CURSOR|      |      |      |      |       |
 * `------+------+------+------+------+------'    `------+------+------+------+------+-------'
 */
[_CURSOR] = LAYOUT( \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , M(0)  , KC_BSPC, \
  KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO, \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_NO  , KC_NO  , M(0)   , KC_NO  , KC_NO  , KC_NO,  \
  KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO  , KC_TRNS,  KC_TRNS, KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
),

/* MEDIA
 * ,-----------------------------------------.    ,------------------------------------------.
 * |      |      |      | MsUp |      |      |    |      |      |      |      | Play |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |MsLeft|MsDown|MsRght|      |    | Prev |VolDn |VolUp | Next |      | MEDIA |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |    |      |VolDn_|VolUp_| Mute |      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |       |
 * `------+------+------+------+------+------'    `------+------+------+------+------+-------'
 */
[_MEDIA] = LAYOUT( \
  KC_NO  , KC_NO  , KC_NO  , KC_MS_U, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY, KC_NO, \
  KC_NO  , KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, KC_NO  ,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO  , KC_TRNS  , \
  KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , S(LALT(KC_VOLD)), S(LALT(KC_VOLU)), KC_MUTE, KC_NO  , KC_NO,  \
  KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO 
),

/* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |   !  |  @   |   #  |  $   |  %   |     |  ^   |  &   |  (   |   )  |  *   |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |   ~  |  |   |   =  |  \   |  `   |     |  '   |  {   |  [   |   ]  |  :   |   }  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  "   |  +   |  <   |   >  |  ?   |   _  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |RESET |      |      |      |LOWER |      |     |Space |      |  {   |   }  |      |      |
 * `------+------+------+------+------+------'     `------+------+------+------+------+------'
 */
[_LOWER] = LAYOUT( \
  KC_NO  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
  KC_NO  , S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  JP_DQT , JP_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),JP_UNDS,
  RESET  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  ,  KC_TRNS, KC_NO  , JP_LCBR, JP_RCBR, KC_NO  , KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BS   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   :  |   ,  |   .  |   /  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,     KC_NO \
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};
