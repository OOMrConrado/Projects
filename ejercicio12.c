#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CADENAS 100
#define LONGITUD_MAX 100

void convertirAMayusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

int main() {
    int n;
    char cadenas[MAX_CADENAS][LONGITUD_MAX];

    printf("Ingresa la cantidad de cadenas: ");
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        printf("Ingresa la cadena %d: ", i + 1);
        fgets(cadenas[i], LONGITUD_MAX, stdin);
        cadenas[i][strcspn(cadenas[i], "\n")] = '\0'; 
    }

    for (int i = 0; i < n; i++) {
        convertirAMayusculas(cadenas[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(cadenas[i], cadenas[j]) > 0) {
                char temp[LONGITUD_MAX];
                strcpy(temp, cadenas[i]);
                strcpy(cadenas[i], cadenas[j]);
                strcpy(cadenas[j], temp);
            }
        }
    }

    printf("Cadenas en mayusculas y ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", cadenas[i]);
    }

    printf("Presiona Enter para continuar...");
    while (getchar() != '\n'); 
    getchar();

    return 0;
}