/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de outubro de 2020, 10:54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    int col,dia,vencb,suba,irs,ss,valol;
    int col1=001, col2=002;
    
    printf("Introduza o codigo do funcionario: ");
    scanf("%i",&col);
    
    if (col==col1){
        printf("Numero de dias: ");
        scanf("%i",&dia);
        vencb=dia*40;
        suba=dia*5;
        irs=(vencb+suba)*0.1;
        ss=(vencb+suba)*0.3475;
        valol=(vencb+suba)-irs-((vencb+suba)*0.11);
        printf("Valor ilíquido: %i",vencb+suba);
        printf("\nSubsidio de alimentação: %i",suba);
        printf("\nIRS: %i",irs);
        printf("\nSegurança Social: %i",ss);
        printf("\nValor liquido: %i",valol);
    }else if(col==col2){
    printf("Numero de dias: ");
        scanf("%i",&dia);
        vencb=dia*40;
        suba=dia*5;
        irs=(vencb+suba)*0.1;
        ss=(vencb+suba)*0.3475;
        valol=(vencb+suba)-irs-((vencb+suba)*0.11);
        printf("Valor ilíquido: %i",vencb+suba);
        printf("\nSubsidio de alimentação: %i",suba);
        printf("\nIRS: %i",irs);
        printf("\nSegurança Social: %i",ss);
        printf("\nValor liquido: %i",valol);
    }
    
    return 0;
}

