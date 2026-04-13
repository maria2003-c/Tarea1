#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "complement.h"

typedef struct {
    char nombre[50];
} Categoria;

typedef struct {
    char descripcion[500];
    char categoria[50];
    char hora[20];
} Tarea;

void agregarCategoria(List* listaCategorias);
void eliminarCategoria(List* listaCategorias, List* listaTareas);
void registrarTarea(List* listaCategorias, List* listaTareas);
void atenderSiguiente(List* listaTareas);
void mostrarTablero(List* listaTareas);
void filtrarPorCategoria(List* listaTareas);

#endif