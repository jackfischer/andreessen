
all: Node.o LayoutEngine.o main.o
	g++ Node.o LayoutEngine.o main.o -o run

main.o:
	g++ -c -std=c++11 main.cpp

LayoutEngine.o:
	g++ -c -std=c++11 LayoutEngine.cpp

Node.o:
	g++ -c -std=c++11 ../dom/Node.cpp

clean:
	rm *.o main run
