/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 6 de novembro de 2020, 12:06
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_LINHA 3
#define TAMANHO_COLUNA 3
/*
 * 
 */
int main() {
   int x,y,matriz[TAMANHO_LINHA][TAMANHO_COLUNA],max,min;
    
    for(x=0;x<TAMANHO_LINHA;x++){
        for(y=0;y<TAMANHO_COLUNA;y++){
            printf("VAlor: ");
            scanf("%i",&matriz[x][y]);
        }
    }
   
   min=matriz[0][0];
   max=matriz[0][0];
   
    system("clear");
    for(x=0;x<TAMANHO_LINHA;x++){
        for(y=0;y<TAMANHO_COLUNA;y++){
            printf("%i",matriz[x][y]);

           
            
            
            if(matriz[x][y]>max){
                max=matriz[x][y];
            } else if(matriz[x][y]<min){
                min=matriz[x][y];
            }
            
           
            
        }
        printf("\n");
    }
    
    printf("\nMáximo: %i\n",max);
    printf("Mínimo: %i\n",min);
    return 0;
}

