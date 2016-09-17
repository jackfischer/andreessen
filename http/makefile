all: run

run:	main.o http.o
	g++ main.o http.o -o run

main.o:	main.cpp
	g++ -c -std=c++11 main.cpp

http.o:	http.cpp
	g++ -c -std=c++11 http.cpp

clean:
	rm *.o run
