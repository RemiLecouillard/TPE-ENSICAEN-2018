/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#ifndef TPE_ENSICAEN_2018_COLORTREE_H
#define TPE_ENSICAEN_2018_COLORTREE_H

#include "core/color.h"

/**
 *
 */
typedef struct histogram *Histogram;

/**
 *
 * @return
 */
Histogram newHistogram();

/**
 * Adds a color to the histogram. Increments its iteration by 1 if already in it.
 * @param this
 * @param color
 */
void histogramAdd(Histogram this, Color color);

/**
 * Gives the number of iteration of the color in the tree.
 * @param this
 * @param color
 * @return The number of iteration
 */
int histogramGetIteration(Histogram this, Color color);

/**
 * Displays the elements
 * @param this
 */
void histogramDisplay(Histogram this);

/**
 *
 * @param this
 * @param color
 * @return
 */
Color histogramGiveNearestColor(Histogram this, Color color);

/**
 * Gives the number of pixels.
 * @param this
 * @return
 */
int histogramGetNumberOfPixels(Histogram this);

/**
 * Free the histogram from the memory.
 * @param this
 */
void histogramDelete(Histogram this);

#endif //TPE_ENSICAEN_2018_COLORTREE_H
