/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 14:26
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int x,y;
    
    printf("Coordenas X:");
        scanf("%d",&x);
    printf("Coordenas Y:");
        scanf("%d",&y);
        
    if (x>=0 && y>=0){
        
        printf("Primeiro Quadrante");
    }else if(x<=0 && y>=0){
        printf("Segundo Quadrante");
    }else if (x<=0 && y<=0){
        printf("Terceiro Quadrante");
    }else {
        printf("Quarto Quadrante");
    }
    
    
    return 0;
}

