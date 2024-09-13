session_root "$HOME/Projects/internal-apps/apps/reviews"

if initialize_session "rvu"; then

  new_window "main"

  split_v 20
  split_h 66
  split_h 50

  run_cmd "cd reviews-api"
  run_cmd "psgdb"

  select_pane 2
  run_cmd "cd reviews-api"
  run_cmd "yarn serve"

  select_pane 1
  run_cmd "cd reviews-ui"
  run_cmd "yarn serve:dev"

  select_pane 0
  run_cmd "nvim"

fi

finalize_and_go_to_session
