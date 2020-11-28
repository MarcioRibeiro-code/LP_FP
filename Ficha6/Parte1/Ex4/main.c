/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 25 de novembro de 2020, 01:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    /*
       if(a>b) swap(&a,&b);
    if(a>c) swap(&a,&c);
    if(b>c) swap(&b,&c);
     * 
     * 
     */
}

void s_sort(int *a,int*b,int*c){
 
}


void ordenar(int *v1, int *v2, int *v3) {


    if(*v1>*v2) swap(&v1,&v2);
    if(*v1>*v3) swap(&v1,&v3);
    if(*v2>*v3) swap(&v2,&v3);
    printf("%i %i %i",*v1,*v2,*v3);
    return 0;
    
      
    /*
     if(*v1 >= *v2 && *v1 >=*v3){
         max=*v1;
     }else if(*v2 >= *v3 && *v2>=v1){
         max=*v2;
     }else{
         max=*v3;
     }*/

    /*
        if (*v1<*v2) {
            if (*v1<*v2) {
                if (*v2<*v3) {
                    min = *v1;
                    aux = *v2;
                    max = *v3;

                } else {

                    min = *v1;
                    aux = *v3;
                    max = *v2;
                }
            } else {
                min = *v3;
                aux = *v1;
                max = *v2;
            }
        } else {
            if (*v2>*v3) {
                if (*v1>*v3) {
                    min = *v2;
                    aux = *v1;
                    max = *v3;
                } else {
                    min = *v2;
                    aux = *v3;
                    max = *v1;
                }
            } else {
                min = *v3;
                aux = *v1;
                max = *v2;
            }
        }

     */
/*
     if ((a < b) && (a < c))
        {
            min = a;
            if (b > c)
            {
                max = b;
                aux = c;
            }
        }
        if ((a < b) && (c < a))
        {
            min = a;
            if (b < c)
            {
                aux = b;
                max = c;
            }
        }
        if ((a > b) && (c > a))
        {
            aux = a;
            if (b < c)
            {
                min = b;
                max = c;
            }
        }
        if ((a < b) && (c < a))
        {
            aux = a;
            if (b > c)
            {
                max = b;
                min = c;
            }
        }
        if ((a > b) && (a > c))
        {
            max =a;
            if (c > b)
            {
                aux = c;
                min = b;
            }
        }

        if ((a > b) && (a > c))
        {
            max = a;
            if (b > c)
            {
                aux = b;
                min = c;
            }
        }
    *v1=min;
    *v2=aux;
    *v3=max;
    */
    
    

    /*
      if (a <= b && a <= c) {  
        if (b <= c) {             
           printf("%i %i %i",a,b,c);
        }else                        
            printf("%i %i %i", a, c, b);
       }
      else if (b <= a && b <= c) {
        if (a <= c) {            
            printf("%i %i %i", b, a, c);
        }else                       
            printf("%i %i %i",b, c, a);
        }
      else if (a <= b) {          
           printf("%i %i %i",c, a, b);
        }else{                       
            printf("%i %i %i",c, b, a);
        }
   */
     
   /* max = a;
    if (b > a) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    if (a <= b && a <= c)
        min = a;
    else if (b <= a && b <= c)
        min = b;

    else
        min = c;
    
    
printf("%i", min);
printf("%i", max);
    */
}







//printf("\n\n%i %i %i", *v1, *v2, *v3);

int main() {

    int a = 2, b = 5, c = 6;

  
    ordenar(&a, &b, &c);
    
    
    
    
      /* printf("Valor 1: ");
      scanf("%i",&a);
      printf("%p",&a);
      printf("Valor 2: ");
      scanf("%i",&b);
      printf("%p",&b);
      printf("Valor 3: ");
      scanf("%i",&c);
     printf("%p",&c); 
      
     */
    /*
        if (a < b) {
            if (a < c) {
                if (b < c) {
                    printf("%i %i %i", a, b, c);
                } else {
                    printf("%i %i %i", a, c, b);
                }
            } else {
                printf("%i %i %i", c, a, b);
            }
        } else {
            if (b > c) {
                if (a > c) {
                    printf("%i %i %i", b, a, c);
                } else {
                    printf("%i %i %i", b, c, a);
                }
            } else {
                printf("%i %i %i", c, b, a);
            }
        }

     */
    return 0;
}

