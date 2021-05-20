cc = g++
CFLAGS = -c -Wall
all: good

good: main.o class1.o class2.o
	$(cc) main.o class1.o class2.o -o good

main.o: main.cpp
	$(cc) $(CFLAGS) main.cpp -o main.o

class1.o: class1.cpp
	$(cc) $(CFLAGS) class1.cpp -o class1.o

class2.o: class2.cpp
	$(cc) $(CFLAGS) class2.cpp -o class2.o

clean:
	rm -rf *o good
