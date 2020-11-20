/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 10:49
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int num1,num2;
    char op;
    
    printf("Introduza um numero: ");
        scanf("%i",&num1);
    printf("Introduza um numero: ");
        scanf("%i",&num2);
        
        printf("\n");
        printf("\n");
        
        
        printf("MENU");
        printf("\nSoma + ");
        printf("\nSubtração -");
        printf("\nMultiplicação *");
        printf("\nDivisão /\n");
        
            scanf(" %c",&op);
            
         switch (op){
         
             case '+':
               printf("\nValor da soma: %i",num1+num2);  
             break;  
             
             case '-':
               printf("\nValor da Subtração: %i",num1-num2);  
             break;    
            
             case '*':
               printf("\nValor da multiplicação: %i", num1*num2); 
             break;
             
             case '/':
                 printf("\nValor da divisão: %.1f",(float)num1/num2);
             break;  
             
             default  :
                printf("\nValor da soma: %i",num1+num2); 
         }   
            
    return 0;
}

