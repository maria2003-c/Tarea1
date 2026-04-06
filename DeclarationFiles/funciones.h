#ifndef FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FUNCIONES_H

typedef struct Categoria Categoria;
typedef struct Tarea Tarea;

Categoria* crearCategoria(char nombre[]);

void agregarCategoria(Categoria** lista, char nombre[]);

void mostrarCategorias(Categoria* lista);

void menuPrincipal(Categoria** lista);


#endif