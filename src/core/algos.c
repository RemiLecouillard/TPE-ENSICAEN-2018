/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#include <image/image.h>
#include "core/algos.h"


Histogram readImage(char* path) {
    int* pixel;
    Color color;
    Histogram tree;
    image img;


    img = FAIRE_image();
    image_charger(img, path);
    image_debut(img);
    tree = newHistogram();

    do {
        pixel = image_lire_pixel(img);

        color = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        histogramAdd(tree, color);
    }while (image_pixel_suivant(img));

    DEFAIRE_image(img);

    return tree;
}