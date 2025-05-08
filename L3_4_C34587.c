#include <stdio.h>

void imprimirBinario(int n) {
    int binario[32];  
    int i = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binario[i] = n % 2;  
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

int main() {
    int n;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Ingrese un número positivo.\n");
    } else {
        printf("Representación binaria de %d: ", n);
        imprimirBinario(n);
printf("\n");
    }

    return 0;
}