/*
 * 別途、keyboards/alpha/config.hに以下を記入
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define RGBLED_NUM 10
#define RGBLIGHT_LAYERS
//#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define COMBO_COUNT 6
#define COMBO_TERM 35
*/
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define HOME 0
#define SYMBOL 1
#define NUMBER 2
#define OTHER 3  //FN
#define CURSOR 4
#define PAREN 5

// DONT FORGET TO UPDATE COMBO_COUNT in config.h when adding a new combo
typedef const uint16_t comb_keys_t[];
static PROGMEM comb_keys_t
  comb_keys_Enter = {KC_J, KC_O, COMBO_END},
  comb_keys_BackSpace = {KC_J, KC_I, COMBO_END},
  comb_keys_Tab = {KC_W, KC_R, COMBO_END},
  comb_keys_Kana = {KC_G, KC_J, COMBO_END},
  comb_keys_Eisu = {KC_G, KC_H, COMBO_END},
  comb_keys_Escape = {KC_W, KC_E, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO( comb_keys_Enter, KC_ENT ),
  COMBO( comb_keys_BackSpace, KC_BSPC ),
  COMBO( comb_keys_Tab, KC_TAB ),
  COMBO( comb_keys_Kana, KC_LANG1 ),
  COMBO( comb_keys_Eisu, KC_LANG2 ),
  COMBO( comb_keys_Escape, KC_ESC ),
};

enum custom_keycodes {
	MACRO1 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case MACRO1:
                                SEND_STRING(SS_LCTRL("z")"[");
				return false;
		}
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, LT(OTHER,KC_P),
    MT(MOD_LCTL,KC_A), LT(NUMBER,KC_S), LT(SYMBOL,KC_D), LT(PAREN,KC_F), KC_G, KC_H, KC_J, LT(SYMBOL,KC_K), LT(NUMBER,KC_L), MT(MOD_RCTL,KC_SCLN),
    MT(MOD_LSFT,KC_Z), KC_X, KC_C, GUI_T(KC_V), LT(CURSOR,KC_SPC), GUI_T(KC_B), KC_N, MT(MOD_RSFT,KC_M)
                ),

	[SYMBOL] = LAYOUT(
                //  !      @      #        $        %        ^       &        *                 -
		KC_EXLM, JP_AT, KC_HASH, KC_DLR, KC_PERC, JP_CIRC, JP_AMPR, JP_ASTR, KC_NO, KC_MINS,
                //  ~      |         =      \        `        '       "        +      /         :
		S(JP_CIRC),S(JP_YEN),JP_EQL,JP_YEN,JP_GRV, JP_QUOT, JP_DQT, JP_PLUS, KC_SLSH, JP_COLN,
                //  _                                           ?       ,         .  
		JP_UNDS,    KC_NO, KC_NO,  KC_NO,  KC_SPC,  S(KC_SLSH), KC_COMM, KC_DOT),

	[NUMBER] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

	[OTHER] = LAYOUT(
		RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		RGB_VAI, RGB_VAD, RGB_HUI, RGB_TOG, RGB_MOD, KC_MPLY, KC_VOLD, KC_VOLU),
 
	[CURSOR] = LAYOUT(
		KC_TAB, KC_NO, KC_END,KC_NO, KC_NO, KC_NO, KC_NO, S(KC_TAB), KC_TAB, MACRO1,
	       KC_HOME,KC_NO, KC_DEL, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
		KC_ESC, KC_NO, KC_NO, GUI_T(KC_LANG2),KC_TRNS,KC_LANG1, KC_NO, MOD_RSFT),

	[PAREN] = LAYOUT(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, JP_LPRN, JP_RPRN, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, S(KC_COMM), S(KC_DOT)),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

//
// Lighting Layers
//

const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_RED}
);
const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CYAN}
);
const rgblight_segment_t PROGMEM other_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM cursor_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_GREEN}
);
const rgblight_segment_t PROGMEM paren_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 5, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = {
    symbol_layer,
    number_layer,
    other_layer,
    cursor_layer,
    paren_layer,
    NULL
};

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));
    rgblight_set_layer_state(3, layer_state_cmp(state, 4));
    rgblight_set_layer_state(4, layer_state_cmp(state, 5));
    return state;
}
