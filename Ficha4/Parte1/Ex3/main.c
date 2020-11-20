/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 6 de novembro de 2020, 11:40
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

#define TAMANHO_LINHA 4
#define TAMANHO_COLUNA 5

int main() {

    int x,y,matriz[TAMANHO_LINHA][TAMANHO_COLUNA],aux,a;
    
    for(x=0;x<TAMANHO_LINHA;x++){
        for(y=0;y<TAMANHO_COLUNA;y++){
            printf("VAlor: ");
            scanf("%i",&matriz[x][y]);
        }
    }
    system("clear");
    printf("Valor a encontrar: " );
    scanf("%i",&aux);
    
     for(x=0;x<TAMANHO_LINHA;x++)
        for(y=0;y<TAMANHO_COLUNA;y++)
    {
            
            if (aux==matriz[x][y]){
                a+=1;
            }
    }

    printf("O valor %i exite %i na matriz",aux,a);
    
    return 0;
}

