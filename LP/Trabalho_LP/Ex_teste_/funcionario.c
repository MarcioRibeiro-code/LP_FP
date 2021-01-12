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


int Procurar_CodFuncionario(FUNCIONARIO funcionarios[], int numero, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        if (funcionarios[i].codigo == numero) {
            return i;
        }
    }
    return -1;
}

void Inserir_Funcionario(FUNCIONARIO *funcionarios) {
    int aux;
    int contador = funcionarios[0].contador;
    printf("\nInserir Funcionario");

    printf("\nCodigo");

    cleanInputBuffer();
    //CODIGO DO FUNCIONARIO
    aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);

    if (Procurar_CodFuncionario(funcionarios, aux, contador) == -1) {
        funcionarios[contador].codigo = aux;

        //NOME DO FUNCIONARIO
        lerString(funcionarios[contador].nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);

        //NUMERO DE TELEFONE DO FUNCIONARIO
        lerString(funcionarios[contador].num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);

        //ESTADO CIVIL DO FUNCIONARIO
        funcionarios[contador].est_civil = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL,
                OBTER_EST_CIVIL);

        //NUMERO DE DEPENDENTES DO FUNCIONARIO
        funcionarios[contador].num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
                MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);

        //ESTADO IRS DO FUNCIONARIO
        funcionarios[contador].est_irs = obterInt(MIN_EST_IRS, MAX_EST_IRS,
                OBTER_EST_IRS);

        //CARGO DO FUNCIONARIO
        funcionarios[contador].cargo = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO,
                OBTER_NUM_CARGO);

        //DATA DE NASCIMENTO
        //DIA
        funcionarios[contador].data_de_nascimento.dia = obterInt(MIN_DIA, MAX_DIA,
                OBTER_DIA_NASC);

        //MES
        funcionarios[contador].data_de_nascimento.mes = obterInt(MIN_MES, MAX_MES,
                OBTER_MES_NASC);

        //ANO
        funcionarios[contador].data_de_nascimento.ano = obterInt(MIN_ANO, MAX_ANO,
                OBTER_ANO_NASC);

        //DATA DE ENTRADA
        //DIA
        funcionarios[contador].data_de_entrada.dia = obterInt(MIN_DIA, MAX_DIA,
                OBTER_DIA_ENTRADA);

        //MES
        funcionarios[contador].data_de_entrada.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);

        //ANO
        funcionarios[contador].data_de_entrada.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);

        funcionarios[contador].flag = 1;
        funcionarios[0].contador++;
        // if(contador%2 ==1)
        //funcionarios = realloc(funcionarios, sizeof (FUNCIONARIO)*contador);
    }
}

void imprimirFuncionario(FUNCIONARIO funcionarios[], int i) {

    if (funcionarios[i].flag == 1) {
        printf("\nCodigo: %d", funcionarios[i].codigo);
        printf("\nNome do Funcionario: %s", funcionarios[i].nome);
        printf("\nNumero de Telefone: %s", funcionarios[i].num_tlf);
        printf("\nEstado Civil: %s", estadoCivilToString(funcionarios[i].est_civil));
        printf("\nNumero de Depentendentes: %d", funcionarios[i].num_dependentes);
        printf("\nCargo: %s", cargoToString(funcionarios[i].cargo));
        printf("\nIRS: %s", EST_IRS_ToString(funcionarios[i].est_irs));

        printf("\nData de Nascimento: %d-%d-%d", funcionarios[i].data_de_nascimento.dia,
                funcionarios[i].data_de_nascimento.mes, funcionarios[i].data_de_nascimento.ano);

        printf("\nData de Entrada: %d-%d-%d\n", funcionarios[i].data_de_entrada.dia,
                funcionarios[i].data_de_entrada.mes, funcionarios[i].data_de_entrada.ano);
    } else {
        printf("\nCodigo: %d", funcionarios[i].codigo);
        printf("\nNome do Funcionario: %s", funcionarios[i].nome);
        printf("\nData de Saida: %i-%i-%i\n", funcionarios[i].data_de_saida.dia,
                funcionarios[i].data_de_saida.mes, funcionarios[i].data_de_saida.ano);
    }
}

