#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "trabalholib.h"
#include "func_do_mes_lib.h"
#include "input.h"

int Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(REG_TRABALHO **reg_trabalho,
        int cod_func, int tamanho) {

    int i, returno = -1;
    int data_max = 0;
    int data;


    for (i = 0; i < tamanho; i++) {
        if ((*reg_trabalho)[i].codigo_funcionario == cod_func) {

            data = ((365 * (*reg_trabalho)[i].data_trabalho.ano) +
                    (30 * (*reg_trabalho)[i].data_trabalho.mes)+
                    (*reg_trabalho)[i].data_trabalho.dia);

            if (data > data_max) {
                data_max = data;
                returno = i;
            }
        }
    }

    return returno;
}

int devolve_numero_de_dias(int mes) {
    int resto_dias = mes % 2;

    if (resto_dias != 0) {
        return 31;
    } else if (mes == 2) {
        return 28;
    } else {
        return 30;
    }

}

int grow_StructArray_Reg_Trabalho(REG_TRABALHO **reg_trabalho) {
    const int novoTamanho = (*reg_trabalho)[0].tamanho * 2;

    REG_TRABALHO *temp = (REG_TRABALHO*) realloc(*reg_trabalho,
            (novoTamanho * sizeof (REG_TRABALHO)));

    if (temp == NULL) {
        faill();
    } else {
        *reg_trabalho = temp;
    }
    return novoTamanho;
}

int devolve_data_em_dias(int dia, int mes, int ano) {

    return ((365 * ano)+(30 * mes) + dia);

}

void Inserir_Dias_Trabalho_Um_Funcionario(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho) {
    int codigo_funcionario;
    int reg_trabalho_contador = (*reg_trabalho)[0].contador;
    int func_contador = (*funcionarios)[0].contador;
    int dia, mes, ano;


    if (reg_trabalho_contador == (*reg_trabalho)[0].tamanho) {
        (*reg_trabalho)[0].tamanho = grow_StructArray_Reg_Trabalho(reg_trabalho);
        printf("REG TRABALHO:%i", (*reg_trabalho)[0].tamanho);
    }

    printf("\nInserir Dias de trabalho -> Um funcionario\n");
    codigo_funcionario = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC,
            OBTER_COD_FUNC_TRABALHO);

    int posicao_funcionario = Procurar_CodFuncionario(funcionarios, codigo_funcionario, func_contador);

    if (posicao_funcionario != -1 &&
            (*funcionarios)[posicao_funcionario].flag != 0) {

        int codigo_func_reg_trabalho = Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(
                reg_trabalho, codigo_funcionario, reg_trabalho_contador);

        if (codigo_func_reg_trabalho != -1) {

            dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_REG_TRABALHO);
            mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_REG_TRABALHO);
            ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_REG_TRABALHO);

            if (ano >= (*funcionarios)[posicao_funcionario].data_de_entrada.ano) {

                int numero_de_dias = devolve_numero_de_dias(mes);

                int data_em_dias = devolve_data_em_dias(dia, mes, ano);


                int ultima_data_em_dias = devolve_data_em_dias(
                        (*reg_trabalho)[codigo_func_reg_trabalho].data_trabalho.dia,
                        (*reg_trabalho)[codigo_func_reg_trabalho].data_trabalho.mes,
                        (*reg_trabalho)[codigo_func_reg_trabalho].data_trabalho.ano);


                if (abs(data_em_dias - ultima_data_em_dias) > numero_de_dias) {
                    (*reg_trabalho)[reg_trabalho_contador].codigo_funcionario =
                            (*funcionarios)[posicao_funcionario].codigo;

                    (*reg_trabalho)[reg_trabalho_contador].jornadas_completas =
                            obterInt(MIN_JORNADAS_COMPLETAS, MAX_JORNADAS_COMPLETAS,
                            OBTER_JORNADAS_COMPLETAS);

                    (*reg_trabalho)[reg_trabalho_contador].meia_jornadas =
                            obterInt(MIN_MEIAS_JORNADAS, MAX_MEIAS_JORNADAS,
                            OBTER_MEIAS_JORNADAS);

                    (*reg_trabalho)[reg_trabalho_contador].jornadas_ao_fim_de_semana =
                            obterInt(MIN_JORNADAS_FIM_DE_SEMANA, MAX_JORNADAS_FIM_DE_SEMANA,
                            OBTER_JORNADAS_FIM_DE_SEMANA);

                    (*reg_trabalho)[reg_trabalho_contador].faltas = obterInt(
                            MIN_FALTAS, MAX_FALTAS, OBTER_FALTAS);



                    //DATA REGISTRO TRABALHO
                    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.dia =
                            dia;
                    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.mes =
                            mes;
                    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.ano =
                            ano;


                    (*reg_trabalho)[0].contador++;
                }


            } else {
                puts(MSG_ERRO_DATA_DE_ENTRADA);
            }
        } else {
            dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_REG_TRABALHO);
            mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_REG_TRABALHO);
            ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_REG_TRABALHO);

            if (ano >= (*funcionarios)[posicao_funcionario].data_de_entrada.ano) {



                (*reg_trabalho)[reg_trabalho_contador].codigo_funcionario =
                        (*funcionarios)[posicao_funcionario].codigo;

                (*reg_trabalho)[reg_trabalho_contador].jornadas_completas =
                        obterInt(MIN_JORNADAS_COMPLETAS, MAX_JORNADAS_COMPLETAS,
                        OBTER_JORNADAS_COMPLETAS);

                (*reg_trabalho)[reg_trabalho_contador].meia_jornadas =
                        obterInt(MIN_MEIAS_JORNADAS, MAX_MEIAS_JORNADAS,
                        OBTER_MEIAS_JORNADAS);

                (*reg_trabalho)[reg_trabalho_contador].jornadas_ao_fim_de_semana =
                        obterInt(MIN_JORNADAS_FIM_DE_SEMANA, MAX_JORNADAS_FIM_DE_SEMANA,
                        OBTER_JORNADAS_FIM_DE_SEMANA);

                (*reg_trabalho)[reg_trabalho_contador].faltas = obterInt(
                        MIN_FALTAS, MAX_FALTAS, OBTER_FALTAS);



                //DATA REGISTRO TRABALHO
                (*reg_trabalho)[reg_trabalho_contador].data_trabalho.dia = dia;
                (*reg_trabalho)[reg_trabalho_contador].data_trabalho.mes = mes;
                (*reg_trabalho)[reg_trabalho_contador].data_trabalho.ano = ano;


                (*reg_trabalho)[0].contador++;



            } else {
                puts(MSG_ERRO_DATA_DE_ENTRADA);
            }
        }
    } else {

        puts(ERRO_FUNCIONARIO_NAO_EXISTE);

    }
}

