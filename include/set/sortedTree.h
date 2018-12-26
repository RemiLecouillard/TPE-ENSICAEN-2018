/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#ifndef TPE_ENSICAEN_2018_SORTEDTREE_H
#define TPE_ENSICAEN_2018_SORTEDTREE_H

#include <core/color.h>

typedef struct sortedTree *SortedTree;

/**
 *
 * @param k
 * @return
 */
SortedTree newSortedTree(int k);

/**
 *
 * @param this
 * @param color
 * @param iteration
 */
void sortedTreeAddColor(SortedTree this, Color color, int iteration);

/**
 *
 * @param this
 */
void sortedTreeDisplay(SortedTree this);

/**
 *
 * @param this
 * @return
 */
int sortedTreeDeleteMinValue(SortedTree this);

#endif //TPE_ENSICAEN_2018_SORTEDTREE_H
