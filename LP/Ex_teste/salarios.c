#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funclib.h"
#include "input.h"
#include "salariolib.h"


int grow_StructArray_Salario(SALARIO **salario) {
    const int novoTamanho = (*salario)[0].tamanho * 2;

    SALARIO *temp = (SALARIO*) realloc(*salario, (novoTamanho * sizeof (FUNCIONARIO)));

    if (temp == NULL) {
        faill();
    } else {
        *salario = temp;
    }
    return novoTamanho;
}
int Procurar_CodFuncionario_Salario(SALARIO **salario, int cod_func, int tamanho) {

    int i;

    for (i = 0; i < tamanho; i++) {
        if ((*salario)[i].codigo_funcionario == cod_func) {

            return i;
        }
    }


    return -1;
}

int Procurar_CodFuncionario_Salario_ultimaposicao(SALARIO **salario, int cod_func, int tamanho) {

    int i;
    int aux = -1;

    int data_aux = 0;
    int data;

    for (i = 0; i < tamanho; i++) {
        if ((*salario)[i].codigo_funcionario == cod_func) {


            data = ((365 * (*salario)[i].data.ano)+(30 * (*salario)[i].data.mes)
                    + (*salario)[i].data.dia);

            if (data > data_aux) {
                data_aux = data;
                aux = i;
            }

        }
    }


    return aux;
}

//trocar nome teste 

void soma_do_salario_de_funcionario_em_funcao_do_tempo(FUNCIONARIO **funcionarios, SALARIO **salario) {
    int j, i;

    int func_contador = (*funcionarios)[0].contador;
    int salario_contador = (*salario)[0].contador;
    //int numero = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);



    for (j = 0; j < func_contador; j++) {

        //aux _ tempo
        int min_aux = ((365 * (*salario)[0].data.ano)+(30 * (*salario)[0].data.mes)
                + (*salario)[0].data.dia);
        int max_aux = ((365 * (*salario)[0].data.ano)+(30 * (*salario)[0].data.mes)
                + (*salario)[0].data.dia);
        int flag = 0;

        if (Procurar_CodFuncionario_Salario(salario, (*funcionarios)[j].codigo, salario_contador) != -1) {
            for (i = 0; i < salario_contador; i++) {
                int codigo_func_salario = Procurar_CodFuncionario_Salario(salario, (*funcionarios)[j].codigo, salario_contador);
                float soma_salario;


                if (codigo_func_salario != -1) {
                    int min = ((365 * (*salario)[codigo_func_salario].data.ano)
                            + (30 * (*salario)[codigo_func_salario].data.mes)
                            + (*salario)[codigo_func_salario].data.dia);

                    int max = ((365 * (*salario)[codigo_func_salario].data.ano)
                            +(30 * (*salario)[codigo_func_salario].data.mes)
                            + (*salario)[codigo_func_salario].data.dia);



                    if (max > max_aux) {
                        max_aux = max;
                    } else if (min < min_aux) {
                        min_aux = min;
                    }

                    soma_salario += (*salario)[codigo_func_salario].valor_liquido;

                    imprimirSalario(salario, codigo_func_salario);
                    flag = 1;
                }

                printf("\nCodigo Funcionario [%i]\nTotal: %f -> "
                        "%f anos", (*funcionarios)[j].codigo, soma_salario,
                        (float) (max_aux - min_aux) / 365);



            }
        }
        if (flag == 0) {
            printf("\nNao foi encontrado salarios com o codigo de funcionario: "
                    "%i", (*funcionarios)[j].contador);

        }
    }



}

int idade(FUNCIONARIO **funcionarios, int numero) {
    int dia, mes, ano;

    dia = devolve_tempo('D');
    mes = devolve_tempo('M');
    ano = devolve_tempo('A');

    int totalIdade = ((365 * ano) + (30 * mes) + dia) - ((365 * (*funcionarios)[numero].data_de_nascimento.ano)
            + (30 * (*funcionarios)[numero].data_de_nascimento.mes) + ((*funcionarios)[numero].data_de_nascimento.dia));

    return totalIdade / 365;
}

