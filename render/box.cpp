#include "box.h"

Box::Box(int voff, int hoff,
        int width, int height,
        int size, int *topcolori, int *botcolori)
{
    /* initialize vertices for box */
    vertices = new GLint*[2];
    for (int i = 0; i < 2; ++i) {
        vertices[i] = new GLint[4];
    }
    vertices[0][0] = hoff;
    vertices[0][1] = voff;
    vertices[1][0] = hoff;
    vertices[1][1] = voff + height;
    vertices[2][0] = hoff + width;
    vertices[2][1] = voff + height;
    vertices[3][0] = hoff + width;
    vertices[3][1] = voff;

    /* set font size */
    font = (size == 1) ? GLUT_BITMAP_HELVETICA_10
        : (size == 2) ? GLUT_BITMAP_HELVETICA_12
        : (size == 3) ? GLUT_BITMAP_HELVETICA_18
        : GLUT_BITMAP_HELVETICA_12;

    topcolorf = new GLfloat [3];
    botcolorf = new GLfloat [3];
    textcolorf = new GLfloat [3];

    /* set div and font color */
    for (int i = 0; i < 3; ++i) {
        topcolorf[i] = topcolori[i] / 255;
        botcolorf[i] = botcolori[i] / 255;
        textcolorf[i] = 0; //perhaps add color later with CSS
    }

}
