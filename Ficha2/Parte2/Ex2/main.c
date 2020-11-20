/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 11:05
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int saldo,mont;
    char v;
    
    printf("Introduza o saldo da conta bancária: ");
        scanf("%d",&saldo);
        
    printf("\nCreditar (C)");
    printf("\nDebitar (D)\n");
    scanf(" %c",&v);
     
    switch (v){
        case 'C':
            
         printf("Montante: ");
         scanf("%i",&mont);
         printf("Saldo: %i",saldo+mont);
        break;   
        
        case 'c':
            
         printf("Montante: ");
         scanf("%i",&mont);
         printf("Saldo: %i",saldo+mont);
        break;
        
        case 'D':
            
         printf("Montante: ");
         scanf("%i",&mont);
         if(mont<saldo){
            printf("Saldo: %i",saldo-mont);
         }
         else {
             printf("Operação impossivel");
         }
        break;
        
        case 'd':
            
         printf("Montante: ");
         scanf("%i",&mont);
         
         if(mont<saldo){
            printf("Saldo: %i",saldo-mont);
         }
         else {
             printf("Operação impossivel");
         }
         
        break;
        
        default:
            printf("Operação invalida");
    }
    
    return 0;
}

