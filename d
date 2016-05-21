clear
date
./mkino.sh
xdotool search --name Arduino windowactivate
xdotool keydown control key u;
sleep 1
xdotool keyup control
sleep 2
xdotool search --name Geany windowactivate

