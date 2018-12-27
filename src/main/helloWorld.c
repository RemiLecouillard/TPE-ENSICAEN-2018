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

#include <stdio.h>
#include <set/histogram.h>
#include <core/color.h>
#include "image/image.h"

Histogram readImage(char* path) {
    int* pixel;
    Color color;
    Histogram tree;
    image img;


    img = FAIRE_image();
    image_charger(img, path);
    image_debut(img);
    tree = newHistogram();

    do {
        pixel = image_lire_pixel(img);

        color = createColor((unsigned char) pixel[0], (unsigned char) pixel[1], (unsigned char) pixel[2]);

        histogramAdd(tree, color);
    }while (image_pixel_suivant(img));

    printf("la\n");

    DEFAIRE_image(img);
    printf("la\n");

    return tree;
}

int main() {
    Histogram tree;
    printf("reading image.. \n");
    tree = readImage("img/fille.ppm");

    printf("displaying colors...\n");
    histogramDisplay(tree);

    Color c = histogramGiveNearestColor(tree, createColor(242, 248, 247));

    printf(" %d %d %d\n", c.r, c.g, c.b);
    histogramDelete(tree);
    return 0;
}
