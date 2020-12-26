#ifndef INPUT_H
#define INPUT_H

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

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

int ProcurarAluno(ALUNOS alunos[], int numero, int x) {
    int i;
    for (i = 0; i != x; i++) {
        if (alunos[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

void Inserir(ALUNOS alunos[]) {
    int numero;
    int x = alunos[0].contador;

    printf("\nINSERIR ALUNOS");

    printf("\nIntroduza um numero para o aluno: ");
    scanf("%i", &numero);

    if (ProcurarAluno(alunos, numero, x) == -1) {
        alunos[x].numero = numero;
        printf("\nNOME");
        scanf(" %[^\n]", alunos[x].nome);
        printf("\nDATA DE NASCIMENTO");
        printf("\nDIA");
        scanf("%d", &alunos[x].Data.dia);
        printf("\nMES");
        scanf("%d", &alunos[x].Data.mes);
        printf("\nANO");
        scanf("%d", &alunos[x].Data.ano);
        alunos[x].flag = 1;
        alunos[0].contador++;
    }


}

void Listar(ALUNOS alunos[]) {
    int x = alunos[0].contador;

    printf("Listar ALUNOS");

    for (int i = 0; i < x; ++i) {

        printf("\n\nNum aluno: %d", alunos[i].numero);
        printf("\nNome aluno: %s", alunos[i].nome);
        printf("\nData de Nascimento %d-%d-%d ", alunos[i].Data.dia, alunos[i].Data.mes,
                alunos[i].Data.ano);
    }
}

void Consulta(ALUNOS alunos[]) {
    int x = alunos[0].contador;
    int numero;
    
    printf("Consultar aluno");

    Consulta(alunos);
    printf("\naluno a alterar: ");
    scanf("%d", &numero);
    numero = numero - 1;

    for (int i = 0; i < x; ++i) {
        if (ProcurarAluno(alunos, numero, x)) {
            printf("\n\nNum aluno: %d", alunos[i].numero);
            printf("\nNome aluno: %s", alunos[i].nome);
            printf("\nData de Nascimento %d-%d-%d ", alunos[i].Data.dia, alunos[i].Data.mes,
                    alunos[i].Data.ano);
        }
    }
}

void Atualizar(ALUNOS alunos[]) {

    int a, op;
    do {
        Consulta(alunos);
        printf("\naluno a alterar: ");
        scanf("%d", &a);
        a = a - 1;

        printf("\n--Alterar--\n"
                "1.nome\n"
                "2.data de nascimento\n"
                "0.acabar\n=");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("\nAlterar nome:");
                cleanInputBuffer();
                scanf("%[^\n]s", alunos[a].nome);
                break;
            case 2:
                printf("\nalterar data de nascimento:\n");
                printf("dia:");
                scanf("%d", &alunos[a].Data.dia);
                printf("mes:");
                scanf("%d", &alunos[a].Data.mes);
                printf("ano:");
                scanf("%d", &alunos[a].Data.ano);
                break;
            default:
                puts("Opção Invalida");
                break;
            case 0:;

        }
    } while (op != 0);
}

void Eliminar(ALUNOS alunos[]) {


    int a;
    Consulta(alunos);
    printf("\naluno a alterar: ");
    scanf("%d", &a);
    a = a - 1;
    alunos[a].flag = 0;
    Consulta(alunos);

}

#endif /* INPUT_H */