float antiguidade(FUNCIONARIO **funcionarios, int numero) {
    int dia, mes, ano;

    dia = devolve_tempo('D');
    mes = devolve_tempo('M');
    ano = devolve_tempo('A');

    int totalIdade = 365 * ano + 30 * mes + dia - 365 * (*funcionarios)[numero].data_de_entrada.ano
            + 30 * (*funcionarios)[numero].data_de_entrada.mes + (*funcionarios)[numero].data_de_entrada.dia;

    return totalIdade / 365;
}

int Procurar_CodSalario(SALARIO **salario, int id, int tamanho) {
    int i, j, frequency = 0;
    int aux1, aux2;

    for (i = 0; i < tamanho; i++) {
        aux1 = 0;
        aux2 = 0;
        for (j = i + 1; j < tamanho; j++) {
            if ((*salario)[i].num_dias >= 22 && (*salario)[i].codigo_funcionario == id) {
                aux1 = ((*salario)[i].data.ano * 365 + (*salario)[i].data.mes * 30 + (*salario)[i].data.dia);
                printf("DATA 1: %i\ncodigo func: %i", aux1, (*salario)[i].codigo_funcionario);
            }
            if ((*salario)[j].num_dias >= 22 && (*salario)[j].codigo_funcionario == id) {
                aux2 = ((*salario)[j].data.ano * 365 + (*salario)[i].data.mes * 30 + (*salario)[j].data.dia);
                printf("DATA 2: %i\ncodigo func: %i", aux2, (*salario)[j].codigo_funcionario);
            }



            if ((*salario)[j].codigo_funcionario == id && (*salario)[i].codigo_funcionario == id && aux2 > aux1) {
                frequency++;
                printf("FREQUENCIA: %i", frequency);
            }
        }
    }

    return frequency;
}
/*
float bonus_assuididade(SALARIO **salario, int id, int x, float sal_base) {

    int num_vezes_dias = Procurar_CodSalario(salario, id, x); //numero de vezes que o funcionario trabalhou >= 22 dias; -> frequencia

    printf("NUM DE VEZES QUE FOI TRABALHADO MAIS QUE 22 DIAS: %i", num_vezes_dias);


    if (num_vezes_dias >= 3 && num_vezes_dias < 5) {
        printf("opção 1");
        return sal_base * 1.023;
    } else if (num_vezes_dias >= 5 && num_vezes_dias < 7) {
        printf("opção 2");
        return sal_base * 1.041;
    } else if (num_vezes_dias >= 7) {
        printf("opção 3");
        return sal_base * 1.067;
    } else {
        printf("opção 4");

        return sal_base * 1;
    }

}
 * */
/*
float bonus_idade(FUNCIONARIO funcionario[], int numero, float sal_base) {
    int func_idade = idade(funcionario, numero);


    if (func_idade >= 26 && func_idade < 36) {
        return sal_base * 1.013;
    } else if (func_idade >= 36 && func_idade < 47) {
        return sal_base * 1.041;
    } else if (func_idade >= 47 && func_idade < 60) {
        return sal_base * 1.067;
    } else if (func_idade >= 60) {
        return sal_base * 1.139;
    } else {

        return sal_base * 1;
    }

}
 */

/*
float bonus_antiguidade(FUNCIONARIO funcionario[], int numero, float sal_base) {
    int func_idade = antiguidade(funcionario, numero);

    if (func_idade >= 3 && func_idade < 7) {
        return sal_base * 1.041;
    } else if (func_idade >= 7 && func_idade < 9) {
        return sal_base * 1.067;
    } else if (func_idade >= 9 && func_idade < 11) {
        return sal_base * 1.12;
    } else if (func_idade >= 11) {
        return sal_base * 1.139;
    } else {

        return sal_base * 1;
    }

}
 */

