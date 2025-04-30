#!/bin/bash
(echo "Pacman Packages:"; pacman -Qe; echo -e "\nAUR Packages:"; pacman -Qm; echo -e "\nSnap Packages:"; snap list; echo -e "\nFlatpak Packages:"; flatpak list --app) > installed_packages.txt

