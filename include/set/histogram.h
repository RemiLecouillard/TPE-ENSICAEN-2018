/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
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
 * Gives the number of differents colors in the histogram.
 * @param this
 * @return
 */
int histogramGetNumberOfColors(Histogram this);

/**
 * Puts the iterator at the beginning.
 * @param this
 */
void histogramBegin(Histogram this);

/**
 * Moves the iterator to the next element.
 * @param this
 * @return 0 if there's no more elements, 1 otherwise.
 */
int histogramNext(Histogram this);

/**
 * Gives the current Color of the iterator.
 * @param this
 * @return
 */
Color histogramCurrentColor(Histogram this);

/**
 * Gives the number of iteration of the current color of the iterator.
 * @param this
 * @return
 */
int histogramCurrentIteration(Histogram this);

/**
 * Free the histogram from the memory.
 * @param this
 */
void histogramDelete(Histogram this);

#endif //TPE_ENSICAEN_2018_COLORTREE_H
