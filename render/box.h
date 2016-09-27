#ifndef BOX_H
#define BOX_H

#include "render.h"
#include "../images/loadimage.h"
#include <vector>
#include <array>

struct Point
{
    GLint x;
    GLint y;
};

class Box
{
    private:
        std::vector<Point> vertices;
        void *font;
        const char *text;
        GLdouble *topcolord;
        GLdouble *botcolord;
        GLdouble *textcolord;
        bool image;
        GLuint texture;
    public:
        Box(const char *text, bool image, int voff, int hoff, int width,
            int height, int size, const std::array<int, 3>& boxtop,
            const std::array<int, 3>& boxbottom);
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
