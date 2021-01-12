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

//MENSAGEM ERRO ALOCAÇÃO DE MEMORIA

void faill(void) {
    printf("Memoria não foi alocada");
    exit(EXIT_FAILURE);
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

char *cargoToString(CARGO cargo) {
    switch (cargo) {
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

char *EST_IRS_ToString(ESTADO_IRS irs) {
    switch (irs) {
        case N_CASADO:
            return "Não Casado";
            break;

        case CASADO_1TITULAR:
            return "Casado 1 Titular";
            break;

        case CASADO_2TITULAR:
            return "Casado 2 Titular";
            break;
    }

}
//______________________________________________________________________________

/*
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
 */

int grow_StructArray_Funcionario(FUNCIONARIO **funcionarios) {

    const int novoTamanho = (*funcionarios)[0].tamanho * 2;

    FUNCIONARIO *temp = (FUNCIONARIO*) realloc(*funcionarios, (novoTamanho * sizeof (FUNCIONARIO)));

    if (temp == NULL) {
        faill();
    } else {
        *funcionarios = temp;
    }

    return novoTamanho;
}

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

int devolve_tempo(char opcao) {

    time_t currentTime;
    time(&currentTime);

    struct tm *myTime = localtime(&currentTime);

    if (toupper(opcao) == 'D') {
        // Retorna o dia atual se opçao for D(DIA).
        return myTime->tm_mday;

    } else if (toupper(opcao) == 'M') {
        return myTime ->tm_mon + 1;
        /*Retorna o mes atual se opçao for M(MES);
        +1 uma vez que janeiro é igual a 0 e dezembro;
        é igual a 11. */
    } else {
        return myTime->tm_year + 1900;
        /*Retorna o ano atual se opçao for diferente das duas anteriores
         é adicionado +1900 ao resultado, uma vez que a função "tm_year"
         * apresenta os anos apartir de 1900; ou seja 2021 é dado como 121
         */
    }

}

int get_size(char *file_name) {
    FILE *file = fopen(file_name, "rb");

    if (file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

int Procurar_CodFuncionario(FUNCIONARIO **funcionarios, int numero, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if ((*funcionarios)[i].codigo == numero) {
            return i;
        }
    }
    return -1;
}

void Inserir_Funcionario(FUNCIONARIO **funcionarios) {
    int aux;
    int contador = (*funcionarios)[0].contador;

    if (contador == (*funcionarios)[0].tamanho) {
        (*funcionarios)[0].tamanho = grow_StructArray_Funcionario(funcionarios);
    }


    printf("\nInserir Funcionario");

    printf("\nCodigo");

    //CODIGO DO FUNCIONARIO
    aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);

    if (Procurar_CodFuncionario(funcionarios, aux, contador) == -1) {
        (*funcionarios)[contador].codigo = aux;

        //NOME DO FUNCIONARIO
        lerString((*funcionarios)[contador].nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);


        //NUMERO DE TELEFONE DO FUNCIONARIO
        lerString((*funcionarios)[contador].num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);

        //ESTADO CIVIL DO FUNCIONARIO
        (*funcionarios)[contador].est_civil = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL,
                OBTER_EST_CIVIL);

        //NUMERO DE DEPENDENTES DO FUNCIONARIO
        (*funcionarios)[contador].num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
                MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);

        //ESTADO IRS DO FUNCIONARIO
        (*funcionarios)[contador].est_irs = obterInt(MIN_EST_IRS, MAX_EST_IRS,
                OBTER_EST_IRS);

        //CARGO DO FUNCIONARIO
        (*funcionarios)[contador].cargo = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO,
                OBTER_NUM_CARGO);

        //DATA DE NASCIMENTO
        //DIA
        (*funcionarios)[contador].data_de_nascimento.dia = obterInt(MIN_DIA, MAX_DIA,
                OBTER_DIA_NASC);

        //MES
        (*funcionarios)[contador].data_de_nascimento.mes = obterInt(MIN_MES, MAX_MES,
                OBTER_MES_NASC);

        //ANO
        (*funcionarios)[contador].data_de_nascimento.ano = obterInt(MIN_ANO, MAX_ANO,
                OBTER_ANO_NASC);

        //DATA DE ENTRADA
        //DIA
        (*funcionarios)[contador].data_de_entrada.dia = obterInt(MIN_DIA, MAX_DIA,
                OBTER_DIA_ENTRADA);

        //MES
        (*funcionarios)[contador].data_de_entrada.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);

        //ANO
        (*funcionarios)[contador].data_de_entrada.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);

        (*funcionarios)[contador].flag = 1;
        (*funcionarios)[0].contador++;

        /* AINDA EM FALTA - REALOCAR, SE CONTADOR == TAMANHO ENTAO AUMENTAR TAMANHO DISPONIVEL 
        if (contador + 1 >= TAMANHO_INICIAL)
            funcionarios = realloc(funcionarios, sizeof (FUNCIONARIO)*2); */
    } else {
        puts(ERRO_FUNCIONARIO_EXISTE);
    }
}