void listarFuncionarios(FUNCIONARIO *funcionarios) {
    int contador = funcionarios[0].contador;


    if (contador > 0) {
        int i;
        for (i = 0; i < contador; i++) {
            imprimirFuncionario(funcionarios, i);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void consultaFuncionario(FUNCIONARIO *funcionarios) {
    int contador = funcionarios[0].contador;

    int numero = Procurar_CodFuncionario(funcionarios, obterInt(MIN_NUM_COD_FUNC,
            MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC), contador);

    if (numero != -1) {
        imprimirFuncionario(funcionarios, numero);
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

void AtualizarFuncionario(FUNCIONARIO *funcionarios) {
    int contador = funcionarios[0].contador;
    int aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);
    int numero = Procurar_CodFuncionario(funcionarios, aux, contador);

    //numero = i se encontrar, logo posição;
    if (numero != -1) {
        int op;
        do {
            printf("\nAlterar Dados");
            printf("\n1-Codigo"
                    "\n2-Nome"
                    "\n3-Numero de telefone"
                    "\n4-Estado Civil"
                    "\n5-Numero de dependentes"
                    "\n6-Cargo"
                    "\n7-Data de Nascimento"
                    "\n8-Data de Entrada");
            scanf("%i", &op);

            cleanInputBuffer();

            switch (op) {

                    //ALTERAR CODIGO
                case 1:
                    aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);
                    if (Procurar_CodFuncionario(funcionarios, aux, contador) == -1) {
                        funcionarios[numero].codigo = aux;
                    }
                    break;

                    //ALTERAR NOME
                case 2:
                    lerString(funcionarios[numero].nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);
                    break;

                    //ALTERAR NUMERO DE TELEFONE DO FUNCIONARIO
                case 3:
                    lerString(funcionarios[numero].num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);
                    break;

                    //ALTERAR ESTADO CIVIL
                case 4:
                    funcionarios[numero].est_civil = obterInt(MIN_EST_CIVIL, MAX_EST_CIVIL,
                            OBTER_EST_CIVIL);
                    break;

                    //ALTERAR NUMERO DE DEPENDENTES DO FUNCIONARIO
                case 5:
                    funcionarios[numero].num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
                            MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);
                    break;

                    //ALTERAR CARGO DO FUNCIONARIO
                case 6:
                    funcionarios[numero].cargo = obterInt(MIN_NUM_CARGO, MAX_NUM_CARGO,
                            OBTER_NUM_CARGO);
                    break;

                    //ALTERAR DATA DE NASCIMENTO
                case 7:
                    printf("\n1-DIA"
                            "\n2-MES"
                            "\n3-ANO"
                            "\nOpção: ");
                    scanf("%i", &op);

                    switch (op) {
                            //ALTERAR DIA
                        case 1:
                            funcionarios[numero].data_de_nascimento.dia = obterInt(MIN_DIA, MAX_DIA,
                                    OBTER_DIA_NASC);
                            break;

                            //ALTERAR MES
                        case 2:
                            funcionarios[numero].data_de_nascimento.mes = obterInt(MIN_MES, MAX_MES,
                                    OBTER_MES_NASC);
                            break;

                            //ALTERAR ANO
                        case 3:
                            funcionarios[numero].data_de_nascimento.ano = obterInt(MIN_ANO, MAX_ANO,
                                    OBTER_ANO_NASC);
                            break;
                    }

                    break;


                case 8:
                    printf("\n1-DIA"
                            "\n2-MES"
                            "\n3-ANO"
                            "\nOpção: ");
                    scanf("%i", &op);

                    switch (op) {
                            //ALTERAR DIA
                        case 1:
                            funcionarios[numero].data_de_entrada.dia = obterInt(MIN_DIA, MAX_DIA,
                                    OBTER_DIA_NASC);
                            break;

                            //ALTERAR MES
                        case 2:
                            funcionarios[numero].data_de_entrada.mes = obterInt(MIN_MES, MAX_MES,
                                    OBTER_MES_NASC);
                            break;

                            //ALTERAR ANO
                        case 3:
                            funcionarios[numero].data_de_entrada.ano = obterInt(MIN_ANO, MAX_ANO,
                                    OBTER_ANO_NASC);
                            break;
                    }
                    break;

                case 0:
                    break;
            }

        } while (op != 0);
    }
}

void EliminarFuncionario(FUNCIONARIO *funcionarios) {
    int contador = funcionarios[0].contador;
    int aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);
    int numero = Procurar_CodFuncionario(funcionarios, aux, contador);

    if (numero != -1) {
        funcionarios[numero].flag = 0;

        time_t currentTime;
        time(&currentTime);

        struct tm *myTime = localtime(&currentTime);

        funcionarios[numero].data_de_saida.dia = myTime->tm_mday; //Adicionar a data local atraves do <time.h> -> video do yt
        funcionarios[numero].data_de_saida.mes = myTime->tm_mon + 1;
        funcionarios[numero].data_de_saida.ano = myTime->tm_year + 1900;
    }
}

void EscreverFicheiro_Binario(FUNCIONARIO *funcionarios, FILE *fp) {
    fp = fopen(FILENAME, "wb+");
    int x = funcionarios[0].contador;

    fwrite(funcionarios, sizeof (FUNCIONARIO), x, fp);

    fclose(fp);
    puts("\nGravado com Sucesso");
}

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
    if (TAMANHO_INICIAL < x) {
        funcionarios = (FUNCIONARIO*) realloc(funcionarios, sizeof (FUNCIONARIO)*(funcionarios[0].contador + 1)*2);
    }
    fread(funcionarios, sizeof (FUNCIONARIO), x, fp);
    funcionarios[0].contador = x;

    fclose(fp);
}

