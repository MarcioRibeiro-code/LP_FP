#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funclib.h"
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


//CONVERTER ENUM EM STRING

char *estadoCivilToString(ESTADO_CIVIL est_civ) {
    switch (est_civ) {
        case CASADO:
            return "CASADO";
            break;
        case DIVORCIADO:
            return "DIVORCIADO";
            break;
        case VIUVO:
            return "VIUVO";
            break;
        case SOLTEIRO:
            return "SOLTEIRO";
            break;
        default:
            return "SOLTEIRO";
    }
}

char *cargoToString(CARGO f_cargo) {
    switch (f_cargo) {
        case EMPREGADO:
            return "EMPREGADO";
            break;
        case ADMINISTRADOR:
            return "ADMINISTRADOR";
            break;
        case CHEFE:
            return "CHEFE";
            break;

        default:
            return "EMPREGADO";
    }
}
//______________________________________________________________________________

void imprimirFuncionario(FUNCIONARIO funcionario) {

    printf("\nCodigo: %d", funcionario.codigo);
    printf("\nNome do Funcionario: %s", funcionario.nome);
    printf("\nNumero de Telefone: %s", funcionario.num_tlf);
    printf("\nEstado Civil: %s", estadoCivilToString(funcionario.est_civil));
    printf("\nNumero de Dependentes: %i", funcionario.num_dependentes);
    printf("\nCargo: %s", cargoToString(funcionario.cargo));

    printf("\nData de Nascimento: %d-%d-%d", funcionario.data_de_nascimento.dia,
            funcionario.data_de_nascimento.mes, funcionario.data_de_nascimento.ano);

    printf("\nData de Entrada: %d-%d-%d", funcionario.data_de_entrada.dia,
            funcionario.data_de_entrada.mes, funcionario.data_de_entrada.ano);

    if (funcionario.data_de_saida != NULL) {

        printf("\nData de Saida: %d-%d-%d", funcionario.data_de_saida.dia,
                funcionario.data_de_saida.mes, funcionario.data_de_saida.ano);

    } else {
        printf("\nData de Saida: %s", ERRO_DATA_DE_SAIDA);
    }
}

void apagarDadosFuncionario(FUNCIONARIO *funcionario) {

    funcionario->codigo = 0;
    strcpy(funcionario->nome, "");
    strcpy(funcionario->num_tlf, "");
    funcionario->est_civil = 0;
    funcionario->num_dependentes = 0;
    funcionario->cargo = 0;

    funcionario->data_de_nascimento.dia = funcionario->data_de_nascimento.mes =
            funcionario->data_de_nascimento.ano = 0;

    funcionario->data_de_entrada.dia = funcionario->data_de_entrada.mes =
            funcionario->data_de_entrada.ano = 0;

    funcionario->data_de_saida.dia = funcionario->data_de_saida.mes =
            funcionario->data_de_saida.ano = 0;
}

int procurarFuncionario(FUNCIONARIOS funcionarios, int numero) {
    int i;


    for (i = 0; i < funcionarios.contador; i++) {
        if (funcionarios.funcionarios[i].codigo == numero) {
            return i;
        }
    }
    return -1;
}

int inserirFuncionario(FUNCIONARIOS *funcionarios) {
    int numero = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);
    int aux;


    if (procurarFuncionarios(*funcionarios, numero) == -1) {

        //CODIGO FUNCIONARIO
        funcionarios->funcionarios[funcionarios->contador].codigo = numero;

        //NOME DO FUNCIONARIO
        lerString(funcionarios->funcionarios[funcionarios->contador].nome,
                MAX_CHAR_NOME, OBTER_NOME_FUNC);

        //NUMERO DE TELEFONE DO FUNCIONARIOS
        lerString(funcionarios->funcionarios[funcionarios->contador].num_tlf,
                MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);


        //ESTADO CIVIL DO FUNCIONARIO
        funcionarios->funcionarios[funcionarios->contador].est_civil
                = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL, OBTER_EST_CIVIL);

        //NUMERO DE DEPENDETENS DO FUNCIONARIO
        funcionarios->funcionarios[funcionarios->contador].num_dependentes
                = obterInt(MIN_NUM_DEPENDENTES, MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);

        //CARGO DO FUNCIONARIO
        funcionarios->funcionarios[funcionarios->contador].cargo
                = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO, OBTER_NUM_CARGO);

        //DATA DE NASCIMENTO
        //DIA
        funcionarios->funcionarios[funcionarios->contador]->data_de_nascimento.dia
                = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);

        //MES    
        funcionarios->funcionarios[funcionarios->contador]->data_de_nascimento.mes
                = obterInt(MIN_MES, MAX_DIA, OBTER_MES_NASC);

        //ANO
        funcionarios->funcionarios[funcionarios->contador]->data_de_nascimento.ano
                = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);

        //DATA DE ENTRADA
        //DIA
        funcionarios->funcionarios[funcionarios->contador]->data_de_entrada.dia
                = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_ENTRADA);

        //MES
        funcionarios->funcionarios[funcionarios->contador]->data_de_entrada.mes
                = obterInt(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);

        //ANO
        funcionarios->funcionarios[funcionarios->contador]->data_de_entrada.ano
                = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);
        return funcionarios->contador++;
    }
    return -1;
}