float salario_bonus(FUNCIONARIO **funcionarios, SALARIO **salario, float sal_base, int cod_func) {

    int tamanho_salario = (*salario)[0].contador;

    int tempo_na_empresa = antiguidade(funcionarios, cod_func);

    if (tempo_na_empresa >= 3 && tempo_na_empresa < 7) {
        sal_base = sal_base * 1.041;
    } else if (tempo_na_empresa >= 7 && tempo_na_empresa < 9) {
        sal_base = sal_base * 1.067;
    } else if (tempo_na_empresa >= 9 && tempo_na_empresa < 11) {
        sal_base = sal_base * 1.12;
    } else if (tempo_na_empresa >= 11) {
        sal_base = sal_base * 1.139;
    } else {
        sal_base = sal_base * 1;
    }


    int func_idade = idade(funcionarios, cod_func);
    if (func_idade >= 26 && func_idade < 36) {
        sal_base = sal_base * 1.013;
    } else if (func_idade >= 36 && func_idade < 47) {
        sal_base = sal_base * 1.041;
    } else if (func_idade >= 47 && func_idade < 60) {
        sal_base = sal_base * 1.067;
    } else if (func_idade >= 60) {
        sal_base = sal_base * 1.139;
    } else {
        sal_base = sal_base * 1;
    }

    int num_vezes_dias = Procurar_CodSalario(salario, cod_func, tamanho_salario);
    //numero de vezes que o funcionario trabalhou >= 22 dias; -> frequencia

    if (num_vezes_dias >= 3 && num_vezes_dias < 5) {
        //printf("opção 1");
        sal_base = sal_base * 1.023;
    } else if (num_vezes_dias >= 5 && num_vezes_dias < 7) {
        //printf("opção 2");
        sal_base = sal_base * 1.041;
    } else if (num_vezes_dias >= 7) {
        //printf("opção 3");
        sal_base = sal_base * 1.067;
    } else {
        //printf("opção 4");

        sal_base = sal_base * 1;
    }



    return sal_base;
}

float calcular_salarioBase(FUNCIONARIO **funcionarios, int numero, int num_dias) {
    float salario_base;
    int excedente_dias; // DIAS a mais -> p.e. 23 - 1 dia a mais 



    switch ((*funcionarios)[numero].cargo) {
        case 0: //EMPREGADO
            if (num_dias <= 22) {
                salario_base = (num_dias * (8 * VALOR_HORA_EMPREGADO));
            } else {
                excedente_dias = num_dias - 22;
                salario_base = (22 * (8 * VALOR_HORA_EMPREGADO)+
                        ((excedente_dias * 8)*(VALOR_HORA_EMPREGADO * 1.5)));
            }

            break;

        case 1://CHEFE
            if (num_dias <= 22) {
                salario_base = (num_dias * (8 * VALOR_HORA_CHEFE));
            } else {
                excedente_dias = num_dias - 22;
                salario_base = (22 * (8 * VALOR_HORA_CHEFE)+
                        ((excedente_dias * 8)*(VALOR_HORA_CHEFE * 1.5)));
            }
            break;

        case 2://ADMINISTRADOR
            if (num_dias <= 22) {
                salario_base = (num_dias * (8 * VALOR_HORA_ADMINISTRADOR));
            } else {
                excedente_dias = num_dias - 22;
                salario_base = (22 * (8 * VALOR_HORA_ADMINISTRADOR)+
                        ((excedente_dias * 8)*(VALOR_HORA_ADMINISTRADOR * 1.5)));
            }
            break;
    }

    return salario_base;
}

