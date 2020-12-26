/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 18 de dezembro de 2020, 23:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "booklib.h"
#include "input.h"
/*
 * 
 */

void faill(void){
    printf("Memory couldn't be allocated");
    exit(EXIT_FAILURE);
}



int main() {
 
    int menu,x;
    
    LIVROS *livros = calloc(TAMANHO_INICIAL,sizeof(LIVROS));
    FILE *fp;
    
    if(livros == NULL) faill();
   
      do {
          printf("\n%d",livros[0].contador);
        printf("\n\nMENU");
        printf("\n1- Inserir livros");
        printf("\n2- Listar todos os livros");
        printf("\n3- Consultar livro");
        printf("\n4- Atualizar dados livro");
        printf("\n5- Eliminar livro");
        printf("\n6- Carregar Ficheiro");
        printf("\n7- Imprimir no Ficheiro");
        printf("\n0 - Sair\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                Inserir(livros);
                break;
            case 2:
                Listar(livros);
                break;
            case 3:
                Consulta(livros);
                break;
            case 4:
                Atualizar(livros);
                break;
            case 5:
                Eliminar(livros);
                break;
            case 6:
               LerFicheiro_Binario(livros, fp);
                break;
                
            case 7:
                EscreverFicheiro_Binario(livros,fp);
                //puts("Gravado com sucesso");
                break;
                
            case 0:
                exit(1);

        }  
    } while (menu != 0);

    free(livros);
    return (0);
}

