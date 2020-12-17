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

#define TAMANHO 2

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int num;
    char nome[30];
    data Data;

} aluno;

int inserir_umaluno(int *count) {
    int a = *count;
    aluno arluno;

    FILE *fp = fopen(FILENAME, "wb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

        printf("ALUNO [%i]", a);
        arluno.num = a;
        printf("\nNOME");
        scanf(" %s", arluno.nome);
        printf("\nDATA DE NASCIMENTO");
        printf("\nDIA");
        scanf("%d", arluno.Data.dia);
        printf("\nMES");
        scanf("%d", arluno.Data.mes);
        printf("\nANO");
        scanf("%d", arluno.Data.ano);

        fwrite(&arluno, sizeof (aluno), 1, fp);
        a++;
 

    fclose(fp);
    return a;
}

void consultar_umaluno() {
    int i;
    aluno arluno;
    printf("Introduza o numero do aluno");
    scanf("%i", &i);


    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < TAMANHO; j++) {
        fread(&arluno, sizeof (aluno), 1, fp);
        if (i == arluno.num) {
            printf("\n\nNum aluno: %d", arluno.num);
            printf("\nNome aluno: %s", arluno.nome);
            printf("\n %d-%d-%d ", arluno.Data.dia, arluno.Data.mes,
                    arluno.Data.ano);
        }

    }
    fclose(fp);
}

void ac_umaluno(int *count) {
    char aux;

    printf("Opçoes");
    printf("\nC- Consultar");
    printf("\nI- Inserir\n");
    scanf(" %c", &aux);

    if (aux == 'C') {
        consultar_umaluno();
    } else if (aux == 'I') {
        *count = inserir_umaluno(count);
    }
}

int inserir_30aluno(int *count, aluno aluno[]) {
    int a = *count;
    do {
        scanf("%d", &aluno[a].num);
        scanf(" %s", aluno[a].nome);
        scanf("%d", &aluno[a].Data.dia);
        scanf("%d", &aluno[a].Data.mes);
        scanf("%d", &aluno[a].Data.ano);
        a++;
    } while (a < TAMANHO);
    return a;
}

void consultar_30aluno(int *count, aluno aluno[]) {
    int a = 0;
    do {
        printf("\n\nNum aluno: %d", aluno[a].num);
        printf("\nNome aluno: %s", aluno[a].nome);
        printf("\n %d-%d-%d ", aluno[a].Data.dia, aluno[a].Data.mes,
                aluno[a].Data.ano);
        a++;
    } while (a < *count);

}

void ac_30alunos(int *count, aluno aluno[]) {
    char aux;

    printf("Opçoes");
    printf("\nC- Consultar");
    printf("\nI- Inserir\n");
    scanf(" %c", &aux);

    if (aux == 'C') {
        consultar_30aluno(count, aluno);
    } else if (aux == 'I') {
        *count = inserir_30aluno(count, aluno);
    }


}
#endif /* ALUNO_H */

