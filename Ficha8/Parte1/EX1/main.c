/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 12 de dezembro de 2020, 21:14
 */

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"



/*
 * 
 */
int main() {
    int count = 0, menu;
    

    /*
        int op=0;
         do{
             inserir(arluno);
             imprimir(arluno);
            
             printf("\n\nDeseja Sair- 0 Sair\n");
             scanf("%i",&op);
         }while(op!=0);
     */
    
        do {

            printf("\n\nMENU");
            printf("\n1- Armazenar/Consultar um aluno");
            printf("\n2- Armazenar/Consultar 30 alunos");
            printf("\n0 - Sair\n");
            scanf("%i", &menu);
            switch (menu) {
                case 1:
                    ac_umaluno(&count);
                    break;
                case 2:
                   // ac_30alunos(&count);
                    break;
                case 0:
                    exit(1);

            }
        } while (menu != 0);
    //inserir(&aluno);
    // imprimir(aluno);
    return 0;
}

