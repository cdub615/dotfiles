#!/bin/bash

POPUP_OFF="sketchybar --set apple.logo popup.drawing=off"
POPUP_CLICK_SCRIPT="sketchybar --set \$NAME popup.drawing=toggle"

apple_logo=(
  icon=$APPLE
  icon.font="$FONT:Black:16.0"
  icon.color=$WHITE
  # padding_right=15
  label.drawing=off
  click_script="$POPUP_CLICK_SCRIPT"
)

apple_prefs=(
  icon=$PREFERENCES
  label="Preferences"
  click_script="open -a 'System Preferences'; $POPUP_OFF"
)

apple_activity=(
  icon=$ACTIVITY
  label="Activity"
  click_script="open -a 'Activity Monitor'; $POPUP_OFF"
)

apple_lock=(
  icon=$LOCK
  label="Lock Screen"
  click_script="pmset displaysleepnow; $POPUP_OFF"
)

# background.color=$ITEM_BG_COLOR \
# background.corner_radius=5 \
# background.height=24 \
# padding_left=5 \
# padding_right=5 \
# label.padding_left=4 \
# label.padding_right=10 \
# icon.padding_left=10 \
# icon.padding_right=4

sketchybar --add item apple.logo left \
  --set apple.logo "${apple_logo[@]}" \
  icon.padding_left=0 \
  label.padding_left=0 \
  padding_left=0 \
  \
  --add item apple.prefs popup.apple.logo \
  --set apple.prefs "${apple_prefs[@]}" \
  background.height=0 \
  \
  --add item apple.activity popup.apple.logo \
  --set apple.activity "${apple_activity[@]}" \
  background.height=0 \
  \
  --add item apple.lock popup.apple.logo \
  --set apple.lock "${apple_lock[@]}" \
  background.height=0
