#include "box.h"
#include "render.h"
#include "text.h"
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;

#define debug(s) cerr << s << endl

const char *example = "Look at my pretty fonts";

vector<Box*> *activeBoxes;

void loadLayoutData(vector<LayoutData> ld)
{
    // debug("AA");
    activeBoxes->clear();
    // vector<Box*> *newboxes = new vector<Box*>();
    // debug("BB");
    Box *addedBox;
    // debug("CC");
    for (auto div : ld) {
        // debug("DD");
        addedBox = new Box(
                div.text,
                // example,
                div.image,
                div.voff,
                div.hoff,
                div.width,
                div.height,
                div.textsize,
                div.topColor,
                div.bottomColor
                );
        // debug("EE");
        activeBoxes->push_back(addedBox);
        // debug("FF");
    }
    // debug("GG");
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 5, 1, 0, 1);
    // drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 10, 1, 1, 0);
    // drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 15, 0, 1, 1);
    // drawBitmapText(example, GLUT_BITMAP_HELVETICA_18, 0, 0, 1, 0, 0);
    // debug("A");
    for (auto box : *activeBoxes) {
        debug("B");
        box->draw();
    }

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(1, -0.95, 1); // set top left to origin
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    /* default to white background */
    glClearColor(1.0, 1.0, 1.0, 1.0);
    activeBoxes = new vector<Box*>();
    startApp();
}

// int startBrowser(int argc, char **argv, vector<LayoutData> ld)
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Andreesen");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();

    return 0;
}
