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
 * @file color.c
 * @author Rémi Lecouillard
 * @author Nicolas Weber
 */

#include <stdlib.h>
#include <stdio.h>
#include "core/color.h"

Color createColor(unsigned char r, unsigned char g, unsigned char b) {
    Color c;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}

Color* newColor(unsigned char r, unsigned char g, unsigned char b) {
    Color *c;
    c = malloc(sizeof(Color));
    c->r = r;
    c->g = g;
    c->b = b;
    return c;
}

int colorEquals(Color *c1, Color *c2) {
    Color *a, *b;
    a = c1;
    b = c2;
    return a->b == b->b && a->g == b->g && a->r == b->r;
}

void colorDisplay(Color c) {
    printf("r: %d g: %d b: %d", c.r, c.g, c.b);
}