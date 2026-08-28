#!/bin/bash
#
# Replace Omarchy's OMARCHY branding with HYPRARCH everywhere it appears.
#
# Omarchy 4 note: omarchy moved from ~/.local/share/omarchy (a git checkout)
# to /usr/share/omarchy (a pacman package). ~/.local/share/omarchy is now just
# a symlink to it. All of these targets are root-owned and package-managed, so
# every `omarchy update` reverts them -- the companion post-update.d hook
# re-runs this script to put them back.
#
# Run directly:  ./install-logo.sh
set -euo pipefail

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ASCII="$HERE/logo.txt"
IMAGE="$HERE/../logo.png"

OMARCHY_PATH="${OMARCHY_PATH:-/usr/share/omarchy}"

[[ -f $ASCII ]] || { echo "missing $ASCII" >&2; exit 1; }
[[ -f $IMAGE ]] || { echo "missing $IMAGE" >&2; exit 1; }

changed=0

install_file() {
    local src=$1 dest=$2
    [[ -e $(dirname "$dest") ]] || return 0
    if [[ -f $dest ]] && cmp -s "$src" "$dest"; then
        printf '  ok       %s\n' "$dest"
        return 0
    fi
    sudo install -m 644 "$src" "$dest"
    printf '  UPDATED  %s\n' "$dest"
    changed=1
}

echo "Applying HYPRARCH branding..."

# Terminal word art (omarchy-show-logo reads $OMARCHY_PATH/logo.txt)
install_file "$ASCII" "$OMARCHY_PATH/logo.txt"

# Boot splash (Plymouth). Also seed omarchy's own copy so that
# `omarchy refresh plymouth` doesn't restore the stock logo.
install_file "$IMAGE" "$OMARCHY_PATH/default/plymouth/logo.png"
install_file "$IMAGE" "/usr/share/plymouth/themes/omarchy/logo.png"

# Login screen (SDDM theme; Main.qml loads logo.png)
install_file "$IMAGE" "/usr/share/sddm/themes/omarchy/logo.png"

if ((changed)); then
    echo
    echo "Branding applied. The Plymouth splash lives in the initramfs, so run:"
    echo "  sudo limine-mkinitcpio     # or: sudo mkinitcpio -P"
    echo "to make the boot screen pick up the new logo."
else
    echo
    echo "Everything already up to date."
fi
