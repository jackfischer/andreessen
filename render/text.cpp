#include "text.h"

void drawBitmapText(const char *string, void *font, int x, int y, float r, float g, float b)
{
    glRasterPos2f(x, y+8);

    const char *c;
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
