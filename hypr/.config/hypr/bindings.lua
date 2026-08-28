-- Personal keybinding overrides.
--
-- Ported from the pre-Omarchy-4 bindings.conf. Most of that file duplicated
-- Omarchy defaults and has been dropped -- Omarchy 4 already ships Terminal,
-- Browser, File manager, Tmux, workspaces 1-0, ChatGPT, Calendar, Docker,
-- Email, Signal, Editor, Google Photos, Passwords, X, YouTube, Grok, WhatsApp,
-- Google Messages and X Post on the same keys you had them on.
--
-- See current bindings: omarchy menu keybindings --print

-- ---------------------------------------------------------------------------
-- Colemak-friendly window movement: M / I / E / N = left / right / up / down
-- (mirrors the right-hand home row on the Charybdis Colemak-DH layout)
-- ---------------------------------------------------------------------------

-- SUPER + M/I/E/N are unused by Omarchy 4.
o.bind("SUPER + M", "Focus on left window", hl.dsp.focus({ direction = "l" }))
o.bind("SUPER + I", "Focus on right window", hl.dsp.focus({ direction = "r" }))
o.bind("SUPER + E", "Focus on above window", hl.dsp.focus({ direction = "u" }))
o.bind("SUPER + N", "Focus on below window", hl.dsp.focus({ direction = "d" }))

-- The swap variants collide with Omarchy 4 defaults, so unbind those first.
hl.unbind("SUPER + SHIFT + M") -- was: Music
hl.unbind("SUPER + SHIFT + E") -- was: Email
hl.unbind("SUPER + SHIFT + N") -- was: Editor

o.bind("SUPER + SHIFT + M", "Swap window to the left", hl.dsp.window.swap({ direction = "l" }))
o.bind("SUPER + SHIFT + I", "Swap window to the right", hl.dsp.window.swap({ direction = "r" }))
o.bind("SUPER + SHIFT + E", "Swap window up", hl.dsp.window.swap({ direction = "u" }))
o.bind("SUPER + SHIFT + N", "Swap window down", hl.dsp.window.swap({ direction = "d" }))

-- ---------------------------------------------------------------------------
-- App overrides
-- ---------------------------------------------------------------------------

-- Screenshot on SUPER+SHIFT+S. Omarchy 4 moved it to PRINT, which still works.
hl.unbind("SUPER + SHIFT + S") -- was: Google Maps
o.bind("SUPER + SHIFT + S", "Screenshot", "omarchy-capture-screenshot")

-- Obsidian needs -disable-gpu and --enable-wayland-ime; the stock binding
-- launches it without them.
hl.unbind("SUPER + SHIFT + O") -- was: Obsidian (no flags)
o.bind("SUPER + SHIFT + O", "Obsidian", {
  focus = "^obsidian$",
  launch = "obsidian -disable-gpu --enable-wayland-ime",
})

-- Typora rather than Omarchy's Omawrite.
hl.unbind("SUPER + SHIFT + W") -- was: Omawrite
o.bind("SUPER + SHIFT + W", "Typora", { launch = "typora --enable-wayland-ime" })

-- Teams is not an Omarchy 4 default.
o.bind("SUPER + SHIFT + T", "Teams", { focus = true, webapp = "https://teams.microsoft.com" })
