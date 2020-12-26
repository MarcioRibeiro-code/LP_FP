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

void Inserir(LIVROS *livros) {
    char ISBN[DIG_ISBN];
    int x = livros[0].contador;

    printf("\nINSERIR LIVROS");

    printf("\nISBN: ");
    scanf(" %s", ISBN);
    cleanInputBuffer();
    if (ProcurarLivro(livros, ISBN, x) == -1) {
        strcpy(livros[x].ISBN, ISBN);
        lerString(livros[x].titulo, MAX_CHAR_TITULO, MSG_OBTER_TITULO);

        printf("\nDATA DE PUBLICAÇÃO\n");
        livros[x].data_de_publicacao.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_PUBL);
        livros[x].data_de_publicacao.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_PUBL);
        livros[x].data_de_publicacao.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_PUBL);

        printf("\nTIPO\n 0-Ficção\n 1-Tecnico\n 2-Romance\n 3-Estudo\n");
        livros[x].tipo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);

        printf("\nEDITORA");
        lerString(livros[x].editora.nome, MAX_CHAR_EDITORA,
                OBTER_EDITORA_NOME);
        lerString(livros[x].editora.morada, MAX_CHAR_MORADA_EDITORA,
                OBTER_EDITORA_MORADA);

        printf("\nAutores\n");
        livros[x].n_autores = obterInt(MIN_AUTORES, MAX_AUTORES
                , OBTER_NUM_AUTORES);

   //NUMERO DINAMICO DE AUTORES
        LIVROS *autores =calloc(livros[x].n_autores,sizeof(tipo_autores)); 
        
        for (int j = 0; j < livros[x].n_autores; j++) {
            printf("Autor[%i]\n ", j + 1);
            lerString(livros[x].autores[j].autores, MAX_CHAR_AUTORES, OBTER_NOME_AUTORES);
        }
        livros[x].flag = 1;
        livros[0].contador++;

        livros = realloc(livros, sizeof (LIVROS)*2);
    }

}

void Listar(LIVROS *livros) {
    int x = livros[0].contador, j = 0;
    printf("Listar ALUNOS");

    for (int i = 0; i < x; ++i) {
        if (livros[i].flag == 1) {
            printf("\n\nLIVRO [%i]", i);
            printf("\n ISBN: %s", livros[i].ISBN);
            printf("\n\n TITULO: %s", livros[i].titulo);
            printf("\n DATA DE PUBLICACAÇÃO: %d-%d-%d", livros[i].data_de_publicacao.dia,
                    livros[i].data_de_publicacao.mes, livros[i].data_de_publicacao.ano);
            printf("\n TIPO: %s", tipoToString(livros[i].tipo));
            printf("\n EDITORA");
            printf("\n  NOME: %s", livros[i].editora.nome);
            printf("\n  MORADA: %s", livros[i].editora.morada);


            for (j = 0; j < MAX_AUTORES; j++) {
                if (strlen(livros[i].autores[j].autores) > 1) {
                    printf("\n AUTORES [%i]", j + 1);
                    printf("\n  %s", livros[i].autores[j].autores);
                } else
                    continue;
            }
        } else {
            printf("\nInativo");
        }
    }
}

void Consulta(LIVROS *livros) {
    int x = livros[0].contador;
    char ISBN[DIG_ISBN];
    int aux;

    cleanInputBuffer();
    printf("Consultar LIVRO");
    printf("\nISBN do livro a consultar: ");
    scanf(" %s", ISBN);
    aux = ProcurarLivro(livros, ISBN, x);


    for (int i = 0; i < x; i++) {
        if (aux == i && livros[i].flag == 1) {
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
        } else {
            printf("\nInativo");
        }
    }
}

