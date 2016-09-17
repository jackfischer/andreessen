#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "imagetools.h"

unsigned char *loadPPM(const char *filename, int &width, int &height)
{
    const int BUFSIZE = 512;
    FILE *fp;
    unsigned int read;
    unsigned char *rawData;
    char buf[3][BUFSIZE];
    char *retval_fgets;
    size_t retval_sscanf;

    fp = fopen(filename, "rb");

    if (!fp) {
        std::cerr << "ppm file does not exist " << filename << std::endl;
        width = height = 0;
        return NULL;
    }

    retval_fgets = fgets(buf[0], BUFSIZE, fp);

    /* get width and height */
    do {
        retval_fgets=fgets(buf[0], BUFSIZE, fp);
    } while (buf[0][0] == '#');

    retval_sscanf=sscanf(buf[0], "%s %s", buf[1], buf[2]);
    width  = atoi(buf[1]);
    height = atoi(buf[2]);

    /* read maxval */
    do {
        retval_fgets=fgets(buf[0], BUFSIZE, fp);
    } while (buf[0][0] == '#');

    /* Read image data */
    rawData = new unsigned char[width * height * 3];
    read = fread(rawData, width * height * 3, 1, fp);
    fclose(fp);
    if (read != 1) {
        std::cerr << "corrupt ppm" << std::endl;
        delete[] rawData;
        width = height = 0;
        return NULL;
    }

    return rawData;
}
