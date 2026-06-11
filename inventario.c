#include <stdio.h>

typedef struct {
    int codigo;
    char nombre[50];
    char marca[50];
    float precio;
    char estado[20];
} Equipo;

int main() {
    int opcion;
    Equipo inventario[100];
    int totalEquipos = 0;

    do {
        printf("\n--- Sistema de Inventario ---\n");
        printf("1. Registrar equipo\n");
        printf("2. Mostrar equipo registrado\n");
        printf("3. Modificar equipo\n");
        printf("4. Eliminar equipo\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\n--- Registrar Equipo ---\n");
                printf("Codigo: ");
                scanf("%d", &inventario[totalEquipos].codigo);
                printf("Nombre: ");
                scanf("%s", inventario[totalEquipos].nombre);
                printf("Marca: ");
                scanf("%s", inventario[totalEquipos].marca);
                printf("Precio: ");
                scanf("%f", &inventario[totalEquipos].precio);
                printf("Estado (Ej: Nuevo, Usado): ");
                scanf("%s", inventario[totalEquipos].estado);
                totalEquipos++;
                printf("Equipo registrado con exito!\n");
                break;
            case 2: 
                printf("Opcion 2\n"); 
                break;
            case 3: 
                printf("Opción 3\n"); 
                break;
            case 4: 
                printf("Opcion 4\n"); 
                break;
            case 5: 
                printf("Opcion 5\n"); 
                break;
            default: 
                printf("Error\n");
        }
    } while(opcion != 5);

    return 0;
}