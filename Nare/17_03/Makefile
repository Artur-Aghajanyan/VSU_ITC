cc = g++
obj = main.o view.o button.o text.o
CFLAGS = -c -Wall

all:	 exec

exec:	 $(obj)
	$(cc) $(obj) -o exec

main.o:		 main.cpp
	$(cc) $(CFLAGS) main.cpp

view.o: 	view.cpp
	$(cc) $(CFLAGS) view.cpp

button.o: 	button.cpp
	$(cc) $(CFLAGS) button.cpp

text.o: 	text.cpp
	$(cc) $(CFLAGS) text.cpp

clean:
	rm -rf $(obj) exec
