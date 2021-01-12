#ifndef BOOKLIB_H
#define BOOKLIB_H


//Constantes

#define FILENAME "booklib.bin"
#define FILENAME_LOG "lob.txt"
#define TAMANHO_INICIAL 2

#define MAX_CHAR_AUTORES 75
#define MAX_AUTORES 5
#define MIN_AUTORES 1
#define OBTER_NUM_AUTORES "Numero de autores da obra: "
#define OBTER_NOME_AUTORES "Nome do autor"

#define DIG_ISBN 13
#define MSG_OBTER_ISBN "Insira um ISBN Valido: "

#define MAX_CHAR_TITULO 250
#define MSG_OBTER_TITULO   "Insira o titulo da obra: "

#define MAX_CHAR_EDITORA 50
#define MAX_CHAR_MORADA_EDITORA 250
#define OBTER_EDITORA_NOME          "Insira o nome da editora: "
#define OBTER_EDITORA_MORADA          "Insira a morada da editora: "

#define MIN_DIA                 0
#define MAX_DIA                 31
#define OBTER_DIA_PUBL          "Insira o dia de publicação: "

#define MIN_MES                 1
#define MAX_MES                 12
#define OBTER_MES_PUBL          "Insira o mês de publicação: "

#define MIN_ANO                 1990
#define MAX_ANO                 2021
#define OBTER_ANO_PUBL          "Insira o ano de publicação: "

#define MIN_NUM_LIVRO           0
#define MAX_NUM_LIVRO           50

#define MIN_TIPO 0
#define MAX_TIPO 3
#define OBTER_TIPO "Insira o tipo: "

#define ERRO_LIVRO_EXISTE       "O ISBN já se encontra atribuído."
#define ERRO_LIVRO_NAO_EXISTE   "O ISBN não existe na lista."
#define ERRO_LISTA_CHEIA        "A lista de ISBN está cheia."
#define ERRO_LISTA_VAZIA        "A lista de ISBN está vazia."

typedef struct {
    int dia, mes, ano;
} data;

typedef enum {
    FICCAO, TECNICO, ROMANCE, ESTUDO
} tipo_genero;

typedef struct {
    char autores[MAX_CHAR_AUTORES];
} tipo_autores;

typedef struct {
    char morada[MAX_CHAR_MORADA_EDITORA];
    char nome[MAX_CHAR_EDITORA];

} tipo_editora;

typedef struct livro{
    int contador,flag,n_autores;
    char ISBN[DIG_ISBN];
    data data_de_publicacao;
    char titulo[MAX_CHAR_TITULO];
    tipo_genero tipo;
    tipo_editora editora;
    tipo_autores autores[MAX_AUTORES];
    struct livro *Prox;
} LIVROS;

typedef struct{
    char contador[50],flag[50],n_autores[50];
    char ISBN[DIG_ISBN];
    char data_d[50],data_m[50],data_a[50];
    char titulo[MAX_CHAR_TITULO];
    char tipo[50];
    tipo_editora editora;
    tipo_autores autores[];
}temp;

typedef LIVROS* FILA;

void cleanInputBuffer();
char *tipoToString(tipo_genero tipo);
int ProcurarLivro(LIVROS livros [], char ISBN[], int x);
void Inserir(LIVROS *livros);
void Listar(LIVROS *livros);
void Consulta(LIVROS *livros);
void Atualizar(LIVROS *livros);
void Eliminar(LIVROS *livros) ;
void EscreverFicheiro(LIVROS *livros, FILE *fp);
void EscreverFicheiro_Binario(LIVROS *livros, FILE *fp);
void LerFicheiro(LIVROS *livros, FILE *fp);
void LerFicheiro_Binario(LIVROS *livros, FILE *fp);
#endif /* BOOKLIB_H */

