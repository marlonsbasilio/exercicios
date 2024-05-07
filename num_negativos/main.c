#include <stdio.h>

int negativo(float *vet, int N){
    int cont_negativo = 0;
    
    for (int i = 0; i < N; i++){
        if (vet[i] < 0){
            cont_negativo++;
        }
    }
    // printf ("VALORES NEGATIVOS: %d\n", cont_negativo);
    return cont_negativo;
}

int main()
{
    float vet[10] = {0,1,2,-3,4,-5,6,7,8,-9};
    int N = 10;
    int cont_negativo = negativo(vet,10);
    printf ("VALORES NEGATIVOS: %d\n", cont_negativo);
    return 0;
}
