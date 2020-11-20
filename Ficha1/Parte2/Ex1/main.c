/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 19:40
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
    b=a;
    printf("Antecessor: %i",--a);
    printf("\nSucessor: %i", ++b);
    
    return 0;
}

