/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 28 de novembro de 2020, 02:05
 */

#include <stdio.h>
#include <stdlib.h>

void intSwap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap_pointers(char** x, char** y) {
    /* Utilizar (char ** variavel1,char ** variavel2)
     
     Codigo exemplo: 
     *  char *tmp = *x;
     *x = *y;
     *y = tmp;
     
     
     */


    char *tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
 * 
 */
int main() {

    int a = 0, b = 1;
    char *s1 = "da programação", *s2 = "Fundamentos";
    intSwap(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    swap_pointers(&s1, &s2);
    /*
     * A falta do & era a causa do erro, e desta forma nao inseria o valor
     * do endereço de memoria da variavel s1 e s2 para o parametro "swap_pointers"
     * 
     * 
     * swap_pointers(s1, s2);*/
    printf("%s %s\n", s1, s2);
    return 0;
}

