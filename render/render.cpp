#include "render.h"
#include <iostream>
using std::cout;
using std::endl;

const char *example = "Look at my pretty fonts";
// void loadtex()
// {
//     GLuint texture;
//     int w, h;
//     unsigned char *data;

//     data = loadPPM("../images/test.ppm", w, h);

//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);
//     glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

void drawBitmapText(const char *string, int x, int y, int size, float r, float g, float b)
{
    glRasterPos2f(x, y);

    glBegin(GL_POLYGON);
        glColor3f(r, g, b);
    glEnd();

    void *character = (size == 1) ? GLUT_BITMAP_HELVETICA_10
        : (size == 2) ? GLUT_BITMAP_HELVETICA_12
        : (size == 3) ? GLUT_BITMAP_HELVETICA_18
        : GLUT_BITMAP_HELVETICA_12;

    const char *c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(character, *c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBitmapText(example, 0, 0, 1, 1, 0, 0);
    drawBitmapText(example, 0, 5, 2, 1, 1, 1);
    drawBitmapText(example, 0, 10, 3, 1, 1, 0);
    drawBitmapText(example, 0, 15, 4, 0, 1, 1);

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(1, -0.95, 1);
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    const unsigned char *a = (unsigned char *)"W";
    cout << glutBitmapLength(GLUT_BITMAP_HELVETICA_10, a) << endl;
    cout << glutBitmapLength(GLUT_BITMAP_HELVETICA_12, a) << endl;
    cout << glutBitmapLength(GLUT_BITMAP_HELVETICA_18, a) << endl;

}

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
