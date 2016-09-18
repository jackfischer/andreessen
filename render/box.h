#ifndef BOX_H
#define BOX_H

#include "render.h"

class Box
{
    private:
        GLint **vertices;
        void *font;
        GLfloat *topcolorf;
        GLfloat *botcolorf;
        GLfloat *textcolorf;
    public:
        Box(int voff, int hoff, int width, int height, int size, int *boxtop, int *boxbottom);
        void draw(void);
};

#endif
