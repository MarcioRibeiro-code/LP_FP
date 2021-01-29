#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "funclib.h"
#include "input.h"
#include "salariolib.h"

int grow_StructArray_Salario(SALARIO **salario) {

    /*!
     * A função realiza a realocação do Struct Array Salario
     * O struct array Salario é passado por referencia.
     * É criado uma nova variavel local (novoTamanho) que obtêm o tamanho maximo
     * do array até aquele momento e o duplica. Uma nova estrutura semelhante á 
     * Salario é criado com o nome temp, e é nela feita a realocação.Apos,é realizada 
     * uma verificação á realocação onde se iguala temp a NULL, uma vez que a realocação devolve NULL quando nao foi possivel
     * devido a algum problema, se o valor for diferente significa que a realocação foi bem sucedida devolvendo o novo endereço de temp para a variavel *salario.
     * 
     * @param salario 
     * @return o novo tamanho possivel para a realocação
     * 
     */
    const int novoTamanho = (*salario)[0].tamanho * 2;

    SALARIO *temp = (SALARIO*) realloc(*salario, (novoTamanho * sizeof (FUNCIONARIO)));

    if (temp == NULL) {
        faill();
    } else {
        *salario = temp;
    }
    return novoTamanho;
}

void imprimirSalario(SALARIO **salario, int posicao) {

    /*!
     * O struct array Salario é passado por referencia.
     * É imprimido toda a informação relativa á estrutura SALARIO na consola
     * da uma dada posicao
     * 
     * @param salario Struct Array
     * @param posicao Posicao que se prentende imprimir
     * 
     */


    printf("\n");
    printf("\nFuncionario [%i]", (*salario)[posicao].codigo_funcionario);
    //printf("\nNumero de Meses: %i", (*salario)[i].num_meses);
    printf("\nDias de trabalho: %i", (*salario)[posicao].num_dias);
    printf("\nSalario base: %.2f", (*salario)[posicao].base);
    printf("\nSubsidio de Alimentação: %.2f", (*salario)[posicao].sub_alimentacao);
    printf("\nSegurança Social: TOTAL -> %.2f", (*salario)[posicao].ss.valor_ss_total);
    printf("\nSegurança Social: Funcionario -> %.2f", (*salario)[posicao].ss.valor_ss_funcionario);
    printf("\nSegurança Social: Empresa -> %.2f", (*salario)[posicao].ss.valor_ss_empresa);
    printf("\nIRS: %.2f", (*salario)[posicao].valor_irs);

    printf("\nData Salario: %i-%i-%i", (*salario)[posicao].data.dia, (*salario)[posicao].data.mes, (*salario)[posicao].data.ano);
    printf("\n-------------------------");
    printf("\nValor Liquido: %.2f", (*salario)[posicao].valor_liquido);
}

int Procurar_CodFuncionario_Salario(SALARIO **salario, int cod_func, int tamanho) {

    /*!
     * O struct array Salario é passado por referencia
     * É percorrido a estrutura salario, até o tamanho maximo atual verificando se
     * existe algum salario com o codigo funcionario que foi passado via paramentro.
     * Ao encontrar retorna i (a primeira posicao), caso contrario retorna -1; 
     * 
     * @param salario Struct Array
     * @param cod_func Codigo funcionario
     * @param tamanho Tamanho atual do struct Array SALARIO
     */

    int i;

    for (i = 0; i < tamanho; i++) {
        if ((*salario)[i].codigo_funcionario == cod_func) {

            return i;
        }
    }


    return -1;
}

