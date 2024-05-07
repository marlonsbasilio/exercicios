#include <stdio.h>
#include <string.h>

void recursiva_letras(char *string, int n){
    
    if (n >= 0){
        printf("%c",string[n]);
        recursiva_letras(string, n-1);
    }
}



int main()
{
    char string[20] = "Faz o L";
    int tamanho = strlen(string);
    
    // printf("TAMANHO DA STRING: %d\n",tamanho);
    
    printf ("\n");
    recursiva_letras(string, tamanho-1);
    printf ("\n");

    return 0;
}

