#!/bin/bash

CAT_MOCHA_DIR="$HOME/.local/share/omarchy/themes/catppuccin-mocha"
if [ ! -d "$CAT_MOCHA_DIR" ]; then
  echo "Catppuccin Mocha not found — run omarchy-theme-install and give it https://github.com/TylerDurham/omarchy-catppuccin-mocha.git"
fi
