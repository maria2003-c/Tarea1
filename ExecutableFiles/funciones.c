#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "complement.h"


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
  strcpy(nueva->nombre, nombre);
  nueva->next = NULL;
  nueva->prev = NULL;
  return nueva;
}

void agregarCategoria (List* list, char nombre[])
{
  Categoria* nueva = crearCategoria(nombre);
  if(listIsEmpty(list))
  {
    list->head = nueva;
    list->current = list->head;
  }
  else{
    if(list->current == NULL){
      return;  
    }
    list->current->next = nueva;
    if(list->current == list->tail){
      list->tail = nueva;
    }
  }
  list->size++;
}


void mostrarCategorias(Categoria* lista)
{
  while(lista != NULL)
    {
      printf("- %s\n", lista->nombre);
      lista = lista->siguiente;
    }
}

void menuPrincipal(){
  printf("Opciones disponibles:\n");
  printf("1. Agregar una categoria nueva.\n");
  printf("2. Eliminar una categoria existente.\n");
  printf("3. Opciones con las tareas.\n");
  printf("4. Mostrar categorias.\n");
  printf("0. Salir\n");
  printf("Ingrese la opcion a realizar: ");

  int opcion;
  scanf("%d", &opcion);
  do{
    switch(opcion){
      case 1:{
        printf("Ingrese el nombre de la categoria a crear:");
        char categoria[50];
        scanf("%s", &categoria);
        agregarCategoria(categoria);
        printf("Categoria Agregada");
        break;
      }
      case 2:{
        
        break;
      }
      case 3:{
        
        break;
      }
      case 4:{
        
        break;
      }
      case 0:{
        printf("adios");
        break;
      }
      default:{
        printf("opcion no valida");
      }
    }
  }while(opcion != 0);
}


