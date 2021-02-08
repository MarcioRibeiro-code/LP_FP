#ifndef TRABALHOLIB_H
#define TRABALHOLIB_H

#include "funclib.h"
#include "func_do_mes_lib.h"
#include "trabalholib.h"

#define FILENAME_BIN_REG_TRABALHO "reg_trabalho.dat"
#define FILENAME_TXT_REG_TRABALHO "reg_trabalho.txt"


#define OBTER_COD_FUNC_TRABALHO "Insira o codigo do funcionario: "

#define OBTER_DIA_REG_TRABALHO "Insira dia -> REGISTRO TRABALHO: "
#define OBTER_MES_REG_TRABALHO "Insira mes -> REGISTRO TRABALHO: "
#define OBTER_ANO_REG_TRABALHO "Insira ano -> REGISTRO TRABALHO: "


#define MIN_JORNADAS_COMPLETAS 0
#define MAX_JORNADAS_COMPLETAS 22
#define OBTER_JORNADAS_COMPLETAS "Insira o numero de jornadas completas: "

#define MIN_MEIAS_JORNADAS 0
#define MAX_MEIAS_JORNADAS 22
#define OBTER_MEIAS_JORNADAS "Insira o numero de meias jornadas: "

#define MIN_JORNADAS_FIM_DE_SEMANA 0
#define MAX_JORNADAS_FIM_DE_SEMANA 5
#define OBTER_JORNADAS_FIM_DE_SEMANA "Insira o numero de jornadas no fim de semana: "

#define MIN_FALTAS 0
#define MAX_FALTAS 22
#define OBTER_FALTAS "Insira o numero de faltas: "

#define MAX_OP_MENU_REG_TRABALHO 7
#define MAX_OPCAO_MIN_MAX_REG_TRABALHO 4


#define MSG_ERRO_DATA_DE_ENTRADA "DATA INVALIDA -> DATA REGISTRO SALARIO É INFERIOR Á DATA DE ENTRADA DO FUNCIONARIO"
#define MSG_ERRO_LISTA_REG_TRABALHO_VAZIA "A lista de registro de trabalho está vazia"

#define OBTER_MES_EXPORTAR "Insira o mes: "
#define OBTER_ANO_EXPORTAR "Insira o ano: "


#define MIN_OP_FUNCIONARIO_DO_MES 1
#define MAX_OP_FUNCIONARIO_DO_MES 2
#define OBTER_OP_FUNCIONARIO_DO_MES "\n1-Data atual\n2-Data introduzida manualmentes"



#define pontos_jornadas_completas 4
#define pontos_meias_jornadas 2
#define pontos_jornadas_fim_de_semana 6
#define pontos_faltas 1

typedef struct {
    int contador;
    int codigo_funcionario;
    int tamanho;
    int meia_jornadas;
    int jornadas_completas;
    int faltas;
    int jornadas_ao_fim_de_semana;
    DATA data_trabalho;

} REG_TRABALHO;


//PROTOTIPOS
int Carregar_Reg_Trabalho(REG_TRABALHO **reg_trabalho, FILE *fp);
//___________________





#endif /* TRABALHOLIB_H */

