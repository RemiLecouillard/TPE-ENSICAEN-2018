
#include <util.h>

#ifndef TPE_ENSICAEN_2018_COLOR_H
#define TPE_ENSICAEN_2018_COLOR_H

struct color{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

typedef struct color Color;

Color createColor(unsigned char r, unsigned char g, unsigned char b);

Color* newColor(unsigned char r, unsigned char g, unsigned char b);

int colorEquales(T c1, T c2);

void colorDisplay(T color);

#endif //TPE_ENSICAEN_2018_COLOR_H
