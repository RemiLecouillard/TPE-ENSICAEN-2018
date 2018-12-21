//
// Created by remi on 17/12/18.
//

#ifndef TPE_ENSICAEN_2018_COLORTREE_H
#define TPE_ENSICAEN_2018_COLORTREE_H

#include "histogram/color.h"

/**
 *
 */
typedef struct colorTree *ColorTree;

/**
 *
 * @return
 */
ColorTree newColorTree();

/**
 * Adds a color to the tree. Increments its iteration by 1 if already in it.
 * @param tree
 * @param color
 */
void colorTreeAdd(ColorTree this, Color color);

/**
 * Gives the number of iteration of the color in the tree.
 * @param tree
 * @param color
 * @return The number of iteration
 */
int colorTreeGetIteration(ColorTree this, Color color);

/**
 * Displayes the elements
 * @param this
 */
void colorTreeDisplay(ColorTree this);

/**
 *
 * @param this
 * @param color
 * @return
 */
Color colorTreeGiveNearestColor(ColorTree this, Color color);


#endif //TPE_ENSICAEN_2018_COLORTREE_H