int Procurar_CodFuncionario_Salario_ultimaposicao(SALARIO **salario, int cod_func, int tamanho) {

    /*!
     * O struct array Salario é passado por referencia
     * É percorrido a estrutra salario, até o tamanho maximo atual verificando se existe
     * algum salario com o codigo funcionario que foi passado via parametro.
     * Se esta condição se verificar, é calculado a data do salario encontrado em dias
     * e este valor é verificado, calculando desta forma a data maxima e é igualado aux=i;
     * 
     * Ao não encontrar mais salarios com o codigo funcionario pretendido, é devolvido a ultima posicao ou -1
     * caso a primeira condição nao se verifique.
     * 
     * @param salario Struct Array
     * @param cod_func Codigo funcionario
     * @param tamanho Tamanho atual do struct Array SALARIO
     */

    int aux = -1;
    int i;

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

    /*!
     * Soma do Salario de um determinado desde que o funcionario entrou na empresa
     * 
     *  O struct array funcionarios e salario são passados por referencia
     * Primeiramente é obtido os contadores de ambas estruturas.
     * O primeiro for percorre salarios, procurando por salarios com o codigo funcionario
     * da posição (j) da estrutura funcionarios.
     * Se encontrar é efetuado a soma de todos os salarios do funcionario e apresenta o numero de meses
     * , senao devolve uma mensagem dizendo que nao existem salarios com o codigo de funcionario em questao.
     * 
     * 
     * 
     * 
     * @param funcionarios Struct Array FUNCIONARIO
     * @param salario Struct Array SALARIO
     */



    int j, i;

    int func_contador = (*funcionarios)[0].contador;
    int salario_contador = (*salario)[0].contador;
    //int numero = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);



    for (j = 0; j < func_contador; j++) {

        //aux _ tempo
        int min_aux = ((365 * (*salario)[0].data.ano)+(30 * (*salario)[0].data.mes)
                + (*salario)[0].data.dia);
        ;
        int max_aux = 0;
        int flag = 0;
        float soma_salario = 0;
        if (Procurar_CodFuncionario_Salario(salario, (*funcionarios)[j].codigo, salario_contador) != -1) {
            for (i = 0; i < salario_contador; i++) {



                if ((*salario)[i].codigo_funcionario == (*funcionarios)[j].codigo) {

                    int valor_data = ((365 * (*salario)[i].data.ano)+(30 * (*salario)[i].data.mes)
                            + (*salario)[i].data.dia);

                    if (valor_data < min_aux) {
                        min_aux = valor_data;
                    }
                    if (valor_data > max_aux) {
                        max_aux = valor_data;
                    }

                    soma_salario += (*salario)[i].valor_liquido;

                    imprimirSalario(salario, i);
                    flag++;
                    printf("DATA FUNC: %i", valor_data);
                }

            }

            printf("MAX DATA: %i", min_aux);
            printf("MAX DATA: %i", max_aux);

            if (flag >= 12) {
                printf("\nCodigo Funcionario [%i]\nTotal: %f"
                        " -> %i anos", (*funcionarios)[j].codigo, soma_salario, flag / 12);
            } else {
                printf("\nCodigo Funcionario [%i]\nTotal: %f"
                        " -> %i mes", (*funcionarios)[j].codigo, soma_salario, flag);
            }

        }
        if (flag == 0) {
            printf("\nNao foi encontrado salarios do funcionario[%i]"
                    , (*funcionarios)[j].codigo);

        }

    }



}

int idade(FUNCIONARIO **funcionarios, int numero) {

    /*!
     *  Funcao que devolve idade de um funcionario
     * 
     * São criadas variaveis para dia,mes,ano que vao obter a data atual atraves da função devolve_tempo,
     * depois é convertido a data atual e a data de nascimento do funcionario para dia.
     * 
     * Após essa conta é efetuado o retorno convertendo a diferença em anos dividindo por 365(numero de dias num ano).
     * 
     * @param funcionarios struct array FUNCIONARIOS
     * @param numero posição do funcionarios que se pretende obter a data
     * @return Idade do funcionario
     */



    int dia, mes, ano;

    dia = devolve_tempo('D');
    mes = devolve_tempo('M');
    ano = devolve_tempo('A');

    int totalIdade = ((365 * ano) + (30 * mes) + dia) - ((365 * (*funcionarios)[numero].data_de_nascimento.ano)
            + (30 * (*funcionarios)[numero].data_de_nascimento.mes) + ((*funcionarios)[numero].data_de_nascimento.dia));

    return totalIdade / 365;
}

