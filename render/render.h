#ifndef RENDER_H
#define RENDER_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "../layout/LayoutData.h"
#include <vector>
#include "../main.h"

void reshape(int w, int h);
void init(void);
void display(void);
void loadLayoutData(std::vector<LayoutData> ld);
// int startBrowser(int argc, char **argv, std::vector<LayoutData>);

#endif
