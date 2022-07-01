# yhara's keymaps

My keymaps.

- [REMAP](https://remap-keys.app/) ready
  - aleth42/
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

## Adding submodules

eg. lesovoz

    git submodule add https://github.com/Tsquash/vial-qmk user_qmk/Tsquash

Now you have all the files in `Tsquash/vial-qmk`. You can save your disk space
by setting `sparsecheckout`.

    git -C user_qmk/Tsquash config core.sparsecheckout true
    echo "/keyboards/lesovoz" >> .git/modules/user_qmk/Tsquash/info/sparse-checkout

After changing branch (or `git -C user_qmk/Tsquash read-tree -mu HEAD`, etc.) you'll only have `keyboards/lesovoz` directory in `lesovoz/qmk`.
