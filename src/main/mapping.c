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
    clock_t start, end;
    int k;

    start = clock();
    if (argc < 2) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    if (argc == 3) {
        k = atoi(argv[2]);
    } else {
        k = 10;
    }

    sortedTree = newSortedTree(k);
    tree = readImage(argv[1]);

    histogramBegin(tree);

    while(histogramNext(tree)) {
        sortedTreeAddColor(sortedTree, histogramCurrentColor(tree), histogramCurrentIteration(tree));
    }

    sortedTreeDisplay(sortedTree);

    end = clock();

    printf("\nImage successfully parsed.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n", histogramGetNumberOfPixels(tree), histogramGetNumberOfColors(tree));


    printf("Took %lf seconds\n", ((float)(end - start)) / CLOCKS_PER_SEC);
    histogramDelete(tree);

    sortedTreeDelete(sortedTree);

    return 0;
}
