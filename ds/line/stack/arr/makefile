all: sqstack

sqstack: sqstack.o main.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o sqstack