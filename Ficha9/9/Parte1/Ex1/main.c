/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 12 de dezembro de 2020, 21:14
 */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "aluno.h"

/*
 * 
 */
int main() {


    int menu, x;

    ALUNO *alunos = calloc(TAMANHO_INICIAL, sizeof (ALUNO));
    FILE *fp;

    if (alunos == NULL)printf("\nCouldn't allocate memory");

    do {
        printf("\nCONTADOR: %d", alunos[0].contador);
        printf("\n\nMENU");
        printf("\n1- Inserir Aluno");
        printf("\n2- Listar todos os alunos");
        printf("\n3- Consultar aluno");
        printf("\n4- Atualizar dados aluno");
        printf("\n5- Eliminar aluno");
        printf("\n6- Carregar Ficheiro");
        printf("\n7- Imprimir no Ficheiro");
        printf("\n0 - Sair\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                Inserir(alunos);
                break;
            case 2:
                Listar(alunos);
                break;
            case 3:
                Consulta(alunos);
                break;
            case 4:
                Atualizar(alunos);
                break;
            case 5:
                Eliminar(alunos);
                break;
            case 6:
              LerFicheiro_Binario(alunos,fp);  
                break;

            case 7:
                EscreverFicheiro_Binario(alunos,fp);
                break;

            case 0:
                break;

        }
    } while (menu != 0);

    free(alunos);
    return 0;
}

