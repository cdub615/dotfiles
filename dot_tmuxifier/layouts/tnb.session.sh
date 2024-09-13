# Set a custom session root path. Default is `$HOME`.
# Must be called before `initialize_session`.
session_root "$HOME/Projects/internal-apps/apps/tnb"

# Create session with specified name if it does not already exist. If no
# argument is given, session name will be based on layout file name.
if initialize_session "tnb"; then

  # Create a new window inline within session layout definition.
  new_window "code"

  new_window "terminal"

  split_v 50
  split_h 33

  select_pane 2
  run_cmd "cd tnb-api"
  run_cmd "psgdb"

  select_pane 1
  run_cmd "cd tnb-api"
  run_cmd "yarn serve"

  select_pane 0
  run_cmd "cd tnb-ui"
  run_cmd "yarn serve"

  select_window "code"
  run_cmd "nvim"

fi

# Finalize session creation and switch/attach to it.
finalize_and_go_to_session
