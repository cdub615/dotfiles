-- See https://wiki.hypr.land/Configuring/Basics/Monitors/
-- List current monitors and supported resolutions with: hyprctl monitors all
--
-- Ported from the pre-Omarchy-4 monitors.conf.

-- Optimized for retina-class 2x displays, like 13" 2.8K, 27" 5K, 32" 6K.
hl.env("GDK_SCALE", "2")

-- Fallback for any monitor not listed below.
hl.monitor({ output = "", mode = "preferred", position = "auto", scale = "auto" })

-- Ultrawide (primary).
hl.monitor({ output = "DP-3", mode = "3440x1440@60", position = "auto", scale = 1 })

-- Framework built-in display.
hl.monitor({ output = "eDP-1", mode = "preferred", position = "auto", scale = "auto" })

-- Keep workspace 1 on the ultrawide.
hl.workspace_rule({ workspace = "1", monitor = "DP-3" })
