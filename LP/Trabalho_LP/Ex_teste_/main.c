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

#include "input.h"
#include "funclib.h"

//struct


int n = 0; //Utilizado no create
int tl, sl, ts;

void input() {

    FUNCIONARIO funcionario;

    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("\nErro no ficheiro");
    }
    
    printf("         Nome Funcionario:");
    scanf("%s", &funcionario.nome);
    printf("\n       Numero Telefone:");
    scanf("%d", &funcionario.num_tlf);
    printf("\n       Estado Civil:");
    printf("\n1 - CASADO\n2 - DIVORCIADO\n3 - SEPARAÇÃO DE FACTO\n4 - VIUVEZ\n5 - SOLTEIRO\n");
    scanf(" %d", &funcionario.est_civil);
    printf("         Numero de Filhos:");
    scanf("%d", &funcionario.num_dependentes);
    printf("         Cargo:");
    scanf(" %c", &funcionario.cargo);
    printf("         Data de nascimento");
    printf("\nDIA: "); scanf("%d", &funcionario.data_de_nascimento.dia);
    printf("MES: ");scanf("%d",&funcionario.data_de_nascimento.mes);
    printf("ANO: ");scanf("%d",&funcionario.data_de_nascimento.ano);
    printf("Data de entrada");
    printf("\nDIA: ");scanf("%d",&funcionario.data_de_entrada.dia);
    printf("MES: ");scanf("%d",&funcionario.data_de_entrada.mes);
    printf("ANO: ");scanf("%d",&funcionario.data_de_entrada.ano);
    funcionario.codigo++;
    fwrite(&funcionario, sizeof (FUNCIONARIO), 1, fp);
    fclose(fp);


}
 



void output() {

    printf("\nNome Funcionario: %s",FUNCIONARIO.nome);

    printf("\nNumero Telefone: %s",FUNCIONARIO.num_tlf);

    printf("\n       Estado Civil:");
    printf("\n1 - CASADO\n2 - DIVORCIADO\n3 - SEPARAÇÃO DE FACTO\n4 - VIUVEZ\n5 - SOLTEIRO\n");
    scanf(" %d", &funcionario.est_civil);
    printf("         Numero de Filhos:");
    scanf("%d", &funcionario.num_dependentes);
    printf("         Cargo:");
    scanf(" %c", &funcionario.cargo);
    printf("         Data de nascimento");
    printf("\nDIA: "); scanf("%d", &funcionario.data_de_nascimento.dia);
    printf("MES: ");scanf("%d",&funcionario.data_de_nascimento.mes);
    printf("ANO: ");scanf("%d",&funcionario.data_de_nascimento.ano);
    printf("Data de entrada");
    printf("\nDIA: ");scanf("%d",&funcionario.data_de_entrada.dia);
    printf("MES: ");scanf("%d",&funcionario.data_de_entrada.mes);
    printf("ANO: ");scanf("%d",&funcionario.data_de_entrada.ano);
}
/*
void searchfile() {

    dados funcionario;
    int indice;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Codigo Funcionario");
    scanf("%i", &indice);

    if (fseek(fp, sizeof (dados) * indice, SEEK_SET) == 0) {
        if (fread(&funcionario, sizeof (dados), 1, fp)) {
            printf("\n\n    codigo    :%d\n", funcionario.f_cod);
            printf("    Name 	   :%s\n", funcionario.f_nome);
            printf("    Mobile no      :%d\n", funcionario.f_numtlf);
            printf("    Estado Civil         :%s\n", estadoCivilToString(funcionario.f_estcivil));
            printf("    Nº de filhos          :%d\n", funcionario.f_numfil);
            printf("    Cargo    :%s\n", cargoToString(funcionario.f_cargo));
            printf("    Idade:%d\n", funcionario.f_idade);
        }
    }

    fclose(fp);
}

void editar() {
    dados func;
    dados temp;

    int indice;

    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Codigo Funcionario");
    scanf("%i", &indice);

    if (fseek(fp, sizeof (dados) * indice, SEEK_SET) == 0) {
        if (fread(&func, sizeof (dados), 1, fp)) {
            printf("         Nome Funcionario:");
            scanf("%s", &temp.f_nome);
            strcpy(func.f_nome, temp.f_nome);
            printf("\n       Numero Telefone:");
            scanf("%d", &temp.f_numtlf);
            func.f_numtlf = temp.f_numtlf;
            printf("\n       Estado Civil:");
            scanf(" %d", &temp.f_estcivil);
            func.f_estcivil = temp.f_estcivil;
            printf("         Numero de Filhos:");
            scanf("%d", &temp.f_numfil);
            func.f_numfil = temp.f_numfil;
            printf("         Cargo:");
            scanf(" %d", &temp.f_cargo);
            func.f_cargo = temp.f_cargo;
            printf("         Idade funcionario:");
            scanf("%d", &temp.f_idade);
            func.f_idade = temp.f_idade;



            fseek(fp, sizeof (dados) * -1, SEEK_CUR);

            fwrite(&func, sizeof (dados), 1, fp);
        }
    }

    fclose(fp);

}



void parsecsv(dict values[], int x) {
    FILE *fp = fopen(FILENAME_CSV, "r");

    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    char buff[1024]; // guarda as 1º 1024 linhas para o buff
    int row_count = 0;
    int field_count = 0;

    //array de struct para armazenar valores

    int i = 0;
    while (fgets(buff, 1024, fp)) {
        field_count = 0;
        row_count++;

        char *field = strtok(buff, ";"); // separa o buff com ;
        while (field != NULL) {
            if (field_count == 0)
                strcpy(values[i].col1, field);
            if (field_count == 1)
                strcpy(values[i].col2, field);
            if (field_count == 2)
                strcpy(values[i].col3, field);
            if (field_count == 3)
                strcpy(values[i].col4, field);
            if (field_count == 4)
                strcpy(values[i].col5, field);
            if (field_count == 5)
                strcpy(values[i].col6, field);
            if (field_count == 6)
                strcpy(values[i].col7, field);

            field = strtok(NULL, ";");
            field_count++;
        }
        i++;
    }
    x = i;
    fclose(fp);

}


 */

