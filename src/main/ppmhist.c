/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#include <set/histogram.h>
#include <util.h>
#include <core/algos.h>
#include <time.h>
#include <image/image.h>


int main(int argc, char *argv[]) {
    Histogram colors;
    clock_t start, end;
    image input;

    /* parameter's check up */

    if (argc < 2) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    start = clock();

    input = FAIRE_image();

    image_charger(input, argv[1]);

    colors = readImage(input);

    end = clock();

    histogramDisplay(colors);

    printf("\nImage successfully parsed.\n"
           "Took %lf s to perform.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n", ((float)end - start) / CLOCKS_PER_SEC,
           histogramGetNumberOfPixels(colors), histogramGetNumberOfColors(colors));

    /* freeing the memory */

    DEFAIRE_image(input);

    histogramDelete(colors);

    return 0;
}
