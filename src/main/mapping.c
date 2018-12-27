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
#include <set/sortedTree.h>
#include <image/image.h>


int main(int argc, char *argv[]) {
    Histogram histogram;
    SortedTree sortedColors;
    clock_t start, end;
    image input, output;
    int k;

    start = clock();

    /* parameter's check up */
    if (argc < 3) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    if (argc == 4) {
        k = atoi(argv[3]);
    } else {
        k = 10;
    }

    input = FAIRE_image();
    output = FAIRE_image();

    image_charger(input, argv[1]);

    histogram = readImage(input);

    sortedColors = quantification(histogram, k);

    mapping(input, output, sortedColors);

    image_sauvegarder(output, argv[2]);
    end = clock();

    printf("\nImage successfully parsed.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n"
           "Took %lf seconds\n",
           histogramGetNumberOfPixels(histogram), histogramGetNumberOfColors(histogram),
           ((float)(end - start)) / CLOCKS_PER_SEC);

    /* Freeing the memory */
    DEFAIRE_image(output);

    DEFAIRE_image(input);

    histogramDelete(histogram);

    sortedTreeDelete(sortedColors);

    return 0;
}
