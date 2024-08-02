# #!/bin/bash

# Format gnome : gnome-terminal --window --geometry=[width]x[length]+[cordX]+[cordY]
# Obtenir la résolution de l'écran : resolution=$(xdpyinfo | awk '/dimensions:/ {print $2}')

nb_colonne=3
nb_ligne=4

largeur_terminal=80
hauteur_terminal=24

largeur_pixel=12
hauteur_pixel=22

for i in $(seq 0 $((nb_colonne - 1)))
do
  for j in $(seq 0 $((nb_ligne - 1)))
  do
    ((X = j * 1050))
    ((Y = i * 750))

    gnome-terminal --window --geometry=${largeur_terminal}x${hauteur_terminal}+${X}+${Y} -- bash -c "curl parrot.live; exec bash" &
  done
done
