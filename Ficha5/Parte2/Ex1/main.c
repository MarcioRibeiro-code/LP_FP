/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 20:28
 */

#include <stdio.h>
#include <stdlib.h>
#include "myIntLib.h"

/*
 * 
 */
int main() {

    int num1;
    
    
    printf("Introduza um numero: ");
    scanf("%i",&num1);
    asterisco(num1);
    return 0;
}

