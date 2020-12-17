/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 1 de dezembro de 2020, 00:39
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 3
/*
 * 
 */
int main() {

    char ar[TAMANHO][TAMANHO];
    int i,j;
    
    
    ar[0][0]='X';
    ar[1][1]='X';
    ar[0][2]='O';
    ar[2][2]='O';
    
    for(i=0;i<TAMANHO;i++){
    
        for(j=0;j<TAMANHO;j++)
            printf("%c %c",ar[i][j],j==TAMANHO-1? ' ':'|');
        if(i!=TAMANHO-1) printf("\n-----------\n");
    }
    
    
    return 0;
}

