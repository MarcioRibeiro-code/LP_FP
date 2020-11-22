/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 23:06
 */

#define t 2

#ifndef LIB_H
#define LIB_H

void obter_dados(int matr[t][t]) {

    int aux;

    for (int x = 0; x < t; x++) {
        for (int y = 0; y < t; y++) {

            printf("\nValor: ");
            scanf("%i", &aux);
            matr[x][y] = aux;
        }



    }
}

void max(int matr[t][t]) {

    int a, max;
    for (int x = 0; x < t; x++) {

        for (int y = 0; y < t; y++) {

            a = matr[x][y];
            if (a > max) {
                max = a;
            }

        }
    }
    printf("\n\nMax: %i", max);
}

void min(int matr[t][t]) {
    int a, min;
    for (int x = 0; x < t; x++) {

        for (int y = 0; y < t; y++) {

            a = matr[x][y];
            if (a < min) {
                min = a;
            }
        }
    }
    printf("\nMin: %i", min);
}

    void escrevermatriz(int a[t][t]) {
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) printf("%3d", a[i][0]);
            printf("\n");
        }
    }

#endif /* LIB_H */

