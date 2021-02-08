#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VALOR_INVALIDO "O valor inserido é inválido."



int devolve_tempo(char opcao) {

    time_t currentTime;
    time(&currentTime);

    struct tm *myTime = localtime(&currentTime);

    switch (opcao) {
        case 'D':
            return myTime->tm_mday;
            break;

        case 'M':
            return myTime ->tm_mon + 1;
            break;

        case 'A':
            return myTime->tm_year + 1900;
            break;
        case 'h':
            return myTime->tm_hour;
            break;
        case 'm':
            return myTime->tm_min;
            break;
        case 's':
            return myTime->tm_sec;
            break;
    }
}

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int obterInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

double obterDouble(double minValor, double maxValor, char *msg) {
    double valor;
    printf(msg);
    while (scanf("%lf", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

char obterChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}

void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}

void logMsg(char *msg, char *filename) {

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", devolve_tempo('A'),
            devolve_tempo('M'), devolve_tempo('D'), devolve_tempo('h')
            , devolve_tempo('m'), devolve_tempo('s'), msg);

    fclose(fp);
}

