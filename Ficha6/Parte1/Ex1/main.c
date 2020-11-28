/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 25 de novembro de 2020, 01:15
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void incrementar(int valor){
    printf("\nvalor: %d",++valor);
}


int main() {
    int valor =0;
    
    incrementar(valor);
    printf("\nvalor:%d",valor);
    
    return 0;
}



