/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 20:36
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
/*
 * 
 */
int main() {

    int a,b;
   a=introduzir_num();
   b=introduzir_num();
   
   menu(a,b);

    return 0;
}

