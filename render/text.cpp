#include "text.h"

void drawBitmapText(const char *string, void *font, int x, int y, float r, float g, float b)
{
    glRasterPos2f(x, y);

    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glEnd();

    const char *c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
