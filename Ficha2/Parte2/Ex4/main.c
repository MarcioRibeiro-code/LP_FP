/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 14:15
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int nota1,nota2;
    float media;
    
    printf("Introduza a nota: ");
        scanf("%i",&nota1);
    printf("Introduza a nota: ");
        scanf("%i",&nota2);
       media=(nota1*0.4)+(nota2*0.6); 
       
    if (nota1<0 || nota1>20){
        printf("Calcúlo não é possivel");
    } else if (nota2<0 || nota2>20){
        printf("Calcúlo não é possivel");
    } else if (media >9.5){
            printf("O aluno esta aprovado");
        }else{
            printf("O aluno esta reprovado");
        }
        
        
       
        
    return 0;
}