void imprimirFuncionario(FUNCIONARIO **funcionarios, int i) {

    if ((*funcionarios)[i].flag == 1) {
        printf("\nCodigo: %d", (*funcionarios)[i].codigo);
        printf("\nNome do Funcionario: %s", (*funcionarios)[i].nome);
        printf("\nNumero de Telefone: %s", (*funcionarios)[i].num_tlf);
        printf("\nEstado Civil: %s", estadoCivilToString((*funcionarios)[i].est_civil));
        printf("\nNumero de Depentendentes: %d", (*funcionarios)[i].num_dependentes);
        printf("\nCargo: %s", cargoToString((*funcionarios)[i].cargo));
        printf("\nIRS: %s", EST_IRS_ToString((*funcionarios)[i].est_irs));

        printf("\nData de Nascimento: %d-%d-%d", (*funcionarios)[i].data_de_nascimento.dia,
                (*funcionarios)[i].data_de_nascimento.mes, (*funcionarios)[i].data_de_nascimento.ano);

        printf("\nData de Entrada: %d-%d-%d\n", (*funcionarios)[i].data_de_entrada.dia,
                (*funcionarios)[i].data_de_entrada.mes, (*funcionarios)[i].data_de_entrada.ano);
    } else {
        printf("\nCodigo: %d", (*funcionarios)[i].codigo);
        printf("\nNome do Funcionario: %s", (*funcionarios)[i].nome);
        printf("\nData de Saida: %i-%i-%i\n", (*funcionarios)[i].data_de_saida.dia,
                (*funcionarios)[i].data_de_saida.mes, (*funcionarios)[i].data_de_saida.ano);
    }
}

void listarFuncionarios(FUNCIONARIO **funcionarios) {
    int contador = (*funcionarios)[0].contador;


    if (contador > 0) {
        int i;
        for (i = 0; i < contador; i++) {
            imprimirFuncionario(funcionarios, i);
        }
    } else {
        puts(ERRO_LISTA_FUNCIONARIO_VAZIA);
    }
}

