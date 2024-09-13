#!/usr/bin/env bash

ACCENT_COLOR=0xff4400d2

if [ "$1" = "change-focused-window" ]; then
  echo "change-focused-window"
  focused_window_info=$(aerospace list-windows --focused)
  focused_window_id=$(echo $focused_window_info | awk -F ' \\| ' '{print $1}')
  if [ "$2" = "$focused_window_id" ]; then
    sketchybar --set $NAME icon.color=$ACCENT_COLOR
  else
    sketchybar --set $NAME icon.color=$WHITE
  fi
fi

if [ "$1" = "change-focused-workspace" ]; then
  echo "change-focused-workspace"
  focused_workspace=$(aerospace list-workspaces --focused)
  if [ "$2" = "$focused_workspace" ]; then
    sketchybar --set $NAME label.color=$ACCENT_COLOR
  else
    sketchybar --set $NAME label.color=$WHITE
  fi
fi

if [ "$1" = "move-window-within-workspace" ]; then
  echo "move-window-within-workspace"
  focused_workspace=$(aerospace list-workspaces --focused)
  if [ "$2" = "$focused_workspace" ]; then
    sketchybar --set $NAME label.color=$ACCENT_COLOR
  else
    sketchybar --set $NAME label.color=$WHITE
  fi
fi

if [ "$1" = "create-delete-window" ]; then
  echo "create-delete"
  apps_in_window=$(aerospace list-windows --workspace $(aerospace list-workspaces --focused))
  # echo $apps_in_window
  # echo $INFO

  #USE A REGEX IN SKETCHYBAR. Prefix all your icons with their window id.
  sketchybar --remove /icon./
  sketchybar --remove /label./
  sketchybar --remove /space./

  # #Re-render all app icons in all workspaces
  source ~/.config/sketchybar/sketchybar-app-font/dist/icon_map.sh

  BAR_COLOR=0xff22202b
  WHITE=0xffa17fa7
  ACCENT_COLOR=0xffe19286
  default=(
    padding_left=5
    padding_right=5
    label.font="Hack Nerd Font:Bold:14.0"
    icon.color=$WHITE
    label.color=$WHITE
    icon.padding_left=4
    icon.padding_right=4
    label.padding_left=4
    label.padding_right=4
  )

  sketchybar --default "${default[@]}"

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

      app_name=$(echo $line | awk -F ' \\| ' '{print $2}')
      __icon_map "${app_name}"

      icon=(
        icon="${icon_result}"
        icon.font="sketchybar-app-font:Regular:20.0"
        label.align=center
        click_script="aerospace workspace $sid"
        script="$PLUGIN_DIR/aerospace.sh change-focused-window $window_id"
      )

      sketchybar --add item icon.$window_id left \
        --subscribe icon.$window_id change-focused-workspace change-focused-window \
        --set icon.$window_id "${icon[@]}"
    done < <(aerospace list-windows --workspace "$sid")

    # echo ${icons[@]}
    space=(
      script="$PLUGIN_DIR/aerospace.sh create-delete-window"
    )
    sketchybar --add bracket space.$sid label.$sid "${icons[@]}" \
      --subscribe space.$sid space_windows_change \
      --set space.$sid "${space[@]}"

  done

fi

#also need MOVE window. get the order from aerospace list-windows --workspace. bind the "move" aerospace commands in aerospace.toml to exec 'sketchybar --trigger ...'.
