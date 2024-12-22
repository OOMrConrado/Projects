#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int filas;
    int columnas;
    int** datos;
} Matriz;

Matriz* crear_matriz(int filas, int columnas);
void liberar_matriz(Matriz* matriz);
Matriz* sumar_matrices(Matriz* a, Matriz* b);
Matriz* restar_matrices(Matriz* a, Matriz* b);
Matriz* multiplicar_matrices(Matriz* a, Matriz* b);
Matriz* transponer_matriz(Matriz* matriz);
void imprimir_matriz(Matriz* matriz);
Matriz* crear_matriz_identidad(int n);
Matriz* traslacion(float tx, float ty);
Matriz* rotacion(float angulo);
Matriz* escalado(float sx, float sy);

#endif