void consultaFuncionario(FUNCIONARIO **funcionarios) {
    int contador = (*funcionarios)[0].contador;

    int codigo_func = Procurar_CodFuncionario(funcionarios, obterInt(MIN_NUM_COD_FUNC,
            MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC), contador);

    if (codigo_func != -1) {
        imprimirFuncionario(funcionarios, codigo_func);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void AtualizarFuncionario(FUNCIONARIO **funcionarios) {
    int contador = (*funcionarios)[0].contador;
    int posicao_func = Procurar_CodFuncionario(funcionarios, obterInt(MIN_NUM_COD_FUNC,
            MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC), contador);

    //numero = i se encontrar, logo posição;
    if (posicao_func != -1) {
        int menu;
        int sub_menu;
        int novo_codigo;
        do {

            // alterar MENU para obter INT ->
            printf("\nAlterar Dados");
            printf("\n1-Codigo"
                    "\n2-Nome"
                    "\n3-Numero de telefone"
                    "\n4-Estado Civil"
                    "\n5-Numero de dependentes"
                    "\n6-Cargo"
                    "\n7-Data de Nascimento"
                    "\n8-Data de Entrada");
            scanf("%i", &menu);


            switch (menu) {

                    //ALTERAR CODIGO
                case 1:
                    novo_codigo = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);

                    if (Procurar_CodFuncionario(funcionarios, novo_codigo, contador) == -1) {
                        (*funcionarios)[posicao_func].codigo = novo_codigo;
                    } else {
                        puts(ERRO_FUNCIONARIO_EXISTE);
                    }

                    break;

                    //ALTERAR NOME
                case 2:
                    lerString((*funcionarios)[posicao_func].nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);
                    break;

                    //ALTERAR NUMERO DE TELEFONE DO FUNCIONARIO
                case 3:
                    lerString((*funcionarios)[posicao_func].num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);
                    break;

                    //ALTERAR ESTADO CIVIL -> ENUMERAÇÃO
                case 4:
                    (*funcionarios)[posicao_func].est_civil = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL,
                            OBTER_EST_CIVIL);
                    break;

                    //ALTERAR NUMERO DE DEPENDENTES DO FUNCIONARIO
                case 5:
                    (*funcionarios)[posicao_func].num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
                            MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);
                    break;

                    //ALTERAR CARGO DO FUNCIONARIO -> ENUMERAÇÃO
                case 6:
                    (*funcionarios)[posicao_func].cargo = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO,
                            OBTER_NUM_CARGO);
                    break;

                    //ALTERAR DATA DE NASCIMENTO
                case 7:

                    printf("\nData de Nascimento");
                    do {
                        sub_menu = obterInt(MIN_OPCAO_DATA, MAX_OPCAO_DATA, OBTER_OPCAO_DATA);

                        switch (sub_menu) {
                                //ALTERAR DIA
                            case 1:
                                (*funcionarios)[posicao_func].data_de_nascimento.dia
                                        = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
                                break;

                                //ALTERAR MES
                            case 2:
                                (*funcionarios)[posicao_func].data_de_nascimento.mes
                                        = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);
                                break;

                                //ALTERAR ANO
                            case 3:
                                (*funcionarios)[posicao_func].data_de_nascimento.ano
                                        = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);
                                break;
                            case 0:
                                break;
                        }
                    } while (sub_menu != 0);

                    break;

                    //ALTERAR DATA DE ENTRADA
                case 8:

                    printf("\nData de Entrada");
                    do {
                        sub_menu = obterInt(MIN_OPCAO_DATA, MAX_OPCAO_DATA, OBTER_OPCAO_DATA);

                        switch (sub_menu) {
                                //ALTERAR DIA
                            case 1:
                                (*funcionarios)[posicao_func].data_de_entrada.dia
                                        = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_ENTRADA);
                                break;

                                //ALTERAR MES
                            case 2:
                                (*funcionarios)[posicao_func].data_de_entrada.mes
                                        = obterInt(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);
                                break;

                                //ALTERAR ANO
                            case 3:
                                (*funcionarios)[posicao_func].data_de_entrada.ano
                                        = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);
                                break;
                            case 0:
                                break;
                        }
                    } while (sub_menu != 0);

                    break;


                    //SAIR -> MENU PRINCIPAL
                case 0:
                    break;
            }

        } while (menu != 0);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void EliminarFuncionario(FUNCIONARIO **funcionarios) {
    int contador = (*funcionarios)[0].contador;
    int numero = Procurar_CodFuncionario(funcionarios, obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC), contador);

    if (numero != -1) {

        //FLAG é igualado a 0.
        (*funcionarios)[numero].flag = 0;



        (*funcionarios)[numero].data_de_saida.dia = devolve_tempo('D');
        (*funcionarios)[numero].data_de_saida.mes = devolve_tempo('M');
        (*funcionarios)[numero].data_de_saida.ano = devolve_tempo('A');
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void EscreverFicheiro_Binario(FUNCIONARIO **funcionarios, FILE *fp) {

    fp = fopen(FILENAME_BIN_FUNCIONARIO, "wb+");
    int contador = (*funcionarios)[0].contador;

    fwrite(*funcionarios, sizeof (FUNCIONARIO), contador, fp);

    fclose(fp);
    puts("\nGravado com Sucesso");
}


//TROCAR 

/*
void LerFicheiro_Binario(FUNCIONARIO *funcionarios, FILE *fp) {
    int x;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    while (fread(funcionarios, sizeof (FUNCIONARIO), 1, fp) == 1) {
        x += funcionarios->contador;
    }
    rewind(fp);

    if (x + 1 >= TAMANHO_INICIAL) {

        funcionarios = realloc(funcionarios, sizeof (FUNCIONARIO)*2);
    }
    fread(funcionarios, sizeof (FUNCIONARIO), x, fp);
    funcionarios[0].contador = x;

    fclose(fp);
}
 */

void printValues_IRS(dict *values) {
    for (int i = 0; i < LINHAS_CSV; i++) {
        printf("COL1 %s,COL2 %s,COL3 %s", values[i].col1, values[i].col2, values[i].col3);
        printf(",COL4 %s,COL5 %s,COL6 %s", values[i].col4, values[i].col5, values[i].col6);
        printf(",COL7 %s\n", values[i].col7);

    }
}

void readcsv(dict *values, int est_irs) {

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
    printValues_IRS(values);
}

void readcsv_seg_social(SS values[]) {
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
        printf("ROW COUNT: %i", row_count);
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

void printValues(SS *values) {

    for (int i = 0; i < 3; i++) {
        printf("Col1 %s,col2 %s\n", values[i].col1, values[i].col2);
    }
}

void imprimirSalario(SALARIO **salario, int i) {

    printf("\nCodigo Funcionario: %i", (*salario)[i].codigo_funcionario);
    printf("\nNumero de Meses: %i", (*salario)[i].num_meses);
    printf("\nDias de trabalho: %i", (*salario)[i].num_dias);
    printf("\nSalario base: %.2f", (*salario)[i].base);
    printf("\nSubsidio de Alimentação: %.2f", (*salario)[i].sub_alimentacao);
    printf("\nSegurança Social: TOTAL -> %.2f", (*salario)[i].ss.valor_ss_total);
    printf("\nSegurança Social: Funcionario -> %.2f", (*salario)[i].ss.valor_ss_funcionario);
    printf("\nSegurança Social: Empresa -> %.2f", (*salario)[i].ss.valor_ss_empresa);
    printf("\nIRS: %.2f", (*salario)[i].valor_irs);

    printf("\nDATA");
    printf("\n DIA: %i", (*salario)[i].data.dia);
    printf("\n MES: %i", (*salario)[i].data.mes);
    printf("\n ANO: %i", (*salario)[i].data.ano);

    printf("\nValor Liquido: %.2f", (*salario)[i].valor_liquido);
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

//trocar nome teste 

void teste(FUNCIONARIO **funcionarios, SALARIO **salario) {
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
        printf("opção 1");
        sal_base = sal_base * 1.023;
    } else if (num_vezes_dias >= 5 && num_vezes_dias < 7) {
        printf("opção 2");
        sal_base = sal_base * 1.041;
    } else if (num_vezes_dias >= 7) {
        printf("opção 3");
        sal_base = sal_base * 1.067;
    } else {
        printf("opção 4");

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
                salario_base = (22 * (8 * VALOR_HORA_EMPREGADO));
            } else {
                excedente_dias = num_dias - 22;
                salario_base = (22 * (8 * VALOR_HORA_EMPREGADO)+
                        ((excedente_dias * 8)*(VALOR_HORA_EMPREGADO * 1.5)));
            }

            break;

        case 1://CHEFE
            if (num_dias <= 22) {
                salario_base = (22 * (8 * VALOR_HORA_CHEFE));
            } else {
                excedente_dias = num_dias - 22;
                salario_base = (22 * (8 * VALOR_HORA_CHEFE)+
                        ((excedente_dias * 8)*(VALOR_HORA_CHEFE * 1.5)));
            }
            break;

        case 2://ADMINISTRADOR
            if (num_dias <= 22) {
                salario_base = (22 * (8 * VALOR_HORA_ADMINISTRADOR));
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
    printf("\nESTADO IRS: %i", est_irs);
    dict values[50];
    int flag = 0;
    printf("\nNUMERO: %i", numero);
    printf("\nSalario Base: %f", sal_base);
    printf("\nDEPENDENTES: %i", (*funcionarios)[numero].num_dependentes);
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
            int codigo_func_salario = Procurar_CodFuncionario_Salario(salario, (*funcionarios)[j].codigo, salario_contador);

            int max_aux = 0;
            int max = ((365 * (*salario)[codigo_func_salario].data.ano)
                    +(30 * (*salario)[codigo_func_salario].data.mes)
                    + (*salario)[codigo_func_salario].data.dia);

            int data_atual = ((365 * (devolve_tempo('A')))+(30 * (devolve_tempo('M'))) + devolve_tempo('D'));

            if (max > max_aux) {
                max_aux = max;
            }

            if ((data_atual - max) > MAX_DIA) {
                Calcular_Salario_tdsfunc(funcionarios,salario,j);
            }else{
                continue;
            }

        }else{
            Calcular_Salario_tdsfunc(funcionarios,salario,j);
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

/*
void LerFicheiro_Binario_Salario(SALARIO *salario) {
    int x;

    FILE *fp = fopen(FILENAME_CSV_SALARIO, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    while (fread(salario, sizeof (SALARIO), 1, fp) == 1) {
        x += salario->contador;
    }
    rewind(fp);
    if (x + 1 >= TAMANHO_INICIAL) {

        salario = realloc(salario, sizeof (SALARIO)*2);
    }
    fread(salario, sizeof (SALARIO), x, fp);
    salario[0].contador = x;

    fclose(fp);
}
 */

void Calcular_Salario(FUNCIONARIO **funcionarios, SALARIO **salario) {


    int salario_contador = (*salario)[0].contador;


    if (salario_contador == (*salario)[0].tamanho) {
        (*salario)[0].tamanho = grow_StructArray_Salario(salario);
    }

    int func_contador = (*funcionarios)[0].contador;
    int codigo_funcionario = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC,
            MSG_OBTER_COD_FUNC); // Introduzir o codigo do funcionario para fazer a pesquisa - se existe ou nao na tabela


    int posicao_funcionario = Procurar_CodFuncionario(funcionarios,
            codigo_funcionario, func_contador); //devolve a posicao do certo codigo na tabela(array) funcionarios

    if (posicao_funcionario != -1) {
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

        (*salario)[salario_contador].data.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_SALARIO); // DEVOLVE TEMPO -> funcao 
        (*salario)[salario_contador].data.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_SALARIO);
        (*salario)[salario_contador].data.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_SALARIO);

        //Escrever em Csv
        /*fprintf(fp, "%i;%i;%i;", salario.contador,
                salario.codigo_funcionario, salario.num_meses);
        for (int j = 0; j < salario.num_meses; j++) {
            fprintf(fp, "%i;%f;%f;%f;%f;%f\n", salario.dias[i], salario.base,
                    salario.ss.valor_ss_total, salario.ss.valor_ss_funcionario, salario.valor_irs, salario.valor_liquido);
            
        }*/

        (*salario)[0].contador++;
    } else {

        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
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
        printf("\n1- Calcular Salario");
        printf("\n2- Listar todos os Salarios");
        printf("\n3- Media dos Salarios");
        printf("\n4- Soma + todos os salarios de um determinado funcionario");
        printf("\n5- Guardar");
        printf("\n0 - Sair\n");
        printf("Opção: ");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                Calcular_Salario(funcionarios, salario);
                break;
            case 2:
                listarSalario(salario);
                break;
            case 3:
                mediaSalario(salario);
                break;
            case 4:teste(funcionarios, salario);
                break;
            case 5:
                EscreverFicheiro_Binario_Salario(salario);
                break;
            case 6:
                break;
            case 0:
                break;

        }
    } while (menu != 0);

}