float antiguidade(FUNCIONARIO **funcionarios, int numero) {
    /*!
     *  Funcao que devolve antiguidade de um funcionario 
     * 
     * São criadas variaveis para dia,mes,ano que vao obter a data atual atraves da função devolve_tempo,
     * depois é convertido a data atual e a data de entrada na empresa para dia.
     * 
     * Após essa conta é efetuado o retorno convertendo a diferença em anos dividindo por 365(numero de dias num ano).
     * 
     * @param funcionarios struct array FUNCIONARIOS
     * @param numero posição do funcionarios que se pretende obter a data
     * @return antiguidade Tempo na empresa
     */

    int dia, mes, ano;

    dia = devolve_tempo('D');
    mes = devolve_tempo('M');
    ano = devolve_tempo('A');

    int totalIdade = 365 * ano + 30 * mes + dia - 365 * (*funcionarios)[numero].data_de_entrada.ano
            + 30 * (*funcionarios)[numero].data_de_entrada.mes + (*funcionarios)[numero].data_de_entrada.dia;

    return totalIdade / 365;
}

int Assuididade(SALARIO **salario, int id, int tamanho) {
    /*!
     *  Funcao que devolve o numero de meses onde o funcionario trabalhou mais de 22 dias
     * 
     * É percorrido o array um determinado num de vezes, conforme o tamanho de salario
     * se encontar o funcionario com o codigo de funcionario pretendido e o numero de dias
     * for igual ou superior a 22 é incrementado um. 
     * 
     * 
     * 
     * @param salario struct array SALARIO
     * @param id codigo funcionario do salario a calcular
     * @return num_vezes Numero de meses onde o funcionario trabalhou >= 22 dias
     */

    printf("\nID:%i", id);

    int i, j;
    int num_vezes = 0;

    for (i = 0; i < tamanho; i++) {

        if ((*salario)[i].codigo_funcionario == id) {
            printf("\n\nCODIGO FUNCIONARIO: %i", (*salario)[i].codigo_funcionario);
            printf("\n\nNumero de dias:%i", (*salario)[i].num_dias);
            if ((*salario)[i].num_dias >= 22) {
                num_vezes++;

            }
        }


    }

    return num_vezes;
}

