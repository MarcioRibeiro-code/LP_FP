/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 20:24
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int a,b,aux;
    
    printf("Introduza um numero: ");
    scanf("%i",&a);
    printf("Introduza um numero: ");
    scanf("%i",&b);
    
    aux=a;
    a=b;
    b=aux;
    
    printf("\nA: %i",a);
    printf("\nB: %i",b);
   
    a ^=b; 
    b^=a;
    a^=b;
    printf(" ");
    printf("\nA: %i",a);
    printf("\nB: %i",b);
    return 0;
}

