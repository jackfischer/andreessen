#ifndef LAYOUTDATA_H
#define LAYOUTDATA_H

/*
 * Frame Tree data encapsulation class
 */

#include <array>

class LayoutData {
    public:

        bool block = true;

        int voff = 0; //vertical offset
        int hoff = 0; //horizontal offset

        int width = 0;
        int height = 0;

        std::array<int, 3> topColor;
        std::array<int, 3> bottomColor;

        const char* text = "wut";
        int textsize = 2;
        bool image = false;

};


#endif
