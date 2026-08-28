-- Extra autostart processes.
--
-- Ported from the pre-Omarchy-4 autostart.conf, which used:
--   exec-once = uwsm-app -- hyprsunset
-- o.launch_on_start() wraps the command in uwsm-app for us.

o.launch_on_start("hyprsunset")
