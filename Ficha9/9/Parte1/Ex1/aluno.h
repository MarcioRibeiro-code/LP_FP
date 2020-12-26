/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aluno.h
 * Author: Desktop
 *
 * Created on 12 de dezembro de 2020, 21:38
 */

#ifndef ALUNO_H
#define ALUNO_H
#define FILENAME "lib_aluno.txt"
#define FILENAME_LOG "log.txt"
#define TAMANHO_INICIAL 2

#include <time.h>


typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int contador, flag;
    int num;
    char nome[30];
    data Data;

} ALUNO;

typedef struct {
    char contador[50], flag[50];
    char nome[50];
    char num[50];
    char data_d[3], data_m[3], data_a[5];
} LER_F;

void logMsg(char *msg, char *filename) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}

void Inserir(ALUNO *alunos) {
    int x = alunos[0].contador;

    alunos[x].num = x;
    alunos[x].flag = 1;
    printf("Nome: ");
    scanf(" %[^\n]", alunos[x].nome);
    printf("Data de Nascimento\n");
    printf("DIA: ");
    scanf("%d", &alunos[x].Data.dia);
    printf("MES: ");
    scanf("%d", &alunos[x].Data.mes);
    printf("ANO: ");
    scanf("%d", &alunos[x].Data.ano);
    alunos[0].contador++;

    alunos = realloc(alunos, sizeof (ALUNO)*2);
}

int ProcurarAluno(ALUNO alunos[], int x, int aux) {
    int i;
    for (i = 0; i < x; i++) {

        if (alunos[i].num == aux) {
            return i;
        }
    }
    return -1;
}

void Listar(ALUNO *alunos) {
    int x = alunos[0].contador;
    printf("Listar ALUNOS");

    for (int i = 0; i < x; ++i) {
        if (alunos[i].flag == 1) {
            printf("\n\nAluno [%i]", i);
            printf("\nNOME: %s", alunos[i].nome);
            printf("\nData de Nascimento: %d-%d-%d", alunos[i].Data.dia, alunos[i].Data.mes, alunos[i].Data.ano);
        } else {
            printf("\nAluno [%i]", i);
            printf("\nInativo");
        }
    }
}

void Consulta(ALUNO *alunos) {
    int x = alunos[0].contador;

    int num, aux;

    printf("\n\nConsultar Aluno");
    printf("\nNum do aluno: ");
    scanf(" %i", &num);
    aux = ProcurarAluno(alunos, x, num);


    for (int i = 0; i < x; i++) {
        if (aux == i && alunos[i].flag == 1) {
            printf("\nAluno [%i]", alunos[i].num);
            printf("\nNOME: %s", alunos[i].nome);
            printf("\nData de Nascimento: %d-%d-%d", alunos[i].Data.dia,
                    alunos[i].Data.mes, alunos[i].Data.ano);
        } else {
            printf("\nAluno [%i]", alunos[i].num);
            printf("\nInativo");
        }
    }
}

void Atualizar(ALUNO *alunos) {
    int x = alunos[0].contador;

    int num, aux, op;

    printf("\n\nConsultar Aluno");
    printf("\nNum do aluno: ");
    scanf(" %i", &num);
    aux = ProcurarAluno(alunos, x, num);
    do {
        Listar(alunos);



        printf("\n--Alterar--\n"
                "1.Nome\n"
                "2.Data de Nascimento\n"
                "0.acabar\n: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                for (int i = 0; i < x; i++) {
                    if (i == aux) {
                        printf("\nNOME: ");
                        scanf("%[^\n]s", alunos[aux].nome);
                    }
                }
                break;
            case 2:

                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        printf("\nData de Nascimento");
                        printf("DIA: ");
                        scanf("%i", &alunos[aux].Data.dia);
                        printf("MES: ");
                        scanf("%i", &alunos[aux].Data.mes);
                        printf("ANO: ");
                        scanf("%i", &alunos[aux].Data.ano);
                    }
                }
                break;

            case 0:
                break;
        }
    } while (op != 0);
}

