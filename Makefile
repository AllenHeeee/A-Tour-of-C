all:  pointersorter.c
	gcc -O -g -o pointersorter pointersorter.c
clean:
	rm -f first