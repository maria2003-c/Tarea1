#ifndef COMPLEMENT_H
#define COMPLEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct List List;

List *list_create();
void *list_first(List *L);
void *list_next(List *L);
void list_pushBack(List *L, void *dato);
void *list_popCurrent(List *L);

#endif