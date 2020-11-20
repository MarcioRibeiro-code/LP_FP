#include <stdio.h>
int main()
{ 
    char palavra[30], aux[30];
    int chave, i=0;
    scanf(" %s", palavra);
    printf("Introduzir chave: ");
    scanf(" %i",&chave);
    
        while(palavra[i] != '\0')
        {
            aux[i] = palavra[i] + chave;
            if((palavra[i] + chave) > 122)
            {
                aux[i] -=26;
            }
            if((palavra[i] + chave) < 97)
            {
                aux[i] += 26;
            }
            i++;
        }
        aux[i] = '\0';
        printf("chave %d: %s ", chave, aux);


    printf("\n");
    
    return 0;
}