void atualizarFuncionario(FUNCIONARIO *funcionario) {

    //ATUALIZAR NOME DO FUNCIONARIO
    lerString((*funcionario).nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);

    //ATUALIZAR TLF DO FUNCIONARIO
    lerString((*funcionario).num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);

    //ATUALIZAR ESTADO DO CIVIL DO FUNCIONARIO
    (*funcionario).est_civil = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL, OBTER_EST_CIVIL);

    //ATUALIZAR NUMERO DE DEPENDENTES DO FUNCIONARIO
    (*funcionario).num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
            MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);

    //ATUALIZAR CARGO DO FUNCIONARIO
    (*funcionario).cargo = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO, OBTER_NUM_CARGO);

    //ATUALIZAR DATA DE NASCIMENTO DO FUNCIONARIO
    //DIA
    (*funcionario).data_de_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);

    //MES
    (*funcionario).data_de_nascimento.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);

    //ANO
    (*funcionario).data_de_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);

    //ATUALIZAR DATA DE ENTRADA DO FUNCIONARIO
    //DIA
    (*funcionario).data_de_entrada.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_ENTRADA);

    //MES
    (*funcionario).data_de_entrada.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);

    //ANO
    (*funcionario).data_de_entrada.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);

    //ATUALIZAR DATA DE SAIDA DO FUNCIONARIO
    int aux = obterInt(MIN_VERIFICACAO_SAIDA, MAX_VERIFICACAO_SAIDA, OBTER_VALOR_VERIFICACAO_SAIDA);
    if (aux == 1) {
        (*funcionario).data_de_saida.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_SAIDA);
        (*funcionario).data_de_saida.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_SAIDA);
        (*funcionario).data_de_saida.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SAIDA);
    }
}

void inserirFuncionarios(FUNCIONARIOS *funcionarios) {
    if (funcionarios->contador < MAX_NUM_FUNC) {
        if (inserirFuncionario(funcionarios) == -1) {
            puts(ERRO_FUNCIONARIO_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_CHEIA);
    }
}

void procurarFuncionarios(FUNCIONARIOS funcionarios) {

    int numero = procurarFuncionario(funcionarios, obterInt(MIN_NUM_COD_FUNC,MAX_NUM_COD_FUNC,MSG_OBTER_COD_FUNC));

    if (numero != -1) {
        imprimirFuncionario(funcionarios.funcionarios[numero]);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void atualizarLivros(FUNCIONARIOS *funcionarios) {

    int numero = procurarFuncionario(*funcionarios, obterInt(MIN_NUM_COD_FUNC,MAX_NUM_COD_FUNC,MSG_OBTER_COD_FUNC));

    if (numero != -1) {
        atualizarFuncionario(&(*funcionarios).funcionarios[numero]);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void removerFuncionarios(FUNCIONARIOS *funcionarios) {


    int i, numero = procurarFuncionario(*funcionarios,obterInt(MIN_NUM_COD_FUNC,MAX_NUM_COD_FUNC,MSG_OBTER_COD_FUNC));

    if (numero != -1) {
        for (i = numero; i < funcionarios->contador - 1; i++) {
            funcionarios->funcionarios[i] = funcionarios->funcionarios[i + 1];
        }

        apagarDadosFuncionario(&funcionarios->funcionarios[i]);

        funcionarios->contador--;
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void listarFuncionarios(FUNCIONARIOS funcionarios) {
    if (funcionarios.contador > 0) {
        int i;
        for (i = 0; i < funcionarios.contador; i++) {
            imprimirFuncionario(funcionarios.funcionarios[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

