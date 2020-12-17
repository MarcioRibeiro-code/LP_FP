/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 1 de dezembro de 2020, 01:01
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10
/*
 * 
 */

char *memset(char a[],char ch){
    for(int i=0;i<TAMANHO;i++){
        a[i]=ch;
        return a;
    }
}



int main() {

    float ar[TAMANHO];
    char v[TAMANHO],ch;
    
    /*
    for(int i=0;i<TAMANHO;i++){
        ar[i]=i*(TAMANHO-i);
    }
    
    for(int i=0;i<TAMANHO;i++){
        printf("\n%f",ar[i]);
    }
    */
    
    
    printf("Caracter");
    scanf(" %c",&ch);
   
    for(int i=0;i<TAMANHO;i++){
        v[i]=*memset(v,ch);
    }

    for(int i=0;i<TAMANHO;i++){
        printf(" %c",v[i]);
    }
    
    return (0);
}

