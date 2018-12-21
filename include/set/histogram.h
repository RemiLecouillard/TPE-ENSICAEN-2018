//
// Created by remi on 17/12/18.
//

#ifndef TPE_ENSICAEN_2018_COLORTREE_H
#define TPE_ENSICAEN_2018_COLORTREE_H

#include "histogram/color.h"

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
 * Displayes the elements
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


#endif //TPE_ENSICAEN_2018_COLORTREE_H
