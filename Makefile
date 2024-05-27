all:
	gcc main.c ./functions/graf.c ./functions/functii.c ./functions/queue.c ./functions/liste.c -o clasament -lm
clean:
	rm -f clasamentS