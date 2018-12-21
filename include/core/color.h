/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

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