void Imprimir_Reg_Trabalho(REG_TRABALHO **reg_trabalho, int posicao) {

    printf("\n");
    printf("\nFuncionario [%i]", (*reg_trabalho)[posicao].codigo_funcionario);
    printf("\nJornadas Completas: %i", (*reg_trabalho)[posicao].jornadas_completas);
    printf("\nMeias Jornadas: %i", (*reg_trabalho)[posicao].meia_jornadas);
    printf("\nJornadas ao fim de semana: %i",
            (*reg_trabalho)[posicao].jornadas_ao_fim_de_semana);
    printf("\nFaltas: %i", (*reg_trabalho)[posicao].faltas);
    printf("\nData: %i-%i-%i", (*reg_trabalho)[posicao].data_trabalho.dia,
            (*reg_trabalho)[posicao].data_trabalho.mes,
            (*reg_trabalho)[posicao].data_trabalho.ano);

}

void Listar_Reg_Trabalho(REG_TRABALHO **reg_trabalho) {
    int reg_trabalho_contador = (*reg_trabalho)[0].contador;

    if (reg_trabalho_contador > 0) {
        int i;
        for (i = 0; i < reg_trabalho_contador; i++) {
            Imprimir_Reg_Trabalho(reg_trabalho, i);
        }

    } else {

        puts(MSG_ERRO_LISTA_REG_TRABALHO_VAZIA);
    }


}

