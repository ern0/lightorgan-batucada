
inotifywait -q -m -e close_write song/batacuda.html song/patterns.inc |
while read -r filename event; do
	date
	./mkino.sh
	xdotool search --name Arduino windowactivate
	xdotool keydown control key u;
	sleep 1
	xdotool keyup control
	sleep 2
	xdotool search --name Geany windowactivate
done

