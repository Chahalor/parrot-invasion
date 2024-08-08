#!/bin/bash

parrot_raid()
{
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

		gnome-terminal --window --geometry=${width_terminal}x${heigth_terminal}+${X}+${Y} -- bash -c "curl parrot.live; exec bash"  &
	done
	done
}

	clear
	echo " _________________________ "
	echo "| what are we going to do |"
	echo "| 1 - sending a raid      |"
	echo "| 2 - make an invasion    |"
	echo "| 3 - take over this place|"
	echo "|                         |"
	echo "| q - quit                |"
	echo "|_________________________|"
	echo

while true; do

	read -p "parrot.live >>> " choix
	case $choix in
		1)
			parrot_raid
			;;
		2)
			echo "not implement"
			;;
		3)
			echo "not implement"
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