void readcsv(dict values[], int est_irs) {
    FILE *fp; //= fopen(FILENAME_CSV_nCasado, "r");

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

    char line[200];
    int row_count = 0;
    int field_count = 0;

    int i = 0;
    while (fgets(line, sizeof (line), fp)) {
        field_count = 0;
        row_count++;

        char *token;
        token = strtok(line, ";");

        while (token != NULL) {
            if (field_count == 0)
                strcpy(values[i].col1, token);
            if (field_count == 1)
                strcpy(values[i].col2, token);
            if (field_count == 2)
                strcpy(values[i].col3, token);
            if (field_count == 3)
                strcpy(values[i].col4, token);
            if (field_count == 4)
                strcpy(values[i].col5, token);
            if (field_count == 5)
                strcpy(values[i].col6, token);
            if (field_count == 6)
                strcpy(values[i].col7, token);
            token = strtok(NULL, ";");
            field_count++;
        }
        i++;
        printf("\n");
    }
    x = i;
}

void readcsv_seg_social(SS values[]) {
    FILE *fp = fopen(FILENAME_CSV_SS, "r");
    int x;
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    char line[200];
    int row_count = 0;
    int field_count = 0;

    int i = 0;
    while (fgets(line, sizeof (line), fp)) {
        field_count = 0;
        row_count++;

        char *token;
        token = strtok(line, ";");

        while (token != NULL) {
            if (field_count == 0)
                strcpy(values[i].col1, token);
            if (field_count == 1)
                strcpy(values[i].col2, token);
            token = strtok(NULL, ";");
            field_count++;
        }
        i++;
        printf("\n");
    }
    x = i;
}

void printValues(SS values[]) {

    for (int i = 0; i < 3; i++) {


        printf(" Col1 %s, Col2 %s", values[i].col1, values[i].col2);
        printf("\n");
    }

}

float calcular_salarioBase(FUNCIONARIO funcionarios[], int numero, int dias[], int i) {
    switch (funcionarios[numero].cargo) {
        case 0:
            //empregado
            return (dias[i] * VALOR_HORA_EMPREGADO);
            break;

        case 1:
            //CHEFE
            return (dias[i] * VALOR_HORA_CHEFE);
            break;

        case 2:
            //ADMINISTRADOR
            return (dias[i] * VALOR_HORA_ADMINISTRADOR);
            break;
    }
}

float calcular_irs(FUNCIONARIO funcionarios[], int numero, SALARIO salario) {
    int est_irs = funcionarios[numero].est_irs;
    dict values[LINHAS_CSV_1titular];
    int flag = 0, i;

    if (est_irs == 0) { // NAO CASADO

        readcsv(values, est_irs);
        switch (funcionarios[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col2));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col2));
                break;

            case 1:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col3));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col3));
                break;

            case 2:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col4));
                break;

            case 3:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col5));
                break;

            case 4:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col6));
                break;

            case 5:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col7));
                break;

            default:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col7));
                break;
        }

    } else if (est_irs == 1) { // 1- TITULAR
        readcsv(values, est_irs);
        switch (funcionarios[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col2));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col2));
                break;

            case 1:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col3));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col3));
                break;

            case 2:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col4));
                break;
            case 3:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col5));
                break;
            case 4:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col6));
                break;
            case 5:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col7));
                break;
            default:
                for (int i = 0; i < LINHAS_CSV_1titular; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 36 && flag == 0)
                    return (salario.base * atof(values[36].col7));
                break;
        }
    } else {

        readcsv(values, est_irs);
        switch (funcionarios[numero].num_dependentes) {

            case 0:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col2));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col2));
                break;

            case 1:
                for (i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col3));
                        flag = 1;
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col3));
                break;

            case 2:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col4));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col4));
                break;

            case 3:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col5));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col5));
                break;

            case 4:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col6));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col6));
                break;

            case 5:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col7));
                break;

            default:
                for (int i = 0; i < LINHAS_CSV; i++) {
                    if (salario.base <= atoi(values[i].col1)) {
                        return (salario.base * atof(values[i].col7));
                    } else continue;
                }
                if (i == 35 && flag == 0)
                    return (salario.base * atof(values[35].col7));
                break;
        }

    }

    //comparar salario base, com o valor para col1 do respetivo ficheiro csv
    //depois disso ver o numero de dependentes do funcionario 
    //coluna para o nº de dependentes, multiplicar salario.base pelo valor da alinea

}

void calcular_ss() {
    SS values[3];
    readcsv_seg_social(values);
    printValues(values);
}

void Calcular_salario(FUNCIONARIO *funcionarios) {
    int contador = funcionarios[0].contador;
    int aux = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);
    int numero = Procurar_CodFuncionario(funcionarios, aux, contador);
    SALARIO salario;

    if (numero != -1) {
        int *dias;
        salario.num_meses = obterInt(MIN_MES, 60, OBTER_MES_TRABALHO) - 1;
        dias = calloc(salario.num_meses, sizeof (int));
        for (int i = 0; i < salario.num_meses; i++) {
            //OBTER NUM DE DIAS POR MES
            printf("MES [%i]", i + 1);
            dias[i] = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_TRABALHO);
            salario.base = calcular_salarioBase(funcionarios, numero, dias, i);
            salario.sub_alimentacao = dias[i] * VALOR_SUBSIDIO_ALIMENTACAO;
            salario.valor_irs = calcular_irs(funcionarios, numero, salario);
        }
    } else {
        puts(ERRO_FUNCIONARIO_NAO_EXISTE);
    }

}