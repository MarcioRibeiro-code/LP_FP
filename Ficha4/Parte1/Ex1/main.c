/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 6 de novembro de 2020, 10:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int preco[10],total;
    
    for(int i=0;preco[i]<10;i++)
    {
        printf("Preço: ");
        scanf("%i",&preco[i]);
       total+=preco[i]; 
    }
    printf("Total %i",total);
    return 0;
}

