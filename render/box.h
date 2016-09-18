#ifndef BOX_H
#define BOX_H

#include "render.h"

class Box
{
    private:
        GLint **vertices;
        void *font;
        const char *text;
        GLfloat *topcolorf;
        GLfloat *botcolorf;
        GLfloat *textcolorf;
    public:
        Box(const char *text, int voff, int hoff, int width, int height, int size, int *boxtop, int *boxbottom);
        ~Box();
        void draw(void);
};

#endif
