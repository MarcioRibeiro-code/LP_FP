/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de novembro de 2020, 23:23
 */

#include <stdio.h>
#include <stdlib.h>

char *strchar(char *str, char ch) {

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            printf("%p\n", &str[i]);
            return &str[i];
        }
    }

}

/*
 * 
 */
int main() {

    char a[99] = "abcd";
    char ch = 'e', *end;


    end = strchar(&a, ch);
    //END NULL 0X4, inves de 0x0?
    if (end == ' ') {
        *end=NULL;
        printf("%p",end);
    } else {
        printf("%p", end);
    }



    return 0;
}

