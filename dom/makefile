all:	run

run:	Parser.o Node.o main.o
	g++ Parser.o Node.o main.o -o run

css:	Parser.o Node.o cssParseDriver.o
	g++ Parser.o Node.o cssParseDriver.o -o run

cssParseDriver.o:
	g++ -c -std=c++11 cssParseDriver.cpp

main.o:	main.cpp
	g++ -c -std=c++11 main.cpp

Parser.o:	Parser.cpp
	g++ -c -std=c++11 Parser.cpp

Node.o:	Node.cpp
	g++ -c -std=c++11 Node.cpp

clean:
	rm *.o run
