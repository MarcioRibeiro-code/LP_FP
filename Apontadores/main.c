/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

/*
 * Demonstração de Apontadores
 */


void swap(int *v1, int *v2) {
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void multiply(int values[], int size, int value) {
    int i;
    for (i = 0; i < size; i++) {
        values[i] *= value;
    }
}

void printArray(int values[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\n%d", values[i]);
    }
}

int *getMax(int *v1, int *v2) {
    return *v1 >= *v2 ? v1 : v2;
}

int main() {

    int val1 = 2, val2 = 11, *ptr, notas[] = {1, 2, 3, 4};

    ptr = &val1;

    printf("Endereço de val1: %p", &val1);
    printf("\nEndereço de val1: %p", ptr);

    printf("\nValor de val1: %d", val1);
    printf("\nValor de val1: %d", *ptr);
    printf("\nValor de val1: %d", *(&val1));

    printf("\nValor de ptr: %p", ptr);
    printf("\nEndereço de ptr: %p", &ptr);

    puts("");

    swap(&val1, &val2);

    printf("\nval1: %d val2: %d", val1, val2);

    puts("");

    multiply(notas, sizeof (notas) / sizeof (int), val2);

    printArray(notas, sizeof (notas) / sizeof (int));

    puts("");

    *(getMax(&val1, &val2)) += 1;

    printf("\nval1: %d val2: %d", val1, val2);

    return 0;
}
