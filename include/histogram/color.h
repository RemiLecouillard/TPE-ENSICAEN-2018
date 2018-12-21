

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

int colorEquales(Color *c1, Color *c2);

void colorDisplay(Color color);

#endif //TPE_ENSICAEN_2018_COLOR_H
