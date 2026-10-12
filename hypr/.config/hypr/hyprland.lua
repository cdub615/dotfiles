-- Learn how to configure Hyprland: https://wiki.hypr.land/Configuring/Start/

-- Omarchy's bootstrap keeps path setup out of this user config.
dofile((os.getenv("OMARCHY_PATH") or "/usr/share/omarchy") .. "/default/hypr/bootstrap.lua")

-- Disable all Omarchy default bindings. Add your own in hypr/bindings.lua.
-- omarchy_default_bindings = false
--
-- Or disable only bindings for Omarchy's preinstalled apps/web apps while
-- keeping core window-manager bindings:
-- omarchy_preinstalled_bindings = false

-- Load Omarchy defaults.
require("default.hypr.omarchy")

-- Put your personal overrides in these files. They're loaded after Omarchy's
-- defaults so package updates can improve the defaults without rewriting your
-- ~/.config/hypr files.
require("hypr.monitors")
require("hypr.input")
require("hypr.bindings")
require("hypr.looknfeel")
require("hypr.autostart")

-- Toggle config flags dynamically.
require("default.hypr.toggles")

-- Add any other personal Hyprland configuration below.
-- o.window("qemu", { workspace = "5" })

-- Presenting: send the slide deck's speaker-notes popup (title "Notes · N/M")
-- to the laptop panel, maximized, without pulling focus off the deck.
-- A static window rule can't do this: the popup only gets its title after it
-- opens, and static rules match the initial title. Works in Chromium; Vivaldi
-- titles the popup "Blank Page" so it never matches.
local presenter_notes_placed = {}
hl.on("window.title", function(w)
  if w == nil or w.title == nil or not w.title:find("^Notes · ") then return end
  if presenter_notes_placed[w.address] then return end
  presenter_notes_placed[w.address] = true
  if hl.get_monitor("eDP-1") == nil then return end
  if w.monitor ~= nil and w.monitor.name == "eDP-1" then return end
  hl.dispatch(hl.dsp.window.move({ window = w, monitor = "eDP-1", follow = false }))
  hl.dispatch(hl.dsp.window.fullscreen({ window = w, action = "set", mode = "maximized" }))
end)
