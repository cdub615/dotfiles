#!/bin/bash

cat <<EOF >$HOME/.local/share/omarchy/logo.txt
   ▄█    █▄    ▄██   ▄      ▄███████▄    ▄████████    ▄████████    ▄████████  ▄████████    ▄█    █▄   
  ███    ███   ███   ██▄   ███    ███   ███    ███   ███    ███   ███    ███ ███    ███   ███    ███  
  ███    ███   ███▄▄▄███   ███    ███   ███    ███   ███    ███   ███    ███ ███    █▀    ███    ███  
 ▄███▄▄▄▄███▄▄ ▀▀▀▀▀▀███   ███    ███  ▄███▄▄▄▄██▀   ███    ███  ▄███▄▄▄▄██▀ ███         ▄███▄▄▄▄███▄▄
▀▀███▀▀▀▀███▀  ▄██   ███ ▀█████████▀  ▀▀███▀▀▀▀▀   ▀███████████ ▀▀███▀▀▀▀▀   ███        ▀▀███▀▀▀▀███▀ 
  ███    ███   ███   ███   ███        ▀███████████   ███    ███ ▀███████████ ███    █▄    ███    ███  
  ███    ███   ███   ███   ███          ███    ███   ███    ███   ███    ███ ███    ███   ███    ███  
  ███    █▀     ▀█████▀   ▄████▀        ███    ███   ███    █▀    ███    ███ ████████▀    ███    █▀   
                                        ███    ███                ███    ███                          
EOF
echo "Add the logo.txt command to omarchy-update"

echo "Installing our packages..."
yay -S --noconfirm --needed ghostty age tmux yazi yt-dlp zsh openssh zsh-theme-powerlevel10k-git vivaldi bitwarden bitwarden-cli

echo "Installing FiraCode iScript..."
mkdir -p ~/.local/share/fonts

# FiraCode iScript
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Bold.ttf
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Italic.ttf
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Regular.ttf

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

echo "Downloading our logo..."
mkdir -p ~/.local/share/logo
wget -O ~/.local/share/logo/logo.png https://github.com/cdub615/dotfiles/raw/main/logo.png
cp ~/.local/share/logo/logo.png ~/.local/share/omarchy/default/plymouth/logo.png
echo "Add this to omarchy-update"

echo "Changing default terminal to ghostty..."
find ~/.local/share/applications -type f -name "*.desktop" -exec sed -i 's/alacritty/ghostty/g' {} +
find ~/.local/share/omarchy/bin -type f -name "omarchy-theme-set" -exec sed -i 's/alacritty/ghostty/g' {} +
find ~/.local/share/omarchy/bin -type f -name "omarchy-theme-set" -exec sed -i 's/ghostty.config/config/g' {} +
find ~/.config/waybar -type f -name "config.jsonc" -exec sed -i 's/alacritty/ghostty/g' {} +

echo "Changing default browser to vivaldi..."
wget -O ~/.local/share/applications/vivaldi.desktop https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/vivaldi.desktop
find ~/.local/share/omarchy/bin -type f -name "omarchy" -exec sed -i 's/chromium/vivaldi/g' {} +
find ~/.local/share/omarchy/default/bash/functions -type f -name "functions" -exec sed -i 's/chromium/vivaldi/g' {} +
find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/chromium/vivaldi/g' {} +
find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/Chromium/Vivaldi/g' {} +
find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/default-web-browser vivaldi.desktop/vivaldi-stable.desktop/g' {} +
find ~/.local/share/omarchy/bin -type f -exec sed -i 's/chromium/vivaldi/g' {} +
find ~/.config -type f -name "mimeapps.list" -exec sed -i 's/chromium/vivaldi-stable/g' {} +

echo "Applying our configs from dotfiles..."
cp ~/.config/ghostty/config ~/.config/ghostty/config-copy
wget -O ~/.config/ghostty/config https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/ghostty/config

cp ~/.config/hypr/autostart.conf ~/.config/hypr/autostart.conf-copy
wget -O ~/.config/hypr/autostart.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/autostart.conf

cp ~/.config/hypr/bindings.conf ~/.config/hypr/bindings.conf-copy
wget -O ~/.config/hypr/bindings.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/bindings.conf

cp ~/.config/hypr/envs.conf ~/.config/hypr/envs.conf-copy
wget -O ~/.config/hypr/envs.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/envs.conf

cp ~/.config/hypr/hypridle.conf ~/.config/hypr/hypridle.conf-copy
wget -O ~/.config/hypr/hypridle.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hypridle.conf

cp ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland.conf-copy
wget -O ~/.config/hypr/hyprland.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hyprland.conf

cp ~/.config/hypr/hyprlock.conf ~/.config/hypr/hyprlock.conf-copy
wget -O ~/.config/hypr/hyprlock.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hyprlock.conf

cp ~/.config/hypr/hyprsunset.conf ~/.config/hypr/hyprsunset.conf-copy
wget -O ~/.config/hypr/hyprsunset.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hyprsunset.conf

cp ~/.config/hypr/input.conf ~/.config/hypr/input.conf-copy
wget -O ~/.config/hypr/input.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/input.conf

cp ~/.config/hypr/looknfeel.conf ~/.config/hypr/looknfeel.conf-copy
wget -O ~/.config/hypr/looknfeel.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/looknfeel.conf

cp ~/.config/hypr/monitors.conf ~/.config/hypr/monitors.conf-copy
wget -O ~/.config/hypr/monitors.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/monitors.conf

cp ~/.config/hypr/tiling.conf ~/.config/hypr/tiling.conf-copy
wget -O ~/.config/hypr/tiling.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/tiling.conf

cp ~/.p10k.zsh ~/.p10k.zsh-copy
wget -O ~/.p10k.zsh https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_p10k.zsh

cp ~/.tmux.conf ~/.tmux.conf-copy
wget -O ~/.tmux.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_tmux.conf

cp ~/.zshrc ~/.zshrc-copy
wget -O ~/.zshrc https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_zshrc

echo "Rounding Walker's corners..."
find ~/.local/share/omarchy/default/walker/themes -type f -name "omarchy-default.css" -exec sed -i 's/border-radius: 0px/border-radius: 15px/g' {} +
echo "Add this to omarchy-update"

echo "Enabling ssh..."
sudo systemctl enable sshd

# Oh My Zsh install directory
OMZ_DIR="$HOME/.oh-my-zsh"

# Check if installed
if [ ! -d "$OMZ_DIR" ]; then
  echo "Oh My Zsh not found — installing..."
  sh -c "$(https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/install-oh-my-zsh.sh)"
else
  echo "Oh My Zsh already installed — skipping."
fi

CAT_MOCHA_DIR="$HOME/.local/share/omarchy/themes/catppuccin-mocha"
if [ ! -d "$CAT_MOCHA_DIR" ]; then
  echo "Catppuccin Mocha not found — run omarchy-theme-install and give it https://github.com/TylerDurham/omarchy-catppuccin-mocha.git"
fi

if [ -z "$ZSH_VERSION" ]; then
  chsh -s $(which zsh)
fi
