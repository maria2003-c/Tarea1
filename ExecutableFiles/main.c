#include "funciones.h"

int main() 
{
    List* listaCategorias = list_create();
    List* listaTareas = list_create();
    int opcion;

    printf("Bienvenido al administrador de tareas.\n");

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Nueva Categoria\n");
        printf("2. Eliminar Categoria\n");
        printf("3. Registrar Tarea\n");
        printf("4. Atender Siguiente\n");
        printf("5. Mostrar Tablero\n");
        printf("6. Filtrar por Categoria\n");
        printf("7. Mostrar Categorias\n");
        printf("0. Salir\n");
        printf("Opcion: ");

        if (scanf("%d", &opcion) != 1) break;

        switch(opcion) {
            case 1: agregarCategoria(listaCategorias); break;
            case 2: eliminarCategoria(listaCategorias, listaTareas); break;
            case 3: registrarTarea(listaCategorias, listaTareas); break;
            case 4: atenderSiguiente(listaTareas); break;
            case 5: mostrarTablero(listaTareas); break;
            case 6: filtrarPorCategoria(listaTareas); break;
            case 7: {
                Categoria* c = (Categoria*)list_first(listaCategorias);
                if (!c) printf("No hay categorias.\n");
                while(c) {
                    printf("- %s\n", c->nombre);
                    c = (Categoria*)list_next(listaCategorias);
                }
                break;
            }
        }
    } while (opcion != 0);

    return 0;
}