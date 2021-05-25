CC = g++
CFLAGS = -c -Wall

all: file

file: main.o fibonacci.o factorial.o mean.o
	$(CC) main.o fibonacci.o factorial.o mean.o -o file

main.o: main.cpp functions.h
	$(CC) $(CFLAGS) main.cpp -o main.o

fibonacci.o: fibonacci.cpp functions.h
	$(CC) $(CFLAGS) fibonacci.cpp -o fibonacci.o

factorial.o: factorial.cpp functions.h
	$(CC) $(CFLAGS) factorial.cpp -o factorial.o

mean.o: mean.cpp functions.h
	$(CC) $(CFLAGS) mean.cpp -o mean.o

clean:
	rm *.o file
