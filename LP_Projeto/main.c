/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 2 de dezembro de 2020, 17:02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "funclib.h"
#include "salariolib.h"

/*
 * 
 */
int main() {
    /*
        int menu;
        FILE *fp;
        FUNCIONARIO *funcionarios;
        SALARIO *salario;
    
    
        carregar_funcionario(&funcionarios, fp);
        carregar_salario(&salario, fp);
        do {
            printf("\n\nMENU");
            printf("\n1- MENU FUNCIONARIO");
            printf("\n2- MENU SALARIOS");
            menu = obterInt(MIN_OP_MENU_PRINCIPAL, MAX_OP_MENU_PRINCIPAL, "");

            switch (menu) {
                case 1:menu_funcionarios(&funcionarios, fp);
                    logMsg("Menu Funcionarios", FILENAME_LOG);
                    break;
                case 2:menu_salarios(&funcionarios, &salario);
                    logMsg("Menu Salarios", FILENAME_LOG);
                    break;
            }

        } while (menu != 0);
        free(funcionarios);
        free(salario);
    //    free(csv_salario);

     */

    //int proc_salario[70][5];
    readcsv_salario();

    return 0;
}

