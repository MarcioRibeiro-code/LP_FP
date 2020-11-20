/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 6 de novembro de 2020, 12:36
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_STRING 10
/*
 * 
 */
int main() {

    char string1[TAMANHO_STRING],string2[TAMANHO_STRING];
    int i,len1,len2;
    
    //string1
    fgets(string1,TAMANHO_STRING,stdin)  ;  
    len1= strlen(string1)-1;
    
    //string2
    fgets(string2,TAMANHO_STRING,stdin);
    len2=strlen(string2)-1;
    if(len1 !=len2){
        printf("Introduza strings com o mesmo tamanho\n");
        do{
        fgets(string2,TAMANHO_STRING,stdin);
        len2=strlen(string2)-1;
        }while(len1 !=len2);
    }
    

    if (strcmp(string1,string2)==0){
        printf("As strings são iguais");
    }else{
        printf("Strings !=");
    }
 
    
    
   

    
    return 0;
}

