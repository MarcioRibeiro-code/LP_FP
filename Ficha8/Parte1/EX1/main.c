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
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "aluno.h"
#include "input.h"
/*
 * 
 */
int main() {
    int total_registos,menu;
    ALUNOS alunos[ALUNOS_MAX];
    
    FILE *fp;

    do {

        printf("\n\nMENU");
        printf("\n1- Inserir");
        printf("\n2- Listar todos");
        printf("\n3- Consultar um aluno");
        printf("\n4- Atualizar dados aluno");
        printf("\n5- Eliminar dados aluno");
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
                fp = fopen(FILENAME, "rb");
                if (alunos != NULL) {
                    total_registos = fread(alunos, sizeof (ALUNOS), ALUNOS_MAX, fp);
                    if (total_registos != alunos[0].contador) {
                        puts("Lista Vazia");
                    } else if (total_registos == 0) {
                        alunos[0].contador = 0;
                    }
                    else {
                        printf("total: %d\n", alunos[0].contador);
                    }
                }
                fclose(fp);
                break;
                
            case 7:
                fp = fopen(FILENAME, "wb");
                fwrite(alunos, sizeof (ALUNOS), alunos[0].contador , fp);
                fclose(fp);
                puts("Gravado com sucesso");
                break;
                
            case 0:
                exit(1);

        }
    } while (menu != 0);

    //inserir(&aluno);
    // imprimir(aluno);
    return 0;
}

