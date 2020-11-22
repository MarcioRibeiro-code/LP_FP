/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 21 de novembro de 2020, 15:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIB.H"

/*
 * 
 */



int main(){

   int a,b;
   float res;
    a=num();
    b=num();
    
 res = potencia(a,b);
 printf("%d elevado a %d = %f", a, b,res);
 return 0;
}

