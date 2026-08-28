-- Change the default Omarchy look'n'feel.
--
-- Ported from the pre-Omarchy-4 looknfeel.conf. Only the settings that
-- actually differed from Omarchy's defaults are kept here.

-- https://wiki.hypr.land/Configuring/Basics/Variables/#general
hl.config({
  general = {
    gaps_in = 10,
    gaps_out = 20,
    border_size = 4,

    col = {
      -- Blue gradient rather than the stock cyan/green.
      active_border = { colors = { "rgba(33ccffee)", "rgba(3b82f6ee)" }, angle = 45 },
    },
  },

  -- https://wiki.hypr.land/Configuring/Basics/Variables/#decoration
  decoration = {
    rounding = 15,

    -- Transparency of focused and unfocused windows.
    active_opacity = 1.0,
    inactive_opacity = 0.9,

    shadow = {
      enabled = true,
      range = 4,
      render_power = 3,
      color = "rgba(1a1a1aee)",
    },

    blur = {
      enabled = true,
      size = 3,
      passes = 1,
      vibrancy = 0.1696,
    },
  },
})

-- Springy window animation. Omarchy already defines easeOutQuint, linear,
-- almostLinear and quick; this curve is the one addition.
hl.curve("overshot", { type = "bezier", points = { { 0.05, 0.9 }, { 0.1, 1.1 } } })

-- Use it for window open/close, and drop the stock "popin 87%" style.
hl.animation({ leaf = "windows", enabled = true, speed = 2.79, bezier = "overshot" })
hl.animation({ leaf = "windowsIn", enabled = true, speed = 4.1, bezier = "overshot" })
hl.animation({ leaf = "windowsOut", enabled = true, speed = 1.49, bezier = "overshot" })
