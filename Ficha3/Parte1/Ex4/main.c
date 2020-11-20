/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 12:57
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int i,a,num;
    
    do{
        printf("Introduza um numero\n");
        scanf("%i",&num);
        
        i+=num;
        a++;
    }while (num !=0);
    a-=1;
    printf("Media: %f",(float)i/a);
    
    return 0;
}

