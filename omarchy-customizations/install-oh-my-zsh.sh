#!/bin/bash

# Oh My Zsh install directory
OMZ_DIR="$HOME/.oh-my-zsh"

# Check if installed
if [ ! -d "$OMZ_DIR" ]; then
  echo "Oh My Zsh not found — installing..."
  ./install-omz.sh

else
  echo "Oh My Zsh already installed — skipping."
fi

