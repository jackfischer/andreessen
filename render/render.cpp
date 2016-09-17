#include "render.h"

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, 2, -2);
    glMatrixMode(GL_MODELVIEW);
}

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

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Andreesen");
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100, 100);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    loadtex();
    init();
    glutMainLoop();

    return 0;
}
