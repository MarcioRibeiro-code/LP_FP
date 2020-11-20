/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 10:41
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int a;
    
    printf("Introduze um numero (1 a 3):  ");
        scanf("%i",&a);   
    
        switch(a){
        
            case 1:
                printf("O valor é um");
            break;
            
            case 2:
               printf("O valor é dois"); 
            break; 
            
            case 3:
                printf("O valor é três");
            break; 
            
            default:
                printf("valor invalido ");
        }
        
    return 0;
}

