all: run

run:	main.o http.o
	g++ main.o http.o -o run

main.o:	main.cpp
	g++ -c main.cpp

http.o:	http.cpp
	g++ -c http.cpp

clean:
	rm *.o run
