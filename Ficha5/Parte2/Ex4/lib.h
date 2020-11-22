/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 21 de novembro de 2020, 15:16
 */

#ifndef LIB_H
#define LIB_H

int num() {
    int a;

    printf("Numero: ");
    scanf("%i", &a);
    return a;
}

float potencia(int base, signed int expoente) {
    if (expoente == 0) {
        return 1;
    }
    else if (expoente>0) {
        return (base * potencia(base, expoente - 1));
    } else if(expoente<0) {
        return (1 / potencia(base,-expoente ));
    }
}

#endif /* LIB_H */

