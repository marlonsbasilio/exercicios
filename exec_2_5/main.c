#include <stdio.h>


void preencherVetor(int vetor[], int indice, int N) {
    if (indice < N) {
        printf("Digite o valor para a posicao %d: ", indice + 1);
        scanf("%d", &vetor[indice]);
        preencherVetor(vetor, indice + 1, N);
    }
}

// Função recursiva para imprimir os elementos de um vetor de forma crescente
void imprimirCrescente(int vetor[], int indice, int N) {
    if (indice < N) {
        printf("%d ", vetor[indice]);
        imprimirCrescente(vetor, indice + 1, N);
    }
}

// Função recursiva para imprimir os elementos de um vetor de forma decrescente
void imprimirDecrescente(int vetor[], int indice, int N) {
    if (indice >= 0) {
        printf("%d ", vetor[indice]);
        imprimirDecrescente(vetor, indice - 1, N);
    }
}

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int vetor[N];

    // Preenche o vetor recursivamente
    preencherVetor(vetor, 0, N);

    printf("Elementos do vetor em ordem crescente: ");
    // Imprime os elementos do vetor em ordem crescente
    imprimirCrescente(vetor, 0, N);
    printf("\n");

    printf("Elementos do vetor em ordem decrescente: ");
    // Imprime os elementos do vetor em ordem decrescente
    imprimirDecrescente(vetor, N - 1, N);
    printf("\n");

    return 0;
}