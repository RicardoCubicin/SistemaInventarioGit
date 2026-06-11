#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int codigo;
    char nombre[50];
    char marca[50];
    float precio;
    char estado[20];
} Equipo;

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int esSoloLetras(char cadena[]) {
    if (strlen(cadena) == 0) return 0;
    for (int i = 0; i < strlen(cadena); i++) {
        if (!isalpha(cadena[i]) && cadena[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int main() {
    int opcion;
    Equipo inventario[100];
    int totalEquipos = 0;
    int datoValido = 0; 
    do {
        printf("\n--- Sistema de Inventario ---\n");
        printf("1. Registrar equipo\n");
        printf("2. Mostrar equipo registrado\n");
        printf("3. Modificar equipo\n");
        printf("4. Eliminar equipo\n");
        printf("5. Salir\n");
        printf("Ingrese una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            limpiarBuffer();
            opcion = 0; 
        }

        switch(opcion) {
            case 1:
                printf("\n--- Registrar Equipo ---\n");
                datoValido = 0;
                do {
                    printf("Codigo: ");
                    if (scanf("%d", &inventario[totalEquipos].codigo) != 1) {
                        printf("Error: Ingrese solo digitos validos.\n");
                        limpiarBuffer(); // Limpia las letras incorrectas del buffer
                    } else {
                        datoValido = 1;
                        limpiarBuffer();
                    }
                } while (!datoValido);
                datoValido = 0;
                do {
                    printf("Nombre: ");
                    fgets(inventario[totalEquipos].nombre, 50, stdin);
                    inventario[totalEquipos].nombre[strcspn(inventario[totalEquipos].nombre, "\n")] = 0; // Quita el salto de linea
                    
                    if (esSoloLetras(inventario[totalEquipos].nombre)) {
                        datoValido = 1;
                    } else {
                        printf("Error: Ingrese solo letras.\n");
                    }
                } while (!datoValido);
                datoValido = 0;
                do {
                    printf("Marca: ");
                    fgets(inventario[totalEquipos].marca, 50, stdin);
                    inventario[totalEquipos].marca[strcspn(inventario[totalEquipos].marca, "\n")] = 0;
                    
                    if (esSoloLetras(inventario[totalEquipos].marca)) {
                        datoValido = 1;
                    } else {
                        printf("Error: Ingrese solo letras.\n");
                    }
                } while (!datoValido);
                datoValido = 0;
                do {
                    printf("Precio: ");
                    if (scanf("%f", &inventario[totalEquipos].precio) != 1) {
                        printf("Error: Ingrese solo digitos validos.\n");
                        limpiarBuffer();
                    } else {
                        datoValido = 1;
                        limpiarBuffer();
                    }
                } while (!datoValido);
                datoValido = 0;
                do {
                    printf("Estado: ");
                    fgets(inventario[totalEquipos].estado, 20, stdin);
                    inventario[totalEquipos].estado[strcspn(inventario[totalEquipos].estado, "\n")] = 0;
                    
                    if (esSoloLetras(inventario[totalEquipos].estado)) {
                        datoValido = 1;
                    } else {
                        printf("Error: Ingrese solo letras.\n");
                    }
                } while (!datoValido);

                totalEquipos++;
                printf("Equipo registrado con exito!\n");
                break;

            case 2:
                printf("\n--- Mostrar Equipos Registrados ---\n");
                if (totalEquipos == 0) {
                    printf("No hay equipos registrados.\n");
                } else {
                    for(int i = 0; i < totalEquipos; i++) {
                        printf("\nCodigo: %d | Nombre: %s | Marca: %s | Precio: %.2f | Estado: %s\n", 
                               inventario[i].codigo, inventario[i].nombre, inventario[i].marca, 
                               inventario[i].precio, inventario[i].estado);
                    }
                }
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
                if(opcion != 0) printf("Opcion invalida.\n");
        }
    } while(opcion != 5);

    return 0;
}