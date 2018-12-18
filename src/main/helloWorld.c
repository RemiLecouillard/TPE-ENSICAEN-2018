/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
#include <stdio.h>
#include <set/colorTree.h>
#include "image/image.h"

ColorTree readImage(char* path) {
    int* pixel;
    Color color;
    ColorTree tree;
    image img;


    img = FAIRE_image();
    image_charger(img, path);
    image_debut(img);
    tree = newColorTree();

    do {
        pixel = image_lire_pixel(img);

        color = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        colorTreeAdd(tree, color);
    }while (image_pixel_suivant(img));

    printf("la\n");

    DEFAIRE_image(img);
    printf("la\n");

    return tree;
}

int main() {
    ColorTree tree;
    printf("reading image.. \n");
    tree = readImage("img/fille.ppm");

    printf("displaying colors...\n");
    colorTreeDisplay(tree);
    return 0;
}
