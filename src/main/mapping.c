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


int main(int argc, char *argv[]) {
    Histogram tree;
    SortedTree sortedTree;
    if (argc < 2) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    sortedTree = newSortedTree(20);
    tree = readImage(argv[1]);

    histogramBegin(tree);

    while(histogramNext(tree)) {
        sortedTreeAddColor(sortedTree, histogramCurrentColor(tree), histogramCurrentIteration(tree));
    }

    printf("\nImage successfully parsed.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n", histogramGetNumberOfPixels(tree), histogramGetNumberOfColors(tree));

    histogramDelete(tree);

    return 0;
}
