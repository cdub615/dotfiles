#!/bin/bash
#
# Enable the Plymouth boot splash (so HYPRARCH shows on the LUKS password
# screen) by adding the `plymouth` hook to /etc/mkinitcpio.conf and rebuilding.
#
# Background: the cmdline already passes `quiet splash`, plymouthd is set to
# Theme=omarchy, and the omarchy theme draws a password dialog. Arch's stock
# `encrypt` hook is plymouth-aware (it calls `plymouth ask-for-password`), so
# no plymouth-encrypt hook is needed -- only `plymouth` in HOOKS was missing.
#
# This system boots a UKI built by limine-mkinitcpio; /etc/mkinitcpio.d is
# empty, so `mkinitcpio -P` would do nothing. limine-mkinitcpio is the one
# correct rebuild command here.
#
# Idempotent. Safe to re-run.
set -euo pipefail

CONF=/etc/mkinitcpio.conf
UKI=/boot/EFI/Linux/omarchy_linux.efi
STAMP=$(date +%Y%m%d-%H%M%S)

(( EUID == 0 )) || { echo "Run with sudo: sudo $0" >&2; exit 1; }

echo "== 1/4  Applying HYPRARCH branding first, so it gets baked into the image"
USER_HOME=$(getent passwd "${SUDO_USER:-$USER}" | cut -d: -f6)
LOGO_SCRIPT="$USER_HOME/dotfiles/omarchy-customizations/install-logo.sh"
if [[ -x $LOGO_SCRIPT ]]; then
    sudo -u "${SUDO_USER:-$USER}" env OMARCHY_PATH="${OMARCHY_PATH:-/usr/share/omarchy}" "$LOGO_SCRIPT" || true
else
    echo "  (install-logo.sh not found; skipping)"
fi

echo
echo "== 2/4  Adding the plymouth hook to $CONF"
cp -a "$CONF" "$CONF.bak.$STAMP"
echo "  backup: $CONF.bak.$STAMP"

python3 - "$CONF" <<'PY'
import re, sys
p = sys.argv[1]
src = open(p).read()
m = re.search(r'^HOOKS=\((.*?)\)\s*$', src, re.M)
if not m:
    sys.exit("ABORT: could not find a HOOKS=(...) line")
hooks = m.group(1).split()
if 'plymouth' in hooks:
    print("  already present, no change")
    sys.exit(0)
if 'udev' not in hooks:
    sys.exit("ABORT: no `udev` hook; refusing to guess placement")
hooks.insert(hooks.index('udev') + 1, 'plymouth')
new = src[:m.start()] + "HOOKS=(" + " ".join(hooks) + ")" + src[m.end():]
open(p, 'w').write(new)
print("  new HOOKS: " + " ".join(hooks))
PY

echo
echo "== 3/4  Rebuilding the UKI (limine-mkinitcpio)"
limine-mkinitcpio

echo
echo "== 4/4  Verifying plymouth actually landed in the image"
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
if objcopy -O binary --only-section=.initrd "$UKI" "$TMP/initrd" 2>/dev/null && [[ -s $TMP/initrd ]]; then
    if command -v lsinitcpio >/dev/null 2>&1 && lsinitcpio "$TMP/initrd" 2>/dev/null | grep -qi plymouth; then
        echo "  OK: plymouth files present in the new initramfs"
    elif grep -qa plymouth "$TMP/initrd"; then
        echo "  OK: plymouth present in the new initramfs"
    else
        echo "  WARNING: could not find plymouth in the image -- do NOT reboot;"
        echo "           restore with: cp $CONF.bak.$STAMP $CONF && limine-mkinitcpio"
        exit 1
    fi
else
    echo "  (could not extract .initrd to verify; check the build output above)"
fi

echo
echo "Done. Reboot to see it."
echo "If the boot splash misbehaves, pick an older snapshot in the limine menu, then:"
echo "  sudo cp $CONF.bak.$STAMP $CONF && sudo limine-mkinitcpio"
