-- Keep only your personal input overrides here. Uncommented settings below
-- replace Omarchy's defaults.
--
-- Ported from the pre-Omarchy-4 input.conf.

hl.config({
  input = {
    kb_layout = "us",

    -- Caps Lock acts as Compose.
    kb_options = "compose:caps",

    -- Faster key repeat.
    repeat_rate = 40,
    repeat_delay = 600,

    -- Start with numlock on by default.
    numlock_by_default = true,

    -- Reduce sensitivity for mice (default: 0). The built-in touchpad opts
    -- back out of this via the hl.device override below.
    sensitivity = -0.75,

    touchpad = {
      -- Control the speed of your scrolling.
      scroll_factor = 0.4,
    },
  },
})

-- Use default cursor speed for the built-in trackpad, overriding the global
-- sensitivity above (which stays in effect for mice).
-- Device name from `hyprctl devices`.
hl.device({ name = "pixa3854:00-093a:0274-touchpad", sensitivity = 0 })

-- Scroll nicely in the terminal.
o.window("(Alacritty|kitty|foot)", { scroll_touchpad = 1.5 })
o.window("com.mitchellh.ghostty", { scroll_touchpad = 0.2 })
