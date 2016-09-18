
all: http.o Node.o Parser.o LayoutEngine.o main.o
	g++ http.o Node.o Parser.o LayoutEngine.o main.o -o main

main.o:
	g++ -c -std=c++11 main.cpp

LayoutEngine.o:
	g++ -c -std=c++11 layout/LayoutEngine.cpp

Parser.o:
	g++ -c -std=c++11 dom/Parser.cpp

Node.o:
	g++ -c -std=c++11 dom/Node.cpp


http.o:
	g++ -c -std=c++11 http/http.cpp

clean:
	rm *.o main

