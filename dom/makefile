all: run

run:	Parser.o Node.o main.o
	g++ Parser.o Node.o main.o -o run

main.o:	main.cpp
	g++ -c main.cpp

Parser.o:	Parser.cpp
	g++ -c Parser.cpp

Node.o:	Node.cpp
	g++ -c Node.cpp

clean:
	rm *.o run
