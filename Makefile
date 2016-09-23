ifeq "$(shell uname)" "Darwin"
	LDFLAGS= -lglut -framework OpenGL
	CXX=g++
else
	LDFLAGS= -lglut -lGL -lGLU -lX11
	CXX=clang++-3.9
endif

all: http.o Node.o Parser.o LayoutEngine.o main.o render.o box.o text.o loadimage.o
	$(CXX) $(LDFLAGS) render.o box.o text.o loadimage.o http.o Node.o Parser.o LayoutEngine.o main.o -o main

render.o:
	$(CXX) -c -std=c++11 render/render.cpp

box.o:
	$(CXX) -c -std=c++11 render/box.cpp

text.o:
	$(CXX) -c -std=c++11 render/text.cpp

loadimage.o:
	$(CXX) -c -std=c++11 images/loadimage.cpp

main.o:
	$(CXX) -c -std=c++11 main.cpp

LayoutEngine.o:
	$(CXX) -c -std=c++11 layout/LayoutEngine.cpp

Parser.o:
	$(CXX) -c -std=c++11 dom/Parser.cpp

Node.o:
	$(CXX) -c -std=c++11 dom/Node.cpp

http.o:
	$(CXX) -c -std=c++11 http/http.cpp

clean:
	rm *.o main