void Inserir_Dias_Trabalho(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, int posicao_funcionario) {

    int reg_trabalho_contador = (*reg_trabalho)[0].contador;

    if (reg_trabalho_contador == (*reg_trabalho)[0].tamanho) {
        (*reg_trabalho)[0].tamanho = grow_StructArray_Reg_Trabalho(reg_trabalho);
    }


    printf("\nFuncionario [%i]\n", (*funcionarios)[posicao_funcionario].codigo);
    (*reg_trabalho)[reg_trabalho_contador].codigo_funcionario =
            (*funcionarios)[posicao_funcionario].codigo;

    (*reg_trabalho)[reg_trabalho_contador].jornadas_completas =
            obterInt(MIN_JORNADAS_COMPLETAS, MAX_JORNADAS_COMPLETAS,
            OBTER_JORNADAS_COMPLETAS);

    (*reg_trabalho)[reg_trabalho_contador].meia_jornadas =
            obterInt(MIN_MEIAS_JORNADAS, MAX_MEIAS_JORNADAS,
            OBTER_MEIAS_JORNADAS);

    (*reg_trabalho)[reg_trabalho_contador].jornadas_ao_fim_de_semana =
            obterInt(MIN_JORNADAS_FIM_DE_SEMANA, MAX_JORNADAS_FIM_DE_SEMANA,
            OBTER_JORNADAS_FIM_DE_SEMANA);

    (*reg_trabalho)[reg_trabalho_contador].faltas = obterInt(
            MIN_FALTAS, MAX_FALTAS, OBTER_FALTAS);



    //DATA REGISTRO TRABALHO
    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.dia =
            devolve_tempo('D');
    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.mes =
            devolve_tempo('M');
    (*reg_trabalho)[reg_trabalho_contador].data_trabalho.ano =
            devolve_tempo('A');


    (*reg_trabalho)[0].contador++;




}

void Inserir_Dias_Trabalho_Todos_Funcionarios_Num_Mes(FUNCIONARIO ** funcionarios, REG_TRABALHO **reg_trabalho) {
    int j, i;

    int funcionario_contador = (*funcionarios)[0].contador;
    int reg_trabalho_contador = (*reg_trabalho)[0].contador;

    for (i = 0; i < funcionario_contador; i++) {
        if ((*funcionarios)[i].flag != 0 && (*funcionarios)[i].data_de_entrada.ano <= devolve_tempo('A')) {

            int codigo_funcionario_reg_trabalho = Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(reg_trabalho,
                    (*funcionarios)[i].codigo, reg_trabalho_contador);

            if (codigo_funcionario_reg_trabalho != -1) {
                int max_data_auxiliar = 0;

                int max_data_reg_trabalho = devolve_data_em_dias(
                        (*reg_trabalho)[codigo_funcionario_reg_trabalho].data_trabalho.dia,
                        (*reg_trabalho)[codigo_funcionario_reg_trabalho].data_trabalho.mes,
                        (*reg_trabalho)[codigo_funcionario_reg_trabalho].data_trabalho.ano);


                int data_atual = devolve_data_em_dias(devolve_tempo('D'),
                        devolve_tempo('M'), devolve_tempo('A'));

                int numero_de_dias = devolve_numero_de_dias(
                        (*reg_trabalho)[codigo_funcionario_reg_trabalho].data_trabalho.mes);

                if (max_data_reg_trabalho > max_data_auxiliar) {
                    max_data_auxiliar = max_data_reg_trabalho;
                }

                if (abs(data_atual - max_data_auxiliar) > numero_de_dias) {
                    Inserir_Dias_Trabalho(funcionarios, reg_trabalho, i);
                } else {
                    continue;
                }

            } else {
                Inserir_Dias_Trabalho(funcionarios, reg_trabalho, i);
            }
        }

    }

}

void EscreverFicheiro_Binario_Reg_Trabalho(REG_TRABALHO **reg_trabalho, FILE *fp) {

    int reg_trabalho_contador = (*reg_trabalho)[0].contador;

    fp = fopen(FILENAME_BIN_REG_TRABALHO, "wb+");

    if (fp == NULL) {
        puts(ERRO_ABRIR_FICHEIRO);
    } else {
        fwrite(*reg_trabalho, sizeof (REG_TRABALHO), reg_trabalho_contador, fp);
    }

    fclose(fp);
    puts(GRAVADO_COM_SUCESSO);

}

