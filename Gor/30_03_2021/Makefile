cc = g++
rm = rm -rf *.o Run

CFLAGS = -c -Wall

all: Run

Run: main.o func1.o func2.o func3.o func4.o
	$(cc) main.o func1.o func2.o func3.o func4.o -o Run

main.o: main.cpp
	$(cc) $(CFLAGS) main.cpp -o main.o

func1.o: func1.cpp
	$(cc) $(CFLAGS) func1.cpp -o func1.o

func2.o: func2.cpp
	$(cc) $(CFLAGS) func2.cpp -o func2.o

func3.o: func3.cpp
	$(cc) $(CFLAGS) func3.cpp -o func3.o

func4.o: func4.cpp
	$(cc) $(CFLAGS) func4.cpp -o func4.o

clean:
	$(rm)



