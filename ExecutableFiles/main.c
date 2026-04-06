#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funciones.h"
#include "complement.h"

int main()
{
  Categoria* listaCategorias = NULL;
  printf("Bienvenido al administrador de tareas.\n");

  menuPrincipal(&listaCategorias);

  printf("Muchas gracias, hasta luego.\n");
  
  return 0;  
}