float calcular_irs(FUNCIONARIO **funcionarios, int numero, float sal_base) {

    int est_irs = (*funcionarios)[numero].est_irs;
    // printf("\nESTADO IRS: %i", est_irs);
    dict values[50];
    int flag = 0;
    //printf("\nNUMERO: %i", numero);
    //printf("\nSalario Base: %f", sal_base);
    //printf("\nDEPENDENTES: %i", (*funcionarios)[numero].num_dependentes);
    float val = 0;

    if (est_irs == 0) { // NAO CASADO
        int i;
        readcsv(values, est_irs);
        switch ((*funcionarios)[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) { //COL1 valor do salario
                        return (sal_base * atof(values[i].col2)); //COL2+ percentagem de desconto
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col2));
                break;

            case 1:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col3));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col3));
                break;

            case 2:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col4));
                break;

            case 3:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col5));
                break;

            case 4:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col6));
                break;

            case 5:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col7));
                break;

            default:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col7));
                break;
        }

    } else if (est_irs == 1) { // 1- TITULAR
        int i;
        readcsv(values, est_irs);
        switch ((*funcionarios)[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col2));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col2));
                break;

            case 1:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col3));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col3));
                break;

            case 2:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col4));
                break;
            case 3:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col5));
                break;
            case 4:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col6));
                break;
            case 5:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col7));
                break;
            default:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (sal_base * atof(values[36].col7));
                break;
        }
    } else {
        int i;
        readcsv(values, est_irs);
        switch ((*funcionarios)[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col2));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col2));
                break;

            case 1:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col3));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col3));
                break;

            case 2:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col4));
                break;

            case 3:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col5));
                break;

            case 4:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col6));
                break;

            case 5:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col7));
                break;

            default:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (sal_base <= atof(values[i].col1)) {
                        return (sal_base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (sal_base * atof(values[35].col7));

                break;
        }

    }

    //comparar salario base, com o valor para col1 do respetivo ficheiro csv
    //depois disso ver o numero de dependentes do funcionario 
    //coluna para o nº de dependentes, multiplicar salario.dias[aux].base pelo valor da alinea

}

float calcular_ss(FUNCIONARIO **funcionarios, int numero, int opcao_ss, float sal_base) { //trocar aux por outro nome e i 
    SS values[3];
    TIPO_SS seg_social;

    readcsv_seg_social(values);
    if ((*funcionarios)[numero].cargo == 0) {
        //Segurança Social - FUNCIONARIO
        if (opcao_ss == 0) {
            return seg_social.valor_ss_funcionario = sal_base * atof(values[0].col2);
        }
        if (opcao_ss == 1) {
            return seg_social.valor_ss_empresa = sal_base * atof(values[0].col1);
        }
        if (opcao_ss == 2) {
            return seg_social.valor_ss_total = seg_social.valor_ss_funcionario
                    + seg_social.valor_ss_empresa;
        }

    } else if ((*funcionarios)[numero].cargo == 1) {
        //Segurança Social - CHEFE
        if (opcao_ss == 0) {
            return seg_social.valor_ss_funcionario = sal_base * atof(values[1].col2);
        }

        if (opcao_ss == 1) {
            return seg_social.valor_ss_empresa = sal_base * atof(values[1].col1);
        }

        if (opcao_ss == 2) {
            return seg_social.valor_ss_total = seg_social.valor_ss_funcionario
                    + seg_social.valor_ss_empresa;
        }


    } else {
        //Segurança Social - Administrador
        if (opcao_ss == 0) {
            return seg_social.valor_ss_funcionario = sal_base * atof(values[2].col2);
        }
        if (opcao_ss == 1) {
            return seg_social.valor_ss_empresa = sal_base * atof(values[2].col1);
        }

        if (opcao_ss == 2) {
            return seg_social.valor_ss_total = seg_social.valor_ss_funcionario
                    + seg_social.valor_ss_empresa;
        }
    }

}

