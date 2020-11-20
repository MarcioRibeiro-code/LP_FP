/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 11 de novembro de 2020, 10:48
 */

#include <stdio.h>
#include <stdlib.h>

#define mes 12

/*
 * 
 */
int main() {
    /*
        int op = 1, col, dia = 1, vencb = 0, suba = 0, irs = 0, ss = 0, valol = 0, valoi = 0;
        char cargo;



        do {

            printf("Introduza o codigo do funcionario: ");
            scanf("%i", &col);
            printf("Introduza o cargo do funcionario: ");
            scanf(" %c", &cargo);

            if (col == 99 || cargo == 'S') {
                return (0);
            } else {


                switch (cargo) {
                    case 'E':
                        printf("Numero de dias: ");
                        scanf("%i", &dia);
                        do {
                            printf("Valor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        } while (dia < 0 || dia > 30);
                        if (dia > 20) {
                            vencb = (dia * 40)*1.05;
                        } else if (dia > 17 && dia < 20) {
                            vencb = (dia * 40)*1.02;
                        } else {
                            vencb = dia * 40;
                        }


                        suba = dia * 5;
                        valoi = vencb + suba;
                        if (valoi < 1000) {
                            irs = (valoi)*0.1;
                        } else if (valoi >= 1000 && valoi < 2500) {
                            irs = (valoi)*0.2;
                        } else {
                            irs = (valoi)*0.3;
                        }
                        ss = (valoi)*0.3475;
                        valol = (valoi) - irs - ((valoi)*0.11);

                        break;

                    case 'C':
                        printf("Numero de dias: ");
                        scanf("%i", &dia);
                        do {
                            printf("Valor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        } while (dia < 0 || dia > 30);
                        if (dia > 20) {
                            vencb = (dia * 60)*1.05;
                        } else if (dia > 17 && dia < 20) {
                            vencb = (dia * 60)*1.02;
                        } else {
                            vencb = dia * 60;
                        }


                        suba = dia * 7.5;
                        valoi = vencb + suba;
                        if (valoi < 1000) {
                            irs = (valoi)*0.1;
                        } else if (valoi >= 1000 && valoi < 2500) {
                            irs = (valoi)*0.2;
                        } else {
                            irs = (valoi)*0.3;
                        }




                    
                        ss = (valoi)*0.3475;
                        valol = (valoi) - irs - ((valoi)*0.11);

                        break;

                    case 'A':
                        printf("Numero de dias: ");
                        scanf("%i", &dia);
                        do {
                            printf("Valor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        } while (dia < 0 || dia > 30);
                        vencb = dia * 80;
                        suba = dia * 7.5;
                        valoi = vencb + suba;
                        if (valoi < 1000) {
                            irs = (valoi)*0.1;
                        } else if (valoi >= 1000 && valoi < 2500) {
                            irs = (valoi)*0.2;
                        } else {
                            irs = (valoi)*0.3;
                        }
                        ss = (valoi)*0.30;
                        valol = (valoi) - irs - ((valoi)*0.09);

                        break;
                }
            }
            system("clear");
            printf("Valor ilíquido: %i", vencb + suba);
            printf("\nSubsidio de alimentação: %i", suba);
            printf("\nIRS: %i", irs);
            printf("\nSegurança Social: %i", ss);
            printf("\nValor liquido: %i", valol);
            printf("\nDeseja sair. 0 Sair\n");
            scanf("%i", &op);

        } while (op != 0);
     */

    int valol[mes],valoril[mes], cod, sub_al[mes], irs[mes], ss[mes], totale[mes], total[mes];
    int dia, total_liquido, total_iliquido, total_emp, total_subal, total_ss;
    char cargo, op = '1';

    do {
        printf("Introduza o codigo do funcionario: ");
        scanf("%i", &cod);
        printf("Introduza o cargo do funcionario: ");
        scanf(" %c", &cargo);

        while (cargo != 'E' && cargo != 'A' && cargo != 'C' && cargo != 'S') {
            printf("Opção Invalida");
            printf("\nIntroduza o cargo do funcionario: ");
            scanf(" %c", &cargo);
        }


        if (cod == 99 || cargo == 'S') {
            return (0);
        } else {


            switch (cargo) {
                case 'E':

                    for (int i = 0; i < mes; i++) {
                        printf("Mes %i", i + 1);
                        printf("\nNumero de dias: ");
                        scanf("%i", &dia);
                        while (dia < 0 || dia > 30) {
                            printf("\nValor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        }
                        if (dia > 20) {
                            valoril[i] = (dia * 40)*1.05;
                        } else if (dia > 17 && dia < 20) {
                            valoril[i] = (dia * 40)*1.02;
                        } else {
                            valoril[i] = dia * 40;
                        }
                        sub_al[i] = dia * 5;

                        if (valoril[i] < 1000) {
                            irs[i] = (valoril[i])*0.1;
                        } else if (valoril[i] >= 1000 && valoril[i] < 2500) {
                            irs[i] = (valoril[i])*0.2;
                        } else {
                            irs[i] = (valoril[i])*0.3;
                        }

                        ss[i] = (valoril[i])*0.3475;
                        valol[i] = (valoril[i]) - irs[i] - ((valoril[i])*0.11);

                    }

                    break;

                case 'C':
                    for (int i = 0; i < mes; i++) {
                        printf("Mes %i", i + 1);
                        printf("Numero de dias: ");
                        scanf("%i", &dia);
                        while (dia < 0 || dia > 30) {
                            printf("\nValor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        }
                        if (dia > 20) {
                            valoril[i] = (dia * 60)*1.05;
                        } else if (dia > 17 && dia < 20) {
                            valoril[i] = (dia * 60)*1.02;
                        } else {
                            valoril[i] = dia * 60;
                        }


                        sub_al[i] = dia * 7.5;

                        if (valoril[i] < 1000) {
                            irs[i] = (valoril[i])*0.1;
                        } else if (valoril[i] >= 1000 && valoril[i] < 2500) {
                            irs[i] = (valoril[i])*0.2;
                        } else {
                            irs[i] = (valoril[i])*0.3;
                        }





                        ss[i] = (valoril[i])*0.3475;
                        valol[i] = (valoril[i]) - irs[i] - ((valoril[i])*0.11);

                    }
                case 'A':
                    for(int i=0;i<mes;i++){
                    printf("Mes %i", i + 1);
                        printf("\nNumero de dias: ");
                        scanf("%i", &dia);
                        while (dia < 0 || dia > 30) {
                            printf("\nValor Invalido");
                            printf("\nNumero de dias: ");
                            scanf("%i", &dia);
                        }
                        
                        if (dia > 20) {
                            valoril[i] = (dia * 80)*1.05;
                        } else if (dia > 17 && dia < 20) {
                            valoril[i] = (dia * 80)*1.02;
                        } else {
                            valoril[i] = dia * 80;
                        }
                        
                        sub_al[i] = dia * 7.5;

                        if (valoril[i] < 1000) {
                            irs[i] = (valoril[i])*0.1;
                        } else if (valoril[i] >= 1000 && valoril[i] < 2500) {
                            irs[i] = (valoril[i])*0.2;
                        } else {
                            irs[i] = (valoril[i])*0.3;
                        }

                       ss[i] = (valoril[i])*0.30;
                        valol[i] = (valoril[i]) - irs[i] - ((valoril[i])*0.09); 
                    }
                    
                    
                    
                    
                    
                    
                    break;
            }
        }
        if (cargo == 'C' || cargo == 'E') {
            for (int i = 0; i < mes; i++) {
                total_liquido += valol[i];
                total_iliquido += valoril[i];
                total_subal += sub_al[i];
                total_ss = (valoril[i]*0.2375) * mes;
                totale[i] = valoril[i] + sub_al[i]+(valoril[i]*0.2375);
                total_emp += totale[i];
                printf("\n\nMes %i", i + 1);
                printf("\nValor Iliquido: %i", valoril[i]);
                printf("\n Subsidio de Alimentação: %i", sub_al[i]);
                printf("\n IRS: %i", irs[i]);
                printf("\n Segurança Social: %i", ss[i]);
                printf("\n Valor Liquido: %i", valol[i]);
                printf("\n Total empresa: %i", totale[i]);
            }
            
            }else{
            for(int i=0;i<mes;i++){
            total_liquido += valol[i];
                total_iliquido += valoril[i];
                total_subal += sub_al[i];
                total_ss = (valoril[i]*0.21) * mes;
                totale[i] = valoril[i] + sub_al[i]+(valoril[i]*0.21);
                total_emp += totale[i];
                printf("\n\nMes %i", i + 1);
                printf("\nValor Iliquido: %i", valoril[i]);
                printf("\n Subsidio de Alimentação: %i", sub_al[i]);
                printf("\n IRS: %i", irs[i]);
                printf("\n Segurança Social: %i", ss[i]);
                printf("\n Valor Liquido: %i", valol[i]);
                
                printf("\n Total empresa 1M: %i", totale[i]);
            }
            

        }
        printf("\n Total 12M: %i", total_liquido);
        printf("\n\n\n\n\nTotal empresa 12 meses: %i", total_emp);
        printf("\nDeseja sair. 0 Sair\n");
        scanf("%i", &op);
    } while (op != '0');



    return 0;
}