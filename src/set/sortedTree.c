/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#include <malloc.h>
#include "set/sortedTree.h"

#define _root this->root
#define _left this->left
#define _right this->right
#define _color this->value
#define _iter this->iteration
#define _k this->k
#define _nbElements this->nbElements
#define _minValue this->minValue
#define IS_MIN_VALUE -1

typedef struct sortedNode *SortedNode;

struct sortedNode {
    int iteration;
    Color value;
    SortedNode left;
    SortedNode right;
};

struct sortedTree {
    SortedNode root;
    int k;
    int nbElements;
    int minValue;
};

SortedNode newSortedNode(Color color, int iteration);

void sortedNodeAdd(SortedNode this, Color color, int iteration);

int nodeDeleteMinValue(SortedNode this);

void sortedNodeDisplay(SortedNode this);

SortedTree newSortedTree(int k) {
    SortedTree this;

    this = malloc(sizeof(struct sortedTree));

    _k = k;
    _root = NULL;
    _nbElements = 0;
    _minValue = 0;

    return this;
}

void sortedTreeAddColor(SortedTree this, Color color, int iteration) {

    if (_nbElements >= _k && iteration <= _minValue) {
        /* An element that we are sure won't fit in the tree */
        return;
    }

    if (_root) {
        sortedNodeAdd(_root, color, iteration);
        _nbElements += 1;

        if (_nbElements > _k) {
            _minValue = sortedTreeDeleteMinValue(this);
            _nbElements -= 1;
        } else if (iteration < _minValue) {
            _minValue = iteration;
        }

    } else {
        _root = newSortedNode(color, iteration);
        _nbElements += 1;
        _minValue = iteration;
    }

}

void sortedTreeDisplay(SortedTree this) {
    sortedNodeDisplay(_root);
}

int sortedTreeDeleteMinValue(SortedTree this) {
    int min;

    if(!_root)
        return 0;

    min = nodeDeleteMinValue(_root);

    if (min == IS_MIN_VALUE) {
        free(_root);
        _root = _root->right;
        return _root ? _root->iteration : 0;
    }

    return min;
}

int nodeDeleteMinValue(SortedNode this) {
    int min;

    if (!this)
        return 0;

    if (!_left)
        return IS_MIN_VALUE;

    min = nodeDeleteMinValue(_left);

    if (min == IS_MIN_VALUE) {
        free(_left);
        _left = _left->right;
        return _iter;
    }

    return min;

}

void sortedTreeDelete(SortedTree this) {

}

SortedNode newSortedNode(Color color, int iteration) {
    SortedNode this;

    this = malloc(sizeof(struct sortedNode));

    _color = color;
    _iter = iteration;

    _left = NULL;
    _right = NULL;

    return this;
}

void sortedNodeAdd(SortedNode this, Color color, int iteration) {
    if (_iter > iteration) {
        if (_left) {
            sortedNodeAdd(_left, color, iteration);
        } else {
            _left = newSortedNode(color, iteration);
        }
    } else {
        if (_right) {
            sortedNodeAdd(_right, color, iteration);
        } else {
            _right = newSortedNode(color, iteration);
        }
    }
}

void sortedNodeDisplay(SortedNode this) {

    if (!this) {
        return;
    }

    sortedNodeDisplay(_left);
    printf("%d %d %d %d\n", _color.r, _color.g, _color.b, _iter);
    sortedNodeDisplay(_right);

}