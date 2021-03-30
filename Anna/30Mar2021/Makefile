cc=g++
CF= -c -Wall
all: f

f: main.o func.o
	$(cc) main.o func.o -o f

main.o: main.cpp
	$(cc) $(CF) main.cpp -o main.o
func.o: func.cpp
	$(cc) $(CF) func.cpp -o func.o
clean:
	rm -rf *.o f
