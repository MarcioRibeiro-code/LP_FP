/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 22 de novembro de 2020, 15:24
 */

#ifndef LIB_H
#define LIB_H

int ABS(int x) {

    return abs(x);
}

float VAL(float x, int n, float t) {

    float a;

    for (int i = 1; i < n; i++) {
        a += (x / pow((1 + t), i));
    }
    return a;
}

long int n_segundos(int n_horas) {

    return 3600 * n_horas;
}

long int num(int n_horas, char tipo) {
    switch (tipo) {
        case 'h':
        case'H':
            return (n_horas * 1);
            break; //retirar o break- para switch sem break; chega ao return e volta ao programa principal
        case'm':
        case'M':
            return (n_horas * 60);
            break;

        case 's':
        case 'S':
            return (n_horas * 3600);
            break;

    }

}

float MAX(float x, float y, float w) {

    int a = 0;

    if (x < a) {
        a = x;
    } else if (y < a) {
        a = y;
    } else {
        a = w;
    }
    return a;
}

int Impar(int x) {

    if (x % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int Entre(int x, int lim_inf, int lim_sup) {

    int a = 0;

    if (lim_inf <= x && x <= lim_sup) {
        a = 1;
    }

    return a;
}

int is_d(char c) {

    if (isdigit(c) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int is_a(char c) {

    if (isalpha(c) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int is_num(char c) {
    if (isalnum(c) == 0) {
        return 0;
    } else {
        return 1;
    }

}



#endif /* LIB_H */

