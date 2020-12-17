/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: LAPTOP
 *
 * Created on 4 de dezembro de 2020, 13:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "booklib.h"


/*
 * 
 */
int main() {
    LIVROS livros = {.contador = 0};

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
        printf("\nLivros: %d/%d", livros.contador, MAX_NUM_LIVRO);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirLivros(&livros);
                break;
            case 2:
                procurarLivros(livros);
                break;
            case 3:
                atualizarLivros(&livros);
                break;
            case 4:
                removerLivros(&livros);
                break;
            case 5:
                listarLivros(livros);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    /*
    printf("autor");
    scanf("%[^\n]",autor);
    printf("%s",autor);
     */





    return 0;
}