void Exportar_Reg_Trabalho(REG_TRABALHO **reg_trabalho, FILE *fp) {

    int reg_trabalho_contador = (*reg_trabalho)[0].contador;
    int i;

    if (reg_trabalho_contador >= 1) {

        int mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_EXPORTAR);
        int ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_EXPORTAR);

        fp = fopen(FILENAME_TXT_REG_TRABALHO, "w+");

        if (fp == NULL) {
            puts(ERRO_ABRIR_FICHEIRO);
        } else {

            fprintf(fp, "Codigo Funcionario,");
            fprintf(fp, "Meias Jornadas,Jornadas Completas,Faltas,");
            fprintf(fp, "Jornadas ao fim de semana,");
            fprintf(fp, "Data-dia,Data-mes,Data-ano\n");


            for (i = 0; i < reg_trabalho_contador; i++) {

                if ((*reg_trabalho)[i].data_trabalho.mes == mes &&
                        (*reg_trabalho)[i].data_trabalho.ano == ano) {

                    fprintf(fp, "%i,", (*reg_trabalho)[i].codigo_funcionario);

                    fprintf(fp, "%i,%i,%i,", (*reg_trabalho)[i].meia_jornadas,
                            (*reg_trabalho)[i].jornadas_completas,
                            (*reg_trabalho)[i].faltas);

                    fprintf(fp, "%i,", (*reg_trabalho)[i].jornadas_ao_fim_de_semana);

                    fprintf(fp, "%i,%i,%i\n", (*reg_trabalho)[i].data_trabalho.dia,
                            (*reg_trabalho)[i].data_trabalho.mes,
                            (*reg_trabalho)[i].data_trabalho.ano);

                }

            }
            
            puts(EXPORTADO_COM_SUCESSO);
        }

        fclose(fp);
    } else {
        puts(MSG_ERRO_LISTA_REG_TRABALHO_VAZIA);
    }

}

int Carregar_Reg_Trabalho(REG_TRABALHO **reg_trabalho, FILE *fp) {
    int returno = 0;
    int contador = 0;

    fp = fopen(FILENAME_BIN_REG_TRABALHO, "rb");

    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        printf("CONTADOR REG TRABALHO: %i\n", contador);

        rewind(fp);

        if (contador > 0) {
            *reg_trabalho = (REG_TRABALHO*) malloc(contador * sizeof (REG_TRABALHO));
            fread(*reg_trabalho, sizeof (REG_TRABALHO), contador, fp);
            (*reg_trabalho)[0].tamanho = contador;
            (*reg_trabalho)[0].contador = contador;

            returno = 1;
        }
        fclose(fp);
        if (!returno) {
            fp = fopen(FILENAME_BIN_REG_TRABALHO, "wb");
            if (fp != NULL) {
                *reg_trabalho = (REG_TRABALHO*) malloc(TAMANHO_INICIAL * sizeof (REG_TRABALHO));
                (*reg_trabalho)[0].contador = 0;
                (*reg_trabalho)[0].tamanho = TAMANHO_INICIAL;
                fclose(fp);

                returno = 1;
            }
        }

    }
    printf("RETURNO REG TRABALHO: %i", returno);
    return returno;

}

