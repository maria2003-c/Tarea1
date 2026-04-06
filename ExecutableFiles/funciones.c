#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "complement.h"

typedef struct Categoria Categoria;

typedef struct Categoria
{
  char name[50];
  Categoria* next;
  Categoria* prev;
}Categoria;


typedef struct Tarea
{
  char descripcion[500];
  char categoria[50];
  char hora[20];
  struct Tarea* siguiente;
}Tarea;

Categoria* crearCategoria(char nombre[])
{
  Categoria* nueva = malloc(sizeof(Categoria));
  strcpy(nueva->name, nombre);
  nueva->next = NULL;
  nueva->prev = NULL;
  return nueva;
}

void agregarCategoria(Categoria** lista, char nombre[])
{
  Categoria* nueva = crearCategoria(nombre);
  if (nueva == NULL) return;

  if (*lista == NULL) {
    *lista = nueva;
  } else {
    Categoria* temp = *lista;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nueva;
    nueva->prev = temp;
  }
}


void mostrarCategorias(Categoria* lista)
{
  if (lista == NULL) {
    printf("No hay categorias disponibles.\n");
    return;
  }
  printf("\n=== CATEGORIAS ===\n");
  while (lista != NULL) {
    printf("- %s\n", lista->name);
    lista = lista->next;
  }
  printf("\n");
}

void menuPrincipal(Categoria** lista){
  int opcion;

  do {
    printf("\n=== MENU PRINCIPAL ===");
    printf("\nOpciones disponibles:\n");
    printf("1. Agregar una categoria nueva.\n");
    printf("2. Eliminar una categoria existente.\n");
    printf("3. Opciones con las tareas.\n");
    printf("4. Mostrar categorias.\n");
    printf("0. Salir\n");
    printf("Ingrese la opcion a realizar: ");
    scanf("%d", &opcion);

    switch(opcion) {
      case 1: {
        printf("Ingrese el nombre de la categoria a crear: ");
        char categoria[50];
        scanf("%s", categoria);
        agregarCategoria(lista, categoria);
        printf("Categoria agregada exitosamente.\n");
        break;
      }
      case 2: {
        break;
      }
      case 3: {
        printf("Opciones con tareas (proximamente).\n");
        break;
      }
      case 4: {
        mostrarCategorias(*lista);
        break;
      }
      case 0: {
        printf("Muchas gracias por usar el administrador de tareas.\n");
        break;
      }
      default: {
        printf("Opcion no valida. Por favor, intente nuevamente.\n");
      }
    }
  } while(opcion != 0);
}


