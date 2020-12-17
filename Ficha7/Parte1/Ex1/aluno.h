/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aluno.h
 * Author: LAPTOP
 *
 * Created on 4 de dezembro de 2020, 10:00
 */

#ifndef ALUNO_H
#define ALUNO_H
#define TAMANHO 2

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    int num;
    char nome[30];
    data Data;

} aluno;

void inserir(aluno aluno[]) {
    for (int i = 0; i < TAMANHO; i++) {
        scanf("%d", &aluno[i].num);
        scanf(" %s", aluno[i].nome);
        scanf("%d", &aluno[i].Data.dia);
        scanf("%d", &aluno[i].Data.mes);
        scanf("%d", &aluno[i].Data.ano);

    }


}

void imprimir(aluno aluno[]) {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        printf("\n\nNum aluno: %d", aluno[i].num);
        printf("\nNome aluno: %s", aluno[i].nome);
        printf("\n %d-%d-%d ", aluno[i].Data.dia, aluno[i].Data.mes, aluno[i].Data.ano);
    }
}

int inserir_umaluno(int *count, aluno aluno[]) {
    int a = *count;
    do {
        scanf("%d", &aluno[a].num);
        scanf(" %s", aluno[a].nome);
        scanf("%d", &aluno[a].Data.dia);
        scanf("%d", &aluno[a].Data.mes);
        scanf("%d", &aluno[a].Data.ano);
        a++;
    } while (a < 1);


    return a;
}

void consultar_umaluno(aluno aluno[]) {
    int i;
    printf("Introduza o numero do aluno");
    scanf("%i", &i);

    for (int j = 0; j < TAMANHO; j++) {
        if (i == aluno[j].num) {
            printf("\n\nNum aluno: %d", aluno[j].num);
            printf("\nNome aluno: %s", aluno[j].nome);
            printf("\n %d-%d-%d ", aluno[j].Data.dia, aluno[j].Data.mes,
                    aluno[j].Data.ano);
        }

    }

}

void ac_umaluno(int *count, aluno aluno[]) {
    char aux;

    printf("Opçoes");
    printf("\nC- Consultar");
    printf("\nI- Inserir\n");
    scanf(" %c", &aux);

    if (aux == 'C') {
        consultar_umaluno(aluno);
    } else if (aux == 'I') {
        *count = inserir_umaluno(count, aluno);
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

void consultar_30aluno(int *count,aluno aluno[]) {
    int a=0;
    do {
        printf("\n\nNum aluno: %d", aluno[a].num);
        printf("\nNome aluno: %s", aluno[a].nome);
        printf("\n %d-%d-%d ", aluno[a].Data.dia, aluno[a].Data.mes,
                aluno[a].Data.ano);
        a++;
    } while (a < *count);

}

void ac_30alunos(int *count,aluno aluno[]) {
    char aux;

    printf("Opçoes");
    printf("\nC- Consultar");
    printf("\nI- Inserir\n");
    scanf(" %c", &aux);

    if (aux == 'C') {
        consultar_30aluno(count,aluno);
    } else if (aux == 'I') {
        *count = inserir_30aluno(count, aluno);
    }


}



#endif /* ALUNO_H */

