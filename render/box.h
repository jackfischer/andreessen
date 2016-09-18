#ifndef BOX_H
#define BOX_H

#include "render.h"
#include "../images/loadimage.h"

class Box
{
    private:
        GLint **vertices;
        void *font;
        const char *text;
        GLfloat *topcolorf;
        GLfloat *botcolorf;
        GLfloat *textcolorf;
        bool image;
        GLuint texture;
    public:
        Box(const char *text, bool image, int voff, int hoff, int width, int height,
                int size, int *boxtop, int *boxbottom);
        ~Box();
        void draw(void);
};

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
#endif