void menu_funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {

    int menu, size;

    do {
        printf("\n%d", (*funcionarios)[0].contador);
        printf("\n\nMENU_FUNCIONARIO");
        printf("\n1- Inserir Funcionario");
        printf("\n2- Listar todos os Funcionarios");
        printf("\n3- Consultar Funcionario");
        printf("\n4- Atualizar dados Funcionario");
        printf("\n5- Eliminar Funcionario");
        printf("\n6- Guardar");
        printf("\n0 - Sair\n");
        printf("Opção: ");
        scanf("%i", &menu);
        switch (menu) {
            case 1:

                Inserir_Funcionario(funcionarios);

                break;
            case 2:
                listarFuncionarios(funcionarios);
                break;
            case 3:
                consultaFuncionario(funcionarios);
                break;
            case 4:
                AtualizarFuncionario(funcionarios);
                break;
            case 5:
                EliminarFuncionario(funcionarios);
                break;
            case 6:EscreverFicheiro_Binario(funcionarios, fp);

                break;

            case 0:
                break;

        }
    } while (menu != 0);

}

int carregar_funcionario(FUNCIONARIO **funcionarios, FILE *fp) {

    int returno = 0;
    int contador = 0;

    fp = fopen(FILENAME_BIN_FUNCIONARIO, "rb");

    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        printf("contador : %i", contador);
        rewind(fp);
        if (contador > 0) {
            *funcionarios = (FUNCIONARIO*) malloc(contador * sizeof (FUNCIONARIO));
            fread(*funcionarios, sizeof (FUNCIONARIO), contador, fp);
            (*funcionarios)[0].tamanho = contador;
            (*funcionarios)[0].contador = (*funcionarios)[0].tamanho;
            returno = 1;

        }
        fclose(fp);
        if (!returno) {
            fp = fopen(FILENAME_BIN_FUNCIONARIO, "wb");
            if (fp != NULL) {
                *funcionarios = (FUNCIONARIO*) malloc(TAMANHO_INICIAL * sizeof (FUNCIONARIO));
                (*funcionarios)[0].contador = 0;
                (*funcionarios)[0].tamanho = TAMANHO_INICIAL;
                fclose(fp);

                returno = 1;
            }

        }
    }
    // printf("RETURNO: %i", returno);
    return returno;
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
