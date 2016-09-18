#include "box.h"
#include "text.h"
#include "../images/loadimage.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::vector;

#define debug(s) cerr << s << endl

Box::Box(const char *text, bool image, int voff, int hoff,
        int width, int height,
        int size, int *topcolori, int *botcolori)
{
    // debug(111);
    this->text = text;
    // debug(112);
    this->image = image;
    // debug(113);

    /* initialize vertices for box */
    vertices = vector<Point>();

    vertices.push_back({hoff, voff});
    vertices.push_back({hoff, voff + height});
    vertices.push_back({hoff + width, voff + height});
    vertices.push_back({hoff + width, voff});

    /* set font size */
    font = (size == 1) ? GLUT_BITMAP_HELVETICA_10
        : (size == 2) ? GLUT_BITMAP_HELVETICA_12
        : (size == 3) ? GLUT_BITMAP_HELVETICA_18
        : GLUT_BITMAP_HELVETICA_12;
    // debug(125);

    topcolord = new GLdouble [3];
    // debug(126);
    botcolord = new GLdouble [3];
    // debug(127);
    textcolord = new GLdouble [3];
    // debug(128);

    /* set div and font color */
    for (int i = 0; i < 3; ++i) {
        // debug(129);
        topcolord[i] = ((GLdouble) topcolori[i])/ 255;
        // debug(130);
        botcolord[i] = ((GLdouble) botcolori[i])/ 255;
        // debug(131);
        textcolord[i] = 0.0; //perhaps add color later with CSS
        // debug(132);
    }
    // debug(133);
}

Box::~Box()
{
    delete [] topcolord;
    delete [] botcolord;
    delete [] textcolord;
}

void Box::draw(void)
{
    // debug(1);
    glBegin(GL_POLYGON);
    // debug(2);
    glColor3f(topcolord[0], topcolord[1], topcolord[2]);
    // debug(3);
    glVertex2i(vertices[0].x, vertices[0].y);
    // debug(4);
    glVertex2i(vertices[1].x, vertices[1].y);
    // debug(5);
    glColor3f(botcolord[0], botcolord[1], botcolord[2]);
    // debug(6);
    glVertex2i(vertices[2].x, vertices[2].y);
    // debug(7);
    glVertex2i(vertices[3].x, vertices[3].y);
    // debug(8);
    glColor3f(0.0, 0.0, 0.0);
    glEnd();
    // debug(9);
   
    // debug(vertices[0].x);
    // debug(vertices[0].y);
    // debug(vertices[1].x);
    // debug(vertices[1].y);
    // debug(vertices[2].x);
    // debug(vertices[2].y);
    // debug(vertices[3].x);
    // debug(vertices[4].y);
    // debug(topcolord[0] * 255);
    // debug(topcolord[1] * 255);
    // debug(topcolord[2] * 255);

    if (!image) {
        drawBitmapText(text, font, vertices[0].x, vertices[0].y,
                0.0, 0.0, 0.0);
    }
    // } else {
    //     glBegin(GL_QUADS);
    //     glTexCoord2f()
    //     glEnd();
    // }
}
