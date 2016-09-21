ifeq "$(shell uname)" "Darwin"
	LDFLAGS= -lglut -framework OpenGL
else
	LDFLAGS= -lglut -lGL -lGLU -lX11
endif

all: http.o Node.o Parser.o LayoutEngine.o main.o render.o box.o text.o loadimage.o
	clang++-3.9 $(LDFLAGS) render.o box.o text.o loadimage.o http.o Node.o Parser.o LayoutEngine.o main.o -o main

render.o:
	clang++-3.9 -c -std=c++11 render/render.cpp

box.o:
	clang++-3.9 -c -std=c++11 render/box.cpp

text.o:
	clang++-3.9 -c -std=c++11 render/text.cpp

loadimage.o:
	clang++-3.9 -c -std=c++11 images/loadimage.cpp

main.o:
	clang++-3.9 -c -std=c++11 main.cpp

LayoutEngine.o:
	clang++-3.9 -c -std=c++11 layout/LayoutEngine.cpp

Parser.o:
	clang++-3.9 -c -std=c++11 dom/Parser.cpp

Node.o:
	clang++-3.9 -c -std=c++11 dom/Node.cpp

http.o:
	clang++-3.9 -c -std=c++11 http/http.cpp

clean:
	rm *.o main
