/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 19 de novembro de 2020, 23:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#include "lib.h"

/*
 * 
 */

typedef struct key_value {
    char col1[50];
    char col2[50];
    char col3[50];
    char col4[50];
    char col5[50];
    char col6[50];
    char col7[50];
} dict;

void readcsv(dict values[], int est_irs) {
    FILE *fp; //= fopen(FILENAME_CSV_nCasado, "r");

    if (est_irs == 0) {
        fp = fopen("Tabelas_IRS_2020_nCasado.csv", "r");
    }


    int x;
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    char line[200];
    int row_count = 0;
    int field_count = 0;

    int i = 0;
    while (fgets(line, sizeof (line), fp)) {
        field_count = 0;
        row_count++;

        char *token;
        token = strtok(line, ";");

        while (token != NULL) {
            if (field_count == 0)
                strcpy(values[i].col1, token);
            if (field_count == 1)
                strcpy(values[i].col2, token);
            if (field_count == 2)
                strcpy(values[i].col3, token);
            if (field_count == 3)
                strcpy(values[i].col4, token);
            if (field_count == 4)
                strcpy(values[i].col5, token);
            if (field_count == 5)
                strcpy(values[i].col6, token);
            if (field_count == 6)
                strcpy(values[i].col7, token);
            token = strtok(NULL, ";");
            field_count++;
        }
        i++;
        printf("\n");
    }
    x = i;
}

float calcular_irs() {
    int est_irs = 0;
    int num_dependentes=1;
    dict values[36];
    int teste = 26000;
    int i, flag = 0;

    if (est_irs == 0) { // NAO CASADO

        readcsv(values, est_irs);
        switch (num_dependentes) {

            case 1:

                for (i = 0; i < 35; i++) {
                    if (teste <= atoi(values[i].col1)) {
                        return (teste * atof(values[i].col3));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (teste * atof(values[35].col3));
                break;
        }
    }
}

int main() {
    /* //variaveis
     char cargo;
     int vencb[mes],suba[mes],irs[mes],ss[mes],valoi[mes];
     int dia[mes],op=1,cod;
    
    
    
     //Programa
    
     do{
     cod=obterfunc();
     if (cod==99){
         return 0;
     }
    
     cargo=menu_cargo();
     if (cargo == 'S') {
         return 0;
     }
     array_dia(dia);
     calcular(cargo,dia,vencb,suba,irs,ss,valoi);
     imprimir(cargo,vencb,suba,irs,ss,valoi);
    
    
     printf("\nSair - 0\n");
     scanf("%i",&op);
     }while(op!=0);
     */

    printf("%f", calcular_irs());

    return 0;
}

