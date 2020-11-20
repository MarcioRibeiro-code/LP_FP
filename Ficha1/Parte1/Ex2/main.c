/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 19:13
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int aluno1,aluno2,aluno3;
    float media;
    
    printf("Insira a idade do aluno 1: ");
    scanf("%i", &aluno1);
    printf("Insira a idade do aluno 2: ");
    scanf("%i", &aluno2);
    printf("Insira a idade do aluno 3: ");
    scanf("%i", &aluno3);
    
    
    media=(aluno1+aluno2+aluno3)/3;
    printf("A média de idades é: %.2f",media);
    
    return 0;
}

