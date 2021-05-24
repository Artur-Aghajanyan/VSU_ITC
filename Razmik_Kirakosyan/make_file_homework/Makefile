cc = g++
CFLAGS = -c  -Wall

all: hi

hi: main.o das1.o das2.o
	$(cc) main.o das1.o das2.o -o hi_team

main.o: main.cpp
	$(cc) $(CFLAGS) main.cpp -o main.o

das1.o: das1.cpp
	$(cc) $(CFLAGS) das1.cpp -o das1.o

das2.o: das2.cpp
	$(cc) $(CFLAGS) das2.cpp -o das2.o

clean:
	rm *.o hi_team a.out
	

