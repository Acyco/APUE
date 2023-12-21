all: queue

queue: queue.o main.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o queue