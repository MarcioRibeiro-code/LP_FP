/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 2 de dezembro de 2020, 17:02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct

struct dados {
    int f_cod; //funcionario_codigo
    char f_nome[25]; //funcionario_nome
    int f_numtlf; //funcionario_telefone
    char f_estcivil; //funcionario_estadocivil
    int f_numfil; //funcionario_ numero de filhos
    char f_cargo; //funcionario_cargo
    //data de saida
    int f_idade; //funcionario_idade
    int f_temp_emp; //funcionario_ Tempo na empresa
    int f_assiduidade; //funcionario_Assiduidade


} funcionario;

int n = 0; //Utilizado no create
int tl, sl, ts;

void input() {
    FILE *fp = fopen("funcionario.txt", "rb+");
    if (fp == NULL) {
        printf("\nErro no ficheiro");
    } else {
        printf("\ncustomer no:%d\n", ++funcionario.f_cod);
        printf("         Nome Funcionario:");
        scanf("%s", &funcionario.f_nome);
        printf("\n       Numero Telefone:");
        scanf("%d", &funcionario.f_numtlf);
        printf("\n       Estado Civil:");
        scanf(" %c", &funcionario.f_estcivil);
        printf("         Numero de Filhos:");
        scanf("%d", &funcionario.f_numfil);
        printf("         Cargo:");
        scanf(" %c", &funcionario.f_cargo);
        printf("         Idade funcionario:");
        scanf("%d", &funcionario.f_idade);

        fclose(fp);
    }

}

void output() {
    printf("\n\n    codigo    :%d\n", funcionario.f_cod);
    printf("    Name 	   :%s\n", funcionario.f_nome);
    printf("    Mobile no      :%d\n", funcionario.f_numtlf);
    printf("    Estado Civil         :%c\n", funcionario.f_estcivil);
    printf("    Nº de filhos          :%d\n", funcionario.f_numfil);
    printf("    Cargo    :%c\n", funcionario.f_cargo);
    printf("    Idade:%d\n", funcionario.f_idade);
}

void writefile() {
    FILE *fp;
    fp = fopen("funcionario.txt", "a+b");
    fwrite(&funcionario, sizeof (struct dados), 1, fp);
    fclose(fp);
    return;
}

void searchfile() {


    FILE *fp;
    fp = fopen("funcionario.txt", "r");
    fseek(fp, 0, SEEK_END);
    tl = ftell(fp);
    sl = sizeof (funcionario);
    ts = tl / sl;
    printf("\nchoose customer number:");
    scanf("%d", &n);
    fseek(fp, (n - 1) * sl, SEEK_SET);
    fread(&funcionario, sl, 1, fp);
    output();
    fclose(fp);
}

void editar() {
    searchfile();

    FILE *fp;
    FILE *fptr;
    int h;
    int found = 0;
    int ka = 0;
    int p;
    fp = fopen("funcionario.txt", "rb+");
    fptr = fopen("temp1.txt", "rb+");
    printf("\t");
    printf("Codigo do Funcionario: ");
    scanf("%d", &h);
    printf("\n");
    p = n;

}

/*
 * 
 */
int main() {
    int ch = 0;


    scanf("%i", & ch);
    switch (ch) {
        case 1:
            system("clear");
            printf("\nhow many customer accounts?");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                input();
                writefile();
            }
            main();
        case 2:
            searchfile();
            main();
        case 3:
            system("clear");
            exit(1);

    }
    return 0;
}

