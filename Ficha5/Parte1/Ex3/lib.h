/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 20:37
 */

#ifndef LIB_H
#define LIB_H

int introduzir_num() {

    int aux;

    printf("Numero: ");
    scanf("%i", &aux);

    return aux;
}

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a*b;
}

float divisao(int a, int b) {
    return (float) a / b;
}

void menu(int a, int b) {

    //variavel
    char aux;

    printf("\n\nMenu");
    printf("\n+ Soma");
    printf("\n- Subtração");
    printf("\n* Multiplicação");
    printf("\n/ Divisão");
    printf("\nOpção: ");

    scanf(" %c", &aux);

    while(aux!='+' && aux!='-' && aux!='*' && aux!='/'){
        printf("\nCaracter Invalido- Introduza novamente\n");
        scanf(" %c", &aux);
    }

    //MENU
    switch (aux) {

        case '+':

            printf("\n\nResultado: %i", soma(a, b));
            break;

        case '-':
            printf("\n\nResultado: %i", subtracao(a, b));
            break;

        case'*':
            printf("\n\nResultado: %i", multiplicacao(a, b));
            break;

        case'/':
            printf("\n\nResultado: %.2f", divisao(a, b));
            break;
    }

}

#endif /* LIB_H */

