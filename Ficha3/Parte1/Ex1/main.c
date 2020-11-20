/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 11:38
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int numero = 0, soma = 0;
    
    do{
        soma+= numero;
        printf("Introduza um numero entre 1 e 9\n");
        scanf("%i", &numero);
    } while(numero>0);
            
    return 0;
}

