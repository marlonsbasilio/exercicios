#include <stdio.h>
#include <stdlib.h>

int multiplicação_recursiva(int N, int M, int soma){
    
    if (N > 1){
        soma = soma + M;
        printf ("M + ");
        multiplicação_recursiva(N-1, M, soma);
    }
    else{
        soma = soma + M;
        printf ("M ");
    return soma;
    }
}

int main()
{

    int N = 5;
    int M = 10;
    
    printf ("\nN * M = ");
    int soma = multiplicação_recursiva(N,M,0);

    printf (" =  %d\n",soma);
    
    return 0;
}
