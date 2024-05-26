all:
	gcc main.c ./functions/graf.c ./functions/functii.c ./functions/queue.c ./functions/stack.c -o clasament
clean:
	rm -f clasament