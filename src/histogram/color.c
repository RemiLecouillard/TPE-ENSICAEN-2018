
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

int colorEquales(T c1, T c2) {
    Color *a, *b;
    a = c1;
    b = c2;
    return a->b == b->b && a->g == b->g && a->r == b->r;
}

void colorDisplay(T color) {
    Color c;
    c = *(Color*)color;
    printf("r: %d g: %d b: %d", c.r, c.g, c.b);
}