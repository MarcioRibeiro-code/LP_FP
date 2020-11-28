/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 25 de novembro de 2020, 01:24
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


void foo(int a,int *aPtr){

//imprimir o valor de a
    printf("\nValor de a: %i",a);
//imprimir o endereço de a
  printf("\nEndereço de a: <%p>",&a);

  
//imprimir o valor de aPtr
   printf("\nValor de aPtr: %i",aPtr);
//imprimir o endereço de aPtr
   printf("\nEndereço de aPtr: <%p>",&aPtr);
//somar um ao valor de a
   a++;
//somar um ao valor apontado por de aPtr
   aPtr++;


}

int main() {
    int a=0;
    //imprimir o valor de a
    printf("\nValor de a: %i",a);
    //imprimir o endereço de a
    printf("\nEndereço de a: <%p>",&a);
    foo(a,&a);
    //imprimir o valor de a
    printf("\nValor de a: %i",a);
    
    return 0;
}

