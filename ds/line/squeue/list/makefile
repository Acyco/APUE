all: queue

queue: queue.o main.o llist.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o queue