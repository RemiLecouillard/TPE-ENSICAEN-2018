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


Histogram readImage(image img) {
    int* pixel;
    Color color;
    Histogram histo;

    image_debut(img);
    histo = newHistogram();

    do {
        pixel = image_lire_pixel(img);

        color = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        histogramAdd(histo, color);
    }while (image_pixel_suivant(img));

    return histo;
}

SortedTree quantification(Histogram hist, int k) {
    SortedTree sortedTree;

    sortedTree = newSortedTree(k);

    histogramBegin(hist);

    while(histogramNext(hist)) {
        sortedTreeAddColor(sortedTree, histogramCurrentColor(hist), histogramCurrentIteration(hist));
    }

    return sortedTree;
}

void mapping(image input,image output, SortedTree colors) {
    Histogram histogram;
    Color inputColor, outputColor;
    int *pixel;

    /* Create an histogram only with the selected colors */
    histogram = newHistogram();

    sortedTreeBegin(colors);

    while(sortedTreeNext(colors)) {
        histogramAdd(histogram, sortedTreeCurrentColor(colors));
    }

    /* create the output image */

    image_initialize(output, image_give_dim(input), image_give_largeur(input), image_give_hauteur(input));

    image_debut(input);
    image_debut(output);

    do {
        pixel = image_lire_pixel(input);

        inputColor = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        outputColor = histogramGiveNearestColor(histogram, inputColor);
        pixel[0] = outputColor.r;
        pixel[1] = outputColor.g;
        pixel[2] = outputColor.b;
        image_ecrire_pixel(output, pixel);
    }while (image_pixel_suivant(output) && image_pixel_suivant(input));

    histogramDelete(histogram);
}