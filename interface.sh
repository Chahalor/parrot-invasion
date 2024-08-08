#!/bin/bash

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

	read -p "Choisissez une option : " choix
	case $choix in
		1)
			chmod -x ./parrot_invasion.sh
			timeout 5 bash parrot_invasion.sh 
			# rm parrot_invasion.sh
			# rm interface.sh
			# clear
			# exit 0
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
