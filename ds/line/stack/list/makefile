all: stack

stack: stack.o main.o llist.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o stack