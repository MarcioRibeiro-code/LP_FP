/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 27 de novembro de 2020, 12:34
 */

#include <stdio.h>
#include <stdlib.h>

void printFirst(char *str, int n) {

    int i=0;

    while (i <= strlen(str)) {
      
        for(int o=0;o<n;o++){
        printf("%c", str[i+o]);
        }
        
        //printf("%c", str[i + 1]);
        printf("\n");
        i = i + n;

    }




    /*
      for(int k=0;k<strlen(str);k++){
      for (int j = 0; j < n;j++) {
               printf("%c", str[k+j]);
           } printf("\n");
       }
    */
   }
     

/*
 * 
 */
int main() {
    char a[99]="Calentador de Cuarz";
    int n = 1;

    //scanf(" %s",&a);
    printFirst(&a, n);
    printf("%i",strlen(a));
    return 0;
}