void Calcular_Salario_tdsfunc(FUNCIONARIO **funcionarios, SALARIO **salario, int posicao_funcionario) {


    int salario_contador = (*salario)[0].contador;
    int func_contador = (*funcionarios)[0].contador;

    if (salario_contador == (*salario)[0].tamanho) {
        (*salario)[0].tamanho = grow_StructArray_Salario(salario);
    }




    (*salario)[salario_contador].codigo_funcionario =
            (*funcionarios)[posicao_funcionario].codigo;


    printf("\nFuncionario [%i]", (*salario)[salario_contador].codigo_funcionario);
    (*salario)[salario_contador].num_dias = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_TRABALHO);

    (*salario)[salario_contador].base = calcular_salarioBase(funcionarios,
            posicao_funcionario, (*salario)[salario_contador].num_dias);

    (*salario)[salario_contador].base = salario_bonus(funcionarios, salario,
            (*salario)[salario_contador].base, posicao_funcionario);

    (*salario)[salario_contador].sub_alimentacao =
            (*salario)[salario_contador].num_dias * VALOR_SUBSIDIO_ALIMENTACAO;

    (*salario)[salario_contador].valor_irs =
            calcular_irs(funcionarios, posicao_funcionario, (*salario)[salario_contador].base);

    (*salario)[salario_contador].ss.valor_ss_funcionario =
            calcular_ss(funcionarios, posicao_funcionario, 0, (*salario)[salario_contador].base);

    (*salario)[salario_contador].ss.valor_ss_empresa =
            calcular_ss(funcionarios, posicao_funcionario, 1, (*salario)[salario_contador].base);

    (*salario)[salario_contador].ss.valor_ss_total =
            calcular_ss(funcionarios, posicao_funcionario, 2, (*salario)[salario_contador].base);

    (*salario)[salario_contador].valor_liquido =
            ((*salario)[salario_contador].base + (*salario)[salario_contador].sub_alimentacao)-
            ((*salario)[salario_contador].valor_irs + (*salario)[salario_contador].ss.valor_ss_funcionario);

    (*salario)[salario_contador].data.dia = devolve_tempo('D');
    (*salario)[salario_contador].data.mes = devolve_tempo('M');
    (*salario)[salario_contador].data.ano = devolve_tempo('A');

    //Escrever em Csv
    /*fprintf(fp, "%i;%i;%i;", salario.contador,
            salario.codigo_funcionario, salario.num_meses);
    for (int j = 0; j < salario.num_meses; j++) {
        fprintf(fp, "%i;%f;%f;%f;%f;%f\n", salario.dias[i], salario.base,
                salario.ss.valor_ss_total, salario.ss.valor_ss_funcionario, salario.valor_irs, salario.valor_liquido);
            
    }*/

    (*salario)[0].contador++;

}

void calcular_salario_tdsfunc_nummes(FUNCIONARIO **funcionarios, SALARIO **salario) {
    int j, i;

    int func_contador = (*funcionarios)[0].contador;
    int salario_contador = (*salario)[0].contador;

    for (j = 0; j < func_contador; j++) {
        if (Procurar_CodFuncionario_Salario(salario, (*funcionarios)[j].codigo, salario_contador) != -1) {
            int codigo_func_salario = Procurar_CodFuncionario_Salario_ultimaposicao(salario, (*funcionarios)[j].codigo, salario_contador);

            int max_aux = 0;
            int max = ((365 * (*salario)[codigo_func_salario].data.ano)
                    +(30 * (*salario)[codigo_func_salario].data.mes)
                    + (*salario)[codigo_func_salario].data.dia);

            int data_atual = ((365 * (devolve_tempo('A')))+(30 * (devolve_tempo('M'))) + devolve_tempo('D'));

            if (max > max_aux) {
                max_aux = max;
            }

            if ((data_atual - max) > MAX_DIA) {
                Calcular_Salario_tdsfunc(funcionarios, salario, j);
            } else {
                continue;
            }

        } else {
            Calcular_Salario_tdsfunc(funcionarios, salario, j);
        }

    }


}

void EscreverFicheiro_Binario_Salario(SALARIO **salario) {

    FILE *fp = fopen(FILENAME_BIN_SALARIO, "wb+");
    int contador = (*salario)[0].contador;

    fwrite(*salario, sizeof (SALARIO), contador, fp);

    fclose(fp);
    puts("\nGravado com Sucesso");
}

