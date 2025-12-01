#!/bin/bash

echo "Installing FiraCode iScript..."
mkdir -p ~/.local/share/fonts

# FiraCode iScript
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Bold.ttf
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Italic.ttf
wget -P ~/.local/share/fonts https://github.com/kencrocken/FiraCodeiScript/blob/master/FiraCodeiScript-Regular.ttf
