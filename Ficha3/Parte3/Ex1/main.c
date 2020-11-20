/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 11:10
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int op=1,col,dia=1,vencb=0,suba=0,irs=0,ss=0,valol=0,valoi=0;
    char cargo;
    
    
    
    do{
    
    printf("Introduza o codigo do funcionario: ");
    scanf("%i",&col);
    printf("Introduza o cargo do funcionario: ");
    scanf(" %c",&cargo);
    
   if (col==99 || cargo=='S'){
       return(0);}
       else{
           
 
    switch (cargo)
    {
        case 'E':
         printf("Numero de dias: ");
        scanf("%i",&dia);
        do{
            printf("Valor Invalido");
            printf("\nNumero de dias: ");
        scanf("%i",&dia);
        }while(dia<0 || dia>30);
        if(dia>20 && dia>17 ){
            vencb=(dia*40)*1.05;
        }else if(dia>17 && dia<20){
            vencb=(dia*40)*1.02;
        }else{
        vencb=dia*40;
        }
        
        
        suba=dia*5;
        valoi=vencb+suba;
        if (valoi<1000){
        irs=(vencb+suba)*0.1;
        }else if(valoi>=1000 && valoi<2500){
        irs=(vencb+suba)*0.2;
        }else{
            irs=(vencb+suba)*0.3;
        }
        ss=(vencb+suba)*0.3475;
        valol=(valoi)-irs-((valoi)*0.11);
        
        break;
        
        case 'C':
         printf("Numero de dias: ");
        scanf("%i",&dia);
        do{
            printf("Valor Invalido");
            printf("\nNumero de dias: ");
        scanf("%i",&dia);
        }while(dia<0 || dia>30);
        if(dia>20 && dia>17 ){
            vencb=(dia*60)*1.05;
        }else if(dia>17 && dia<20){
            vencb=(dia*60)*1.02;
        }else{
        vencb=dia*60;
        }
        
        
        suba=dia*7.5;
        valoi=vencb+suba;
        if (valoi<1000){
        irs=(vencb+suba)*0.1;
        }else if(valoi>=1000 && valoi<2500){
        irs=(vencb+suba)*0.2;
        }else{
            irs=(vencb+suba)*0.3;
        }
        
        
        
        
        valoi=vencb+suba;
        if (valoi<1000){
        irs=(vencb+suba)*0.1;
        }else{
        irs=(vencb+suba)*0.2;
        }
        ss=(vencb+suba)*0.3475;
        valol=(valoi)-irs-((valoi)*0.11);

         break; 
        
        case 'A':
         printf("Numero de dias: ");
        scanf("%i",&dia);
        do{
            printf("Valor Invalido");
            printf("\nNumero de dias: ");
        scanf("%i",&dia);
        }while(dia<0 || dia>30);
        vencb=dia*80;
        suba=dia*7.5;
        valoi=vencb+suba;
        if (valoi<1000){
        irs=(vencb+suba)*0.1;
        }else{
        irs=(vencb+suba)*0.2;
        }
        ss=(vencb+suba)*0.30;
        valol=(valoi)-irs-((valoi)*0.11);
        
        break;
    }    
       }    
    printf("Valor ilíquido: %i",vencb+suba);
        printf("\nSubsidio de alimentação: %i",suba);
        printf("\nIRS: %i",irs);
        printf("\nSegurança Social: %i",ss);
        printf("\nValor liquido: %i",valol); 
        printf("\nDeseja sair. 0 Sair\n");
        scanf("%i",&op);
   
    }while(op!=0);
    
    return 0;
}

