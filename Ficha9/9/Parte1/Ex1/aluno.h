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
#define FILENAME "lib_aluno.bin"
#define FILENAME_TXT "lib_aluno.txt"
#define FILENAME_LOG "log.txt"
#define TAMANHO_INICIAL 2

#include <time.h>

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int contador, flag, tamanho;
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

void Inserir(ALUNO **alunos) {
    int x = (*alunos)[0].contador;
    *alunos = (ALUNO*) realloc(*alunos, sizeof (ALUNO)*2);

    (*alunos)[x].num = x;
    (*alunos)[x].flag = 1;
    printf("Nome: ");
    scanf(" %[^\n]", (*alunos)[x].nome);
    printf("Data de Nascimento\n");
    printf("DIA: ");
    scanf("%d", &(*alunos)[x].Data.dia);
    printf("MES: ");
    scanf("%d", &(*alunos)[x].Data.mes);
    printf("ANO: ");
    scanf("%d", &(*alunos)[x].Data.ano);
    (*alunos)[0].contador++;


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

void imprimir(ALUNO *alunos, int contador) {

    if (alunos[contador].flag == 1) {
        printf("\nAluno [%i]", alunos[contador].num);
        printf("\nNOME: %s", alunos[contador].nome);
        printf("\nData de Nascimento: %d-%d-%d", alunos[contador].Data.dia,
                alunos[contador].Data.mes, alunos[contador].Data.ano);
    }

    if (alunos[contador].flag == 0) {

        printf("\nAluno [%i]", alunos[contador].num);
        printf("\nInativo");
    }

}

void Listar(ALUNO *alunos) {
    int x = alunos[0].contador;
    printf("Listar ALUNOS");

    for (int i = 0; i < x; ++i) {
        imprimir(alunos, i);
        printf("\n");
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
        if (aux == i) {
            imprimir(alunos, aux);
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
    if (aux != -1) {
        do {
            Listar(alunos);



            printf("\n--Alterar--\n"
                    "1.Nome\n"
                    "2.Data de Nascimento\n"
                    "0.acabar\n: ");
            scanf("%d", &op);
            switch (op) {
                case 1:

                    printf("\nNOME: ");
                    scanf(" %[^\n]s", alunos[aux].nome);


                    break;
                case 2:
                    printf("\nData de Nascimento");
                    printf("DIA: ");
                    scanf("%i", &alunos[aux].Data.dia);
                    printf("MES: ");
                    scanf("%i", &alunos[aux].Data.mes);
                    printf("ANO: ");
                    scanf("%i", &alunos[aux].Data.ano);
                    break;

                case 0:
                    break;
            }
        } while (op != 0);
    }


}

void Eliminar(ALUNO *alunos) {
    int x = alunos[0].contador;

    int num, contador, op;

    Listar(alunos);
    printf("\n\nConsultar Aluno");
    printf("\nNum do aluno: ");
    scanf(" %i", &num);
    contador = ProcurarAluno(alunos, x, num);

    if (contador != -1) {
        printf("\nAluno removido: %i", alunos[contador].num);

        alunos[contador].flag = 0;
    }

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

int carregar(ALUNO **alunos) {

    int returno = 0;
    int contador = 0;

    FILE *fp = fopen(FILENAME, "rb");

    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        rewind(fp);
        if (contador > 0) {
            *alunos = (ALUNO*) malloc(contador * sizeof (ALUNO));
            fread(*alunos, sizeof (ALUNO), contador, fp);
            (*alunos)[0].tamanho = (*alunos)[0].contador = contador;
            printf("contador : %i", (*alunos)[0].contador);
            returno = 1;

        }
        fclose(fp);
        if (!returno) {
            fp = fopen(FILENAME, "wb");
            if (fp != NULL) {
                *alunos = (ALUNO*) malloc(TAMANHO_INICIAL * sizeof (ALUNO));
                contador = 0;
                (*alunos)[0].contador = contador;
                (*alunos)[0].tamanho = TAMANHO_INICIAL;
                fclose(fp);

                returno = 1;
            }

        }
    }
    return returno;
}

void LerFicheiro(FILE *fp) {
    fp = fopen(FILENAME_TXT, "r");

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
                strcpy(values[i].contador, field);


            if (field_count == 1)
                strcpy(values[i].flag, field);

            if (field_count == 2)
                strcpy(values[i].num, field);


            if (field_count == 3)
                strcpy(values[i].nome, field);


            if (field_count == 4)
                strcpy(values[i].data_d, field);


            if (field_count == 5)
                strcpy(values[i].data_m, field);


            if (field_count == 6)
                strcpy(values[i].data_a, field);



            field = strtok(NULL, ",");
            field_count++;
            i++;
        }
        for (int j = 0; j < i; j++) {
            printf("col1: %s ,col2: %s ,col3: %s ,col4: %s ",
                    values[i].contador, values[i].flag, values[i].num, values[i].nome);
        }
    }
    fclose(fp);
    printf("CONTADOR: %i", i);


    //Listar(alunos);
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
    if (TAMANHO_INICIAL < x) {
        alunos = realloc(alunos, sizeof (ALUNO)*2);
    }
    fread(alunos, sizeof (ALUNO), x, fp);
    alunos[0].contador = x;


    fclose(fp);
}

void EscreverFicheiro(ALUNO *alunos, FILE *fp) {
    fp = fopen(FILENAME, "w");
    int x;
    x = alunos[0].contador;

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

