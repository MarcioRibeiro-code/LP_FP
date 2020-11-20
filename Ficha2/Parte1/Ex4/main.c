/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 10:38
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int num;
    
    printf("Introduza um numero: ");
        scanf("%i",&num);
    
        if(num%2 == 0){
            printf("O numero é par");
        }else{
            printf("O numero é impar");
        }
        
    return 0;
}

