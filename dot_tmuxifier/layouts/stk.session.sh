session_root "$HOME/Projects/internal-apps/apps/stocks"

# Create session with specified name if it does not already exist. If no
# argument is given, session name will be based on layout file name.
if initialize_session "stk"; then

  # Create a new window inline within session layout definition.
  new_window "code"

  new_window "terminal"

  split_v 50
  split_h 33

  select_pane 2
  run_cmd "cd stocks-api"
  run_cmd "yarn ssh:database"

  select_pane 1
  run_cmd "cd stocks-api"
  run_cmd "yarn serve"

  select_pane 0
  run_cmd "cd stocks-ui"
  run_cmd "yarn serve:dev"

  select_window "code"
  run_cmd "nvim"

fi
