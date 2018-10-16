CC = g++

all: main.o 
	echo "make all"
	$(CC) main.o -o all

tickTackToe: main.o tickTackToe.o
	echo "make tickTackToe"
	$(CC) -c main.o tickTackToe.o -o tickTackToe

main.o: main.cpp
	$(CC) -c main.cpp 

tickTackToe.o: 
	cd

clean: 
	rm -f *.o all
	cd tickTackToe && make clean
	echo "DONE with clean"