#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Categoria
{
  char nombre[50];
  struct Categoria* siguiente;
}Categoria;


typedef struct Tarea
{
  char descripcion[500];
  char categoria[50];
  char hora[20];
  struct Tarea* siguiente;
}Tarea;


typedef struct Cola
{
  Tarea* front;
  Tarea* last;
}Cola;


Categoria* crearCategoria(char nombre[])
{
  Categoria* nueva = malloc(sizeof(Categoria));
  strcpy(nueva->nombre, nombre);
  nueva->siguiente = NULL;
  return nueva;
}

void agregarCategoria (Categoria** lista, char nombre[])
{
  Categoria* nueva= crearCategoria(nombre);
  if(*lista == NULL)
  {
    *lista = nueva;
    return;
  }
  Categoria* temp = *lista;
  while(temp->siguiente != NULL)
    {
      temp = temp->siguiente;
    }
  temp->siguiente = nueva;
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


