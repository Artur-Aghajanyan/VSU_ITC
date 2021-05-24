CC = g++
CFLAGS = -c -Wall
OFLAGS = -o
OBJECTS = main.o complex.o function.o


all: complex

complex: $(OBJECTS)
	$(CC) main.o complex.o function.o $(OFLAGS) complex

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(OFLAGS) main.o

complex.o: complex.cpp
	$(CC) $(CFLAGS) complex.cpp $(OFLAGS) complex.o

function.o: function.cpp
	$(CC) $(CFLAGS) function.cpp $(OFLAGS) function.o

clean:
	rm *.o complex
