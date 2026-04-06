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
  size_t size;
}List;

typedef struct Cola
{
  Tarea* front;
  Tarea* last;
}Cola;

Node* createNode(void *data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL; 
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

List* createList()
{
  List* newList = (List*) malloc(sizeof(List));
  if (newList == NULL) {
    return NULL;
  }
  newList->head = NULL;
  newList->tail = NULL;
  newList->current = NULL;
  newList->size = 0;
  return newList;
}

bool listIsEmpty(List* list){
  if(list->head == NULL){
    return true;
  }
  return false;
}