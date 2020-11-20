/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 26 de outubro de 2020, 20:45
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int segundos[9],minutos[9],i,aux;
    float somam,somas,somah;
    
    aux=0;
    
    printf("Musicas album: ");
    scanf("%i",&i);
    
    do {
        printf("Minutos da musica [%i]",aux+1);
        scanf("%i",&minutos[i]);
        printf("Segundos da musica [%i]",aux+1);
        scanf("%i",&segundos[i]);
        aux +=1;
        
        somam +=minutos[i];
        somas +=segundos[i];
    }while (aux<i);
    
    if (somas>=60){
        somam=somam+somas/60;
        
    }
    
    if (somam>=60){
        int a;
        a=somam-60;
        somah=(somam-a)/60;
        somas+=a*60;
    }
    
    printf("\nHoras %.0f",somah);
     printf("\nMinutos %.0f",somam);
    printf("\nSegundos %.0f",somas);
    
    return 0;
}

