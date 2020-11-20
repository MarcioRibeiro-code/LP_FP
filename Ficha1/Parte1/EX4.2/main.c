/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 19:29
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    float r,area;
    
    printf("Introduza o raio da circunferencia: ");
    scanf("%f",&r);
    
    area= 3.14*pow(r,2);
    
    printf("Area: %.2f",area);
    
    return 0;
}

