#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/matriz.h" //para incluir el contenido del archivo cabecera matriz.h

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Matriz* crear_matriz(int filas, int columnas) {
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    matriz->filas = filas;
    matriz->columnas = columnas;
    matriz->datos = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz->datos[i] = (int*)malloc(columnas * sizeof(int));
    }
    return matriz;
}

void liberar_matriz(Matriz* matriz) {
    for (int i = 0; i < matriz->filas; i++) {
        free(matriz->datos[i]);
    }
    free(matriz->datos);
    free(matriz);
}

Matriz* sumar_matrices(Matriz* a, Matriz* b) {
    if (a->filas != b->filas || a->columnas != b->columnas) return NULL;
    Matriz* resultado = crear_matriz(a->filas, a->columnas);
    for (int i = 0; i < a->filas; i++) {
        for (int j = 0; j < a->columnas; j++) {
            resultado->datos[i][j] = a->datos[i][j] + b->datos[i][j];
        }
    }
    return resultado;
}

Matriz* restar_matrices(Matriz* a, Matriz* b) {
    if (a->filas != b->filas || a->columnas != b->columnas) return NULL;
    Matriz* resultado = crear_matriz(a->filas, a->columnas);
    for (int i = 0; i < a->filas; i++) {
        for (int j = 0; j < a->columnas; j++) {
            resultado->datos[i][j] = a->datos[i][j] - b->datos[i][j];
        }
    }
    return resultado;
}

Matriz* multiplicar_matrices(Matriz* a, Matriz* b) {
    if (a->columnas != b->filas) return NULL;
    Matriz* resultado = crear_matriz(a->filas, b->columnas);
    for (int i = 0; i < a->filas; i++) {
        for (int j = 0; j < b->columnas; j++) {
            resultado->datos[i][j] = 0;
            for (int k = 0; k < a->columnas; k++) {
                resultado->datos[i][j] += a->datos[i][k] * b->datos[k][j];
            }
        }
    }
    return resultado;
}

Matriz* transponer_matriz(Matriz* matriz) {
    Matriz* resultado = crear_matriz(matriz->columnas, matriz->filas);
    for (int i = 0; i < matriz->filas; i++) {
        for (int j = 0; j < matriz->columnas; j++) {
            resultado->datos[j][i] = matriz->datos[i][j];
        }
    }
    return resultado;
}

void imprimir_matriz(Matriz* matriz) {
    for (int i = 0; i < matriz->filas; i++) {
        for (int j = 0; j < matriz->columnas; j++) {
            printf("%d ", matriz->datos[i][j]);
        }
        printf("\n");
    }
}

Matriz* crear_matriz_identidad(int n) {
    Matriz* matriz = crear_matriz(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz->datos[i][j] = (i == j) ? 1 : 0;
        }
    }
    return matriz;
}

Matriz* traslacion(float tx, float ty) {
    Matriz* matriz = crear_matriz_identidad(3);
    matriz->datos[0][2] = tx;
    matriz->datos[1][2] = ty;
    return matriz;
}

Matriz* rotacion(float angulo) {
    Matriz* matriz = crear_matriz_identidad(3);
    float radianes = angulo * M_PI / 180.0;
    matriz->datos[0][0] = cos(radianes);
    matriz->datos[0][1] = -sin(radianes);
    matriz->datos[1][0] = sin(radianes);
    matriz->datos[1][1] = cos(radianes);
    return matriz;
}

Matriz* escalado(float sx, float sy) {
    Matriz* matriz = crear_matriz_identidad(3);
    matriz->datos[0][0] = sx;
    matriz->datos[1][1] = sy;
    return matriz;
}