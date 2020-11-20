/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 12:33
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    char a,b;
    
    printf("M - Maiúsculas");
    printf("\nm - minúsculas\n");
    scanf(" %c",&b);
    
    if (b == 'M'){
    printf("\n\nAlfabeto MAIUSCULO\n");
       for(a='A';a!='[';a++)printf("%c ",a);
    }else{
    printf("\n\nAlfabeto minusculo\n");
       for(a='a';a!='{';a++)printf("%c ",a);
       
    }
    printf("\n\n");
       
       
    
    return 0;
}

