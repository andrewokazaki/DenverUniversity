CC = g++

all: main.o tickTackToe.o
	echo "make all"
	$(CC) -std=c++11 main.o tickTackToe.o -o run

tickTackToe: main.o tickTackToe.o
	echo "make tickTackToe"
	$(CC) -c main.o tickTackToe.o -o tickTackToe

main.o: main.cpp
	$(CC) -c -std=c++11 main.cpp 

tickTackToe.o: ./tickTackToe/tickTackToe.cpp
	$(CC) -c -std=c++11 ./tickTackToe/tickTackToe.cpp

clean: 
	rm -f *.o run
	cd tickTackToe && make clean
	echo "DONE with clean"
