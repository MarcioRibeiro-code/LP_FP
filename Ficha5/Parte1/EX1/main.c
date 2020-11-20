/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 13 de novembro de 2020, 10:09
 */

#include <stdio.h>
#include <stdlib.h>


void asteriscos(int num1){
    printf("Introduza um numero: ");
    scanf("%i",&num1);
    for(int i=0;i<num1;i++){
        printf("*");
    }

}

/*
 * 
 */
int main() {
   int num1;
    asteriscos(num1);
    
    
    return (0);
}

