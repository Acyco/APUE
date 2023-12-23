all: main

main: queue.o main.o llist.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o main