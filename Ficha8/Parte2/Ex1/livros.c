#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "booklib.h"
#include "input.h"

void logMsg(char *msg, char *filename) { //FALTA DECLARAR O NOME DO FILENAME LOGS E CRIAR
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}

char *tipoToString(tipo_genero tipo) {
    switch (tipo) {
        case FICCAO:
            return "FICÇÃO";
            break;
        case TECNICO:
            return "TECNICO";
            break;
        case ROMANCE:
            return "ROMANCE";
            break;
        case ESTUDO:
            return "ESTUDO";
            break;
        default:
            return "FICÇÃO";
    }
}

int ProcurarLivro(LIVROS livros[], char ISBN[], int x) {
    int i;
    for (i = 0; i < x; i++) {

        if (strcmp(livros[i].ISBN, ISBN) == 0) {
            return i;
        }
    }
    return -1;
}

void Inserir(LIVROS livros[]) {
    char ISBN[DIG_ISBN];
    int x = livros[0].contador;

    printf("\nINSERIR LIVROS");

    printf("\nIntroduza um numero para o aluno: ");
    scanf(" %s", ISBN);

    if (ProcurarLivro(livros, ISBN, x) == -1) {
        strcpy(livros[x].ISBN, ISBN);
        printf("\nTITULO");
        scanf(" %[^\n]", livros[x].titulo);
        printf("\nDATA DE PUBLICAÇÃO");
        printf("\n DIA");
        scanf("%d", &livros[x].data_de_publicacao.dia);
        printf("\n MES");
        scanf("%d", &livros[x].data_de_publicacao.mes);
        printf("\n ANO");
        scanf("%d", &livros[x].data_de_publicacao.ano);
        printf("\nTIPO\n 0-Ficção\n 1-Tecnico\n 2-Romance\n 3-Estudo");
        scanf("%d", &livros[x].tipo);
        printf("\nEDITORA");
        printf("\n MORADA");
        scanf(" %[^\n]", livros[x].editora.morada);
        printf("\n NOME");
        scanf(" %[^\n]", livros[x].editora.nome);
        printf("\nAutores");
        printf("\nNº de autores");
        scanf("%d", &livros[x].n_autores);
        for (int j = 0; j < livros[x].n_autores; j++) {
            printf("AUTOR[%i]", j + 1);
            scanf(" %[^\n]", &livros[x].autores[j].autores);
        }
        livros[x].flag = 1;
        livros[0].contador++;
    }
}

void Listar(LIVROS livros[]) {
    int x = livros[0].contador;
    printf("Listar ALUNOS");

    for (int i = 0; i != x; ++i) {
        printf("\n\nLIVRO [%i]", i);
        printf("\n ISBN: %s", livros[i].ISBN);
        printf("\n TITULO: %s", livros[i].titulo);
        printf("\n DATA DE PUBLICACAÇÃO: %d-%d-%d", livros[i].data_de_publicacao.dia,
                livros[i].data_de_publicacao.mes, livros[i].data_de_publicacao.ano);
        printf("\n TIPO: %s", tipoToString(livros[i].tipo));
        printf("\n EDITORA");
        printf("\n  NOME: %s", livros[i].editora.nome);
        printf("\n  MORADA: %s", livros[i].editora.morada);

        for (int j = 0; j < livros[j].n_autores; j++) {
            printf("\n AUTORES [%i]", j + 1);
            printf("\n  %s", livros[i].autores[j].autores);
        }

    }
}

void Consulta(LIVROS livros[]) {
    int x = livros[0].contador;
    char ISBN[DIG_ISBN];

    cleanInputBuffer();
    printf("Consultar LIVRO");
    printf("\nISBN do livro a alterar: ");
    scanf(" %s", ISBN);

    for (int i = 0; i < x; ++i) {
        if (ProcurarLivro(livros, ISBN, x) == i) {
            printf("\n ISBN: %s", livros[i].ISBN);
            printf("\n TITULO: %s", livros[i].titulo);
            printf("\n DATA DE PUBLICACAÇÃO: %d-%d-%d", livros[i].data_de_publicacao.dia,
                    livros[i].data_de_publicacao.mes, livros[i].data_de_publicacao.ano);
            printf("\n TIPO: %s", tipoToString(livros[i].tipo));
            printf("\n EDITORA");
            printf("\n  NOME: %s", livros[i].editora.nome);
            printf("\n  MORADA: %s", livros[i].editora.morada);

            for (int j = 0; j < livros[j].n_autores; j++) {
                printf("\n AUTORES [%i]", j + 1);
                printf("\n  %s", livros[i].autores[j].autores);
            }
        }
    }
}

void Atualizar(LIVROS livros[]) {
    char ISBN[DIG_ISBN];
    int x = livros[0].contador;
    int aux;
    int op;

    printf("\nISBN do livro a alterar: ");
    scanf(" %s", ISBN);
    aux = ProcurarLivro(livros, ISBN, x);
    do {
        Listar(livros);



        printf("\n--Alterar--\n"
                "1.TITULO\n"
                "2.DATA DE PUBLICACAO\n"
                "3.TIPO\n"
                "4.EDITORA\n"
                "5.AUTORES\n"
                "0.acabar\n: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        printf("\nTITULO");
                        cleanInputBuffer();
                        scanf(" %[^\n]", livros[aux].titulo);

                    }
                }
                break;
            case 2:

                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        printf("\nDATA DE PUBLICACAO");
                        cleanInputBuffer();
                        printf("\n DIA: ");
                        scanf(" %d", livros[aux].data_de_publicacao.dia);
                        printf("\n MES: ");
                        scanf(" %d", livros[aux].data_de_publicacao.mes);
                        printf("\n ANO: ");
                        scanf("%d", livros[aux].data_de_publicacao.ano);
                    }
                }
                break;

            case 3:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        printf("\nTIPO\n"
                                "0-Ficcao\n"
                                "1-Tecnico\n"
                                "2-Romance\n"
                                "3-Estudo\n");
                        cleanInputBuffer();
                        printf("\n OPÇÃO: ");
                        scanf(" %d", livros[aux].tipo);
                    }
                }
                break;

            case 4:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        cleanInputBuffer();
                        printf("NOME: ");
                        scanf("%[^\n]", livros[aux].editora.nome);
                        printf("\n Morada: ");
                        scanf(" %[^\n]", livros[aux].editora.morada);
                    }
                }
                break;

            case 5:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        cleanInputBuffer();
                        printf("Nº de autores: ");
                        scanf("%d", livros[aux].n_autores);
                        for (int j = 0; j < livros[aux].n_autores; j++) {
                            printf("Autor[%i]: ", j + 1);
                            scanf(" %[^\n]", livros[aux].autores[j].autores);
                        }
                    }
                }
                break;
                
            case 0:
                break;
        }
    }while (op != 0);
}


void Eliminar(LIVROS livros[]) {
    int aux;
    int x = livros[0].contador;
    char ISBN[DIG_ISBN];
    
    Listar(livros);
    printf("\nLivro a remover: ");
    printf("\nISBN do livro a alterar: ");
    scanf(" %s",ISBN);
    aux = ProcurarLivro(livros, ISBN, x);
    livros[aux].flag = 0;
    Listar(livros);

}

