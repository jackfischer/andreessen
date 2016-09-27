CXXFLAGS=-std=c++11 -Wall -pedantic
ifeq "$(shell uname)" "Darwin"
	LDFLAGS := -lglut -framework OpenGL
	CXX := g++
else
	LDFLAGS := -lglut -lGL -lGLU -lX11 -lc++ -lc++abi
	CXX := clang++
	CXXFLAGS += -stdlib=libc++
endif

OBJS := \
  main.o \
  http/http.o \
  images/loadimage.o \
  dom/Node.o \
  dom/Parser.o \
  layout/LayoutEngine.o \
  render/render.o \
  render/box.o \
  render/text.o

all: main
	
main: $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) main
