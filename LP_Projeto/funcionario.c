#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funclib.h"
#include "input.h"
#include "salariolib.h"


//MENSAGEM ERRO ALOCAÇÃO DE MEMORIA

void faill(void) {
    printf("Memoria não foi alocada");
    exit(EXIT_FAILURE);
}


//CONVERTER ENUM EM STRING

char *estadoCivilToString(ESTADO_CIVIL est_civ) {
    
    
     
    /*!
     * A função faz a conversao de uma enumeração para string
     * 
     * A função nao "converte" apenas devolve uma string quando o valor for 
     * encontrado, por exemplo ao introduzir 0 - o texto que se irá obter será
     * Casado.
     * 
     * @param est_civ
     * @return string 
     * 
     */
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
    /*!
     * A função faz a conversao de uma enumeração para string
     * 
     * A função nao "converte" apenas devolve uma string quando o valor for 
     * encontrado, por exemplo ao introduzir 0 - o texto que se irá obter será
     * empregado.
     * 
     * @param cargo
     * @return string 
     * 
     */
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
    
     /*!
     * A função faz aconversao de uma enumeração para string
     * 
     * A função nao "converte" apenas devolve uma string quando o valor for 
     * encontrado, por exemplo ao introduzir 0 - o texto que se irá obter será
     * não casado.
     * 
     * @param irs
     * @return string 
     * 
     */
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

int grow_StructArray_Funcionario(FUNCIONARIO **funcionarios) {

    
    
    /*!
     * A função realiza a realocação do Struct Array FUNCIONARIO
     * O struct array funcionario é passado por referencia.
     * É criado uma nova variavel local (novoTamanho) que obtêm o tamanho maximo
     * do array até aquele momento e o duplica. Uma nova estrutura semelhante á 
     * funcionarios é criado com o nome temp, e é nela feita a realocação.Apos,é realizada 
     * uma verificação á realocação onde se iguala temp a NULL, uma vez que a realocação devolve NULL quando nao foi possivel
     * devido a algum problema, se o valor for diferente significa que a realocação foi bem sucedida devolvendo o novo endereço de temp para a variavel *funcionarios
     * 
     * @param funcionarios Struct Array FUNCIONARIO 
     * @return novotamanho tamanho possivel para a realocação
     * 
     */
    
    
    const int novoTamanho = (*funcionarios)[0].tamanho * 2;

    FUNCIONARIO *temp = (FUNCIONARIO*) realloc(*funcionarios, (novoTamanho * sizeof (FUNCIONARIO)));

    if (temp == NULL) {
        faill();
    } else {
        *funcionarios = temp;
    }

    return novoTamanho;
}

int devolve_tempo(char opcao) {

    /*!
     * Função Devolve tempo
     * 
     * Esta função devolve a data atual utilizando as funcionalidades da 
     * biblioteca <time.h>
     * 
     * @param opcao
     * 
     */
    
    
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

int Procurar_CodFuncionario(FUNCIONARIO **funcionarios, int numero, int tamanho) {
    
    /*!
     * Função Procurar Funcionario
     * 
     * É percorrido a estrutura funcionario, até o tamanho maximo atual verificando se
     * existe algum funcionario com o codigo funcionario que foi passado via parametro.
     * Ao encontrar retorna i , caso contrario retorna -1; 
     * 
     * @param funcionarios Struct Array FUNCIONARIO
     * @param numero Codigo funcionario
     * @param tamanho Tamanho atual do struct Array FUNCIONARIO
     */
    
    int i;

    for (i = 0; i < tamanho; i++) {
        if ((*funcionarios)[i].codigo == numero) {
            return i;
        }
    }
    return -1;
}

void Inserir_Funcionario(FUNCIONARIO **funcionarios) {
    
    /*!
     * Procedimento Inserir Funcionario
     * 
     * O procedimento permite a introduzir dados para a estrutura Funcionario.
     * 
     * @param funcionarios Struct Array FUNCIONARIO
     *
     */
    
    
    
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


    } else {
        puts(ERRO_FUNCIONARIO_EXISTE);
    }
}

void imprimirFuncionario(FUNCIONARIO **funcionarios, int posicao) {

     /*!
      * Procedimento Imprimir Funcionario
      * 
     * É imprimido toda a informação relativa á estrutura FUNCIONARIO na consola
     * da uma dada posicao(i)
     * 
     * @param funcionarios Struct Array
     * @param posicao Posicao que se prentende imprimir
     * 
     */
    
    
    
    if ((*funcionarios)[posicao].flag == 1) {
        printf("\nCodigo: %d", (*funcionarios)[posicao].codigo);
        printf("\nNome do Funcionario: %s", (*funcionarios)[posicao].nome);
        printf("\nNumero de Telefone: %s", (*funcionarios)[posicao].num_tlf);
        printf("\nEstado Civil: %s", estadoCivilToString((*funcionarios)[posicao].est_civil));
        printf("\nNumero de Depentendentes: %d", (*funcionarios)[posicao].num_dependentes);
        printf("\nCargo: %s", cargoToString((*funcionarios)[posicao].cargo));
        printf("\nIRS: %s", EST_IRS_ToString((*funcionarios)[posicao].est_irs));

        printf("\nData de Nascimento: %d-%d-%d", (*funcionarios)[posicao].data_de_nascimento.dia,
                (*funcionarios)[posicao].data_de_nascimento.mes, (*funcionarios)[posicao].data_de_nascimento.ano);

        printf("\nData de Entrada: %d-%d-%d\n", (*funcionarios)[posicao].data_de_entrada.dia,
                (*funcionarios)[posicao].data_de_entrada.mes, (*funcionarios)[posicao].data_de_entrada.ano);
    } else {
        printf("\nCodigo: %d", (*funcionarios)[posicao].codigo);
        printf("\nNome do Funcionario: %s", (*funcionarios)[posicao].nome);
        printf("\nData de Saida: %i-%i-%i\n", (*funcionarios)[posicao].data_de_saida.dia,
                (*funcionarios)[posicao].data_de_saida.mes, (*funcionarios)[posicao].data_de_saida.ano);
    }
}

void listarFuncionarios(FUNCIONARIO **funcionarios) {
    
    /*!
     *  Procedimento que imprime na consola todos os dados relativos aos funcionarios
     * 
     *
        * @param funcionarios array struct FUNCIONARIO
     * 
     */
    
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
    
    /*!
     *  Procedimento que imprime na consola os dados relativos a um funcionario
     * 
     * 
     * É perguntado ao utilizador por um input, um codigo de funcionario, se
     * a função procurar funcionarios devolver um valor diferente de -1 significa
     * que encontrou um funcionario no Struct Array e devolve a sua posição no array
     * e escreve no ecrã os dados relativos ao funcionario.
     *
     * @param funcionarios array struct FUNCIONARIOS
     * 
     */
    
    
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
     /*!
     *  Procedimento que permite alterar todos os dados relativos a um funcionario
     *
     * 
     * @param funcionarios array struct FUNCIONARIO
     * 
     * 
     */
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
    
     /*!
     *  Procedimento que escreve eliminar um funcionario
     * 
     * Este procedimento elimina um funcionario ao atribuir o valor de 0 á variavel
      * flag
     * 
     * @param funcionarios array struct FUNCIONARIO
     * 
     * 
     */
    
    
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

     /*!
     *  Procedimento que escreve num ficheiro binario a estrutura funcionarios
     * 
     * Este procedimento escreve num ficheiro binario os dados contidos em memoria
     * relativos aos funcionarios
     * 
     * @param funcionarios array struct FUNCIONARIO
     * @param fp ponteiro fp
     * 
     * 
     */
    
    
    
    fp = fopen(FILENAME_BIN_FUNCIONARIO, "wb+");
    int contador = (*funcionarios)[0].contador;

    fwrite(*funcionarios, sizeof (FUNCIONARIO), contador, fp);

    fclose(fp);
    puts("\nGravado com Sucesso");
}

void menu_funcionarios(FUNCIONARIO **funcionarios, FILE *fp) {

    
    /*!
     * Procedimento Menu funcionarios
     * 
     * Este procedimento é o menu funcionarios, onde o utilizador visualiza todas as opções que se encontram disponiveis.
     * 
     * @param funcionarios Struct Array funcionarios
     * @param fp ponteiro fp
     */

    
    
    
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
        menu = obterInt(MIN_OP_MENU_FUNCIONARIO, MAX_OP_MENU_FUNCIONARIO, "");
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
                logMsg("Consultar Funcionario", FILENAME_LOG);
                break;
            case 4:
                AtualizarFuncionario(funcionarios);
                logMsg("Atualizar Funcionario", FILENAME_LOG);
                break;
            case 5:
                EliminarFuncionario(funcionarios);
                logMsg("Eliminar Funcionario", FILENAME_LOG);
                break;
            case 6:EscreverFicheiro_Binario(funcionarios, fp);
                logMsg("Gravar Funcionario", FILENAME_LOG);
                break;

            case 0:
                break;

        }
    } while (menu != 0);

}

int carregar_funcionario(FUNCIONARIO **funcionarios, FILE *fp) {

    /*!
     * Função Carregar funcionario
     * 
     * Esta função permite verificar se o ficheiro binarios relativos aos funcionarios
     * se encontra vazio ou possui dados.
     * É lido o primeiro valor inteiro, que devido á programação
     * realizada sabemos que é o contador da estrutura funcionarios. Se este se econtrar
     * vazio podemos determinar que o ficheiro se encontra vazio. Mas se o valor
     * for diferente de 0, neste caso superior a 0, sabemos que possui dados e 
     * é alocado memoria tendo em conta o numero de estruturas que se encontram escritras
     * no ficheiro.
     * 
     * 
     * @param funcionario Struct Array funcionarios
     * @param fp Ponteiro de FP
     */
    
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



