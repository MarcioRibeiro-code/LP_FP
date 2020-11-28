/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 28 de novembro de 2020, 00:57
 */

#include <stdio.h>
#include <stdlib.h>

int *findMax(int *data, int size) {

    int c, location = 0;

    for (c = 1; c < size; c++) {

        if (data[c] > data[location]) {
            location = c;
        }
    }

    return &data[location];
}

/*
 * 
 */
int main() {
    int size = 5, *a;
    int num[5] = {19, 10, 51, 17, 9};
    for (int i = 0; i < 5; i++) {
        printf("%p\n", &num[i]);
    }



    a = findMax(&num,size);
    printf("%p",a);



    return 0;
}

