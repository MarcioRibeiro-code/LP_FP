/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 18:48
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int i,a,b;
    
    printf("Jogador 1\n");
    printf("\nIntroduza um numero entre 0 e 100\n");
        scanf("%i",&a);
         system("clear");
    do {
        printf("Jogador 2");
        printf("\nInsira um numero entre 0 e 100\n");
        scanf("%i",&b);
        if(a<b){
            printf("\nValor superior\n");
        }else if (a>b){
            printf("\nValor inferior\n");
        }else{
            printf("\nValor igual\n");
        }
        
        i++;
    }while(a!=b);
    printf("Tentivas: %i",i);
    return 0;
}