void Calcular_Salario(FUNCIONARIO **funcionarios, SALARIO **salario) {

    int salario_contador = (*salario)[0].contador;
    int dia, mes, ano;

    if (salario_contador == (*salario)[0].tamanho) {
        (*salario)[0].tamanho = grow_StructArray_Salario(salario);
    }

    int func_contador = (*funcionarios)[0].contador;
    int codigo_funcionario = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC,
            MSG_OBTER_COD_FUNC); // Introduzir o codigo do funcionario para fazer a pesquisa - se existe ou nao na tabela

    int posicao_funcionario = Procurar_CodFuncionario(funcionarios,
            codigo_funcionario, func_contador); //devolve a posicao do certo codigo na tabela(array) funcionarios

    if (posicao_funcionario != -1) {
        if (Procurar_CodFuncionario_Salario(salario, codigo_funcionario, salario_contador) != -1) {
            int codigo_func_salario = Procurar_CodFuncionario_Salario_ultimaposicao(salario, codigo_funcionario, salario_contador);
            int max_aux = 0;
            dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_SALARIO); // DEVOLVE TEMPO -> funcao 
            mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_SALARIO);
            ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);
            if (ano >= (*funcionarios)[posicao_funcionario].data_de_entrada.ano) {
                int resto=mes%2;
                int numero_de_dias;
                
                if(resto != 0){
                    numero_de_dias=31;
                }else if(mes == 2){
                    numero_de_dias=28;
                }else{
                    numero_de_dias=30;
                }
                
                
                int max = ((365 * ano)+
                        (numero_de_dias * mes) +
                        dia);

                int ultima_data = ((365 * (*salario)[codigo_func_salario].data.ano) +(30 * (*salario)[codigo_func_salario].data.mes) + (*salario)[codigo_func_salario].data.dia);



                if (abs((max - ultima_data)) > MAX_DIA) {
                    (*salario)[salario_contador].codigo_funcionario =
                            (*funcionarios)[posicao_funcionario].codigo;

                    (*salario)[salario_contador].num_dias = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_TRABALHO);

                    (*salario)[salario_contador].base = calcular_salarioBase(funcionarios,
                            posicao_funcionario, (*salario)[salario_contador].num_dias);

                    (*salario)[salario_contador].base = salario_bonus(funcionarios, salario,
                            (*salario)[salario_contador].base, posicao_funcionario);

                    (*salario)[salario_contador].sub_alimentacao =
                            (*salario)[salario_contador].num_dias * VALOR_SUBSIDIO_ALIMENTACAO;

                    (*salario)[salario_contador].valor_irs =
                            calcular_irs(funcionarios, posicao_funcionario, (*salario)[salario_contador].base);

                    (*salario)[salario_contador].ss.valor_ss_funcionario =
                            calcular_ss(funcionarios, posicao_funcionario, 0, (*salario)[salario_contador].base);

                    (*salario)[salario_contador].ss.valor_ss_empresa =
                            calcular_ss(funcionarios, posicao_funcionario, 1, (*salario)[salario_contador].base);

                    (*salario)[salario_contador].ss.valor_ss_total =
                            calcular_ss(funcionarios, posicao_funcionario, 2, (*salario)[salario_contador].base);

                    (*salario)[salario_contador].valor_liquido =
                            ((*salario)[salario_contador].base + (*salario)[salario_contador].sub_alimentacao)-
                            ((*salario)[salario_contador].valor_irs + (*salario)[salario_contador].ss.valor_ss_funcionario);

                    (*salario)[salario_contador].data.dia = dia; // DEVOLVE TEMPO -> funcao 
                    (*salario)[salario_contador].data.mes = mes;
                    (*salario)[salario_contador].data.ano = ano;

                    (*salario)[0].contador++;
                }
            } else {
                puts("\nDATA INVALIDA -> DATA SALARIO É INFERIOR Á DATA DE ENTRADA DO FUNCIONARIO");
            }
        } else {

            dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_SALARIO); // DEVOLVE TEMPO -> funcao 
            mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_SALARIO);
            ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);

            if (ano >= (*funcionarios)[posicao_funcionario].data_de_entrada.ano) {
                (*salario)[salario_contador].codigo_funcionario =
                        (*funcionarios)[posicao_funcionario].codigo;

                (*salario)[salario_contador].num_dias = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_TRABALHO);

                (*salario)[salario_contador].base = calcular_salarioBase(funcionarios,
                        posicao_funcionario, (*salario)[salario_contador].num_dias);

                (*salario)[salario_contador].base = salario_bonus(funcionarios, salario,
                        (*salario)[salario_contador].base, posicao_funcionario);

                (*salario)[salario_contador].sub_alimentacao =
                        (*salario)[salario_contador].num_dias * VALOR_SUBSIDIO_ALIMENTACAO;

                (*salario)[salario_contador].valor_irs =
                        calcular_irs(funcionarios, posicao_funcionario, (*salario)[salario_contador].base);

                (*salario)[salario_contador].ss.valor_ss_funcionario =
                        calcular_ss(funcionarios, posicao_funcionario, 0, (*salario)[salario_contador].base);

                (*salario)[salario_contador].ss.valor_ss_empresa =
                        calcular_ss(funcionarios, posicao_funcionario, 1, (*salario)[salario_contador].base);

                (*salario)[salario_contador].ss.valor_ss_total =
                        calcular_ss(funcionarios, posicao_funcionario, 2, (*salario)[salario_contador].base);

                (*salario)[salario_contador].valor_liquido =
                        ((*salario)[salario_contador].base + (*salario)[salario_contador].sub_alimentacao)-
                        ((*salario)[salario_contador].valor_irs + (*salario)[salario_contador].ss.valor_ss_funcionario);
                (*salario)[salario_contador].data.dia = dia; // DEVOLVE TEMPO -> funcao 
                (*salario)[salario_contador].data.mes = mes;
                (*salario)[salario_contador].data.ano = ano;
                (*salario)[0].contador++;
            } else {
                puts("\nDATA INVALIDA -> DATA SALARIO É INFERIOR Á DATA DE ENTRADA DO FUNCIONARIO");
            }
        }

    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }


    //Escrever em Csv
    /*fprintf(fp, "%i;%i;%i;", salario.contador,
            salario.codigo_funcionario, salario.num_meses);
    for (int j = 0; j < salario.num_meses; j++) {
        fprintf(fp, "%i;%f;%f;%f;%f;%f\n", salario.dias[i], salario.base,
                salario.ss.valor_ss_total, salario.ss.valor_ss_funcionario, salario.valor_irs, salario.valor_liquido);
            
    }*/
}

