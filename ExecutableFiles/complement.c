#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

typedef struct Node
{
  void *data;
  Node *next;
  Node *prev;
}Node;

typedef struct List
{
  Node *head;
  Node *tail;
  Node *current;
}List;

typedef struct Cola
{
  Tarea* front;
  Tarea* last;
}Cola;

Node* createNode(void *data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

List* createList()
{
  List* newList = (List*) malloc(sizeof(List));
  newList->head = NULL;
  newList->tail = NULL;
  newList->current = NULL;
  return newList;
}