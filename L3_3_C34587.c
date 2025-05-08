#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO 8

void llenar_matriz_aleatoria(int matriz[TAMANO][TAMANO]) {
    srand(time(NULL));  
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            matriz[i][j] = rand() % 2;  
        }
    }
}

void imprimir_matriz(int matriz[TAMANO][TAMANO]) {
    printf("Matriz generada:\n");
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    } 
}

int encontrar_diagonal_mas_larga(int matriz[TAMANO][TAMANO]) {
    int maximo1 = 0;
    int diagonal = 0;

    //Recorre las diagonales que empiezan en la primer fila 
    for (int k = 0; k < TAMANO; k++) {
        for (int i = 0, j = k; i < TAMANO && j >= 0; i++, j--) {
            if (matriz[i][j] == 1) {
                diagonal++;
                if (diagonal > maximo1)
                    maximo1 = diagonal;
            } else {
                diagonal = 0;
            }
        }
    }

    // REcorre las diagonales que empizan en la ultima columna
    for (int k = 1; k < TAMANO; k++) {
        for (int i = k, j = TAMANO - 1; i < TAMANO && j >= 0; i++, j--) {
            if (matriz[i][j] == 1) {
                diagonal++;
                if (diagonal > maximo1)
                    maximo1 = diagonal;
            } else {
                diagonal = 0;
            }
        }
    }

    return maximo1;
}


int main() {
    int matriz[TAMANO][TAMANO];
    
    llenar_matriz_aleatoria(matriz);
    imprimir_matriz(matriz);

    int diagonal_mas_larga = encontrar_diagonal_mas_larga(matriz);
    printf("La secuencia de 1s más grande es: %d\n", diagonal_mas_larga);

    return 0;
}