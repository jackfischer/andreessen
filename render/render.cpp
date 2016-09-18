#include "box.h"
#include "../layout/LayoutData.h"
#include "render.h"
#include "text.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const char *example = "Look at my pretty fonts";

vector<Box*> activeBoxes;

void loadLayoutData(vector<LayoutData> ld)
{
    activeBoxes.clear();
    Box *addedBox;
    for (auto div : ld) {
        addedBox = new Box(
                div.text,
                div.image,
                div.voff,
                div.hoff,
                div.width,
                div.height,
                div.textsize,
                div.topColor,
                div.bottomColor
                );
        activeBoxes.push_back(addedBox);
    }

    for (auto box : activeBoxes) {
        box->draw();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 5, 1, 0, 1);
    drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 10, 1, 1, 0);
    drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 15, 0, 1, 1);
    drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 0, 1, 0, 0);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(1, -0.95, 1); // set top left to origin
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    /* default to white background */
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Andreesen");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    loadtex();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();

    return 0;
}
