for sid in $(aerospace list-workspaces --all); do
  label=(
    label="$sid"
    label.color=$WHITE
    label.padding_right=13
    script="$PLUGIN_DIR/aerospace.sh change-focused-workspace $sid"
  )
  sketchybar --add item label.$sid left \
    --subscribe label.$sid change-focused-workspace \
    --set label.$sid "${label[@]}"

  icons=()
  while IFS= read -r line; do

    window_id=$(echo $line | awk -F ' \\| ' '{print $1}')
    icons+=("icon.$window_id")

    #this is to set the focused window a highlighted color
    # focused_window_info=$(aerospace list-windows --focused)
    focused_window_id=$(echo $focused_window_info | awk -F ' \\| ' '{print $1}')
    # echo $focused_window_id
    if [ "$window_id" = "$focused_window_id" ]; then
      icon_color=$ACCENT_COLOR
    else
      icon_color=$WHITE
    fi
    # echo $icon_color

    app_name=$(echo $line | awk -F ' \\| ' '{print $2}')
    __icon_map "${app_name}"

    icon=(
      icon="${icon_result}"
      icon.font="$FONT:Regular:20.0"
      icon.color="$icon_color"
      label.align=center
      click_script="aerospace workspace $sid"
      script="$PLUGIN_DIR/aerospace.sh change-focused-window $window_id"
    )

    sketchybar --add item icon.$window_id left \
      --subscribe icon.$window_id change-focused-workspace change-focused-window \
      --set icon.$window_id "${icon[@]}"
  done < <(aerospace list-windows --workspace "$sid")

  echo "${icons[@]}"
  space=(
    background.height=26
    background.corner_radius=4
    background.border_color=$WHITE
    background.border_width=1
    background.color=0x00000000
    script="$PLUGIN_DIR/aerospace.sh create-delete-window"
  )
  sketchybar --add bracket space.$sid label.$sid "${icons[@]}" \
    --subscribe space.$sid space_windows_change \
    --set space.$sid "${space[@]}"

done