void Atualizar(LIVROS *livros) {
    char ISBN[DIG_ISBN];
    int x = livros[0].contador;
    int aux;
    int op;

    printf("\nISBN do livro a atualizar: ");
    printf("ISBN: ");
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
                    if (i == aux) {
                        cleanInputBuffer();
                        printf("\nTITULO");
                        lerString(livros[aux].titulo, MAX_CHAR_TITULO, MSG_OBTER_TITULO);
                    }
                }
                break;
            case 2:

                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        cleanInputBuffer();
                        printf("\nDATA DE PUBLICACAO");
                        livros[aux].data_de_publicacao.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_PUBL);
                        livros[aux].data_de_publicacao.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_PUBL);
                        livros[aux].data_de_publicacao.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_PUBL);
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
                        livros[aux].tipo = obterInt(MIN_TIPO, MAX_TIPO, OBTER_TIPO);
                    }
                }
                break;

            case 4:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        cleanInputBuffer();
                        printf("EDITORA");
                        lerString(livros[aux].editora.nome, MAX_CHAR_EDITORA,
                                OBTER_EDITORA_NOME);
                        lerString(livros[aux].editora.morada, MAX_CHAR_MORADA_EDITORA,
                                OBTER_EDITORA_MORADA);
                    }
                }
                break;

            case 5:
                for (int i = 0; i < x; i++) {
                    if (aux == i) {
                        cleanInputBuffer();
                        livros[aux].n_autores = obterInt(MIN_AUTORES, MAX_AUTORES
                                , OBTER_NUM_AUTORES);

                        for (int j = 0; j < livros[aux].n_autores; j++) {
                            printf("Autor[%i]: ", j + 1);
                            lerString(livros[aux].autores[j].autores, MAX_CHAR_AUTORES, OBTER_NOME_AUTORES);
                        }
                    }
                }
                break;

            case 0:
                break;
        }
    } while (op != 0);
}

void Eliminar(LIVROS *livros) {
    int aux;
    int x = livros[0].contador;
    char ISBN[DIG_ISBN];

    Listar(livros);
    printf("\nLivro a remover: ");
    printf("ISBN: ");
    scanf(" %s", ISBN);
    aux = ProcurarLivro(livros, ISBN, x);
    livros[aux].flag = 0;
    Listar(livros);

}

