/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 13 de novembro de 2020, 10:52
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 3

/*
 * 
 */

void somamatriz(int a[TAMANHO][TAMANHO], int b[TAMANHO][TAMANHO], int c[TAMANHO][TAMANHO]) {
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            c[x][y] = a[x][y] + b[x][y];
        }
    }
}

void escrevermatriz(int a[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) printf("%3d", a[i][j]);
        printf("\n");
    }
}

void somatorio(int a[TAMANHO][TAMANHO], int aux) {
    aux=0;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            aux += a[i][j];
        }
    }
    printf("Somatorio: %i",aux);
}

int main() {

    int matriz1[TAMANHO][TAMANHO], matriz2[TAMANHO][TAMANHO], res[TAMANHO][TAMANHO];
    int aux;

    //Matriz 1
    printf("Matriz 1\n");
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            printf("Valor: ");
            scanf("%i", &aux);
            matriz1[x][y] = aux;
        }
    }
    system("clear");

    //Matriz 2
    printf("Matriz 2\n");
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            printf("Valor: ");
            scanf("%i", &aux);
            matriz2[x][y] = aux;
        }
    }
    system("clear");
    //funçao soma matriz
    somamatriz(matriz1, matriz2, res);
    //funçao escrever soma_matriz
    escrevermatriz(res);
    //somatorio de res
    somatorio(res, aux);


    return 0;
}

