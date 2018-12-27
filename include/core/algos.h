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

/**
 * @file algos.h
 * @author Rémi Lecouillard
 * @author Nicolas Weber
 */

#ifndef TPE_ENSICAEN_2018_ALGOS_H
#define TPE_ENSICAEN_2018_ALGOS_H

#include "set/histogram.h"
#include "set/sortedTree.h"
#include "image/image.h"

/**
 * Converts an image to an Histogram
 * @param img
 * @return
 */
Histogram readImage(image img);

/**
 * Select the k colors most present in the histogram
 * @param hist
 * @param k number of colors too kepp
 * @return
 */
SortedTree quantification(Histogram hist, int k);

/**
 * Creates the output image with the input image, but only with the selected colors.
 * @param input
 * @param output
 * @param colors The only colors of the output image.
 */
void mapping(image input,image output, SortedTree colors);

#endif //TPE_ENSICAEN_2018_ALGOS_H
