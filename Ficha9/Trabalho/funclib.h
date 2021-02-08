#ifndef FUNCLIB_H
#define FUNCLIB_H

#define FILENAME_BIN_FUNCIONARIO "funcionario.dat"
#define FILENAME_TXT_FUNCIONARIO "funcionario.txt"
#define  FILENAME_LOG "log.txt"


//ENUMERAÇOES

typedef enum {
    N_CASADO, CASADO_1TITULAR, CASADO_2TITULAR
} ESTADO_IRS;
//______________________________________________________________________

//CONSTANTES

#define TAMANHO_INICIAL 10


//NUMERO DE FUNCIONARIOS POSSIVEIS NO PROGRAMA
#define MAX_NUM_FUNC 50

//ERROS
#define ERRO_FUNCIONARIO_EXISTE "O codigo introduzido já se encontra atribuído."
#define ERRO_FUNCIONARIO_NAO_EXISTE  "O funcionario não existe na lista."
#define ERRO_LISTA_VAZIA "A lista de funcionarios está vazia"
#define ERRO_LISTA_CHEIA "A lista de funcionario está cheia."
#define ERRO_ABRIR_FICHEIRO "Erro, nao foi possivel abrir o arquivo\n"

//FICHEIRO
#define GRAVADO_COM_SUCESSO "Gravado com Sucesso"
#define EXPORTADO_COM_SUCESSO "Exportado com Sucesso"

//NUMERO DE TELEFONE
#define MAX_CHAR_NUM_TLF 9
#define OBTER_TLF_FUNC "Insira o numero de telefone do funcionario: "

//NOME FUNCIONARIO
#define MAX_CHAR_NOME 50
#define OBTER_NOME_FUNC "Insira o nome do funcionario: "

//DATA DE SAIDA
#define ERRO_DATA_DE_SAIDA "Data de saida está vazia"

//CODIGO FUNCIONARIO
#define MIN_NUM_COD_FUNC           0
#define MAX_NUM_COD_FUNC           100
#define MSG_OBTER_COD_FUNC     "\nInsira um codigo para o funcionario [0-100]: "
#define OBTER_COD_FUNC_ALT     "\n\nMENU ATUALIZAR DADOS\nInsira o codigo do funcionario: "

//ESTADO CIVIL FUNCIONARIO
#define OBTER_EST_CIVIL "C - Casado\nD - Divorciado\nV - Viuvo(a)\nS - Solteiro\nInsira o estado civil do funcionarios : "

//NUMERO DE DEPENDENTES DO FUNCIONARIO
#define MIN_NUM_DEPENDENTES 0
#define MAX_NUM_DEPENDENTES 20
#define OBTER_NUM_DEPENDENTES "Insira o numero de dependentes do funcionario [0-5+]"

//ESTADO IRS
#define MIN_EST_IRS 0
#define MAX_EST_IRS 1
#define OBTER_EST_IRS "0 - Casado 1 Titular\n1 - Casado 2 Titulares[0-1]: "

//CARGO DO FUNCIONARIO
#define OBTER_NUM_CARGO "E - Empregado\nC - Chefe\nA - Administrador\nInsira o cargo do funcionario : "


//DIA (NASCIMENTO) (ENTRADA/SAIDA EMPRESA)
#define MIN_DIA                 1
#define MAX_DIA                 31
#define OBTER_DIA_TRABALHO "Nº de dias que trabalhou: "
#define OBTER_DIA_NASC          "Insira o dia de nascimento: "
#define OBTER_DIA_ENTRADA "Insira o dia de entrada na empresa: "
#define OBTER_DIA_SAIDA "Insira o dia de saida da empresa: "

#define MIN_MES                 1
#define MAX_MES                 12
#define OBTER_MES_TRABALHO "Nº de meses que trabalhou: "
#define OBTER_MES_NASC          "Insira o mês de nascimento: "
#define OBTER_MES_ENTRADA "Insira o mês de entrada na empresa: "
#define OBTER_MES_SAIDA "Insira o mês de saida da empresa: "

#define MIN_ANO                 1970
#define MAX_ANO                 2021
#define OBTER_ANO_NASC          "Insira o ano de nascimento: "
#define OBTER_ANO_ENTRADA "Insira o ano de entrada na empresa: "
#define OBTER_ANO_SAIDA "Insira o ano de saida da empresa: "

//MENU 
#define MIN_OPCAO_MENU 0
//MENU FUNCIONARIO

#define MAX_OP_MENU_FUNC 6
#define MSG_MENU_FUNC "\n1- Inserir Funcionario\n2- Listar todos os Funcionarios\n3- Consultar Funcionario\n4- Atualizar Dados Funcionario\n5- Eliminar Funcionario\n6- Imprimir no Ficheiro\n0- Sair\nOpção:"

//SUBMENU ATUALIZAR
#define MAX_OP_SUBMENU_ATUALIZAR 2
#define MSG_SUBMENU_ATUALIZAR "\n1- Codigo Funcionario\n2- Nome\n0- Sair\nOpcao:"

//_______________________________________________________________________



//------------------------------------------------------------------------
//ESTRUTURAS

typedef struct {
    int dia, mes, ano;
} DATA;

typedef struct {
    int contador, flag, tamanho;
    int codigo; //funcionario_codigo
    char nome[MAX_CHAR_NOME]; //funcionario_nome
    char num_tlf[MAX_CHAR_NUM_TLF]; //funcionario_telefone
    char est_civil; //funcionario_estadocivil
    int num_dependentes; //funcionario_ numero de filhos
    char cargo; //funcionario_cargo
    ESTADO_IRS est_irs; //ESTADO IRS
    DATA data_de_nascimento; //funcionario_idade
    DATA data_de_entrada; //funcionario_Data de entrada na empresa
    DATA data_de_saida; //funcionario_Assiduidade
} FUNCIONARIO;


//_______________________________________________________________________

//PROTOTIPOS

/*
int Procurar_CodFuncionario(FUNCIONARIO **funcionarios, int numero, int tamanho);
void Inserir_Funcionario(FUNCIONARIO **funcionarios);
void listarFuncionarios(FUNCIONARIO **funcionarios);
void consultaFuncionario(FUNCIONARIO **funcionarios);
void AtualizarFuncionario(FUNCIONARIO **funcionarios);
void EliminarFuncionario(FUNCIONARIO **funcionarios);
void EscreverFicheiro_Binario(FUNCIONARIO **funcionarios, FILE *fp);
 */
void menu_funcionarios(FUNCIONARIO **funcionarios, FILE *fp);
int carregar_funcionario(FUNCIONARIO **funcionarios, FILE *fp);
int Procurar_CodFuncionario(FUNCIONARIO **funcionarios, int numero, int tamanho);
void faill(void);

//________________________________________________________________________
#endif /* FUNCLIB_H */

