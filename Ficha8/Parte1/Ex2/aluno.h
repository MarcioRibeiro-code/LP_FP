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
#define FILENAME "lib_aluno.bin"
#define LOG_FILE "log.txt"


#define ALUNOS_MAX 30
#define STRING_MAX 40

#define ERRO_ALUNO_NAO_EXISTE   "O aluno não existe na lista."
#define ERRO_LISTA_VAZIA        "A lista de alunos está vazia."
#define ERRO_LISTA_CHEIA        "A lista de alunos está cheia."
#define ERRO_ALUNO_EXISTE       "O número de aluno já se encontra atribuído."

#define MIN_NUM_ALUNO           0
#define MAX_NUM_ALUNO           1000
#define MSG_OBTER_NUM_ALUNO     "Insira um número de aluno [0-1000]: "

#define MAX_NOME_ALUNO          31
#define MSG_OBTER_NOME              "Insira o nome do aluno: "

#define MIN_DIA                 0
#define MAX_DIA                 31
#define OBTER_DIA_NASC          "Insira o dia de nascimento: "

#define MIN_MES                 1
#define MAX_MES                 12
#define OBTER_MES_NASC          "Insira o mês de nascimento: "

#define MIN_ANO                 1990
#define MAX_ANO                 2021
#define OBTER_ANO_NASC          "Insira o ano de nascimento: "

typedef struct {
    int dia, mes, ano;
} data;

typedef struct {
    
    int numero;
    char nome[30];
    data data_nascimento;

} Aluno;

typedef struct{
    int contador;
    Aluno alunos[ALUNOS_MAX];
}Alunos;


void inserirAlunos(Alunos *alunos);
void procurarAlunos(Alunos alunos);
void atualizarAlunos(Alunos *alunos);
void removerAlunos(Alunos *alunos);
void listarAlunos(Alunos alunos);



#endif /* ALUNO_H */

