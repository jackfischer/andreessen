#ifndef LAYOUTDATA_H
#define LAYOUTDATA_H

/*
 * Frame Tree data encapsulation class
 */


class LayoutData {
    public:

        bool block = true;

        int voff = 0; //vertical offset
        int hoff = 0; //horizontal offset

        int width = 0;
        int height = 0;

        int topColor[3];
        int bottomColor[3];

        char* text;

};


#endif
