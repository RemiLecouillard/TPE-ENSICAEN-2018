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
#include <image/image.h>


int main(int argc, char *argv[]) {
    Histogram colors;
    clock_t start, end;
    image input;

    /* parameter's check up */

    if (argc < 2) {
        fprintf(stderr, "No image parameter specified\n");
        return 1;
    }

    start = clock();

    input = FAIRE_image();

    image_charger(input, argv[1]);

    colors = readImage(input);

    end = clock();

    histogramDisplay(colors);

    printf("\nImage successfully parsed.\n"
           "Took %lf s to perform.\n"
           "%d pixels in the image.\n"
           "%d differents colors in the image.\n", ((float)end - start) / CLOCKS_PER_SEC,
           histogramGetNumberOfPixels(colors), histogramGetNumberOfColors(colors));

    /* freeing the memory */

    DEFAIRE_image(input);

    histogramDelete(colors);

    return 0;
}
