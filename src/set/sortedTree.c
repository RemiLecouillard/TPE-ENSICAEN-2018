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
 * @file sortedTree.c
 * @author Rémi Lecouillard
 * @author Nicolas Weber
 */

#include <malloc.h>
#include <Queue.h>
#include "set/sortedTree.h"

#define _root this->root
#define _left this->left
#define _right this->right
#define _color this->value
#define _iter this->iteration
#define _k this->k
#define _nbElements this->nbElements
#define _minValue this->minValue
#define _current this->iterator.current
#define _queue this->iterator.queue

#define IS_MIN_VALUE -1

/**
 * A pointer of a sortedNode.
 */
typedef struct sortedNode *SortedNode;

/**
 * A node of the SortedTree.
 */
struct sortedNode {
    int iteration;
    Color value;
    SortedNode left;
    SortedNode right;
};

/**
 * An iterator to browse the tree.
 */
struct iterator {
    Queue queue;
    SortedNode current;
};

/**
 * A binary tree of colors, sorted by their number of iteration.
 * With a maximum number of colors in it.
 * Keeps only the most common colors.
 */
struct sortedTree {
    /** the root node */
    SortedNode root;
    /** the iterator */
    struct iterator iterator;
    /** the max number of elements */
    int k;
    /** the number of elements in the tree. */
    int nbElements;
    /** the min value of iteration */
    int minValue;
};

/**
 * Creates a new SortedNode on the heap.
 * @param color
 * @param iteration
 * @return
 */
SortedNode newSortedNode(Color color, int iteration);

/**
 *
 * @param this
 * @param color
 * @param iteration
 */
void sortedNodeAdd(SortedNode this, Color color, int iteration);

/**
 *
 * @param this
 * @return
 */
int nodeDeleteMinValue(SortedNode this);

/**
 *
 * @param this
 */
void sortedNodeDisplay(SortedNode this);

/**
 *
 * @param this
 * @param Queue
 */
void sortedNodeAddToQueue(SortedNode this, Queue Queue);

/**
 *
 * @param this
 */
void sortedNodeDelete(SortedNode this);

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


void sortedTreeBegin(SortedTree this) {
    if (_queue) {
        QueueDelete(_queue);
    }
    _queue = newQueue();
    sortedNodeAddToQueue(_root, _queue);
}

void sortedNodeAddToQueue(SortedNode this, Queue queue) {

    if (!this)
        return;
    sortedNodeAddToQueue(_left, queue);
    QueueAdd(queue, this);
    sortedNodeAddToQueue(_right, queue);

}

int sortedTreeNext(SortedTree this) {
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

Color sortedTreeCurrentColor(SortedTree this) {
    if (_current)
        return _current->value;
    /* Arbitrary color when there's no current element */
    return createColor(0,0,0);
}

int sortedTreeCurrentIteration(SortedTree this) {
    if (_current)
        return _current->iteration;
    return 0;
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
    sortedNodeDelete(_root);
    free(this);
}

void sortedNodeDelete(SortedNode this) {
    if (!this)
        return;
    sortedNodeDelete(_left);
    sortedNodeDelete(_right);
    free(this);
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