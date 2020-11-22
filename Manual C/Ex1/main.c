/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 22 de novembro de 2020, 15:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "lib.h"


/*
 * 
 */
int main() {

    printf("\n%i",ABS(-5));
    printf("\n\n%f",VAL(500,5,0.005));
    printf("\n\n %i",num(5,'s'));
    printf("\n %f",MAX(1,5,9));
    
    if(Impar(5)==0){
        printf("Par");
    }else{
        printf("Impar");
    }
    
    if(Entre(2,0,9)==0){
        printf(" ");
    }else{
        printf("Encontra-se no periodo");
    }
    
    if (is_d('1') == 0)
         printf("%c is not a digit.",'1');
    else
         printf("%c is a digit.",'1');
    
     
    if (is_a('c') == 0)
         printf("%c não é uma letra do alfabeto.",'c');
    else
         printf("%c é uma letra do alfabeto.",'c');
    
    
     if (is_num('c') == 0)
         printf("%c não é uma letra do alfabeto ou um digito.",'c');
    else
         printf("%c é uma letra do alfabeto ou um digito.",'c');
    
    
    return 0;
}

