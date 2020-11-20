/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 10:19
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int num1,num2,num3;
    
    printf("Introduze um numero: ");
        scanf("%i",&num1);
    
    printf("Introduze um numero: ");
        scanf("%i",&num2);
        
        printf("Introduze um numero: ");
        scanf("%i",&num3);
        
        if(num1<num2 && num1<num3){
            printf("O menor número é: %i",num1);
        }   
        else{
            if (num2<num3 && num2<num1){
            printf("o menor número é: %i", num2);
            }
            else{
                printf("O menor número é: %i", num3);
            }
        }
    return 0;
}

