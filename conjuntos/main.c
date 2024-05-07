#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elementos;
    int tamanho;
} Conjunto;


Conjunto* criarConjunto() {
    Conjunto* conjunto = (Conjunto*)malloc(sizeof(Conjunto));
    if (conjunto == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o conjunto.\n");
        exit(EXIT_FAILURE);
    }
    conjunto->elementos = NULL;
    conjunto->tamanho = 0;
    return conjunto;
}

bool estaNoConjunto(Conjunto* conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            return true;
        }
    }
    return false;
}


void inserirElemento(Conjunto* conjunto, int elemento) {
    if (!estaNoConjunto(conjunto, elemento)) {
        conjunto->elementos = (int*)realloc(conjunto->elementos, (conjunto->tamanho + 1) * sizeof(int));
        if (conjunto->elementos == NULL) {
            fprintf(stderr, "Erro: Falha ao realocar memória para o conjunto.\n");
            exit(EXIT_FAILURE);
        }
        conjunto->elementos[conjunto->tamanho] = elemento;
        conjunto->tamanho++;
    }
}

Conjunto* uniaoConjuntos(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* uniao = criarConjunto();
    

    for (int i = 0; i < conjunto1->tamanho; i++) {
        inserirElemento(uniao, conjunto1->elementos[i]);
    }
    

    for (int i = 0; i < conjunto2->tamanho; i++) {
        inserirElemento(uniao, conjunto2->elementos[i]);
    }
    
    return uniao;
}

void removerElemento(Conjunto* conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            for (int j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            conjunto->elementos = (int*)realloc(conjunto->elementos, conjunto->tamanho * sizeof(int));
            return;
        }
    }
}


Conjunto* intersecaoConjuntos(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* intersecao = criarConjunto();
    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (estaNoConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(intersecao, conjunto1->elementos[i]);
        }
    }
    return intersecao;
}


Conjunto* diferencaConjuntos(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* diferenca = criarConjunto();
    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (!estaNoConjunto(conjunto2, conjunto1->elementos[i])) {
            inserirElemento(diferenca, conjunto1->elementos[i]);
        }
    }
    
    for (int i = 0; i < conjunto2->tamanho; i++) {
        if (!estaNoConjunto(conjunto1, conjunto2->elementos[i])) {
            inserirElemento(diferenca, conjunto2->elementos[i]);
        }
    }
    
    return diferenca;
}


bool pertenceAoConjunto(Conjunto* conjunto, int elemento) {
    return estaNoConjunto(conjunto, elemento);
}


bool saoIguaisConjuntos(Conjunto* conjunto1, Conjunto* conjunto2) {
    if (conjunto1->tamanho != conjunto2->tamanho) {
        return false;
    }
    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (!estaNoConjunto(conjunto2, conjunto1->elementos[i])) {
            return false;
        }
    }
    return true;
}


int menorValorConjunto(Conjunto* conjunto) {
    if (conjunto->tamanho == 0) {
        fprintf(stderr, "Erro: Conjunto vazio.\n");
        exit(EXIT_FAILURE);
    }
    int menor = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] < menor) {
            menor = conjunto->elementos[i];
        }
    }
    return menor;
}


int maiorValorConjunto(Conjunto* conjunto) {
    if (conjunto->tamanho == 0) {
        fprintf(stderr, "Erro: Conjunto vazio.\n");
        exit(EXIT_FAILURE);
    }
    int maior = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] > maior) {
            maior = conjunto->elementos[i];
        }
    }
    return maior;
}

// Função para obter o tamanho do conjunto
int tamanhoConjunto(Conjunto* conjunto) {
    return conjunto->tamanho;
}

// Função para verificar se o conjunto é vazio
bool conjuntoVazio(Conjunto* conjunto) {
    return conjunto->tamanho == 0;
}


int main() {
    // Criar conjuntos
    Conjunto* conjunto1 = criarConjunto();
    Conjunto* conjunto2 = criarConjunto();
    
    // Inserir elementos nos conjuntos
    inserirElemento(conjunto1, 1);
    inserirElemento(conjunto1, 2);
    inserirElemento(conjunto1, 3);
    inserirElemento(conjunto2, 3);
    inserirElemento(conjunto2, 2);
    inserirElemento(conjunto2, 5);
    inserirElemento(conjunto2, 4);
    inserirElemento(conjunto2, 6);
    
    removerElemento(conjunto2, 6);
    
    // Realizar união dos conjuntos
    Conjunto* uniao = uniaoConjuntos(conjunto1, conjunto2);
    
    // Exibir elementos da união
    printf("União dos conjuntos:\n");
    for (int i = 0; i < uniao->tamanho; i++) {
        printf("%d ", uniao->elementos[i]);
    }
    printf("\n");
    
    
    // Realizar interseção dos conjuntos
    Conjunto* intersecao = intersecaoConjuntos(conjunto1, conjunto2);
    
    printf("Intersecao dos conjuntos:\n");
    for (int i = 0; i < intersecao->tamanho; i++) {
        printf("%d ", intersecao->elementos[i]);
    }
    printf("\n");
    
    // Realizar diferença dos conjuntos
    Conjunto* diferenca = diferencaConjuntos(conjunto1, conjunto2);
    
    printf("Diferenca dos conjuntos:\n");
    for (int i = 0; i < diferenca->tamanho; i++) {
        printf("%d ", diferenca->elementos[i]);
    }
    printf("\n\n");
    
    // Testar se um número pertence ao conjunto
    printf("O número 3 pertence ao conjunto 1: %s\n\n", pertenceAoConjunto(conjunto1, 3) ? "Sim" : "Não");
    
    // Testar se dois conjuntos são iguais
    printf("Os conjuntos sao iguais: %s\n\n", saoIguaisConjuntos(conjunto1, conjunto2) ? "Sim" : "Não");
    
    // Obter o menor e o maior valor do conjunto
    printf("Menor valor do conjunto 1: %d\n\n", menorValorConjunto(conjunto1));
    printf("Maior valor do conjunto 1: %d\n\n", maiorValorConjunto(conjunto1));
    
    printf("Menor valor do conjunto 2: %d\n\n", menorValorConjunto(conjunto2));
    printf("Maior valor do conjunto 2: %d\n\n", maiorValorConjunto(conjunto2));
    
    // Obter o tamanho do conjunto
    printf("Tamanho do conjunto 1: %d\n\n", tamanhoConjunto(conjunto1));
        // Obter o tamanho do conjunto
    printf("Tamanho do conjunto 2: %d\n\n", tamanhoConjunto(conjunto2));
    
    // Testar se o conjunto é vazio
    printf("O conjunto 1 eh vazio: %s\n\n", conjuntoVazio(conjunto1) ? "Sim" : "Não");

    free(conjunto1->elementos);
    free(conjunto1);
    free(conjunto2->elementos);
    free(conjunto2);
    free(uniao->elementos);
    free(uniao);
    free(intersecao->elementos);
    free(intersecao);
    free(diferenca->elementos);
    free(diferenca);
    
    return 0;
}
