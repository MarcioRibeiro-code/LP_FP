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

    int col, dia, vencb, suba, irs, ss, valol, valoi;
    char cargo;

    printf("Introduza o codigo do funcionario: ");
    scanf("%i", &col);
    printf("Introduza o cargo do funcionario: ");
    scanf(" %c", &cargo);

    switch (cargo){
        case'E':
        case 'e':
        printf("Numero de dias: ");
    scanf("%i", &dia);
    vencb = dia * 40;
    suba = dia * 5;
    valoi = vencb + suba;
    if (valoi < 1000) {
        irs = (vencb + suba)*0.1;
    } else {
        irs = (vencb + suba)*0.2;
    }
    ss = (vencb + suba)*0.3475;
    valol = (valoi) - irs - ((valoi)*0.11);
    printf("Valor ilíquido: %i", vencb + suba);
    printf("\nSubsidio de alimentação: %i", suba);
    printf("\nIRS: %i", irs);
    printf("\nSegurança Social: %i", ss);
    printf("\nValor liquido: %i", valol);
    break;

    case 'C':
    case 'c':
    printf("Numero de dias: ");
    scanf("%i", &dia);
    vencb = dia * 40;
    suba = dia * 5;
    valoi = vencb + suba;
    if (valoi < 1000) {
        irs = (vencb + suba)*0.1;
    } else {
        irs = (vencb + suba)*0.2;
    }
    ss = (vencb + suba)*0.3475;
    valol = (valoi) - irs - ((valoi)*0.11);
    printf("Valor ilíquido: %i", vencb + suba);
    printf("\nSubsidio de alimentação: %i", suba);
    printf("\nIRS: %i", irs);
    printf("\nSegurança Social: %i", ss);
    printf("\nValor liquido: %i", valol);
    break;

    case 'A':
    case 'a':
    printf("Numero de dias: ");
    scanf("%i", &dia);
    vencb = dia * 80;
    suba = dia * 7.5;
    valoi = vencb + suba;
    if (valoi < 1000) {
        irs = (vencb + suba)*0.1;
    } else {
        irs = (vencb + suba)*0.2;
    }
    ss = (vencb + suba)*0.30;
    valol = (valoi) - irs - ((valoi)*0.11);
    printf("Valor ilíquido: %i", vencb + suba);
    printf("\nSubsidio de alimentação: %i", suba);
    printf("\nIRS: %i", irs);
    printf("\nSegurança Social: %i", ss);
    printf("\nValor liquido: %i", valol);
    break;
    }
    return 0;
}