void searchfile() {
    char ch;
    char nam[100];
    int n,i,m=1;
    FILE *fp;
    
    fp=fopen(FILENAME,"rb");
    
    do{
        printf("\n1-codigo");
        printf("\n2-nome");
        scanf("%c",&ch);
    }while(ch!='1' && ch!='2');
    switch(ch){
        case '1':
            fseek(fp,0,SEEK_END);
            tl=ftell(fp);
            sl=sizeof(FUNCIONARIO);
            ts=tl/sl;
            do{
                printf("codigo");
                scanf("%d",&n);
                if(n<=0 || n>ts)
			printf("\nenter correct\n");
			else{
			    fseek(fp,(n-1)*sl,SEEK_SET);
			    fread(&FUNCIONARIO,sl,1,fp);
			    
			}
            }
            
            break;
    
    }
    
}



/*
 * 
 */
int main() {
    int menu, x;
    FILE *fp;
    int i,n;
    char ch;
  

    do {
        printf("\n\nMENU");
        printf("\n1- Inserir Funcionario");
        printf("\n2- Listar todos os Funcionarios");
        printf("\n3- Consultar Funcionario");
        printf("\n4- Atualizar dados Funcionario");
        printf("\n5- Eliminar Funcionario");
        printf("\n6- Carregar Ficheiro");
        printf("\n7- Imprimir no Ficheiro");
        printf("\n0 - Sair\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                input();
                break;
            case 2:
                searchfile();
                break;
            
            case 0:
                exit(1);

        }
    } while (menu != 0);

































    /*int ch = 0, x=0;
    dict values[999];
    
    
    readcsv(values);

        printf("1 - Inserir");
        printf("2 - Pesquisar");
        printf("3 - Listar");
        printf("4 - Editar");
        printf("0 - sair");

        scanf("%i", & ch);
        switch (ch) {
            case 1:

                printf("\nhow many customer accounts?");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    input();
                }
                main();
            case 2:
                searchfile();
                main();

            case 3:
                output();
                main();

            case 4:
                editar();
                main();
            case 0:
                system("clear");
                exit(1);

        }
     */


    //parsecsv(values, x);
    //printValues(values, x);
   // free(funcionarios);
    return 0;
}