void Eliminar(ALUNO *alunos) {
    int x = alunos[0].contador;

    int num, aux, op;

    printf("\n\nConsultar Aluno");
    printf("\nNum do aluno: ");
    scanf(" %i", &num);
    aux = ProcurarAluno(alunos, x, num);

    Listar(alunos);
    printf("\nAluno a remover: ");

    alunos[aux].flag = 0;
    Listar(alunos);

}

int StringToInteger(char* string) {
    int digit, j = 1, m = 0;

    for (int i = strlen(string) - 1; i >= 0; i--) {
        digit = string[i];
        digit = digit - 48;
        m = m + (digit * j);
        j = j * 10;
    }


    return digit;
}

void LerFicheiro(ALUNO *alunos, FILE *fp) {
    fp = fopen(FILENAME, "r");

    if (!fp) {
        printf("\nError occured");
        exit(EXIT_FAILURE);
    }

    char buff[1024];
    int row_count = 0;
    int field_count = 0;

    LER_F values[50];

    int i = 0;
    while (fgets(buff, 1024, fp)) {
        field_count = 0;
        row_count = 0;
        char *field = strtok(buff, ",");

        while (field) {
            if (field_count == 0)
                strncpy(values[i].contador, field, 50);
            alunos[i].contador = StringToInteger(values[i].contador);

            if (field_count == 1)
                strncpy(values[i].flag, field, 50);
            alunos[i].flag = StringToInteger(values[i].flag);

            if (field_count == 2)
                strncpy(values[i].num, field, 50);
            alunos[i].num = StringToInteger(values[i].num);

            if (field_count == 3)
                strncpy(values[i].nome, field, 50);
            strncpy(alunos[i].nome, values[i].nome, 50);

            if (field_count == 4)
                strncpy(values[i].data_d, field, 3);
            alunos[i].Data.dia = atoi(values[i].data_d);

            if (field_count == 5)
                strncpy(values[i].data_m, field, 3);
            alunos[i].Data.mes = atoi(values[i].data_m);

            if (field_count == 6)
                strncpy(values[i].data_a, field, 5);
            alunos[i].Data.ano = atoi(values[i].data_a);


            field = strtok(NULL, ",");
            field_count++;
        }
        alunos = realloc(alunos, sizeof (ALUNO)*2);
        i++;
    }
    fclose(fp);
    Listar(alunos);
}

void LerFicheiro_Binario(ALUNO *alunos, FILE *fp) {
    int x;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    //fread(&alunos[0].contador,sizeof(int),2,fp);
    while (fread(alunos, sizeof (ALUNO), 1, fp) == 1) {
        x += alunos->contador;
    }
    printf("\nLido: %i", x);
    rewind(fp);
    if(TAMANHO_INICIAL<x){
        alunos = realloc(alunos, sizeof (ALUNO)*2);
    }
    fread(alunos, sizeof (ALUNO), x, fp);
    alunos[0].contador = x;


    fclose(fp);
}

void EscreverFicheiro(ALUNO *alunos,FILE *fp){
    fp =fopen(FILENAME,"w");
    int x;
    x=alunos[0].contador;
    
       for (int i = 0; i < x; i++) {
           fprintf(fp, "%d,%d,%d,", alunos[i].contador, alunos[i].flag, alunos[i].num);
           fprintf(fp, "%s,", alunos[i].nome);
           fprintf(fp, "%d,%d,%d\n", alunos[i].Data.dia, alunos[i].Data.mes, alunos[i].Data.ano);
       }
    fclose(fp);
}



void EscreverFicheiro_Binario(ALUNO *alunos, FILE *fp) {
    fp = fopen(FILENAME, "wb");
    int x;
    x = alunos[0].contador;
    
    fwrite(alunos, sizeof (ALUNO), x, fp);



    fclose(fp);

    puts("Gravado com sucesso");
}


#endif /* ALUNO_H */

