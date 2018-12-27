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

#include "core/color.h"
#include "set/histogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <Queue.h>

#define _root this->root
#define _color this->color
#define _iter this->iteration
#define _sons this->sons
#define _pixels this->numberOfPixels
#define _nbColors this->numberOfColors
#define _current this->iterator.current
#define _queue this->iterator.queue

/**
 * A pointer of the structure node.
 */
typedef struct node *Node;

/**
 * A node of the tree set histogram.
 * Contains a color, its number of iterations and its sons.
 */
struct node {
    Color color;
    int iteration;
    /**
     * Index 0 means less than
     * Index 1 means greater than
     * The first dimension corresponds to red
     * The second to green.
     * The third to blue.
     */
    Node sons[2][2][2];
};

struct iterator {
    Queue queue;
    Node current;
};

/**
 * A tree set containing colors.
 */
struct histogram {
    int numberOfPixels;
    int numberOfColors;
    Node root;
    struct iterator iterator;
};

/**
 * Malloc a new Node with the given color.
 * Giving it 1 iteration.
 * @param color
 * @return
 */
Node newNode(Color color);

/**
 * Adds an iteration of the given color. If not present in the tree create a new Node.
 * @param this
 * @param color
 * @return 1 if a color had been added. 0 otherwise.
 */
int addColor(Node this, Color color);

/**
 * Gives the number of iteration of the given color.
 * @param this
 * @param color
 * @return the number of iteration.
 */
int nodeIteration(Node this, Color color);

/**
 * Gives the nearest color in the tree.
 * @param this
 * @param color
 * @return The nearest color.
 */
Color nodeNearestColor(Node this, Color color);

/**
 * Displays the color of the node with its iterations, along with all its sons.
 * @param this
 */
void nodeDisplay(Node this);

/**
 * Removes the node from the memory along with its sons.
 * @param this
 */
void nodeDeletes(Node this);

/**
 * Adds all the nodes to the queue.
 * @param this
 * @param queue
 */
void nodeAddToQueue(Node this, Queue queue);

Histogram newHistogram() {
    Histogram tree;
    tree = malloc(sizeof(struct histogram));
    tree->root = NULL;
    tree->numberOfPixels = 0;
    tree->numberOfColors = 0;
    tree->iterator.current = NULL;
    tree->iterator.queue = NULL;
    return tree;
}

void histogramAdd(Histogram this, Color color) {

    if (!_root) {
        _root = newNode(color);
    }

    _nbColors += addColor(_root, color);

    _pixels++;

}

int histogramGetIteration(Histogram this, Color color) {
    return nodeIteration(_root, color);
}

Color histogramGiveNearestColor(Histogram this, Color color) {
    return nodeNearestColor(_root, color);
}

Node newNode(Color color) {
    Node this;
    int i,j,k;
    this = malloc(sizeof(struct node));
    _color = color;
    _iter = 1;

    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                _sons[i][j][k] = NULL;
            }
        }
    }
    return this;
}

int addColor(Node this, Color color) {
    int r,g,b;

    if (colorEquales(&_color, &color)) {
        _iter++;
        return 0;
    } else {
        r = color.r > _color.r;
        g = color.g > _color.g;
        b = color.b > _color.b;

        if (!_sons[r][g][b]) {
            _sons[r][g][b] = newNode(color);
            return 1;
        } else {
            return addColor(_sons[r][g][b], color);
        }
    }
}

void nodeDisplay(Node this) {
    int i,j, k;

    if (!this) {
        return;
    }

    printf("| %3d | %3d | %3d | %3d | %d\n", _color.r, _color.g, _color.b, (_color.b + _color.g + _color.r)/3, _iter);
    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                nodeDisplay(_sons[i][j][k]);
            }
        }
    }
}

void histogramDisplay(Histogram this) {
    printf("|  r  |  g  |  b  | lum | Iteration(s)\n");
    nodeDisplay(_root);
}

int nodeIteration(Node this, Color color) {
    int r,g,b;

    if (colorEquales(&_color, &color)) {
        return _iter;
    }

    r = color.r > _color.r;
    g = color.g > _color.g;
    b = color.b > _color.b;

    if (!_sons[r][g][b]) {
        return 0;
    } else {
        return nodeIteration(_sons[r][g][b], color);
    }
}

Color nodeNearestColor(Node this, Color color) {
    int r,g,b;

    if (colorEquales(&_color, &color)) {
        return _color;
    }

    r = color.r > _color.r;
    g = color.g > _color.g;
    b = color.b > _color.b;

    if (!_sons[r][g][b]) {
        return _color;
    } else {
        return nodeNearestColor(_sons[r][g][b], color);
    }
}

int histogramGetNumberOfPixels(Histogram this) {
    return _pixels;
}

void histogramDelete(Histogram this) {
    nodeDeletes(_root);
    free(this);
}

int histogramGetNumberOfColors(Histogram this) {
    return _nbColors;
}

void nodeDeletes(Node this) {
    int i,j,k;

    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                if (_sons[i][j][k] != NULL) {
                    nodeDeletes(_sons[i][j][k]);
                }
            }
        }
    }
    free(this);
}

void nodeAddToQueue(Node this, Queue queue) {
    int i,j,k;

    QueueAdd(queue, this);

    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                if (_sons[i][j][k] != NULL) {
                    nodeAddToQueue(_sons[i][j][k], queue);
                }
            }
        }
    }
}

void histogramBegin(Histogram this) {
    if (_queue) {
        QueueDelete(_queue);
    }
    _queue = newQueue();
    nodeAddToQueue(_root, _queue);
}

int histogramNext(Histogram this) {
    if (!_queue) {
        return 0;
    }

    _current = QueuePop(_queue);

    if (!_current) {
        /* If there's no elements left */
        return 0;
    }

    return 1;
}

Color histogramCurrentColor(Histogram this) {
    if (_current)
        return _current->color;
    /* Arbitrary color when there's no current element */
    return createColor(0,0,0);
}

int histogramCurrentIteration(Histogram this) {
    if (_current)
        return _current->iteration;
    return 0;
}
