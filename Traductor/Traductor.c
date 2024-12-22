#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_TRADUCCIONES 50

typedef struct {
    char espanol[MAX_LEN];
    char ingles[MAX_LEN];
} Traduccion;

void cargarDiccionario(Traduccion diccionario[], int *n) {
    FILE *dicFile = fopen("Diccionario.txt", "r");
    if (dicFile == NULL) {
        printf("Error al abrir el archivo de diccionario.\n");
        exit(1);
    }
    *n = 0;
    while (fscanf(dicFile, "%s %s", diccionario[*n].espanol, diccionario[*n].ingles) != EOF) {
        (*n)++;
    }
    fclose(dicFile);
}

void traducirTexto(char *texto, Traduccion diccionario[], int n) {
    for (int i = 0; i < n; i++) {
        char *goku = strstr(texto, diccionario[i].espanol);
        while (goku != NULL) {
            
            strncpy(goku, diccionario[i].ingles, strlen(diccionario[i].ingles));
            
           
            for (int j = strlen(diccionario[i].ingles); j < strlen(diccionario[i].espanol); j++) {
                goku[j] = ' ';
            }

            
            goku = strstr(goku + strlen(diccionario[i].ingles), diccionario[i].espanol);
        }
    }
}

int main() {
    FILE *entrada = fopen("Espanol.txt", "r");
    FILE *salida = fopen("ingles.txt", "w");
    if (entrada == NULL) {
        printf("Error al abrir Espanol.txt.\n");
        return 1;
    }
    if (salida == NULL) {
        printf("Error al abrir ingles.txt.\n");
        fclose(entrada);
        return 1;
    }

    Traduccion diccionario[MAX_TRADUCCIONES];
    int numTraducciones;
    cargarDiccionario(diccionario, &numTraducciones);

    char linea[MAX_LEN];
    while (fgets(linea, sizeof(linea), entrada)) {
        traducirTexto(linea, diccionario, numTraducciones);
        fputs(linea, salida);
    }

    fclose(entrada);
    fclose(salida);

    printf("Traduccion completada y guardada en ingles.txt.\n");
    printf("Presiona enter para continuar...\n");
    getchar();  
    return 0;
}
