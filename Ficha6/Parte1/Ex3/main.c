/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 25 de novembro de 2020, 01:42
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void somar(int num1, int num2,int *resultado){

*resultado=num1+num2;

}


int main() {

    int a,b,resultado;
    
    printf("Valor 1: ");
    scanf("%i",&a);
    printf("Valor 2: ");
    scanf("%i",&b);
    
    somar(a,b,&resultado);
    printf("%i",resultado);
    return 0;
}

