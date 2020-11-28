/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de novembro de 2020, 11:53
 */

#include <stdio.h>
#include <stdlib.h>

void len(char *str) {
    int i;
    char a;

    for (i = 0;; i++) {
        a = (str[i]);
        if (a == '\0') {
            printf("Tamanho: %i", i);
            return 0;
        }
    }
}

/*
 * 
 */
int main() {

    char a[99] = "Marcio\0";



    len(&a);




    return 0;
}

