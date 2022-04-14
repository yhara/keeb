#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define TG_NKRO MAGIC_TOGGLE_NKRO

// Layer names

enum layer_names {
    _QWERTY,
    _MEDIA,
    _PAREN,
    _LOWER,
    _RAISE,
    _CURSOR
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MEDIA,
  PAREN,
  LOWER,
  RAISE,
  CURSOR,
  MACRO1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp | Del  |  Alt |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F ,LT(_PAREN,KC_G),    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_MEDIA,KC_ENT), \
  LSFT_T(KC_TAB),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
  KC_BSPC,KC_DEL,KC_LALT,KC_LGUI,LT(_LOWER,KC_LANG2),ALT_T(KC_SPC), LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LANG1),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT \
),

/* Audio, RGB
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_ortho_4x12( \
  _______, AU_ON  , AU_OFF , _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_M_B, RGB_M_SW, _______, \
  _______, CK_ON  , CK_OFF , CK_UP  , CK_DOWN, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R, RGB_M_SN, KC_TRNS, \
  _______, MU_ON,   MU_OFF , MU_MOD , _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, RGB_M_K, _______, \
  _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, _______, _______, _______, _______, _______ \
),

/* Paren
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_PAREN] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, JP_LPRN, JP_RPRN, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,S(KC_COMM),S(KC_DOT),_______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   ~  |   |  |   =  |   \  |   `  |   '  |   {  |   [  |   ]  |   :  |  }   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |RESET |  F7  |  F8  |  F9  |  F10 |   /  |   "  |   +  |   <  |   >  |   ?  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNKRO|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_NO  , KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,  JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
  KC_NO  , S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN, JP_GRV,   JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
  KC_NO  , KC_NO  , KC_NO  , KC_SLSH , KC_SLSH, KC_SLSH,  JP_DQUO , JP_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),JP_UNDS,
  RESET  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  ,  KC_TRNS, KC_NO  , JP_LCBR, JP_RCBR, KC_NO  , KC_NO
),

/* Num, Fn
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |TGNKRO|RESET |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_TRNS, \
  KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_TRNS, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   JP_COLN, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,     RESET 
),

/* Cursor
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff Audon |      |      |      |      |RGBMOD|
 * `-----------------------------------------------------------------------------------'
 */
[_CURSOR] =  LAYOUT_ortho_4x12( \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , MACRO1  , KC_BSPC, \
  KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO, \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
  KC_NO  ,KC_NO  ,KC_NO,  KC_NO  ,KC_NO  , KC_TRNS,  KC_TRNS, KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case MEDIA:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MEDIA);
      }
      return false;
      break;
    case PAREN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PAREN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _CURSOR);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _CURSOR);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _CURSOR);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _CURSOR);
      }
      return false;
      break;
    case CURSOR:
      if (record->event.pressed) {
        layer_on(_CURSOR);
      } else {
        layer_off(_CURSOR);
      }
      return false;
      break;
    case MACRO1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("z")"[");
      }
      return false;
      break;
  }
  return true;
}

//
// Combos
//
//const uint16_t PROGMEM test_combo1[] = {KC_J, KC_I, COMBO_END};
//const uint16_t PROGMEM test_combo2[] = {KC_J, KC_O, COMBO_END};
//combo_t key_combos[COMBO_COUNT] = {
//      COMBO(test_combo1, KC_BSPC),
//      COMBO(test_combo2, KC_END),
//};
