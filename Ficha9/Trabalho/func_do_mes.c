#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "func_do_mes_lib.h"
#include "input.h"

int devolve_frequencia_funcionario_mes(REG_TRABALHO **reg_trabalho, int funcionario_codigo, int opcao, int *mes, int *ano) {

    printf("MES:%i", *mes);
    printf("\nANO:%i", *ano);
    int frequencia_mes = *mes;
    int frequencia_ano = *ano;

    int reg_trabalho_contador = (*reg_trabalho)[0].contador;
    int frequencia = 0;

    switch (opcao) {
        case 1:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo &&
                        (*reg_trabalho)[i].data_trabalho.mes == frequencia_mes &&
                        (*reg_trabalho)[i].data_trabalho.ano == frequencia_ano) {
                    if ((*reg_trabalho)[i].jornadas_completas == MAX_JORNADAS_COMPLETAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;


        case 2:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo &&
                        (*reg_trabalho)[i].data_trabalho.mes == frequencia_mes &&
                        (*reg_trabalho)[i].data_trabalho.ano == frequencia_ano) {
                    if ((*reg_trabalho)[i].meia_jornadas > MIN_MEIAS_JORNADAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

        case 3:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo &&
                        (*reg_trabalho)[i].data_trabalho.mes == frequencia_mes &&
                        (*reg_trabalho)[i].data_trabalho.ano == frequencia_ano) {
                    if ((*reg_trabalho)[i].jornadas_ao_fim_de_semana > MIN_JORNADAS_FIM_DE_SEMANA) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

        case 4:
            for (int i = 0; i < reg_trabalho_contador; i++) {
                if ((*reg_trabalho)[i].codigo_funcionario == funcionario_codigo &&
                        (*reg_trabalho)[i].data_trabalho.mes == frequencia_mes &&
                        (*reg_trabalho)[i].data_trabalho.ano == frequencia_ano) {
                    if ((*reg_trabalho)[i].faltas > MIN_FALTAS) {
                        frequencia++;
                    }
                }
            }
            return frequencia;
            break;

    }

}

void grow_StructArray_Func_Do_Mes(FUNC_DO_MES **func_do_mes) {

    const int novoTamanho = (*func_do_mes)[0].tamanho * 2;
    printf("Novo Tamanho: %i", novoTamanho);


    FUNC_DO_MES *temp = (FUNC_DO_MES*) realloc(*func_do_mes, (novoTamanho * sizeof (FUNC_DO_MES)));

    if (temp == NULL) {
        faill();
    } else {
        *func_do_mes = temp;
        (*func_do_mes)[0].tamanho = novoTamanho;
        printf("Funcionario Tamanho:%i", (*func_do_mes)[0].tamanho);
    }
}

int Procurar_Data_Func_Do_Mes(FUNC_DO_MES **func_do_mes, int mes, int ano, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if ((*func_do_mes)[i].data_mes == mes &&
                (*func_do_mes)[i].data_ano == ano) {
            return i;
        }
    }
    return -1;
}

void EscreverFicheiro_Binario_Func_Do_Mes(FUNC_DO_MES **func_do_mes, FILE *fp) {

    int contador = (*func_do_mes)[0].contador;

    if (contador >= 1) {

        fp = fopen(FILENAME_BIN_FUNC_DO_MES, "wb+");

        if (fp == NULL) {
            puts(ERRO_ABRIR_FICHEIRO);
        } else {
            fwrite(*func_do_mes, sizeof (FUNC_DO_MES), contador, fp);
        }
        fclose(fp);
        puts(GRAVADO_COM_SUCESSO);
    }
}

void EscreverFicheiro_Texto_Func_Do_Mes(FUNC_DO_MES **func_do_mes, FILE *fp) {
    int contador = (*func_do_mes)[0].contador;

    if (contador >= 1) {
        fp = fopen(FILENAME_TXT_FUNCIONARIO_DO_MES, "w+");

        if (fp == NULL) {
            puts(ERRO_ABRIR_FICHEIRO);
        } else {
            fprintf(fp, "Codigo Funcionario,Pontos,Mes,Ano\n");
            for (int i = 0; i < contador; i++) {
                fprintf(fp, "%i,%i,%i,%i\n", (*func_do_mes)[i].codigo_funcionario,
                        (*func_do_mes)[i].pontos,
                        (*func_do_mes)[i].data_mes,
                        (*func_do_mes)[i].data_ano);
            }

        }
        fclose(fp);
    }



}

void Funcionario_Do_Mes(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, FUNC_DO_MES **func_do_mes) {

    int funcionario_contador = (*funcionarios)[0].contador;
    int func_do_mes_contador = (*func_do_mes)[0].contador;
    int max_auxiliar = 0;
    int contador_aux = 0;
    int posicao_funcionario;
    int mes, ano;


    if (func_do_mes_contador == (*func_do_mes)[0].tamanho) {
        grow_StructArray_Func_Do_Mes(func_do_mes);
    }


    printf("\nFUNCIONARIO DO MÊS");
    int escolha = obterInt(MIN_OP_FUNCIONARIO_DO_MES, MAX_OP_FUNCIONARIO_DO_MES,
            OBTER_OP_FUNCIONARIO_DO_MES);



    if (escolha == 1) {
        mes = devolve_tempo('M');
        ano = devolve_tempo('A');
    } else {
        mes = obterInt(MIN_MES, MAX_MES, "Insira mes:");
        ano = obterInt(MIN_ANO, MAX_ANO, "Insira ano:");
    }



    if (Procurar_Data_Func_Do_Mes(func_do_mes, mes, ano, func_do_mes_contador) == -1) {
        if (funcionario_contador > 0) {



            for (int i = 0; i < funcionario_contador; i++) {
                int frequencia_jornadas_completas = devolve_frequencia_funcionario_mes
                        (reg_trabalho, (*funcionarios)[i].codigo, 1, &mes, &ano);

                int frequencia_meias_jornadas = devolve_frequencia_funcionario_mes
                        (reg_trabalho, (*funcionarios)[i].codigo, 2, &mes, &ano);

                int frequencia_jornadas_fim_de_semana = devolve_frequencia_funcionario_mes
                        (reg_trabalho, (*funcionarios)[i].codigo, 3, &mes, &ano);

                int frequencia_faltas = devolve_frequencia_funcionario_mes(reg_trabalho,
                        (*funcionarios)[i].codigo, 4, &mes, &ano);


                int max = ((pontos_jornadas_completas * frequencia_jornadas_completas)+
                        (pontos_meias_jornadas * frequencia_meias_jornadas)+
                        (pontos_jornadas_fim_de_semana * frequencia_jornadas_fim_de_semana)
                        -(pontos_faltas * frequencia_faltas));
                if (max != 0) {
                    contador_aux++;
                }



                if (contador_aux >= 2) {
                    if (max != 0 && max > max_auxiliar) {
                        max_auxiliar = max;
                        posicao_funcionario = i;
                    } else if (max == max_auxiliar) {

                        int idade_aux1 = devolve_data_em_dias((*funcionarios)[i].data_de_nascimento.ano,
                                (*funcionarios)[i].data_de_nascimento.mes,
                                (*funcionarios)[i].data_de_nascimento.dia);

                        int idade_aux2 = devolve_data_em_dias((*funcionarios)[posicao_funcionario].data_de_nascimento.ano,
                                (*funcionarios)[posicao_funcionario].data_de_nascimento.mes,
                                (*funcionarios)[posicao_funcionario].data_de_nascimento.dia);

                        int antiguidade1 = devolve_data_em_dias((*funcionarios)[i].data_de_entrada.ano,
                                (*funcionarios)[i].data_de_entrada.mes,
                                (*funcionarios)[i].data_de_entrada.dia);

                        int antiguidade2 = devolve_data_em_dias((*funcionarios)[posicao_funcionario].data_de_entrada.ano,
                                (*funcionarios)[posicao_funcionario].data_de_entrada.mes,
                                (*funcionarios)[posicao_funcionario].data_de_entrada.dia);


                        if (idade_aux1 < idade_aux2) {
                            max_auxiliar = max;
                            posicao_funcionario = i;
                        } else if (idade_aux1 == idade_aux2) {
                            if (antiguidade1 < antiguidade2) {
                                max_auxiliar = max;
                                posicao_funcionario = i;
                            }
                        }
                    }
                } else {
                    if (max != 0 && max > max_auxiliar) {
                        max_auxiliar = max;
                        posicao_funcionario = i;
                    }
                }


            }

            if (max_auxiliar != 0) {
                (*func_do_mes)[func_do_mes_contador].codigo_funcionario =
                        (*funcionarios)[posicao_funcionario].codigo;
                (*func_do_mes)[func_do_mes_contador].pontos = max_auxiliar;
                (*func_do_mes)[func_do_mes_contador].data_mes = mes;
                (*func_do_mes)[func_do_mes_contador].data_ano = ano;


                (*func_do_mes)[0].contador++;

            }
        } else {
            puts(ERRO_LISTA_VAZIA);
        }

    }
}

void imprimirFunc_Do_Mes(FUNC_DO_MES **func_do_mes, int i) {

    printf("\n\nFuncionario[%i]", (*func_do_mes)[i].codigo_funcionario);
    printf("\nPontos: %i", (*func_do_mes)[i].pontos);
    printf("\nData");
    printf("\n Mes:%i", (*func_do_mes)[i].data_mes);
    printf("\n Ano:%i", (*func_do_mes)[i].data_ano);

}

void listarFunc_Do_Mes(FUNC_DO_MES **func_do_mes) {
    int contador = (*func_do_mes)[0].contador;


    if (contador > 0) {
        int i;
        for (i = 0; i < contador; i++) {
            imprimirFunc_Do_Mes(func_do_mes, i);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void menu_func_do_mes(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, FUNC_DO_MES **func_do_mes, FILE *fp) {

    int menu;


    do {

        printf("\n\nMENU FUNCIONARIO DO MES");
        printf("\nContador: %d",(*func_do_mes)[0].contador);
        printf("\n1- Calcular Funcionario do Mês");
        printf("\n2- Listar todos os funcionarios do Mes");
        printf("\n3- Guardar Ficheiros");
        printf("\n0- Sair");
        printf("\nOpcao: ");
        menu=obterInt(MIN_OPCAO_MENU,MAX_OP_FUNC_DO_MES,"");
        
        switch (menu) {

            case 1:Funcionario_Do_Mes(funcionarios, reg_trabalho, func_do_mes);
                break;

            case 2:listarFunc_Do_Mes(func_do_mes);
                break;

            case 3:EscreverFicheiro_Texto_Func_Do_Mes(func_do_mes, fp);
                EscreverFicheiro_Binario_Func_Do_Mes(func_do_mes, fp);
                break;

            case 0:
                break;

        }


    } while (menu != 0);


}

int Carregar_Func_Do_Mes(FUNC_DO_MES **func_do_mes, FILE *fp) {
    int returno = 0;
    int contador = 0;

    fp = fopen(FILENAME_BIN_FUNC_DO_MES, "rb");

    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        printf("CONTADOR FUNC DO MES: %i\n", contador);

        rewind(fp);

        if (contador > 0) {
            *func_do_mes = (FUNC_DO_MES*) malloc(contador * sizeof (FUNC_DO_MES));
            fread(*func_do_mes, sizeof (FUNC_DO_MES), contador, fp);
            (*func_do_mes)[0].tamanho = contador;
            (*func_do_mes)[0].contador = contador;

            returno = 1;
        }
        fclose(fp);
        if (!returno) {
            fp = fopen(FILENAME_BIN_FUNC_DO_MES, "wb");
            if (fp != NULL) {
                *func_do_mes = (FUNC_DO_MES*) malloc(TAMANHO_INICIAL * sizeof (FUNC_DO_MES));
                (*func_do_mes)[0].contador = 0;
                (*func_do_mes)[0].tamanho = TAMANHO_INICIAL;
                fclose(fp);

                returno = 1;
            }
        }

    }
    printf("RETURNO FUNC DO MES: %i", returno);
    return returno;

}