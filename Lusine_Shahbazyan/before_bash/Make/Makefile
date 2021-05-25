cc = g++

cfl = -c -Wall

all:	hello

hello:	main.o base.o button.o text.o
	$(cc) main.o base.o button.o text.o -o run

main.o:	main.cpp
	$(cc) $(cfl) main.cpp -o main.o

base.o:	base.cpp
	$(cc) $(cfl) base.cpp -o base.o

button.o:	button.cpp
	$(cc) $(cfl) button.cpp -o button.o

text.o:	text.cpp
	$(cc) $(cfl) text.cpp -o  text.o

clean:
	rm *.o run



