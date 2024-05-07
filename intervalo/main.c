
#include <stdio.h>
#include <stdlib.h>

int indice_maior(int *intervalo, int tamanho);
int soma_recursiva_crescente(int *intervalo, int indice_maior, int indice_menor, int n, int soma);
int indice_menor(int *intervalo, int tamanho);
int soma_recursiva(int *intervalo, int indice_maior, int indice_menor);
int soma_recursiva_crescente(int *intervalo, int indice_maior, int indice_menor, int n, int soma);
int soma_recursiva_decrescente(int *intervalo, int indice_maior, int indice_menor, int n, int soma);



int indice_maior(int *intervalo, int tamanho){
   
   int maior = -1000;
   int indice;
   
   for (int i = 0; i < tamanho; i++){
        // encontrar o indice do maior
        if (maior <= intervalo[i]){
            maior = intervalo[i];
            indice = i;
        }
   }
   printf ("MAIOR = %d\n",maior);
   printf ("indice = %d\n",indice);
   return indice;
   
}

int indice_menor(int *intervalo, int tamanho){
   
   int menor = 1000;
   int indice;
   
   for (int i = 0; i < tamanho; i++){
        // encontrar o indice do menor
        if (menor >= intervalo[i]){
            menor = intervalo[i];
            indice = i;
        }
   }
   printf ("MENOR = %d\n",menor);
   printf ("indice = %d\n",indice);
   return indice;
   
}

int soma_recursiva(int *intervalo, int indice_maior, int indice_menor){
    int soma = 0;
    if (indice_maior < indice_menor){
        // ordem crescente
        soma = soma_recursiva_crescente(intervalo, indice_maior, indice_menor, indice_maior, 0);
    }
    else if(indice_maior > indice_menor){
        // ordem decrescente
        soma = soma_recursiva_decrescente(intervalo, indice_maior, indice_menor, indice_maior, 0);
    }
    else{
        // nesse caso o valor é tanto maior quanto o menor
        return intervalo[indice_maior];
    }
    return soma;
}

int soma_recursiva_crescente(int *intervalo, int indice_maior, int indice_menor, int n, int soma){
    
    if (n >= indice_maior && n <= indice_menor){
        soma = soma + intervalo[n];
        printf ("%d ",intervalo[n]);
        soma_recursiva_crescente(intervalo, indice_maior, indice_menor, n+1, soma);
    }
    else{
    return soma;
    } 
}

int soma_recursiva_decrescente(int *intervalo, int indice_maior, int indice_menor, int n, int soma){
    
    if (n <= indice_maior && n >= indice_menor){
        soma = soma + intervalo[n];
        printf ("%d ",intervalo[n]);
        soma_recursiva_decrescente(intervalo, indice_maior, indice_menor, n-1, soma);
    }
    else{
    return soma;
    } 
}

int main()
{
    int intervalo[11] = {3,4,5,0,2,6,7,3,1,8,9};
    int tamanho = 11;
    printf("\nNUMEROS DO INTERVALO:\n");
    for (int i = 0; i < tamanho; i++){
        printf ("%d ",intervalo[i]);
    }
    printf("\n");
    
    int index_maior = indice_maior(intervalo,tamanho);
    int index_menor = indice_menor(intervalo,tamanho);
    int soma = soma_recursiva(intervalo, index_maior, index_menor);
    
    printf("\nVALOR DA SOMA: %d\n", soma);
    return 0;
}
