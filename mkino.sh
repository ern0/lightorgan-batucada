cat song/batacuda.html \
	| tr \>\< "\n\n" \
	| grep batacuda \
	| tr -cd '\11\12\15\40-\176' \
	> song/batacuda.inc

cat \
	song/lightorgan.inc \
	song/batacuda.inc \
	song/patterns.inc \
	> lightorgan-batacuda.ino
