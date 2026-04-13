#include "complement.h"

typedef struct Node Node;

struct Node {
    void *data;
    Node *next;
    Node *prev;
};

struct List {
    Node *head;
    Node *tail;
    Node *current;
    size_t size;
};

List* list_create() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) return NULL;
    newList->head = NULL;
    newList->tail = NULL;
    newList->current = NULL;
    newList->size = 0;
    return newList;
}

void *list_first(List *L) {
    if (L == NULL || L->head == NULL) return NULL;
    L->current = L->head;
    return L->current->data;
}

void *list_next(List *L) {
    if (L == NULL || L->current == NULL || L->current->next == NULL) return NULL;
    L->current = L->current->next;
    return L->current->data;
}

void list_pushBack(List *L, void *dato) {
    if (L == NULL) return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = dato;
    newNode->next = NULL;
    if (L->tail == NULL) {
        newNode->prev = NULL;
        L->head = newNode;
        L->tail = newNode;
    } else {
        newNode->prev = L->tail;
        L->tail->next = newNode;
        L->tail = newNode;
    }
    L->size++;
}

void *list_popCurrent(List *L) {
    if (L == NULL || L->current == NULL) return NULL;
    Node *aux = L->current;
    void *data = aux->data;

    if (aux->prev != NULL) aux->prev->next = aux->next;
    else L->head = aux->next;

    if (aux->next != NULL) aux->next->prev = aux->prev;
    else L->tail = aux->prev;

    L->current = aux->next;
    free(aux);
    L->size--;
    return data;
}