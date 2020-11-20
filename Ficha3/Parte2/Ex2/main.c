/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 23 de outubro de 2020, 12:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    char ins[800]="abc",con[800]="def";
    int op;
    
   printf("Menu");
    printf("\n1. Criar");
    printf("\n2. Atualizar");
    printf("\n3. Eliminar");
    printf("\n4. Sair\n");
    scanf(" %i",&op);
    
    do{
        switch (op){
            case 1:
               printf("Texto a inserir: ");
               // scanf(" %c",ins);  
            break;  
            
            case 2:
                printf("Texto para atualizar: ");
                 //scanf(" %c",&con);                
                strcat(ins,con);
                 
            break;   
            
            case 3:
                strcpy(ins, "");
                strcpy(con, "");
            break;
        }
      system("clear");
        printf("\nMenu");
                     printf("\n1. Criar");
                     printf("\n2. Atualizar");
                     printf("\n3. Eliminar");
                     printf("\n4. Sair\n");
                        scanf(" %i",&op); 
        printf(" %s",ins);
    }while(op !=4);
    
            
    return 0;
}

