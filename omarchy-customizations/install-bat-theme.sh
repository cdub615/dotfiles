#!/bin/bash

echo "Installing catppuccin-mocha for bat..."
# Paths
BAT_CONFIG_DIR="$(bat --config-dir)"
THEME_DIR="$BAT_CONFIG_DIR/themes"
THEME_FILE="$THEME_DIR/Catppuccin Mocha.tmTheme"
CONFIG_FILE="$BAT_CONFIG_DIR/config"

# Ensure directories exist
mkdir -p "$THEME_DIR"

# Download theme only if it doesn't exist
if [ ! -f "$THEME_FILE" ]; then
  wget -q -O "$THEME_FILE" \
    "https://github.com/catppuccin/bat/raw/main/themes/Catppuccin%20Mocha.tmTheme"
fi

# Add theme to config only if it's not already there
if ! grep -Fxq '--theme="Catppuccin Mocha"' "$CONFIG_FILE" 2>/dev/null; then
  echo '--theme="Catppuccin Mocha"' >>"$CONFIG_FILE"
fi

# Rebuild bat cache
bat cache --build

