#!/bin/bash

./install-logo.sh
./install-base-packages.sh
./install-fira-code.sh
./install-bat-theme.sh
./install-oh-my-zsh.sh
./round-walkers-corners.sh
./enable-ssh.sh
./set-shell.sh

# echo "Changing default terminal to ghostty..."
# find ~/.local/share/applications -type f -name "*.desktop" -exec sed -i 's/alacritty/ghostty/g' {} +
# find ~/.local/share/omarchy/bin -type f -name "omarchy-theme-set" -exec sed -i 's/alacritty/ghostty/g' {} +
# find ~/.local/share/omarchy/bin -type f -name "omarchy-theme-set" -exec sed -i 's/ghostty.config/config/g' {} +
# find ~/.config/waybar -type f -name "config.jsonc" -exec sed -i 's/alacritty/ghostty/g' {} +
#
# echo "Changing default browser to vivaldi..."
# wget -O ~/.local/share/applications/vivaldi.desktop https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/vivaldi.desktop
# find ~/.local/share/omarchy/bin -type f -name "omarchy" -exec sed -i 's/chromium/vivaldi/g' {} +
# find ~/.local/share/omarchy/default/bash/functions -type f -name "functions" -exec sed -i 's/chromium/vivaldi/g' {} +
# find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/chromium/vivaldi/g' {} +
# find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/Chromium/Vivaldi/g' {} +
# find ~/.local/share/omarchy/install -type f -name "mimetypes.sh" -exec sed -i 's/default-web-browser vivaldi.desktop/vivaldi-stable.desktop/g' {} +
# find ~/.local/share/omarchy/bin -type f -exec sed -i 's/chromium/vivaldi/g' {} +
# find ~/.config -type f -name "mimeapps.list" -exec sed -i 's/chromium/vivaldi-stable/g' {} +
#
# echo "Applying our configs from dotfiles..."
# cp ~/.config/ghostty/config ~/.config/ghostty/config-copy
# wget -O ~/.config/ghostty/config https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/ghostty/config
#
# cp ~/.config/hypr/hyprland.conf ~/.config/hypr/hyprland.conf-copy
# wget -O ~/.config/hypr/hyprland.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hyprland.conf
#
# cp ~/.config/hypr/hyprlock.conf ~/.config/hypr/hyprlock.conf-copy
# wget -O ~/.config/hypr/hyprlock.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_config/hypr/hyprlock.conf
#
# cp ~/.p10k.zsh ~/.p10k.zsh-copy
# wget -O ~/.p10k.zsh https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_p10k.zsh
#
# cp ~/.tmux.conf ~/.tmux.conf-copy
# wget -O ~/.tmux.conf https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_tmux.conf
#
# cp ~/.zshrc ~/.zshrc-copy
# wget -O ~/.zshrc https://raw.githubusercontent.com/cdub615/dotfiles/refs/heads/main/dot_zshrc
#


