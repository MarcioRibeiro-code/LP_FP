#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "booklib.h"
#include "input.h"

char *convert_enum_to_char(tipo_genero tipo) {

    switch (tipo) {
        case 1:
            return "Ficção";
            break;
        case 2:
            return "Tecnico";
            break;
        case 3:
            return "Romance";
            break;
        case 4:
            return "Estudo";
            break;
    }
}



void imprimirLivro(LIVRO livro) {
    
    int i=0;
    
    printf("\nISBN: %s",livro.ISBN);
    printf("\nData De Publicação: %d-%d-%d",livro.data_de_publicacao.dia,livro.data_de_publicacao.mes,livro.data_de_publicacao.ano);
    printf("\nTITULO: %s",livro.titulo);
    printf("\nTIPO: %s",convert_enum_to_char(livro.tipo));
    printf("\nEDITORA");
    printf("\n NOME: %s",livro.editora.nome);
    printf("\n MORADA: %s",livro.editora.morada);
    printf("\nEDITOR(ES)");
    while(i != 5){
    printf("\nNOME: %s",livro.autores[i]);
    i++;
    }
}

void apagarDadosLivro(LIVRO *livro) {
    int i=0;
    
    strcpy(livro->ISBN,"");
    livro->data_de_publicacao.dia = livro->data_de_publicacao.mes = livro->data_de_publicacao.ano = 0;
    strcpy(livro->titulo, "");
    livro->tipo = 0;
    strcpy(livro->editora.nome,"");
    strcpy(livro->editora.morada,"");
    for(i;i<MAX_AUTORES;i++)
    strcpy(livro->autores[i].autores,"");
     
}

int procurarLivro(LIVROS livros, char numero[]) {
    int i;
    
    
    for (i = 0; i < livros.contador; i++) {
        if (strcmp(livros.livros[i].ISBN,numero) == 0) {
            return i;
        }
    }
    return -1;
}

int inserirLivro(LIVROS *livros) {
    char numero[DIG_ISBN];
    int aux;
    
    printf("ISBN: ");
    scanf(" %s",numero);
    
    
    
    if (procurarLivro(*livros, numero) == -1) {

        strlcpy(livros->livros[livros->contador].ISBN,numero,DIG_ISBN);
        
        livros->livros[livros->contador].data_de_publicacao.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_PUBL);
        livros->livros[livros->contador].data_de_publicacao.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_PUBL);
        livros->livros[livros->contador].data_de_publicacao.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_PUBL);
        
        lerString(livros->livros[livros->contador].titulo, MAX_CHAR_TITULO, MSG_OBTER_TITULO);
        
        printf("\n1 - Ficção\n2 - Tecnico\n3 - Romance\n4- Estudo\n");
        livros->livros[livros->contador].tipo = obterInt(MIN_TIPO,MAX_TIPO,OBTER_TIPO);
        
        lerString(livros->livros[livros->contador].editora.nome,MAX_CHAR_EDITORA,OBTER_EDITORA_NOME);
        lerString(livros->livros[livros->contador].editora.morada,MAX_CHAR_MORADA_EDITORA,OBTER_EDITORA_MORADA);
        
        aux=obterInt(MIN_AUTORES,MAX_AUTORES,OBTER_NUM_AUTORES);
        
        for(int i=0;i<aux;i++)
        lerString(livros->livros[livros->contador].autores[i].autores,MAX_CHAR_AUTORES,OBTER_NOME_AUTORES);
        
        return livros->contador++;
    }
    return -1;
}

void atualizarLivro(LIVRO *livro) {
    lerString((*livro).titulo, MAX_CHAR_TITULO, MSG_OBTER_TITULO);
    (*livro).data_de_publicacao.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_PUBL);
    (*livro).data_de_publicacao.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_PUBL);
    (*livro).data_de_publicacao.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_PUBL);
}

void inserirLivros(LIVROS *livros) {
    if (livros->contador < MAX_NUM_LIVRO) {
        if (inserirLivro(livros) == -1) {
            puts(ERRO_LIVRO_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_CHEIA);
    }
}

void procurarLivros(LIVROS livros) {
    char aux_num[DIG_ISBN];
   printf("ISBN: ");
    scanf(" %s",aux_num);
   
    
    int numero = procurarLivro(livros, aux_num);

    if (numero != -1) {
        imprimirLivro(livros.livros[numero]);
    } else {
        puts(ERRO_LIVRO_NAO_EXISTE);
    }
}

void atualizarLivros(LIVROS *livros) {
   char aux_num[DIG_ISBN];
    printf("ISBN: ");
    scanf(" %s",aux_num);
    
    int numero = procurarLivro(*livros,aux_num);

    if (numero != -1) {
        atualizarLivro(&(*livros).livros[numero]);
    } else {
        puts(ERRO_LIVRO_NAO_EXISTE);
    }
}


void removerLivros(LIVROS *livros) {
   
    char aux_num[DIG_ISBN];
    printf("ISBN: ");
    scanf(" %s",aux_num);
    
    int i, numero = procurarLivro(*livros,aux_num);

    if (numero != -1) {
        for (i = numero; i < livros->contador - 1; i++) {
            livros->livros[i] = livros->livros[i + 1];
        }

        apagarDadosLivro(&livros->livros[i]);

        livros->contador--;
    } else {
        puts(ERRO_LIVRO_NAO_EXISTE);
    }
}

void listarLivros(LIVROS livros) {
    if (livros.contador > 0) {
        int i;
        for (i = 0; i < livros.contador; i++) {
            imprimirLivro(livros.livros[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}

