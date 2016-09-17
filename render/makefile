CC=g++
CFLAGS= -std=gnu++11 -c -g -Wall

ifeq "$(shell uname)" "Darwin"
	GLUT_LDFLAGS = -lglut -framework OpenGL
	#GLUT_LDFLAGS = -framework GLUT -framework OpenGL
else
	GLUT_LDFLAGS = -lglut -lGL -lGLU -lX11
endif

LDFLAGS= $(GLUT_LDFLAGS)

SOURCES= render.cpp
HEADERS= render.h
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE= render

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# bitmap.o: bitmap.cpp
# 	$(CC) $(CFLAGS) $< -o $@

test: all
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm $(OBJECTS) $(EXECUTABLE)
