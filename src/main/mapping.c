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

#include <set/histogram.h>
#include <util.h>
#include <core/algos.h>
#include <time.h>
#include <set/sortedTree.h>
#include <image/image.h>


int main(int argc, char *argv[]) {
    Histogram histogram;
    SortedTree sortedColors;
    clock_t start, end;
    image input, output;
    int k;

    start = clock();

    /* parameter's check up */
    if (argc < 3) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    if (argc == 4) {
        k = atoi(argv[3]);
    } else {
        k = 10;
    }

    input = FAIRE_image();
    output = FAIRE_image();

    image_charger(input, argv[1]);

    histogram = readImage(input);

    sortedColors = quantification(histogram, k);

    mapping(input, output, sortedColors);

    image_sauvegarder(output, argv[2]);
    end = clock();

    printf("\nImage successfully parsed.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n"
           "Took %lf seconds\n",
           histogramGetNumberOfPixels(histogram), histogramGetNumberOfColors(histogram),
           ((float)(end - start)) / CLOCKS_PER_SEC);

    /* Freeing the memory */
    DEFAIRE_image(output);

    DEFAIRE_image(input);

    histogramDelete(histogram);

    sortedTreeDelete(sortedColors);

    return 0;
}
