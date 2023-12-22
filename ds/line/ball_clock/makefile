all: ball_clock

ball_clock: sqstack.o main.o queue.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o ball_clock