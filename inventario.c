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
                printf("Opcion 1 en construccion...\n"); 
                break;
            case 2: 
                printf("Opcion 2 en construccion...\n"); 
                break;
            case 3: 
                printf("Modificar equipo (Pendiente)\n"); 
                break;
            case 4: 
                printf("Eliminar equipo (Pendiente)\n"); 
                break;
            case 5: 
                printf("Saliendo del sistema...\n"); 
                break;
            default: 
                printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    return 0;
}