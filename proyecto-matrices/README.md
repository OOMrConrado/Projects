# Proyecto de Transformaciones Geométricas con Matrices

Este proyecto implementa transformaciones geométricas en gráficos 2D utilizando matrices. Las transformaciones incluyen traslación, rotación y escalado. El programa crea matrices de transformación, las imprime en la consola y luego libera la memoria asignada para estas matrices.

# Estructura del Proyecto


#### `include/matriz.h`
Este archivo contiene las definiciones de las estructuras y las declaraciones de las funciones utilizadas para manejar matrices y realizar transformaciones geometricas.

#### `src/matriz.c`
Este archivo contiene las implementaciones de las funciones declaradas en `matriz.h`. Incluye funciones para crear matrices, liberar memoria, imprimir matrices y realizar transformaciones geométricas (traslación, rotación y escalado).

#### `src/main.c`
Este archivo contiene la función principal del programa. Crea matrices de transformación, las imprime en la consola y luego libera la memoria asignada para estas matrices.

### Contenido de `src/main.c`

```c
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

Para compilar esto debes seguir los siguente pasos ;)