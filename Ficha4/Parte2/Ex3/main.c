/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 11 de novembro de 2020, 09:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


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
   printf("Transposta");
   for(x=0;x<TAMANHO_LINHA;x++){
       printf("\n");
        for(y=0;y<TAMANHO_COLUNA;y++){
            printf(" %i",matriz[y][x]);
            
        }
    }
            

        
   
        

    return 0;
}
