#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funclib.h"
#include "input.h"





//MENSAGEM ERRO ALOCAÇÃO DE MEMORIA

void faill(void) {
    printf("Memoria não foi alocada");
    exit(EXIT_FAILURE);
}

void grow_StructArray_Funcionario(FUNCIONARIO **funcionarios) {

    const int novoTamanho = (*funcionarios)[0].tamanho * 2;
    printf("Novo Tamanho: %i", novoTamanho);


    FUNCIONARIO *temp = (FUNCIONARIO*) realloc(*funcionarios, (novoTamanho * sizeof (FUNCIONARIO)));

    if (temp == NULL) {
        faill();
    } else {
        *funcionarios = temp;
        (*funcionarios)[0].tamanho = novoTamanho;
        printf("Funcionario Tamanho:%i", (*funcionarios)[0].tamanho);
    }


}
//CONVERTER ENUM EM STRING

char *estadoCivilToString(char est_civ) {
    switch (est_civ) {
        case 'C':
            return "CASADO";
            break;
        case 'D':
            return "DIVORCIADO";
            break;
        case 'V':
            return "VIUVO";
            break;
        case 'S':
            return "SOLTEIRO";
            break;
        default:
            return "SOLTEIRO";
    }
}

char *cargoToString(char cargo) {
    switch (cargo) {
        case 'E':
            return "EMPREGADO";
            break;
        case 'A':
            return "ADMINISTRADOR";
            break;
        case 'C':
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
    int codigo_funcionario;
    int contador = (*funcionarios)[0].contador;


    if (contador == (*funcionarios)[0].tamanho) {

        grow_StructArray_Funcionario(funcionarios);
    }



    printf("\nInserir Funcionario");


    //CODIGO DO FUNCIONARIO
    codigo_funcionario = obterInt(MIN_NUM_COD_FUNC, MAX_NUM_COD_FUNC, MSG_OBTER_COD_FUNC);

    if (Procurar_CodFuncionario(funcionarios, codigo_funcionario, contador) == -1) {
        (*funcionarios)[contador].codigo = codigo_funcionario;

        //NOME DO FUNCIONARIO
        lerString((*funcionarios)[contador].nome, MAX_CHAR_NOME, OBTER_NOME_FUNC);


        //NUMERO DE TELEFONE DO FUNCIONARIO
        lerString((*funcionarios)[contador].num_tlf, MAX_CHAR_NUM_TLF, OBTER_TLF_FUNC);

        //ESTADO CIVIL DO FUNCIONARIO

        (*funcionarios)[contador].est_civil = toupper(obterChar(OBTER_EST_CIVIL));
        while ((*funcionarios)[contador].est_civil != 'C'
                && (*funcionarios)[contador].est_civil != 'D' &&
                (*funcionarios)[contador].est_civil != 'V' &&
                (*funcionarios)[contador].est_civil != 'S') {
            (*funcionarios)[contador].est_civil = toupper(obterChar(OBTER_EST_CIVIL));
        }
        if ((*funcionarios)[contador].est_civil == 'C') {
            //ESTADO IRS DO FUNCIONARIO
            (*funcionarios)[contador].est_irs = obterInt(MIN_EST_IRS, MAX_EST_IRS,
                    OBTER_EST_IRS);

        } else {
            (*funcionarios)[contador].est_irs = 0;
        }

        //NUMERO DE DEPENDENTES DO FUNCIONARIO
        (*funcionarios)[contador].num_dependentes = obterInt(MIN_NUM_DEPENDENTES,
                MAX_NUM_DEPENDENTES, OBTER_NUM_DEPENDENTES);


        //CARGO DO FUNCIONARIO
        (*funcionarios)[contador].cargo = toupper(obterChar(OBTER_NUM_CARGO));
        while ((*funcionarios)[contador].cargo != 'E' &&
                (*funcionarios)[contador].cargo != 'C' &&
                (*funcionarios)[contador].cargo != 'A') {
            (*funcionarios)[contador].cargo = toupper(obterChar(OBTER_NUM_CARGO));
        }



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
        puts(ERRO_LISTA_VAZIA);
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
            MAX_NUM_COD_FUNC, OBTER_COD_FUNC_ALT), contador);

    //numero = i se encontrar, logo posição;
    if (posicao_func != -1) {
        int menu_atualizar;
        int novo_codigo;
        do {

            menu_atualizar = obterInt(MIN_OPCAO_MENU, MAX_OP_SUBMENU_ATUALIZAR,
                    MSG_SUBMENU_ATUALIZAR);


            switch (menu_atualizar) {

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

                    //SAIR -> MENU PRINCIPAL
                case 0:
                    break;

            }

        } while (menu_atualizar != 0);
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

void EscreverFicheiro_Binario_Funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {

    int contador = (*funcionarios)[0].contador;

    if (contador >= 1) {

        fp = fopen(FILENAME_BIN_FUNCIONARIO, "wb+");

        if (fp == NULL) {
            puts(ERRO_ABRIR_FICHEIRO);
        } else {
            fwrite(*funcionarios, sizeof (FUNCIONARIO), contador, fp);
        }
        fclose(fp);
        puts(GRAVADO_COM_SUCESSO);
    }
}

void EscreverFicheiro_Texto_Funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {

    int contador = (*funcionarios)[0].contador;
    int i;

    if (contador >= 1) {

        fp = fopen(FILENAME_TXT_FUNCIONARIO, "w+");
        if (fp == NULL) {
            puts(ERRO_ABRIR_FICHEIRO);
        } else {

            fprintf(fp, "Contador,Flag,Codigo Funcionario,");
            fprintf(fp, "Nome,Numero de Telefone,Estado Civil,");
            fprintf(fp, "Numero de Dependentes,Cargo,Estado IRS");
            fprintf(fp, "Data Nascimento-Dia,Data Nascimento-Mes,Data Nascimento-Ano,");
            fprintf(fp, "Data Entrada-Dia,Data Entrada-Mes,Data Entrada-Ano,");
            fprintf(fp, "Data Saida-Dia,Data Saida-Mes,Data Saida-Ano\n");
            for (i = 0; i < contador; i++) {
                fprintf(fp, "%i,%i,%i,", (*funcionarios)[i].contador,
                        (*funcionarios)[i].flag, (*funcionarios)[i].codigo);

                fprintf(fp, "%s,%s,%c,", (*funcionarios)[i].nome,
                        (*funcionarios)[i].num_tlf, (*funcionarios)[i].est_civil);

                fprintf(fp, "%i,%c,%i,", (*funcionarios)[i].num_dependentes,
                        (*funcionarios)[i].cargo, (*funcionarios)[i].est_irs);

                fprintf(fp, "%i,%i,%i,", (*funcionarios)[i].data_de_nascimento.dia,
                        (*funcionarios)[i].data_de_nascimento.mes,
                        (*funcionarios)[i].data_de_nascimento.ano);

                fprintf(fp, "%i,%i,%i,", (*funcionarios)[i].data_de_entrada.dia,
                        (*funcionarios)[i].data_de_entrada.mes,
                        (*funcionarios)[i].data_de_entrada.ano);

                if ((*funcionarios)[i].flag == 1) {
                    fprintf(fp, "%i,%i,%i\n", 0, 0, 0);
                } else {
                    fprintf(fp, "%i,%i,%i\n", (*funcionarios)[i].data_de_saida.dia,
                            (*funcionarios)[i].data_de_saida.mes,
                            (*funcionarios)[i].data_de_saida.ano);
                }
            }

        }
        fclose(fp);
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

void Escrever_Ficheiros_Funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {
    EscreverFicheiro_Binario_Funcionarios(funcionarios, fp);
    EscreverFicheiro_Texto_Funcionarios(funcionarios, fp);

}

void menu_funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {

    int menu;

    do {

        printf("\n\nMENU FUNCIONARIOS");
        printf("\nContador: %d", (*funcionarios)[0].contador);
        menu = obterInt(MIN_OPCAO_MENU, MAX_OP_MENU_FUNC, MSG_MENU_FUNC);

        switch (menu) {
            case 1:
                Inserir_Funcionario(funcionarios);
                logMsg("Inserir Funcionario", FILENAME_LOG);
                break;

            case 2:
                listarFuncionarios(funcionarios);
                logMsg("Listar Funcionarios", FILENAME_LOG);
                break;

            case 3:
                consultaFuncionario(funcionarios);
                logMsg("Consulta Funcionario", FILENAME_LOG);
                break;

            case 4:
                AtualizarFuncionario(funcionarios);
                logMsg("Atualizar dados Funcionarios", FILENAME_LOG);
                break;

            case 5:
                EliminarFuncionario(funcionarios);
                logMsg("Eliminar Funcionario", FILENAME_LOG);
                break;

            case 6: Escrever_Ficheiros_Funcionarios(funcionarios, fp);
                logMsg("Guardar Ficheiros Funcionarios",FILENAME_LOG);
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
        printf("contador FUNCIONARIO: %i\n", contador);
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
    printf("RETURNO FUNCIONARIO: %i", returno);
    return returno;
}