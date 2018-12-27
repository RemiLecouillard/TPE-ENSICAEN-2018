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

/**
 * Puts the iterator at the beginning.
 * @param this
 */
void sortedTreeBegin(SortedTree this);

/**
 * Moves the iterator to the next element.
 * @param this
 * @return 0 if there's no more elements, 1 otherwise.
 */
int sortedTreeNext(SortedTree this);

/**
 * Gives the current Color of the iterator.
 * @param this
 * @return
 */
Color sortedTreeCurrentColor(SortedTree this);

/**
 * Gives the number of iteration of the current color of the iterator.
 * @param this
 * @return
 */
int sortedTreeCurrentIteration(SortedTree this);

/**
 *
 * @param this
 */
void sortedTreeDelete(SortedTree this);


#endif //TPE_ENSICAEN_2018_SORTEDTREE_H
