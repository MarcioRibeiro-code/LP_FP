/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lib.h
 * Author: Desktop
 *
 * Created on 19 de novembro de 2020, 23:55
 */

#ifndef LIB_H
#define LIB_H
#define mes 12

int obterfunc() {
    int cod;


    printf("Codigo do funcionario: ");
    scanf("%i", &cod);
    return cod;


}

int array_dia(int a[]) {

    int dia;

    for (int i = 0; i < mes; i++) {
        printf("\n\nMes [%i]", i + 1);
        printf("\nDias: ");
        scanf("%i", & a[i]);
        while(a[i]<0 || a[i]>30){
            printf("Valor Invalido");
            scanf("%i", & a[i]);
        }
    }



}

char menu_cargo() {

    char cargo;

    printf("\nCargo Funcionario");
    printf("\n E - Empregado");
    printf("\n C- Chefe");
    printf("\n A - Administrador\n");
    scanf(" %c", &cargo);
    cargo = toupper(cargo);

    while (cargo != 'E' && cargo != 'C' && cargo != 'A' && cargo != 'S') {
        printf("Opção Invalida");
        scanf(" %c", &cargo);
        return cargo;

    }
    
}

void calcular(char cargo, int a[], int vb[], int sb[], int ir[], int as[], int vao[]) {

    int vencb, sub_al, irs, ss;

    for (int i = 0; i < mes; i++) {
        //vencb
        if (cargo == 'E') {
            vb[i] = a[i]*40;
            sb[i] = a[i]*5;
        } else if (cargo == 'C') {
            vb[i] = a[i]*60;
            sb[i] = a[i]*7.5;

        } else {
            vb[i] = a[i]*80;
            sb[i] = a[i]*7.5;


        }
        if (a[i] > 20) {
            vb[i] = vb[i]*1.05;
        } else if (a[i] > 17 && a[i] <= 20) {
            vb[i] = vb[i]*1.02;
        } else {
            vb[i] = vb[i];
        }
        vao[i] = vb[i] + sb[i];

        if (cargo == 'E' && cargo == 'C') {
            as[i] = vao[i]*0.3475;
        } else {
            as[i] = vao[i]*0.3;
        }




        if (vao[i] < 1000) {
            ir[i] = vao[i]*0.1;
        } else if (vao[i] >= 1000 && vao[i] < 2500) {
            ir[i] = vao[i]*0.2;
        } else {
            ir[i] = vao[i]*0.3;
        }

    }

}

void imprimir(char cargo, int vb[], int sb[], int ir[], int as[], int vao[]) {

    int total_emp_m[mes],valol[mes],total_valol;
    unsigned int total_emp;
    
    total_emp=0;
    for (int i = 0; i < mes; i++) {


        if (cargo == 'E' && cargo == 'C') {
            total_emp_m[i]=0;
            total_emp_m[i] += (vao[i]*1.2375);
            valol[i]=((vao[i]-((vao[i]*0.11)+ir[i])));
        } else {
            total_emp_m[i]=0;
            total_emp_m[i]+=(vao[i]*1.21);
            valol[i]=((vao[i]-((vao[i]*0.09)+ir[i])));
        }
        total_valol+=valol[i];
        
        total_emp += total_emp_m[i];
        
        printf("\n\nMes %i", i + 1);
        printf("\nVencimento Base %i", vb[i]);
        printf("\nSubsidio de alimentação %i", sb[i]);
        printf("\nValor iliquido %i", vao[i]);
        printf("\nSegurança Social %i", as[i]);
        printf("\nIRS %i", ir[i]);
        printf("\n Valor Liquido %i",valol[i]);
        printf("\n Encargo empresa %i",total_emp_m[i]);

    }
    
    printf("\n\nFinal 12 MESES");
    printf("\nValor líquido: %i",total_valol);
    printf("\nTotal empresa: %d",total_emp);
    
}

#endif /* LIB_H */

