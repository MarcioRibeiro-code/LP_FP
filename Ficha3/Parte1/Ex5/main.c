/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 13:40
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int num,a,impar[999],i;
    
    do {
        printf("Introduza um numero > 0\n");
        scanf("%i",&a);
        if (a<0){
            do {
            printf("Introduza um numero > 0\n");
        scanf("%i",&a);
        }while (a!=0);}
        
    if (a%2==1) {
        for(i=0;;i++){
            impar[i]=a;
            printf("Impar: %i\n",impar[i]);
            break;
        }
    }   
       num=a; 
    }while (num!=0);
    
    return 0;
}

