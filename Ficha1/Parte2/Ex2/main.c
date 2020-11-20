/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 19:44
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int val1,val2,val3;
    float media,mediap;
    
    printf("Introduza valor 1: ");
    scanf("%i",&val1);
    printf("Introduza valor 2: ");
    scanf("%i",&val2);
    printf("Introduza valor 3: ");
    scanf("%i",&val3);
    
    media=(val1+val2+val3)/3;
    mediap=(val1*0.2)+(val2*0.3)+(val3*0.5);
    
    printf("Media: %.2f",media);
    printf("\nMedia Ponderada: %.2f",mediap);
    return 0;
}

