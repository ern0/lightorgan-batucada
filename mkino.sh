cat song/batucada.html \
	| tr \>\< "\n\n" \
	| grep batucada \
	| tr -cd '\11\12\15\40-\176' \
	> song/batucada.inc

cat \
	song/lightorgan.inc \
	song/batucada.inc \
	song/patterns.inc \
	> lightorgan-batucada.ino