int devolve_frequencia(REG_TRABALHO **reg_trabalho, int funcionario_codigo, int opcao) {

    int reg_trabalho_contador = (*reg_trabalho)[0].contador;
    int frequencia = 0;

    switch (opcao) {
            //Frequencia Jornadas Completas -> um funcionario
        case 1:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo) {
                    if ((*reg_trabalho)[i].jornadas_completas == MAX_JORNADAS_COMPLETAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

        case 2:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo) {
                    if ((*reg_trabalho)[i].meia_jornadas > MIN_MEIAS_JORNADAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

        case 3:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo) {
                    if ((*reg_trabalho)[i].jornadas_ao_fim_de_semana > MIN_JORNADAS_FIM_DE_SEMANA) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

        case 4:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo) {
                    if ((*reg_trabalho)[i].faltas > MIN_FALTAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

    }

}


void Maximo_Dados(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, int opcao) {

    int funcionario_contador = (*funcionarios)[0].contador;
    int reg_trabalho_contador = (*reg_trabalho)[0].contador;
    int i, j;
    int max_aux = 0;
    int funcionario_posicao = 0;

    switch (opcao) {

            //Assuididade Exemplar, o funcionario trabalha os 22 dias
        case 1:
            for (i = 0; i < funcionario_contador; i++) {

                if (Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(reg_trabalho,
                        (*funcionarios)[i].codigo, reg_trabalho_contador) != -1) {

                    int frequencia = devolve_frequencia(reg_trabalho, (*funcionarios)[i].codigo, 1);
                    printf("Funcionario[%i]- Assuididade exemplar"
                            " (jornadas completas == 22) -> %i\n", (*funcionarios)[i].codigo, frequencia);
                }
            }


            break;

            //Vezes que o funcionario trabalhou, meias jornadas 
        case 2:
            for (i = 0; i < funcionario_contador; i++) {

                if (Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(reg_trabalho,
                        (*funcionarios)[i].codigo, reg_trabalho_contador) != -1) {

                    int frequencia = devolve_frequencia(reg_trabalho,
                            (*funcionarios)[i].codigo, 2);

                    printf("Funcionario[%i]- Nº de meias jornadas > 0: %i\n",
                            (*funcionarios)[i].codigo, frequencia);
                }
            }


            //Vezes que o funcionario trabalhou nos fim de semana
        case 3:
            for (i = 0; i < funcionario_contador; i++) {

                if (Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(reg_trabalho,
                        (*funcionarios)[i].codigo, reg_trabalho_contador) != -1) {

                    int frequencia = devolve_frequencia(reg_trabalho,
                            (*funcionarios)[i].codigo, 3);

                    printf("Funcionario[%i]- Nº de meses que trabalhou ao fim de semana: %i\n",
                            (*funcionarios)[i].codigo, frequencia);

                }

            }
            break;

            //Vezes que o funcionario trabalhou
        case 4:
            for (i = 0; i < funcionario_contador; i++) {

                if (Procurar_CodFuncionario_Reg_Trabalho_UltimaPosicao(reg_trabalho,
                        (*funcionarios)[i].codigo, reg_trabalho_contador) != -1) {

                    int frequencia = devolve_frequencia(reg_trabalho,
                            (*funcionarios)[i].codigo, 4);


                    printf("Funcionario[%i]- Nº de meses que faltou > 0: %i\n",
                            (*funcionarios)[i].codigo, frequencia);
                }

            }


            break;

        case 0:
            break;

    }

}


void Menu_Maximo_Dados(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho) {
    int menu;


    do {
        printf("\n\nMENU FUNCIONALIDADES EXTRA");
        printf("\n1- Jornadas Completas");
        printf("\n2- Meias Jornadas");
        printf("\n3- Jornadas ao fim de semana");
        printf("\n4- Faltas");
        printf("\n0- Sair");
        printf("\nOpçao:");
        menu = obterInt(MIN_OPCAO_MENU, MAX_OPCAO_MIN_MAX_REG_TRABALHO, "");

        Maximo_Dados(funcionarios, reg_trabalho, menu);


    } while (menu != 0);


}



void Menu_Reg_Trabalho(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, FUNC_DO_MES **func_do_mes, FILE *fp) {

    int menu;

    do {
        printf("\n\nMENU REGISTRO TRABALHO");
        printf("\nContador: %d", (*reg_trabalho)[0].contador);
        printf("\n1- Registro Trabalho -> 1 funcionario");
        printf("\n2- Registro Trabalho -> todos os funcionarios");
        printf("\n3- Listar todos os registros de trabalho");
        printf("\n4- Exportar Registro de Trabalho dos funcionarios de um determinado mes");
        printf("\n5- Imprimir no Ficheiro");
        printf("\n6- Menu Funcionalidades Extra");
        printf("\n7- Menu Funcionario do Mes");
        printf("\n0 - Sair\n");
        printf("Opção: ");
        menu = obterInt(MIN_OPCAO_MENU, MAX_OP_MENU_REG_TRABALHO, "");
        switch (menu) {
            case 1:
                Inserir_Dias_Trabalho_Um_Funcionario(funcionarios, reg_trabalho);
                logMsg("Inserir Dias de trabalho de um funcionario", FILENAME_LOG);
                break;
            case 2:
                Inserir_Dias_Trabalho_Todos_Funcionarios_Num_Mes(funcionarios, reg_trabalho);
                logMsg("Inserir Dias de trabalho de todos os funcionarios", FILENAME_LOG);
                break;

            case 3:
                Listar_Reg_Trabalho(reg_trabalho);
                logMsg("Listar o Registro de Trabalho", FILENAME_LOG);
                break;

            case 4:
                Exportar_Reg_Trabalho(reg_trabalho, fp);
                logMsg("Exportar o registro de trabalho de um certo mes", FILENAME_LOG);
                break;

            case 5:
                EscreverFicheiro_Binario_Reg_Trabalho(reg_trabalho, fp);
                logMsg("Guardar Registro Binario", FILENAME_LOG);
                break;

            case 6:Menu_Maximo_Dados(funcionarios, reg_trabalho);
                logMsg("Frequencia Registro de Trabalho", FILENAME_LOG);
                break;

            case 7:menu_func_do_mes(funcionarios, reg_trabalho, func_do_mes, fp);
                logMsg("Menu Funcionario Do Mes", FILENAME_LOG);
                break;

            case 0:
                break;

        }
    } while (menu != 0);
}