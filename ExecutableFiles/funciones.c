#include "funciones.h"

void agregarCategoria(List* listaCategorias) {
    char nombre[50];
    printf("Ingrese el nombre de la nueva categoria: ");
    scanf("%s", nombre);

    Categoria* nueva = (Categoria*)malloc(sizeof(Categoria));
    if (nueva == NULL) return;
    strcpy(nueva->nombre, nombre);
    list_pushBack(listaCategorias, nueva);
    printf("Categoria agregada exitosamente.\n");
}

void eliminarCategoria(List* listaCategorias, List* listaTareas) {
    char nombre[50];
    printf("Ingrese el nombre de la categoria a eliminar: ");
    scanf("%s", nombre);

    Categoria* c = (Categoria*)list_first(listaCategorias);
    bool encontrada = false;
    while (c != NULL) {
        if (strcmp(c->nombre, nombre) == 0) {
            free(list_popCurrent(listaCategorias));
            encontrada = true;
            break;
        }
        c = (Categoria*)list_next(listaCategorias);
    }

    if (!encontrada) {
        printf("Categoria no encontrada.\n");
        return;
    }

    Tarea* t = (Tarea*)list_first(listaTareas);
    while (t != NULL) {
        if (strcmp(t->categoria, nombre) == 0) {
            free(list_popCurrent(listaTareas));
            t = (Tarea*)list_first(listaTareas);
        } else {
            t = (Tarea*)list_next(listaTareas);
        }
    }
    printf("Categoria y sus tareas eliminadas.\n");
}

void registrarTarea(List* listaCategorias, List* listaTareas) {
    char catNombre[50];
    printf("Ingrese categoria: ");
    scanf("%s", catNombre);

    bool existe = false;
    Categoria* c = (Categoria*)list_first(listaCategorias);
    while (c != NULL) {
        if (strcmp(c->nombre, catNombre) == 0) {
            existe = true;
            break;
        }
        c = (Categoria*)list_next(listaCategorias);
    }

    if (!existe) {
        printf("Error: La categoria no existe.\n");
        return;
    }

    Tarea* nueva = (Tarea*)malloc(sizeof(Tarea));
    if (nueva == NULL) return;

    printf("Ingrese descripcion: ");
    getchar();
    fgets(nueva->descripcion, 500, stdin);
    nueva->descripcion[strcspn(nueva->descripcion, "\n")] = 0;
    strcpy(nueva->categoria, catNombre);

    time_t t_now = time(NULL);
    struct tm tm = *localtime(&t_now);
    sprintf(nueva->hora, "%02d:%02d", tm.tm_hour, tm.tm_min);

    list_pushBack(listaTareas, nueva);
    printf("Tarea registrada.\n");
}

void atenderSiguiente(List* listaTareas) {
    Tarea* t = (Tarea*)list_first(listaTareas);
    if (t == NULL) {
        printf("¡Libre de pendientes!\n");
        return;
    }

    printf("Atendiendo: %s | Categoria: %s | Registrada a las: %s\n", 
           t->descripcion, t->categoria, t->hora);
    free(list_popCurrent(listaTareas));
}

void mostrarTablero(List* listaTareas) {
    Tarea* t = (Tarea*)list_first(listaTareas);
    if (t == NULL) {
        printf("No hay pendientes.\n");
        return;
    }

    printf("\n=== TABLERO GENERAL ===\n");
    while (t != NULL) {
        printf("[%s] %s (%s)\n", t->hora, t->descripcion, t->categoria);
        t = (Tarea*)list_next(listaTareas);
    }
}

void filtrarPorCategoria(List* listaTareas) {
    char nombre[50];
    printf("Ingrese categoria a consultar: ");
    scanf("%s", nombre);

    Tarea* t = (Tarea*)list_first(listaTareas);
    bool hayTareas = false;
    while (t != NULL) {
        if (strcmp(t->categoria, nombre) == 0) {
            printf("[%s] %s\n", t->hora, t->descripcion);
            hayTareas = true;
        }
        t = (Tarea*)list_next(listaTareas);
    }

    if (!hayTareas) printf("No hay tareas en esta categoria.\n");
}