clear
This script compiles and uploads the sketch:
- Arduino IDE has to be started
- lightorgan-batacuda.ino has to be loaded 
date
./mkino.sh
xdotool search --name Arduino windowactivate
xdotool keydown control key u;
sleep 1
xdotool keyup control
sleep 2
xdotool search --name Geany windowactivate

