#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "func_do_mes.h"
#include "input.h"

int devolve_frequencia_funcionario_mes(REG_TRABALHO **reg_trabalho, int funcionario_codigo, int opcao, int *mes, int *ano) {


    int frequencia_mes = *mes;
    int frequencia_ano = *ano;
    printf("MES:%i", frequencia_mes);
    printf("\nANO:%i", frequencia_ano);



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

void Funcionario_Excelente(FUNCIONARIO **funcionarios, REG_TRABALHO **reg_trabalho, FILE *fp) {

    int funcionario_contador = (*funcionarios)[0].contador;
    int max_auxiliar = 0;
    int posicao_funcionario;
    int contador_aux = 0;
    int mes, ano;


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

            printf("\nJC:%i", frequencia_jornadas_completas);
            printf("\nMJ:%i\n", frequencia_meias_jornadas);
            printf("JFS:%i\n", frequencia_jornadas_fim_de_semana);
            printf("JFALTASS:%i\n", frequencia_faltas);


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

                    int idade_aux1 = ((365 * (*funcionarios)[i].data_de_entrada.ano)+(30 * (*funcionarios)[i].data_de_entrada.mes) + (*funcionarios)[i].data_de_entrada.dia);
                    int idade_aux2 = ((365 * (*funcionarios)[posicao_funcionario].data_de_entrada.ano)+(30 * (*funcionarios)[posicao_funcionario].data_de_entrada.mes) + (*funcionarios)[posicao_funcionario].data_de_entrada.dia);
                    int antiguidade1 = 1;
                    int antiguidade2 = 2;


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
    }



    printf("MAX:%i", max_auxiliar);
    printf("Funcionario do mes: %i -> %s",
            (*funcionarios)[posicao_funcionario].codigo,
            (*funcionarios)[posicao_funcionario].nome);





    /*
                else if (max == max_auxiliar) {
                    if ((*funcionarios)[i].data_de_nascimento.ano <
                            (*funcionarios)[posicao_funcionario].data_de_nascimento.ano) {
                        max_auxiliar = max;
                        posicao_funcionario = i;
                    }
                }

            }

            if (max_auxiliar != 0) {
                printf("Funcionario do mes: %i -> %s",
                        (*funcionarios)[posicao_funcionario].codigo,
                        (*funcionarios)[posicao_funcionario].nome);

                /*
                            fp = fopen(FILENAME_TXT_FUNCIONARIO_DO_MES, "a+");

                            if (fp == NULL) {
                                puts(ERRO_ABRIR_FICHEIRO);
                            } else {
                                fprintf(fp, "%i,%i,%i,%i", (*funcionarios)[posicao_funcionario].codigo,
                                        max_auxiliar, mes, ano);
                            }
                            fclose(fp);
             

            }

        } else {
            puts(ERRO_LISTA_VAZIA);
        }
     */
}