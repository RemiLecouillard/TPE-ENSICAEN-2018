//
// Created by remi on 16/12/18.
//

#include "histogram/color.h"
#include "set/histogram.h"
#include <stdio.h>
#include <stdlib.h>

#define _root this->root
#define _color this->color
#define _iter this->iteration
#define _sons this->sons

typedef struct node *Node;

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

struct histogram {
    Node root;
};

Node newNode(Color color);

void addColor(Node this, Color color);

int nodeIteration(Node this, Color color);

Color nodeNearestColor(Node this, Color color);


Histogram newHistogram() {
    Histogram tree;
    tree = malloc(sizeof(struct histogram));
    tree->root = NULL;
    return tree;
}

void histogramAdd(Histogram this, Color color) {

    if (!_root) {
        _root = newNode(color);
    }

    addColor(_root, color);

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

void display(Node this) {
    int i,j, k;

    if (!this) {
        return;
    }

    printf("r %d g %d b %d iteration %d\n", _color.r, _color.g, _color.b, _iter);
    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 2; j ++) {
            for (k = 0; k < 2; k ++) {
                display(_sons[i][j][k]);
            }
        }
    }
}

void histogramDisplay(Histogram this) {
    display(_root);
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