#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[20];
    char telefono[15];
} Contacto; 

void agregar_contacto(Contacto agenda[], int *contador) {
    if (*contador >= 50) {
        printf("Agenda llena.\n");
        return;
    }

    Contacto nuevo;
    printf("Ingrese nombre: ");
    fgets(nuevo.nombre, 20, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0; 
    printf("Ingrese telefono: ");
    fgets(nuevo.telefono, 15, stdin);
    nuevo.telefono[strcspn(nuevo.telefono, "\n")] = 0;

    agenda[*contador] = nuevo;
    (*contador)++;

    FILE *archivo = fopen("agenda.bin", "ab");
    if (archivo) {                   
        fwrite(&nuevo, sizeof(Contacto), 1, archivo);
        fclose(archivo);
        printf("Contacto agregado.\n");
    } else {
        printf("Error al abrir el archivo.\n");
    }
}

void mostrar_contactos(Contacto agenda[], int contador) {
    if (contador == 0) {
        printf("No hay contactos en la agenda.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
    
        printf("Contacto %d: %s - %s\n", i + 1, agenda[i].nombre, agenda[i].telefono);
    }
}   

void eliminar_contacto(Contacto agenda[], int *contador, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < *contador; i++) {
        if (strcmp(agenda[i].nombre, nombre) == 0) {
            encontrado = 1; 
            for (int j = i; j < *contador - 1; j++) {
               
                agenda[j] = agenda[j + 1];
               

            }
            (*contador)--;
            break;
        }
    }
    
    if (encontrado) { 
        FILE *archivo = fopen("agenda.bin", "wb");
        if (archivo) {
            fwrite(agenda, sizeof(Contacto), *contador, archivo);
            fclose(archivo);
            printf("Contacto eliminado.\n");
        } else {
            printf("Error al actualizar el archivo.\n");
        }
    } else {
        printf("Contacto no encontrado.\n");
    }
}

void ordenar_contactos(Contacto agenda[], int contador) { 
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
        
            if (strcmp(agenda[j].nombre, agenda[j + 1].nombre) > 0) {
                
                Contacto temp = agenda[j]; 
                agenda[j] = agenda[j + 1];
                agenda[j + 1] = temp; 
            }
        }
    }
    printf("Contactos ordenados.\n");
}

void cargar_contactos(Contacto agenda[], int *contador) {
    FILE *archivo = fopen("agenda.bin", "rb");
    if (archivo) {
        while (fread(&agenda[*contador], sizeof(Contacto), 1, archivo)) { 
            (*contador)++;
        }
        fclose(archivo);
    }
}

int main() {
    Contacto agenda[100]; 
    int contador = 0;
    int opcion;
    char nombre[20];

    cargar_contactos(agenda, &contador);

    do {
        printf("\nMenu:\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Eliminar contacto\n");
        printf("4. Ordenar contactos\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1) {
            agregar_contacto(agenda, &contador);
        } else if (opcion == 2) {
            mostrar_contactos(agenda, contador);
        } else if (opcion == 3) {
            printf("Ingrese el nombre del contacto a eliminar: ");
            fgets(nombre, 20, stdin);
            nombre[strcspn(nombre, "\n")] = 0;
            eliminar_contacto(agenda, &contador, nombre);
        } else if (opcion == 4) {
            ordenar_contactos(agenda, contador);
            mostrar_contactos(agenda, contador);
        } else if (opcion == 5) {
            printf("Saliendo del programa.\n");
        } else {
            printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}
