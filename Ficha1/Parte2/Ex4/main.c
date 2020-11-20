/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 20:40
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int produto1,produto2,produto3;
    float desc;
    
    printf("Produto 1 - Preço: ");
    scanf("%i",&produto1);
    printf("Produto 2 - Preço: ");
    scanf("%i",&produto2);
    printf("Produto 3 - Preço: ");
    scanf("%i",&produto3);
    
    desc= (produto1+produto2+produto3)*0.9;
    
    printf("Valor a pagar: %.2f",desc);
    
    return 0;
}

