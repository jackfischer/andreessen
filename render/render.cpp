#include "render.h"

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

void drawBitmapText(const char *string, float x, float y, float z)
{
    const char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 1, 1);

    // glBegin(GL_QUADS);
    //     glTexCoord2f(0, 1); glVertex2f(-2, -1);
    //     glTexCoord2f(1, 1); glVertex2f(2, -1);
    //     glTexCoord2f(1, 0); glVertex2f(2, 1);
    //     glTexCoord2f(0, 0); glVertex2f(-2, 1);
    // glEnd();
    //
    drawBitmapText(example, 0, 0, 0);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, 0, -10);
    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Andreesen");
    glutInitWindowSize(1000, 700);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();

    return 0;
}
