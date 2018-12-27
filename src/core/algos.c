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


#include <image/image.h>
#include "core/algos.h"


Histogram readImage(image img) {
    int* pixel;
    Color color;
    Histogram histo;

    image_debut(img);
    histo = newHistogram();

    do {
        pixel = image_lire_pixel(img);

        color = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        histogramAdd(histo, color);
    }while (image_pixel_suivant(img));

    return histo;
}

SortedTree quantification(Histogram hist, int k) {
    SortedTree sortedTree;

    sortedTree = newSortedTree(k);

    histogramBegin(hist);

    while(histogramNext(hist)) {
        sortedTreeAddColor(sortedTree, histogramCurrentColor(hist), histogramCurrentIteration(hist));
    }

    return sortedTree;
}

void mapping(image input,image output, SortedTree colors) {
    Histogram histogram;
    Color inputColor, outputColor;
    int *pixel;

    /* Create an histogram only with the selected colors */
    histogram = newHistogram();

    sortedTreeBegin(colors);

    while(sortedTreeNext(colors)) {
        histogramAdd(histogram, sortedTreeCurrentColor(colors));
    }

    /* create the output image */

    image_initialize(output, image_give_dim(input), image_give_largeur(input), image_give_hauteur(input));

    image_debut(input);
    image_debut(output);

    do {
        pixel = image_lire_pixel(input);

        inputColor = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        outputColor = histogramGiveNearestColor(histogram, inputColor);
        pixel[0] = outputColor.r;
        pixel[1] = outputColor.g;
        pixel[2] = outputColor.b;
        image_ecrire_pixel(output, pixel);
    }while (image_pixel_suivant(output) && image_pixel_suivant(input));

    histogramDelete(histogram);
}