void listarSalario(SALARIO **salario) {
    int contador = (*salario)[0].contador;


    if (contador > 0) {
        int i;
        for (i = 0; i < contador; i++) {
            imprimirSalario(salario, i);
        }
    } else {

        puts(ERRO_LISTA_SALARIO_VAZIA);
    }
}

void mediaSalario_det_ano(SALARIO **salario) { //media salarios de um determinado ano
    int ano_atual = devolve_tempo('A') + 1;
    int contador = (*salario)[0].contador;
    int min_data = ano_atual;

    if (contador > 0) {
        int i, j;

        for (j = 0; j < contador; j++) {
            if ((*salario)[j].data.ano < min_data) {
                min_data = (*salario)[j].data.ano;
            }
        }


        while (min_data != ano_atual) {
            float soma_salario = 0;
            int num_salario = 0;
            for (i = 0; i < contador; i++) {
                if ((*salario)[i].data.ano == min_data) {
                    soma_salario += (*salario)[i].valor_liquido;
                    num_salario++;
                }

            }
            printf("Media dos Salarios[%i]: %.2f\n", min_data, soma_salario / num_salario);
            min_data++;
        }

    } else {
        puts(ERRO_LISTA_SALARIO_VAZIA);
    }

}

void media_numdias(SALARIO **salario) {
    int contador_salario = (*salario)[0].contador;
    int i;
 int media_dias=0,contador=0;

    if (contador_salario != 0) {
        int ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);
        int cod_func = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC,
            MSG_OBTER_COD_FUNC);
        
       
        
        for (i = 0; i < contador_salario; i++) {
            if((*salario)[i].codigo_funcionario == cod_func &&(*salario)[i].data.ano <=ano){
                media_dias+=(*salario)[i].num_dias;
                
               contador++; 
            }
        }
        printf("\nFUNCIONARIO [%i]",cod_func);
        printf("Media Dias de trabalho: %i",media_dias/contador);
        
    } else {
        puts(ERRO_LISTA_SALARIO_VAZIA);

    }

}

