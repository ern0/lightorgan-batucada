
inotifywait -q -m -e close_write song/batacuda.html |
while read -r filename event; do
	date
	tr < song/batacuda.html \>\< "\n\n"|grep batacuda > song/batacuda.inc
	xdotool search --name Arduino windowactivate
	xdotool keydown control key u;
	sleep 1
	xdotool keyup control
	sleep 2
	xdotool search --name Geany windowactivate
done
