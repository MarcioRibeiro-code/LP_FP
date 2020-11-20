/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 10:32
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int a,b;
    
    printf("Introduza um numero: ");
        scanf("%i",&a);
     printf("Introduza um numero: ");
        scanf("%i",&b);
    
        if (a>b){
            printf("Maior: %i",a);
        }else{
            printf("Maior: %i",b);
        }
        
    return 0;
}

