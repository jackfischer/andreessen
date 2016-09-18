ifeq "$(shell uname)" "Darwin"
	LDFLAGS= -lglut -framework OpenGL
else
	LDFLAGS= -lglut -lGL -lGLU -lX11
endif

all: http.o Node.o Parser.o LayoutEngine.o main.o render.o box.o text.o loadimage.o
	g++ $(LDFLAGS) render.o box.o text.o loadimage.o http.o Node.o Parser.o LayoutEngine.o main.o -o main

render.o:
	g++ -c -std=c++11 render/render.cpp

box.o:
	g++ -c -std=c++11 render/box.cpp

text.o:
	g++ -c -std=c++11 render/text.cpp

loadimage.o:
	g++ -c -std=c++11 images/loadimage.cpp

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
