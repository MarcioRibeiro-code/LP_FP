/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 13 de novembro de 2020, 11:45
 */

#include <stdio.h>
#include <stdlib.h>

#include "teste.h"
/*
 * 
 */
int main( ) {

    
         int num1,num2;
    char ca='s',op;
    
    do{
        printf("Numero 1: ");
            scanf("%i",&num1);
        printf("Numero 2: ");
            scanf("%i",&num2);
        
        printf("\n\n + Soma");
        printf("\n - Subtração");
        printf("\n * Multiplicação");
        printf("\n / Divisão\n");
            scanf(" %c",&op);
        
            switch (op){
                case '+':
                    
                    printf("Soma: %i",soma(num1,num2));
                break;
                
                case '-':
                    
                    printf("Subtração: %i",subtracao(num1,num2));
                 
                break;
                
                case '*':
            
                    printf("Multiplicação: %i",multiplicacao(num1,num2));
                break;
                
                case '/':
                    printf("Multiplicação: %.2f",divisao(num1,num2));
                break;
            }
        
        printf("\nDeseja continuar s/n\n");
        scanf(" %c",&ca);
    }while (ca != 'n');
    
    
    
    return 0;
}

