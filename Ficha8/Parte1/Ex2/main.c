/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: LAPTOP
 *
 * Created on 4 de dezembro de 2020, 09:59
 */

#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "input.h"
/*
 * 
 */
int main() {
    int count=0,menu;
        Alunos alunos = {.contador = 0};
    
   /*
       int op=0;
        do{
            inserir(arluno);
            imprimir(arluno);
            
            printf("\n\nDeseja Sair- 0 Sair\n");
            scanf("%i",&op);
        }while(op!=0);
    */
        

    int opcao;

    do {
        printf("\nLivros------------------------------------------------------");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Atualizar");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nLivros: %d/%d", alunos.contador, ALUNOS_MAX);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirAlunos(&alunos);
                break;
            case 2:
                procurarAlunos(alunos);
                break;
            case 3:
                atualizarAlunos(&alunos);
                break;
            case 4:
                removerAlunos(&alunos);
                break;
            case 5:
                listarAlunos(alunos);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    
    //inserir(&aluno);
 // imprimir(aluno);
    return 0;
}

