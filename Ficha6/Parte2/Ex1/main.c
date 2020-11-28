/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de novembro de 2020, 12:05
 */

#include <stdio.h>
#include <stdlib.h>

int len(char *str) {
    int i;
    char a;

    for (i = 0;; i++) {
        a = (str[i]);
        if (a == '\0') {
            return i;
        }
    }
}

int equal(char *str1,char *str2){

    int i,aux;
    char a,b;
    int len_a,len_b;
    
    len_a=len(&str1);
    len_b=len(&str2);
    
   if(len_a!=len_b){
       aux=0;
   } else{
       for(i=0;i<len_a;i++){
           a=str1[i];
           b=str2[i];
           
           if(a==b){
               aux=1;
           }else{
               aux=0;
           }
       }
   
   }
   
    return aux;
}

/*
 * 
 */
int main() {
    
    char a[99]="marcio\0";
    char b[99]="marcio\0";
    int vl;
    
    
    vl=equal(&a,&b);
    
    if(vl==0){
        printf("As strings são diferentes");
    }else{
        printf("As strings são iguais");
    }
    return 0;
}

