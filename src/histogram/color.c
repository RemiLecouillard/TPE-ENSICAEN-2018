/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
#include <stdlib.h>
#include <stdio.h>
#include "histogram/color.h"

Color createColor(unsigned char r, unsigned char g, unsigned char b) {
    Color c;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}

Color* newColor(unsigned char r, unsigned char g, unsigned char b) {
    Color *c;
    c = malloc(sizeof(Color));
    c->r = r;
    c->g = g;
    c->b = b;
    return c;
}

int colorEquales(Color *c1, Color *c2) {
    Color *a, *b;
    a = c1;
    b = c2;
    return a->b == b->b && a->g == b->g && a->r == b->r;
}

void colorDisplay(Color color) {
    Color c;
    c = *(Color*)color;
    printf("r: %d g: %d b: %d", c.r, c.g, c.b);
}