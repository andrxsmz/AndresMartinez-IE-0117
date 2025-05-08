#include <stdio.h>

#define MAX_SIZE 10

void sumarDiagonales(int matriz[MAX_SIZE][MAX_SIZE], int n) {
    printf("Sumas de diagonales principales:\n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        for (int i = 0; i < n; i++) {
            int j = d - i;
            if (j >= 0 && j < n) {
                suma += matriz[i][j];
            }
        }
        printf("Diagonal %d: %d\n", d + 1, suma);
    }

    printf("\nSumas de diagonales secundarias : \n");
    for (int d = 0; d < 2 * n - 1; d++) {
        int suma = 0;
        for (int i = 0; i < n; i++) {
            int j = (n - 1) - (d - i);
            if (j >= 0 && j < n) {
                suma += matriz[i][j];
            }
        }
        printf("Diagonal %d: %d\n", d + 1, suma);
    }
}

void imprimir_matriz(int matriz[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz1[MAX_SIZE][MAX_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("Matriz 3x3:\n");
    imprimir_matriz(matriz1, 3);
    sumarDiagonales(matriz1, 3);

    int matriz2[MAX_SIZE][MAX_SIZE] = {
        {1, 2},
        {3, 4}
    };
    printf("\nMatriz 2x2:\n");
    imprimir_matriz(matriz2, 2);
    sumarDiagonales(matriz2, 2);

    int matriz3[MAX_SIZE][MAX_SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    printf("\nMatriz 4x4:\n");
    imprimir_matriz(matriz3, 4);
    sumarDiagonales(matriz3, 4);

    return 0;
}