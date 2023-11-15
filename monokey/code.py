print("Monokey Starting")

import board
from kmk.kmk_keyboard import KMKKeyboard
from kmk.keys import KC
from kmk.consts import UnicodeMode
from kmk.scanners.keypad import KeysScanner
from kmk.handlers.sequences import simple_key_sequence
from kmk.handlers.sequences import send_string
from kmk.handlers.sequences import unicode_string_sequence
from kmk.handlers.sequences import compile_unicode_string_sequences as cuss
from kmk.handlers.sequences import unicode_codepoint_sequence


_KEY_CFG = [
    board.A1
]

# Keyboard implementation class
class Monokey(KMKKeyboard):
    def __init__(self):
        # create and register the scanner
        self.matrix = KeysScanner(
            # require argument:
            pins=_KEY_CFG,
            # optional arguments with defaults:
            value_when_pressed=False,
            pull=True,
            interval=0.02,  # Debounce time in floating point seconds
            max_events=64
        )

keyboard = Monokey()
keyboard.debug_enabled = True
keyboard.unicode_mode = UnicodeMode.OSX

MyKey = unicode_string_sequence(r'🍣k')

emoticons = cuss({
            'BEER': r'🍺',
                    'HAND_WAVE': r'👋',
                    })
EMOJI = simple_key_sequence(
        (
            KC.LALT(no_release=True), 
#            KC.N2,
#            KC.N6,
#            KC.N0,
#            KC.N0,
  KC.D,
  KC.N8,
  KC.N3,
  KC.C,
            KC.LALT(no_press=True),
            KC.LALT(no_release=True), 

  KC.D,
  KC.F,
  KC.N6,
  KC.N3,
            KC.LALT(no_press=True)
            )
        )
unicode_codepoint_sequence([
     "2600"
])

keyboard.keymap = [
    [EMOJI] # [KC.A]
]

if __name__ == '__main__':
    keyboard.go()
