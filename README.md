# yhara's keymaps

My keymaps.

- [REMAP](https://remap-keys.app/) ready
  - aleth42/ (25keys/aleth42)
  - zinc/ (25keyz/zinc)
  - crkbd/
  - helix/
  - kawaii10/
- PRK
  - kasumigasane/
- official qmk
  - alpha/
  - bolt/ (lazydesigners/bolt)
  - lets_split/
  - ristretto/
  - tango/ (vitamins_included)
- user qmk
  - lesovoz/

## Rakefile

For firmwares not merged into official `qmk_firmware`, I'm using [Rake](https://ruby.github.io/rake/) to quickly make build environment. See `Rakefile` for more.

## My keymap

Most of my keebs are 40% so my keymaps for them are mostly the same.

```
#include "keymap_japanese.h"

    // Base layer
    [0] = LAYOUT(
               KC_TAB ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
         CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        LSFT_T(KC_TAB),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
               KC_BSPC,  KC_DEL,  KC_LALT, KC_LGUI, LT(2,KC_LANG2),ALT_T(KC_SPC)   LT(3,KC_SPC),LT(1,KC_LANG1),KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
             ),

    // Number layer
    [1] = LAYOUT(
               _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9  , KC_F10 , _______,
               _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
               _______,  KC_F11,  KC_F12,  KC_NO,   KC_NO ,  KC_NO ,           _______, JP_COLN, JP_PLUS, _______, _______, _______, _______,
               _______,  _______,                   _______, _______,          _______, _______,                   KC_NO,   KC_NO,   RESET
             ),

    // Symbol layer
    [2] = LAYOUT(
               ALT_TAB,  KC_EXLM, JP_AT  , KC_HASH, KC_DLR , KC_PERC,                   JP_CIRC, JP_AMPR, JP_LPRN, JP_RPRN, JP_ASTR, KC_TRNS,
               KC_NO  ,  JP_TILD, JP_PIPE, JP_EQL , JP_YEN , JP_GRV,                    JP_QUOT, JP_LCBR, JP_LBRC, JP_RBRC, JP_COLN, JP_RCBR,
               _______,  KC_NO  , KC_NO  , KC_NO  , S(KC_INS), KC_SLSH,                 JP_DQUO ,JP_PLUS, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
               RESET  ,  KC_NO  ,                   KC_TRNS, KC_NO  ,       KC_SPC,     KC_TRNS,                   KC_NO  , KC_NO  , KC_NO
             ),

    // Cursor layer
    [3] = LAYOUT(
               _______,  _______, _______, KC_END,  _______, _______,                   RGB_TOG,RGB_M_SN, RGB_M_P, _______, KC_NUM , KC_BSPC, \
               _______,  KC_HOME, _______, KC_DEL,  KC_PGDN, KC_BSPC,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, \
               _______,  _______, _______, _______, _______, KC_PGUP,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1, KC_BTN2,  \
               _______,  _______,                   _______, _______,           KC_SPC, _______,                   _______, _______, _______
             ),
```