void LerFicheiro(LIVROS *livros, FILE *fp) {
    fp = fopen(FILENAME, "r");

    if (!fp) {
        printf("\nError occured");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    int row_count = 0;
    int field_count = 0;

    temp values[99];

    int i = 0;
    while (fgets(buff, 1024, fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) continue;

        char *field = strtok(buff, ",");
        while (field) {
            if (field_count == 0) strncpy(values[i].contador, field, 50);
            livros[i].contador = atoi(values[i].contador);

            if (field_count == 1) strncpy(values[i].flag, field, 50);
            livros[i].flag = atoi(values[i].flag);

            if (field_count == 2) strncpy(values[i].n_autores, field, 50);
            livros[i].n_autores = atoi(values[i].n_autores);

            if (field_count == 3) strncpy(values[i].ISBN, field, DIG_ISBN);
            strncpy(livros[i].ISBN, values[i].ISBN, DIG_ISBN);

            if (field_count == 4) strncpy(values[i].data_d, field, 50);
            livros[i].data_de_publicacao.dia = atoi(values[i].data_d);

            if (field_count == 5) strncpy(values[i].data_m, field, 50);
            livros[i].data_de_publicacao.mes = atoi(values[i].data_m);

            if (field_count == 6) strncpy(values[i].data_a, field, 50);
            livros[i].data_de_publicacao.ano = atoi(values[i].data_a);

            if (field_count == 7) strncpy(values[i].titulo, field, 50);
            strncpy(livros[i].titulo, values[i].titulo, 50);

            if (field_count == 8) strncpy(values[i].tipo, field, 50);
            livros[i].tipo = atoi(values[i].tipo);

            if (field_count == 9) strncpy(values[i].editora.nome, field, MAX_CHAR_EDITORA);
            strncpy(livros[i].editora.nome, values[i].editora.nome, MAX_CHAR_EDITORA);

            if (field_count == 10) strncpy(values[i].editora.morada, field, MAX_CHAR_MORADA_EDITORA);
            strncpy(livros[i].editora.morada, values[i].editora.morada, MAX_CHAR_MORADA_EDITORA);

            if (field_count == 11) strncpy(values[i].autores[0].autores, field, MAX_CHAR_AUTORES);
            strncpy(livros[i].autores[0].autores, values[i].autores[0].autores, MAX_CHAR_AUTORES);

            if (field_count == 12) strncpy(values[i].autores[1].autores, field, MAX_CHAR_AUTORES);
            strncpy(livros[i].autores[1].autores, values[i].autores[1].autores, MAX_CHAR_AUTORES);

            if (field_count == 13) strncpy(values[i].autores[2].autores, field, MAX_CHAR_AUTORES);
            strncpy(livros[i].autores[2].autores, values[i].autores[2].autores, MAX_CHAR_AUTORES);

            if (field_count == 14) strncpy(values[i].autores[3].autores, field, MAX_CHAR_AUTORES);
            strncpy(livros[i].autores[3].autores, values[i].autores[3].autores, MAX_CHAR_AUTORES);

            if (field_count == 15) strncpy(values[i].autores[4].autores, field, MAX_CHAR_AUTORES);
            strncpy(livros[i].autores[4].autores, values[i].autores[4].autores, MAX_CHAR_AUTORES);

            field = strtok(NULL, ",");
            field_count++;
        }
        livros = realloc(livros, sizeof (LIVROS)*2);
        i++;
    }
    printf("\n\n\n NUM DE AUTORES: %i", livros[0].n_autores);
    for (int i = 0; i < livros[0].n_autores; i++)
        printf("\nAUTOR: %s", livros[0].autores[i].autores);

    fclose(fp);
}

void EscreverFicheiro(LIVROS *livros, FILE *fp) {
    fp = fopen(FILENAME, "w");
    int x;
    x = livros[0].contador;
    fprintf(fp, "Contador FLAG NUM_AUTOR ISBN DATA-DIA MES ANO TITULO TIPO EDITORA_NOME EDITORA_MORADA"
            " AUTOR1 AUTOR2 AUTOR3 AUTOR4 AUTOR5\n");
    for (int i = 0; i < x; i++) {
        fprintf(fp, "%i,%i,%i,", livros[i].contador, livros[i].flag, livros[i].n_autores);
        fprintf(fp, "%s,", livros[i].ISBN);
        fprintf(fp, "%i,%i,%i,", livros[i].data_de_publicacao.dia,
                livros[i].data_de_publicacao.mes,
                livros[i].data_de_publicacao.ano);
        fprintf(fp, "%s,", livros[i].titulo);
        fprintf(fp, "%i,", livros[i].tipo);
        fprintf(fp, "%s,%s,", livros[i].editora.nome, livros[i].editora.morada);
        for (int j = 0; j < MAX_AUTORES; j++) {
            if (livros[i].autores[j].autores == NULL) {
                fprintf(fp, " ,");
            } else {
                fprintf(fp, "%s,", livros[i].autores[j].autores);
            }
        }
    }
    fclose(fp);

}

void LerFicheiro_Binario(LIVROS *livros, FILE *fp) {
    int x;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }


    //fread(&alunos[0].contador,sizeof(int),2,fp);
    while (fread(livros, sizeof (LIVROS), 1, fp) == 1) {
        x += livros->contador;
    }
    printf("\nLido: %i", x);
    rewind(fp);
    if(TAMANHO_INICIAL<x){
        livros = realloc(livros, sizeof (LIVROS)*2);
    }
    fread(livros, sizeof (LIVROS), x, fp);
    livros[0].contador = x;


    fclose(fp);
}


void EscreverFicheiro_Binario(LIVROS *livros, FILE *fp) {
    fp = fopen(FILENAME, "wb");
    int x;
    x = livros[0].contador;
    
    fwrite(livros, sizeof (LIVROS), x, fp);



    fclose(fp);

    puts("Gravado com sucesso");
}