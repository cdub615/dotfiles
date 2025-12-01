#!/bin/bash

echo "Rounding Walker's corners..."
find ~/.local/share/omarchy/default/walker/themes/omarchy-default -type f -name "style.css" -exec sed -i 's/border-radius: 0px/border-radius: 15px/g' {} +