float salario_bonus(FUNCIONARIO **funcionarios, SALARIO **salario, float sal_base, int cod_func) {

    /*!
     *  Funcao que devolve o salario após os bonus
     * 
     * Nesta função é calculado o bonus que o funcionario pode obter
     * se tiver uma assuididade modelo, a sua idade, como á quanto tempo se encontra
     * na empresa.
     * 
     * 
     * 
     * @param funcionario array struct SALARIO
     * @param salario array struct SALARIO
     * @param sal_base Salario base que foi previamente calculado
     * @param cod_func Codigo do funcionario
     * @return num_vezes Numero de meses onde o funcionario trabalhou >= 22 dias
     */

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

    int num_vezes_dias = Assuididade(salario, cod_func, tamanho_salario);
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

    /*!
     *  Funcao que devolve o salario base
     * 
     * Nesta função é calculado salario base tendo em conta o numero de dias,
     * onde um dia equivale a 8 horas de trabalho. Quando o funcionario trabalha
     * mais que os 22 dias é beneficiado com um aumento em 50% no valor hora, que
     * este recebe normalmente.
     * 
     * 
     * 
     * 
     * @param funcionario array struct FUNCIONARIO
     * @param numero Posicao do funcionario no array funcionario
     * @param num_dias Numero de dias
     * @return salario_base Salario base
     */


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


    /*!
     *  Funcao que devolve o valor de IRS
     * 
     * Nesta função é calculado o valor de IRS tendo em conta o numero de dependentes
     * do funcionario, e o estado de irs do funcionario.
     * É carregado para memoria um csv dependendo do estado irs do funcionario,
     * é comparado o salario base do funcionario como tambem o numero de dependentes do funcionario
     * obtendo desta forma a percentagem que deve ser entregue ao IRS.
     * 
     * 
     * @param funcionario array struct FUNCIONARIO
     * @param numero Posicao do funcionario no array funcionario
     * @param sal_base Salario base
     * @return irs Valor IRS
     */


    int est_irs = (*funcionarios)[numero].est_irs;

    IRS values[50];
    int flag = 0;

    float val = 0;

    if (est_irs == 0) { // NAO CASADO
        int i;
        readcsv(values, est_irs);
        switch ((*funcionarios)[numero].num_dependentes) { // numero de dependentes do funcionario

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

void readcsv_seg_social(SS values[]) {


    /*!
     *  Procedimento que carrega csv Segurança Social para memoria
     * 
     * Nesta função é carregado os valores de um csv para variaveis.
     * 
     * @param values array struct SS
     */



    FILE *fp = fopen(FILENAME_CSV_SS, "r");
    int x;
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    char line[50];
    int row_count = 0;
    int field_count = 0;

    int i = 0;
    while (fgets(line, sizeof (line), fp)) {
        field_count = 0;
        row_count++;
        //printf("ROW COUNT: %i", row_count);
        char *token;
        token = strtok(line, ";");

        while (token != NULL) {
            if (field_count == 0)
                strlcpy(values[i].col1, token, 50);

            if (field_count == 1)
                strlcpy(values[i].col2, token, 50);
            token = strtok(NULL, ";");
            field_count++;
        }
        i++;
    }
    x = i;
    fclose(fp);

    //printValues(values); 
}

void readcsv_salario() {
    int h, w;
    h = 0;
    int proc_salario[70][5];
    /*!
     *  Procedimento que carrega csv Segurança Social para memoria
     * 
     * Nesta função é carregado os valores de um csv para variaveis.
     * 
     * @param values array struct SS
     */



    FILE *fp;

    //if (carregar_csv_salario(fp, csv_salario) != 0) {

    fp = fopen(FILENAME_SALARIO_CONTAS, "r");
    //printf("TAMANHO: %i", (*csv_salario)[0].tamanho);
    //printf("CONTADOR: %i", (*csv_salario)[0].contador);

    if (fp == NULL) {
        printf("Erro ao abrir ficheiro");
        exit(EXIT_FAILURE);

    }
    char *line, *number;

    int i = 0;
    while (!feof(fp)) {
        w = 0;
        fscanf(fp, "%s", line);
        number = strtok(line, " ");
        while (number != NULL) {
            proc_salario[h][w] = atoi(number);
            w++;
            number = strtok(NULL, ",");
        }
        printf("\n");
        h++;

    }
    fclose(fp);






    // printValues(csv_salario);
}

int Convert(char * str) {
    int result = 0;
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        result += ((int) str[i] - 48) * pow(10, j);
    }

    return result;
}

int toString(char a[]) {
    int c, sign, offset, n;

    if (a[0] == '-') { // Handle negative integers
        sign = -1;
    }

    if (sign == -1) { // Set starting position to convert
        offset = 1;
    } else {
        offset = 0;
    }

    n = 0;

    for (c = offset; a[c] != '\0'; c++) {
        n = n * 10 + a[c] - '0';
    }

    if (sign == -1) {
        n = -n;
    }

    return n;
}

void calcular_salario_csv(FUNCIONARIO **funcionarios, int proc_salario[70][5], SALARIO **salario) {





    readcsv_salario(proc_salario);

    //int csv_salario_contador = (*csv_salario)[0].contador;




    int dia, mes, ano, aux_contador;
    const int antigo_contador_salario = (*salario)[0].contador;
    int salario_contador = (*salario)[0].contador;


    int func_contador = (*funcionarios)[0].contador;

    // printf("CONTADOR CSV:%i", (*csv_salario)[0].contador);

    for (int i = 0; i < 70; i++) {

        if ((*salario)[0].contador + i >= (*salario)[0].tamanho) {
            (*salario)[0].tamanho = grow_StructArray_Salario(salario);
        }
        int cod_func = proc_salario[i][0];

        // printf("\n COD: %s\n", (*csv_salario)[i].cod_func);
        int posicao_funcionario = Procurar_CodFuncionario(funcionarios, cod_func, func_contador);

        printf("POSICAO FUNC: %i", posicao_funcionario);

        if (posicao_funcionario != -1 && (*funcionarios)[posicao_funcionario].flag != 0) {

            int max_aux = 0;
            float base = 0;

            dia = devolve_tempo('D');
            mes = devolve_tempo('M');
            ano = devolve_tempo('A');

            (*salario)[salario_contador].codigo_funcionario = cod_func;

            int num_dias_completo = proc_salario[i][1];
            int num_meio_dias = proc_salario[i][2];
            int num_dias_fim_de_semana = proc_salario[i][3];

            printf("\nDIAS COMPLETOS: %i", num_dias_completo);
            printf("\nMEOS DIAS:%i ", num_meio_dias);


            (*salario)[salario_contador].num_dias = num_dias_completo;
            (*salario)[salario_contador].base = 20 * 8 * 4.57;
            /*
                        if ((*funcionarios)[posicao_funcionario].cargo == 0) {
                            (*salario)[salario_contador].base = (((8 * num_dias_completo) * VALOR_HORA_EMPREGADO)+((4 * num_meio_dias) * VALOR_HORA_EMPREGADO)+((8 * num_dias_fim_de_semana) *(VALOR_HORA_EMPREGADO * 1.5)));

                        } else if ((*funcionarios)[posicao_funcionario].cargo == 1) {
                            (*salario)[salario_contador].base = ((((8 * num_dias_completo)) * VALOR_HORA_CHEFE)+(((4 * num_meio_dias)) * VALOR_HORA_CHEFE)+(((8 * num_dias_fim_de_semana))*(VALOR_HORA_CHEFE * 1.5)));
                        } else {
                            (*salario)[salario_contador].base = ((((8 * num_dias_completo)) * VALOR_HORA_ADMINISTRADOR)+(((4 * num_dias_fim_de_semana)) * VALOR_HORA_ADMINISTRADOR)+(((8 * num_dias_fim_de_semana))*(VALOR_HORA_ADMINISTRADOR * 1.5)));
                        };
             */
            (*salario)[salario_contador].num_dias = num_dias_completo;
            printf("\nNUMERO DE DIAS: %i", (*salario)[salario_contador].num_dias);



            (*salario)[salario_contador].base = salario_bonus(funcionarios, salario, (*salario)[salario_contador].base, (*salario)[salario_contador].codigo_funcionario);
            printf("\nBASE: %f", (*salario)[salario_contador].base);

            (*salario)[salario_contador].sub_alimentacao = (*salario)[salario_contador].num_dias * VALOR_SUBSIDIO_ALIMENTACAO;
            printf("\nSUBSDIO DE ALIMENTAÇÂO: %f", (*salario)[salario_contador].sub_alimentacao);
            (*salario)[salario_contador].valor_irs = calcular_irs(funcionarios, posicao_funcionario, (*salario)[salario_contador].base);
            printf("\n IRS: %f", (*salario)[salario_contador].valor_irs);

            (*salario)[salario_contador].ss.valor_ss_funcionario =
                    calcular_ss(funcionarios, posicao_funcionario, 0, (*salario)[salario_contador].base);

            (*salario)[salario_contador].ss.valor_ss_empresa =
                    calcular_ss(funcionarios, posicao_funcionario, 1, (*salario)[salario_contador].base);

            (*salario)[salario_contador].ss.valor_ss_total =
                    calcular_ss(funcionarios, posicao_funcionario, 2, (*salario)[salario_contador].base);

            (*salario)[salario_contador].valor_liquido =
                    ((*salario)[salario_contador].base + (*salario)[salario_contador].sub_alimentacao)-
                    ((*salario)[salario_contador].valor_irs + (*salario)[salario_contador].ss.valor_ss_funcionario);

            (*salario)[salario_contador].data.dia = dia;
            (*salario)[salario_contador].data.mes = mes;
            (*salario)[salario_contador].data.ano = ano;


            (*salario)[0].contador++;
            aux_contador++;



        }

    }



    FILE *fp = fopen(FILENAME_SALARIO_CONTAS, "a+");

    if (fp == NULL) {
        printf("\nErro ao abrir o ficheiro");
        exit(EXIT_FAILURE);
    }
    printf("ANTIGO CONTADOR: %i", aux_contador);
    printf("CONTADOR: %i", salario_contador);
    for (int j = salario_contador; j < aux_contador; j++) {
        fprintf(fp, "%i;%f;%f;%f;", (*salario)[j].codigo_funcionario, (*salario)[j].base,
                (*salario)[j].sub_alimentacao, (*salario)[j].valor_irs);
        fprintf(fp, "%f;%f;%f;%f", (*salario)[j].ss.valor_ss_total, (*salario)[j].ss.valor_ss_funcionario,
                (*salario)[j].ss.valor_ss_empresa, (*salario)[j].valor_liquido);
        fprintf(fp, "%i;%i;%i\n", (*salario)[j].data.dia, (*salario)[j].data.mes, (*salario)[j].data.ano);

    }
    fclose(fp);

    (*salario)[0].contador--;
}

void readcsv(IRS *values, int est_irs) {

    /*!
     *  Procedimento que carrega as tabelas de irs para memoria
     * 
     * Nesta função é carregado os valores de um csv para variaveis.
     * Se o estado de IRS for 0, abre csv Nao casadao.
     * Se o estado de IRS for 1, abre csv Casado 1 Titular.
     * Se o estado de IRS for 2, abre csv Casasdo 2 Titulares.
     * 
     * 
     * A leitura é possivel,graças ao strtok, ele lê o ficheiro e separa em substrings
     * o texto ao encontrar o caracter se introduz(neste caso, o ";").
     * 
     * Se field_count =0, quer dizer que carregou o valor da primeira coluna
     * até 6, querendo dizer que a tabela possui 7 colunas
     * 
     * @param values array struct SS
     * @param est_irs Estado irs (Não casado, Casado 1 Titular, Casado 2 Titulares)
     */

    FILE *fp;

    if (est_irs == 0) {
        fp = fopen(FILENAME_CSV_nCasado, "r");
    } else if (est_irs == 1) {
        fp = fopen(FILENAME_CSV_1Titular, "r");
    } else {
        fp = fopen(FILENAME_CSV_2Titular, "r");
    }

    int x;
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    char line[50];
    int row_count = 0;
    int field_count = 0;

    int i = 0;

    while (fgets(line, sizeof (line), fp)) {
        field_count = 0;
        row_count++;
        char *token;
        token = strtok(line, ";");

        while (token != NULL) {
            if (field_count == 0) strlcpy(values[i].col1, token, 50);
            if (field_count == 1) strlcpy(values[i].col2, token, 50);
            if (field_count == 2) strlcpy(values[i].col3, token, 50);
            if (field_count == 3) strlcpy(values[i].col4, token, 50);
            if (field_count == 4) strlcpy(values[i].col5, token, 50);
            if (field_count == 5) strlcpy(values[i].col6, token, 50);
            if (field_count == 6) strlcpy(values[i].col7, token, 50);

            token = strtok(NULL, ";");
            field_count++;
        }
        i++;
    }
    x = i;
    fclose(fp);
    //printValues_IRS(values);
}

void printValues_IRS(IRS *values) {

    /*!
     *  Procedimento que imprime os valores carregados do csv, de IRS
     * 
     * Nesta função é imprimido o valores carregados do csv, permitindo verificar
     * se a tabela foi carregado com sucesso.
     * 
     * @param values array struct dict
     * 
     */

    for (int i = 0; i < LINHAS_CSV; i++) {
        printf("COL1 %s,COL2 %s,COL3 %s", values[i].col1, values[i].col2, values[i].col3);
        printf(",COL4 %s,COL5 %s,COL6 %s", values[i].col4, values[i].col5, values[i].col6);
        printf(",COL7 %s\n", values[i].col7);

    }
}

float calcular_ss(FUNCIONARIO **funcionarios, int numero, int opcao_ss, float sal_base) {

    /*!
     *  Funcao que devolve o valor da SS
     * 
     * Nesta função é calculado o valor da SS tendo em conta o cargo do funcionario.
     * 
     * Se opcao_ss = 0, calcula o valor que deve ser entregue pelo funcionario
     * Se opcao_ss = 1, calcula o valor que deve ser entregue pela empresa
     * Se opcao_ss = 2, calcula o valor total que deve ser entregue por ambas entidades
     * 
     * 
     * É chamado a função readcsv_seg_social que permite carregar para memoria o csv
     * da SS.
     * 
     * @param funcionario array struct FUNCIONARIO
     * @param numero Posicao do funcionario no array funcionario
     * @param opcao_ss Opçcao SS
     * @param sal_base Salario base
     * @return ss Valor SS
     */

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

    /*!
     *  Funcao que calcula o salario de todos os funcionarios num mes
     * 
     * Nesta função é calculado o salario de todos os funcionarios, que estão na
     * estrutura funcionarios.
     * Se existir algum salario com o codigo de funcionario é verificado se o numero de dias
     * é superior a 31 (um mes) para evitar calcular o salario 2 vezes para um mes.
     * Senao existir esta verificação não é realizada.
     * 
     * A data que será introduzida é data atual atraves da função devolve tempo.
   
     * @param funcionario array struct FUNCIONARIO
     * @param salario array struct SALARIO
     * @param posicao_funcionario 
     * @param posicao_funcionario Posicao do funcionario no array
     * 
     */

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
            (*salario)[salario_contador].base, (*salario)[salario_contador].codigo_funcionario);

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


    (*salario)[0].contador++;

}

void calcular_salario_tdsfunc_nummes(FUNCIONARIO **funcionarios, SALARIO **salario) {

    /*!
     *  Funcao que calcula o salario de todos os funcionarios num mes
     * 
     * Nesta função é calculado o salario de todos os funcionarios, que estão na
     * estrutura funcionarios.
     * Se existir algum salario com o codigo de funcionario é verificado se o numero de dias
     * é superior a 31 (um mes) para evitar calcular o salario 2 vezes para um mes.
     * Senao existir esta verificação não é realizada.
     * 
     * A data que será introduzida é data atual atraves da função devolve tempo.
   
     * @param funcionario array struct FUNCIONARIO
     * @param salario array struct SALARIO
     * @param posicao_funcionario 
     * @param posicao_funcionario Posicao do funcionario no array
     * 
     */


    int j, i;

    int func_contador = (*funcionarios)[0].contador;
    int salario_contador = (*salario)[0].contador;

    for (j = 0; j < func_contador; j++) {
        if ((*funcionarios)[j].flag != 0) {
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

}

void EscreverFicheiro_Binario_Salario(SALARIO **salario) {

    /*!
     *  Procedimento que escreve num ficheiro binario a estrutura salario
     * 
     * Este procedimento escreve num ficheiro binario os dados contidos em memoria
     * relativos aos salarios
     * 
     * @param salario array struct SALARIO
     * 
     * 
     */


    FILE *fp = fopen(FILENAME_BIN_SALARIO, "wb+");
    int contador = (*salario)[0].contador;

    fwrite(*salario, sizeof (SALARIO), contador, fp);

    fclose(fp);
    puts("\nGravado com Sucesso");
}

void Calcular_Salario(FUNCIONARIO **funcionarios, SALARIO **salario) {

    /*!
     *  Funcao que calcula o salario de um funcionario
     * 
     * Nesta função é calculado o salario de um certo funcionario, escolhido pelo
     * utilizador.
     * Antes de se iniciar os calculos é pedido ao utilizador a data relativo ao salario,
     * se esta data comparada ao ultimo dia do salario for superior ou igual a 31 dias
     * é realizado os calculos de salario, caso contrario não são efetuados.
   
     * @param funcionario array struct FUNCIONARIO
     * @param salario array struct SALARIO
     * 
     */

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

    if (posicao_funcionario != -1 && (*funcionarios)[posicao_funcionario].flag != 0) {
        if (Procurar_CodFuncionario_Salario(salario, codigo_funcionario, salario_contador) != -1) {
            int codigo_func_salario = Procurar_CodFuncionario_Salario_ultimaposicao(salario, codigo_funcionario, salario_contador);
            int max_aux = 0;
            dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_SALARIO); // DEVOLVE TEMPO -> funcao 
            mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_SALARIO);
            ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);
            if (ano >= (*funcionarios)[posicao_funcionario].data_de_entrada.ano) {
                int resto = mes % 2;
                int numero_de_dias;

                if (resto != 0) {
                    numero_de_dias = 31;
                } else if (mes == 2) {
                    numero_de_dias = 28;
                } else {
                    numero_de_dias = 30;
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
                            (*salario)[salario_contador].base, codigo_funcionario);

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
                        (*salario)[salario_contador].base, codigo_funcionario);

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


}

void listarSalario(SALARIO **salario) {

    /*!
     *  Procedimento que imprime na consola todos os salarios
     * 
     *
     * @param salario array struct SALARIO
     * 
     */



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

    /*!
     *  Funcao que calcula a media de salarios por ano
     * 
     * Nesta função é calculado o valor medio relativo ao salario em cada ano.
     * A media é calculada desde a data mais antiga introduzida (min_data), até
     * a data introduzida.
     *
     * 
     * @param salario array struct SALARIO
     * 
     */



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

    /*!
     *  Procedimento que calcula a media de dias de um determinado funcionario
     * 
     * Nesta função é calculado o valor medio de dias de um funcionario, ate uma determinada data
     * introduzida pelo utilizador
     *
     * 
     * @param salario array struct SALARIO
     * 
     */



    int contador_salario = (*salario)[0].contador;
    int i;
    int media_dias = 0, contador = 0;

    if (contador_salario != 0) {
        int ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);
        int cod_func = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC,
                MSG_OBTER_COD_FUNC);



        for (i = 0; i < contador_salario; i++) {
            if ((*salario)[i].codigo_funcionario == cod_func && (*salario)[i].data.ano <= ano) {
                media_dias += (*salario)[i].num_dias;

                contador++;
            }
        }
        printf("\nFUNCIONARIO [%i]", cod_func);
        printf("Media Dias de trabalho: %i", media_dias / contador);

    } else {
        puts(ERRO_LISTA_SALARIO_VAZIA);

    }

}

