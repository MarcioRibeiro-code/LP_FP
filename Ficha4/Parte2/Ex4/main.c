/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on 11 de novembro de 2020, 10:01
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 4
/*
 * 
 */
int main()
{
 int matrix[100][100];
 int m,n,i,j;

 
 /* Enter m*n array elements */
 printf("Enter matrix elements: \n");
 for(i=0;i<TAMANHO;i++)
 {
  for(j=0;j<TAMANHO;j++)
  {
   scanf("%d",&matrix[i][j]);
  }
 }
 
 /* matrix after the 90 degrees rotation */
 printf("Matrix after 90 degrees roration \n");
 for(i=0;i<TAMANHO;i++)
 {
  for(j=TAMANHO-1;j>=0;j--)
  {
   printf("%d  ",matrix[j][i]);
  }
  printf("\n");
 }
 
 return 0;
 
}
