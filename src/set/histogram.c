/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#include "core/color.h"
#include "set/histogram.h"
#include <stdio.h>
#include <stdlib.h>

#define _root this->root
#define _color this->color
#define _iter this->iteration
#define _sons this->sons
#define _pixels this->numberOfPixels

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

/**
 * A tree set containing colors.
 */
struct histogram {
    int numberOfPixels;
    int numberOfColors;
    Node root;
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
 */
void addColor(Node this, Color color);

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

Histogram newHistogram() {
    Histogram tree;
    tree = malloc(sizeof(struct histogram));
    tree->root = NULL;
    tree->numberOfPixels = 0;
    tree->numberOfColors = 0;
    return tree;
}

void histogramAdd(Histogram this, Color color) {

    if (!_root) {
        _root = newNode(color);
    }

    addColor(_root, color);

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

void addColor(Node this, Color color) {
    int r,g,b;

    if (colorEquales(&_color, &color)) {
        _iter++;
    } else {
        r = color.r > _color.r;
        g = color.g > _color.g;
        b = color.b > _color.b;

        if (!_sons[r][g][b]) {
            _sons[r][g][b] = newNode(color);
        } else {
            addColor(_sons[r][g][b], color);
        }
    }
}

void nodeDisplay(Node this) {
    int i,j, k;

    if (!this) {
        return;
    }

    printf("r %d g %d b %d iteration %d\n", _color.r, _color.g, _color.b, _iter);
    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                nodeDisplay(_sons[i][j][k]);
            }
        }
    }
}

void histogramDisplay(Histogram this) {
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