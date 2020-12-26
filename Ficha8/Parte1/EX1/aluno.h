

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
    
    int numero,contador,flag;
    char nome[30];
    data Data;

} ALUNOS;



void logMsg(char *msg, char *filename);
int ProcurarAluno(ALUNOS alunos[], int numero,int x);
void Inserir(ALUNOS alunos[]);
void Consulta(ALUNOS alunos[]);
void Atualizar(ALUNOS alunos[]);
void Eliminar(ALUNOS alunos[]);
void Listar(ALUNOS alunos[]);

/*
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

 */
/*
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
 */

/*
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
        scanf("%d", &arluno.Data.dia);
        printf("\nMES");
        scanf("%d", &arluno.Data.mes);
        printf("\nANO");
        scanf("%d", &arluno.Data.ano);

        fwrite(&arluno, sizeof (aluno), 1, fp);
        a++;
 

    fclose(fp);
    return a;
}
 */

#endif /* ALUNO_H */

