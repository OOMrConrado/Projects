#include <stdio.h>
#include "../include/matriz.h"

int main() {
    Matriz* traslacion_matriz = traslacion(2.0, 3.0);
    Matriz* rotacion_matriz = rotacion(45.0);
    Matriz* escalado_matriz = escalado(2.0, 2.0);

    printf("Matriz de traslacion:\n");
    imprimir_matriz(traslacion_matriz);

    printf("\nMatriz de rotacion:\n");
    imprimir_matriz(rotacion_matriz);

    printf("\nMatriz de escalado:\n");
    imprimir_matriz(escalado_matriz);

    liberar_matriz(traslacion_matriz);
    liberar_matriz(rotacion_matriz);
    liberar_matriz(escalado_matriz);

    return 0;
}