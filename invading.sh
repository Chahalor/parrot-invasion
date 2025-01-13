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

TIMER=0
while true; do
	if [[ $TIMER -ge 10 ]]; then
		raid
		TIMER=0
	fi
	TIMER=$(($TIMER + $RANDOM % 4))
	sleep 10m
done
