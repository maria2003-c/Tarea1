#ifndef COMPLEMENT_H
#define COMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node Node;

typedef struct List List;

typedef struct Cola Cola;

Node* createNode(void *data);

List* createList();

#endif 