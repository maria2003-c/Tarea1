#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funciones.h"
#include "complement.h"

int main()
{
  List* list = createList();
  printf("Bienvenido al administrador de tareas(??");

  menuPrincipal();

  printf("Muchas gracias, hasta luego.");
  
  return 0;  
}