void mediaSalario(SALARIO **salario) {
    int contador = (*salario)[0].contador;
    float media;
    if (contador > 0) {
        int i;
        for (i = 0; i < contador; i++) {
            media += (*salario)[i].valor_liquido;
        }
        printf("MEDIA: %f", media / contador);
    } else {

        puts(ERRO_LISTA_SALARIO_VAZIA);
    }

}

void menu_salarios(FUNCIONARIO **funcionarios, SALARIO **salario) {
    int menu, size;

    do {
        printf("\n%d", (*salario)[0].contador);
        printf("\n\nMENU_SALARIO");
        printf("\n1- Calcular Salario -> 1 funcionario");
        printf("\n2- Calcular Salario todos os funcionarios num mes");
        printf("\n3- Listar todos os Salarios");
        printf("\n4- Media dos Salarios");
        printf("\n5- Soma + todos os salarios de um determinado funcionario");
        printf("\n6- Media salario - por ano");
        printf("\n7- Media de dias de um determinado funcionario - ate ano atual");
        printf("\n8- Guardar");
        printf("\n0 - Sair\n");
        printf("Opção: ");
        menu = obterInt(MIN_OP_MENU_SALARIO, MAX_OP_MENU_SALARIO, "");
        switch (menu) {
            case 1:
                Calcular_Salario(funcionarios, salario);
                break;
            case 2:
                calcular_salario_tdsfunc_nummes(funcionarios, salario);
                break;
            case 3:listarSalario(salario);

                break;
            case 4:mediaSalario(salario);
                break;
            case 5:
                soma_do_salario_de_funcionario_em_funcao_do_tempo(funcionarios, salario);
                break;
            case 6:mediaSalario_det_ano(salario);
                break;
                case 7:media_numdias(salario);
                break;
            case 8:EscreverFicheiro_Binario_Salario(salario);
                break;
            case 0:
                break;

        }
    } while (menu != 0);

}
int carregar_salario(SALARIO **salario, FILE *fp) {



    int returno = 0;
    int contador = 0;

    fp = fopen(FILENAME_BIN_SALARIO, "rb");

    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        printf("contador : %i", contador);
        rewind(fp);
        if (contador > 0) {
            *salario = (SALARIO*) malloc(contador * sizeof (SALARIO));

            if (*salario == NULL) {
                faill();
            }

            fread(*salario, sizeof (SALARIO), contador, fp);
           (*salario)[0].tamanho = contador; 
            (*salario)[0].contador = (*salario)[0].tamanho;
            returno = 1;

        }
        fclose(fp);
        if (!returno) {
            fp = fopen(FILENAME_BIN_SALARIO, "wb");
            if (fp != NULL) {
                *salario = (SALARIO*) malloc(TAMANHO_INICIAL * sizeof (SALARIO));
                if (*salario == NULL) {
                    faill();
                }
                (*salario)[0].contador = 0;
                (*salario)[0].tamanho = TAMANHO_INICIAL;
                fclose(fp);

                returno = 1;
            }

        }
    }
    return returno;
}
