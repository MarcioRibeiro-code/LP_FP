#ifndef FUNC_DO_MES_LIB_H
#define FUNC_DO_MES_LIB_H

#include "funclib.h"
#include "trabalholib.h"
#include "input.h"


#define FILENAME_BIN_FUNC_DO_MES "func_do_mes.dat"
#define FILENAME_TXT_FUNCIONARIO_DO_MES "funcionario_do_mes.txt"


#define MAX_OP_FUNC_DO_MES 3


typedef struct {
    int contador;
    int codigo_funcionario;
    int tamanho;
    int pontos;
     int data_mes;
     int data_ano; 
     
} FUNC_DO_MES;



int Carregar_Func_Do_Mes(FUNC_DO_MES **func_do_mes, FILE *fp);
int devolve_data_em_dias(int dia, int mes, int ano);


#endif /* FUNC_DO_MES_LIB_H */

