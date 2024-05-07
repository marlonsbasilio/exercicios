#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_QUANT 100

typedef struct{
    char nome[50];
    double preco;
    int quantidade;
}Produtos;

typedef struct{
    Produtos produtos[MAX_QUANT];
    int total_produtos;
}CatalogoProdutos;


void imprimirInfo(Produtos *produto);
// Funções para o catálogo de produtos:
void criarCatalogo(CatalogoProdutos *c);
// Cria um catálogo vazio, zerando o total de produtos
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
// Adiciona um novo produto ao catálogo
int verificarEstoque(CatalogoProdutos *c, char *nome);
// Verifica a quantidade em estoque de um produto
void imprimirCatalogo(CatalogoProdutos *c);
// Imprime todas as informações dos produtos no catálogo
// Defina uma Main para testar

void imprimirInfo(Produtos *produto){
    printf("Informações:\n");
    printf(" Nome do produto: %s\n",produto->nome);
    printf(" Valor do produto: %.2f\n",produto->preco);
    printf(" Quantidade: %d\n", produto->quantidade);
}

void criarCatalogo(CatalogoProdutos *c){
    
    c->total_produtos = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    int contador = c->total_produtos;
    
    if (contador < MAX_QUANT){
        printf ("\nAdicionando Produtos:\n");
        strcpy(c->produtos[contador].nome, nome);
        c->produtos[contador].preco = preco;
        c->produtos[contador].quantidade = quantidade;
        imprimirInfo(&c->produtos[contador]);
        c->total_produtos++;
    }
    else{
        printf ("Quantidade de produtos está lotada.");
    }
    
}

int verificarEstoque(CatalogoProdutos *c, char *nome){
    
    for (int i = 0; i < c->total_produtos; i++){
        if (strcmp(c->produtos[i].nome, nome) == 0){
            return c->produtos[i].quantidade;
        }
    }
    return -1;
}

void imprimirCatalogo(CatalogoProdutos *c){
    printf ("\n\nImprimindo Catalogo:\n\n");
    for (int i = 0; i < c->total_produtos; i++){
        imprimirInfo(&c->produtos[i]);
    }
}


int main(){
    
    CatalogoProdutos catalogo;
    criarCatalogo(&catalogo);
    adicionarProduto(&catalogo, "mouse", 50, 10);
    adicionarProduto(&catalogo, "teclado", 100, 5);
    adicionarProduto(&catalogo, "monitor", 500, 12);
    adicionarProduto(&catalogo, "gabinete", 400, 8);
    
    // int quant = verificarEstoque(&catalogo,"processador");
    int quant = verificarEstoque(&catalogo,"mouse");
    
    if (quant == -1){
        printf ("\nVerificando Estoque: Produto não encontrado.\n");
    }
    else{
        printf ("\nVerificando Estoque:\n Quantidade Total: %d\n",quant);
    }
    
    imprimirCatalogo(&catalogo);

    return 0;
}
