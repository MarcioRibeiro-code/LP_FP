/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   myIntLib.h
 * Author: Desktop
 *
 * Created on 20 de novembro de 2020, 20:29
 */

#ifndef MYINTLIB_H
#define MYINTLIB_H

void asterisco(int a){
    verificar(a);
    for(int i=0;i<a;i++){
        printf("*");
    }
}

void verificar(int a){
    
        while(a<=0 ||a>18){
            printf("Operação Invalida"); 
            printf("\nNumero - 1 a 18");
            scanf("%i",&a);
        }

}
#endif /* MYINTLIB_H */

