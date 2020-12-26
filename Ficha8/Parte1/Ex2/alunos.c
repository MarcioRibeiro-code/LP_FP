#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "input.h"

int i=0;

void imprimirAluno(Aluno aluno) {
    printf("\n%3d %-30s %d-%d-%d", aluno.numero, aluno.nome, aluno.data_nascimento.dia, aluno.data_nascimento.mes, aluno.data_nascimento.ano);
}

void apagarDadosAluno(Aluno *aluno) {
    aluno->numero = 0;
    strcpy(aluno->nome, "");
    aluno->data_nascimento.dia = aluno->data_nascimento.mes = aluno->data_nascimento.ano = 0;
}

int procurarAluno(Alunos alunos, int numero) {
    int i;
    for (i = 0; i < alunos.contador; i++) {
        if (alunos.alunos[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

int inserirAluno(Alunos *alunos,int i) {
    int numero = i++;

    if (procurarAluno(*alunos, numero) == -1) {

        alunos->alunos[alunos->contador].numero = numero;

        lerString(alunos->alunos[alunos->contador].nome, MAX_NOME_ALUNO, MSG_OBTER_NOME);

        alunos->alunos[alunos->contador].data_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
        alunos->alunos[alunos->contador].data_nascimento.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);
        alunos->alunos[alunos->contador].data_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);


        escrever();

        return alunos->contador++;
    }
    return -1;
}

void atualizarAluno(Aluno *aluno) {
    lerString((*aluno).nome, MAX_NOME_ALUNO, MSG_OBTER_NOME);
    (*aluno).data_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
    (*aluno).data_nascimento.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);
    (*aluno).data_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);
}

void inserirAlunos(Alunos *alunos) {
    if (alunos->contador < ALUNOS_MAX) {
        if (inserirAluno(alunos,i) == -1) {
            puts(ERRO_ALUNO_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_CHEIA);
    }
}

void procurarAlunos(Alunos alunos) {
    int numero = procurarAluno(alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        imprimirAluno(alunos.alunos[numero]);
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void atualizarAlunos(Alunos *alunos) {
    int numero = procurarAluno(*alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        atualizarAluno(&(*alunos).alunos[numero]);
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void removerAlunos(Alunos *alunos) {
    int i, numero = procurarAluno(*alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        for (i = numero; i < alunos->contador - 1; i++) {
            alunos->alunos[i] = alunos->alunos[i + 1];
        }

        apagarDadosAluno(&alunos->alunos[i]);

        alunos->contador--;
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void listarAlunos(Alunos alunos) {
    if (alunos.contador > 0) {
        int i;
        for (i = 0; i < alunos.contador; i++) {
            //imprimirAluno(alunos.alunos[i]);
            lerV1();
        }
    }
    else {

        puts(ERRO_LISTA_VAZIA);
    }
}

void escrever() {
    int i;
    Aluno aluno;
    Alunos alunos;

    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp,"%d",alunos[alunos.contador]);
    fwrite(&aluno, sizeof (Aluno), 1, fp);
    
    fclose(fp);
}

void lerV1() {
    int i;
    Aluno aluno;
    Alunos alunos;
    
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < alunos.contador; ++i) {
        fread(&alunos, sizeof (Alunos), 1, fp);
        printf("Contador: %d", alunos.contador);
       // printf("\n\nNum aluno: %d", alunos[alunos->contador].numero);
        printf("\nNome aluno: %s", aluno.nome);
        printf("\n %d-%d-%d ", aluno.data_nascimento.dia, aluno.data_nascimento.mes,
                aluno.data_nascimento.ano);
    }

    fclose(fp);
}