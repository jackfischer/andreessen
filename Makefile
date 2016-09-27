CXXFLAGS=-std=c++11 -Wall -pedantic
ifeq "$(shell uname)" "Darwin"
	LDFLAGS= -lglut -framework OpenGL
	CXX=g++
else
	LDFLAGS= -lglut -lGL -lGLU -lX11
	CXX=clang++-3.9
endif

all: http.o Node.o Parser.o LayoutEngine.o main.o render.o box.o text.o loadimage.o
	$(CXX) $(LDFLAGS) $^

render.o: render/render.cpp
	$(CXX) $(CXXFLAGS) -c $^

box.o: render/box.cpp
	$(CXX) $(CXXFLAGS) -c $^

text.o: render/text.cpp
	$(CXX) $(CXXFLAGS) -c $^

loadimage.o: images/loadimage.cpp
	$(CXX) $(CXXFLAGS) -c $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $^

LayoutEngine.o: layout/LayoutEngine.cpp
	$(CXX) $(CXXFLAGS) -c $^

Parser.o: dom/Parser.cpp
	$(CXX) $(CXXFLAGS) -c $^

Node.o: dom/Node.cpp
	$(CXX) $(CXXFLAGS) -c $^

http.o: http/http.cpp
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm *.o main