void mediaSalario(SALARIO **salario) {

    /*!
     *  Funcao que calcula a media de salarios 
     * 
     * Nesta função é calculado o valor medio de todos os salarios
     *
     * 
     * @param salario array struct SALARIO
     * 
     */

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

    /*!
     * Procedimento Menu salarios
     * 
     * Este procedimento é o menu salarios, onde o utilizador visualiza todas as opções que se encontram disponiveis.
     * 
     * @param funcionarios Struct Array funcionarios
     * @param salarios Struct Array salario
     */

    int proc_salario[70][5];

    int menu, size;

    do {
        printf("\n%d", (*salario)[0].contador);
        printf("\n\nMENU_SALARIO");
        printf("\n1- Calcular Salario -> 1 funcionario");
        printf("\n2- Calcular Salario, lendo um csv_ Não esta funcional");
        printf("\n3- Calcular Salario todos os funcionarios num mes");
        printf("\n4- Listar todos os Salarios");
        printf("\n5- Media dos Salarios");
        printf("\n6- Soma + todos os salarios de um determinado funcionario");
        printf("\n7- Media salario - por ano");
        printf("\n8- Media de dias de um determinado funcionario - ate ano atual");
        printf("\n9- Guardar");
        printf("\n0 - Sair\n");
        printf("Opção: ");
        menu = obterInt(MIN_OP_MENU_SALARIO, MAX_OP_MENU_SALARIO, "");
        switch (menu) {
            case 1:
                Calcular_Salario(funcionarios, salario);
                logMsg("Calcular Salario", FILENAME_LOG);
                break;
            case 2:
                calcular_salario_csv(funcionarios, proc_salario, salario);
                logMsg("Calcular Salario CSV", FILENAME_LOG);
                break;

            case 3:
                calcular_salario_tdsfunc_nummes(funcionarios, salario);
                logMsg("Calcular todos os Salarios", FILENAME_LOG);
                break;
            case 4:listarSalario(salario);
                logMsg("Listar Salario", FILENAME_LOG);
                break;
            case 5:mediaSalario(salario);
                logMsg("Media Salario", FILENAME_LOG);
                break;
            case 6:
                soma_do_salario_de_funcionario_em_funcao_do_tempo(funcionarios, salario);
                logMsg("Soma do salario de um funcionario", FILENAME_LOG);
                break;
            case 7:mediaSalario_det_ano(salario);
                logMsg("Media Salario em cada Ano", FILENAME_LOG);
                break;
            case 8:media_numdias(salario);
                logMsg("Media do numero dias", FILENAME_LOG);
                break;
            case 9:EscreverFicheiro_Binario_Salario(salario);
                logMsg("Gravar Salario", FILENAME_LOG);
                break;
            case 0:
                break;

        }
    } while (menu != 0);
}

int carregar_salario(SALARIO **salario, FILE *fp) {


    /*!
     * Função Carregar Salario
     * 
     * Esta função permite verificar se o ficheiro binarios relativos aos salarios
     * se encontra vazio ou possui dados.
     * É lido o primeiro valor inteiro, que devido á programação
     * realizada sabemos que é o contador da estrutura salarios. Se este se econtrar
     * vazio podemos determinar que o ficheiro se encontra vazio. Mas se o valor
     * for diferente de 0, neste caso superior a 0, sabemos que possui dados e 
     * é alocado memoria tendo em conta o numero de estruturas que se encontram escritras
     * no ficheiro.
     * 
     * 
     * @param salario Struct Array salario
     * @param fp Ponteiro de FP
     */



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
