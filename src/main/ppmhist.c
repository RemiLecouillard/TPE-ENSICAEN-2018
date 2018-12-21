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


int main(int argc, char *argv[]) {
    Histogram tree;
    clock_t start, end;

    if (argc < 2) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    start = clock();
    tree = readImage(argv[1]);
    end = clock();

    histogramDisplay(tree);

    histogramDelete(tree);

    printf("\nImage successfully parsed.\n"
           "Took %lf s to perform.\n", ((float)end - start) / CLOCKS_PER_SEC);
    return 0;
}
