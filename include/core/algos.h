/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#ifndef TPE_ENSICAEN_2018_ALGOS_H
#define TPE_ENSICAEN_2018_ALGOS_H

#include "set/histogram.h"
#include "set/sortedTree.h"
#include "image/image.h"

/**
 *
 * @param img
 * @return
 */
Histogram readImage(image img);

/**
 *
 * @param hist
 * @param k number of colors too kepp
 * @return
 */
SortedTree quantification(Histogram hist, int k);

/**
 *
 * @param input
 * @param output
 * @param colors
 */
void mapping(image input,image output, SortedTree colors);

#endif //TPE_ENSICAEN_2018_ALGOS_H
