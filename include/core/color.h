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
 * @file color.h
 * @author Rémi Lecouillard
 * @author Nicolas Weber
 */

#ifndef TPE_ENSICAEN_2018_COLOR_H
#define TPE_ENSICAEN_2018_COLOR_H

struct color{
    /** red */
    unsigned char r;
    /** green */
    unsigned char g;
    /** blue */
    unsigned char b;
};

/**
 * A color discribed by red, green and blue.
 */
typedef struct color Color;

/**
 * Creates a color
 * @param r red
 * @param g green
 * @param b blue
 * @return A color with the given parameters.
 */
Color createColor(unsigned char r, unsigned char g, unsigned char b);

/**
 * Creates a new color on the heap.
 * @param r red
 * @param g green
 * @param b blue
 * @return A pointer of a color with the given parameters.
 */
Color* newColor(unsigned char r, unsigned char g, unsigned char b);

/**
 * Checks if two colors are the same.
 * @param c1
 * @param c2
 * @return 0 if not equals, 1 otherwise.
 */
int colorEquals(Color *c1, Color *c2);

/**
 * Display the color on the standard ouput.
 * @param color
 */
void colorDisplay(Color color);

#endif //TPE_ENSICAEN_2018_COLOR_H
