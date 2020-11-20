/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 19:33
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int base,altura;
    float area;
    
    printf("Introduza a base do triangulo: ");
    scanf("%i",&base);
    printf("Introduza a altura do triangulo: ");
    scanf("%i",&altura);
    
    
    area=(base*altura)/2;
    printf("Area: %.2f",area);
    
    return 0;
}

