# Set a custom session root path. Default is `$HOME`.
# Must be called before `initialize_session`.
session_root "$HOME/Projects/wordle-teams"

# Create session with specified name if it does not already exist. If no
# argument is given, session name will be based on layout file name.
if initialize_session "wt"; then

  # Create a new window inline within session layout definition.
  new_window "code"

  new_window "terminal"
  run_cmd "pnpm dev"

  select_window "code"
  run_cmd "nvim"

fi

# Finalize session creation and switch/attach to it.
finalize_and_go_to_session
