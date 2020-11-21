/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 21:44
 */

#define n_aluno 4
#define n_notas 2

#ifndef LIB_H
#define LIB_H

void obter_dados(int matriz_aluno[n_aluno][n_notas]) {

    int aux;

    for (int x = 0; x < n_aluno; x++) {
        printf("\n\nAluno %i", x + 1);
        for (int y = 0; y < n_notas; y++) {
            printf("\nNota 0-20: ");
            scanf("%i", &aux);
            while (aux < 0 || aux > 20) {
                printf("\nValor invalido");
                printf("\nNota 0-20: ");
                scanf("%i", &aux);
            }


            matriz_aluno[x][y] = aux;
        }
    }
    system("clear");


}

void media(int a[n_aluno][n_notas]) {
    int aux = 0;
    int i;
    for (i = 0; i < n_aluno; i++) {
        for (int j = 0; j < n_notas; j++) {
            aux += a[i][j];
        }
    }
    printf("media: %i", (aux / (i * n_notas)));
}

void escrevermatriz(int a[n_aluno][n_notas]) {
    for (int i = 0; i < n_aluno; i++) {
        for (int j = 0; j < n_notas; j++) printf("%3d", a[i][j]);
        printf("\n");
    }
}

#endif /* LIB_H */

