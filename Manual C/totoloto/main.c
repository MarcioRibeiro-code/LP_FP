/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 1 de dezembro de 2020, 01:40
 */

#include <stdio.h>
#include <stdlib.h>
#define NUM_LIN 7
#define NUMS 49
#define MIN_APOSTA 6
/*
 * 
 */
void introduzir_val() {
    long ultime;
    time(&ultime);
    srand((unsigned)ultime);
}

void inic(int a[]) {
    int i;
    
    for(i=0;i<NUMS;i++){
        a[i]=0;
    }
    
}

int Ler_Ns_Apostar(){
    int n;
    do{
        printf("Quantos Nºs quer apostar (0 - Terminar): ");
        scanf("%i",&n);
    }while((n<MIN_APOSTA || n>NUMS)&&n!=0);
    return n;
}

void Gerar(int *v,int n){
    int i,indice;
    for(i=0;i<=NUMS;i++){
        indice=rand()%NUMS;
        if(v[indice]==0){
            v[indice]=1;
        }else{
            i--;
        }
    }
}

void Apresentar(int res[]){
    int i;
    for(i=0;i<NUMS;i++){
        if(res[i]==0)
            printf(" %d",i+1);
        else
            printf(" XX");
        if((i+1)%NUM_LIN==0) putchar('\n');
    }
    putchar('n');
}
/*
 * 
 */
int main() {

    int ar[NUMS];
    int n_nums;
    
    inic(ar);
    if((n_nums=Ler_Ns_Apostar())==0){ return 0;}
       
    Gerar(ar,n_nums);
    Apresentar(ar);
    
    
    return (0);
}

