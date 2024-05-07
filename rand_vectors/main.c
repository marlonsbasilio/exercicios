#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void func_rand_vetor(int *vetor1, int *vetor2, int tamanho){
    
    for (int i = 0; i < tamanho; i++){
        vetor1[i] = rand() % 100;
        vetor2[i] = rand() % 100;
        
    }
    printf ("VETOR 1\n");
    for (int i = 0; i < tamanho; i++){
        printf (" %d ", vetor1[i]);
    }
    
    printf ("\nVETOR 2\n");
    for (int i = 0; i < tamanho; i++){
        printf (" %d ", vetor2[i]);
    }
}

int maior_vetores(int *vetor, int tamanho){
    int maior = 0;
    
    for (int i = 0; i < tamanho; i++){
        if (maior <= vetor[i]){
            maior = vetor[i];
        }
    }
    return maior;
}


int menor_vetores(int *vetor, int tamanho){
    int menor = 100;
    
    for (int i = 0; i < tamanho; i++){
        if (menor >= vetor[i]){
            menor = vetor[i];
        }
    }
    return menor;
}

int media_vetores(int *vetor, int tamanho){
    
    int soma = 0;
    for (int i = 0; i < tamanho; i++){
        soma = soma + vetor[i];
    }
    
    int media = soma / tamanho;
    
    return media;
}


int main(){
    
    int N = 5;
    srand(time(NULL));
    int vetor1[5];
    int vetor2[5];
    
    func_rand_vetor(vetor1, vetor2, N);
    
    int vet1_maior = maior_vetores(vetor1, N);
    printf("\nMAIOR VETOR 1: %d\n",vet1_maior);
    int vet2_maior = maior_vetores(vetor2, N);
    printf("MAIOR VETOR 2: %d\n",vet2_maior);
    
    int vet1_menor = menor_vetores(vetor1, N);
    printf("\nMENOR VETOR 1: %d\n",vet1_menor);
    int vet2_menor = menor_vetores(vetor2, N);
    printf("MENOR VETOR 2: %d\n",vet2_menor);
    
    
    int vet1_media = media_vetores(vetor1, N); 
    printf("\nMEDIA VETOR1: %d\n",vet1_media);
    
    int vet2_media = media_vetores(vetor2, N); 
    printf("MEDIA VETOR2: %d\n",vet2_media);
    
    return 0;
}
