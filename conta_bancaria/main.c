#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int numero_da_conta;
    double saldo_bancario;
    char titular[50];
}ContaBancaria;

int contador_contas;

void criarConta(ContaBancaria *c, int numero, char *titular);
// Cria uma nova conta bancária com o número e titular especificados.
// Inicializa o saldo como zero.
void depositar(ContaBancaria *c, double valor);
// Deposita o valor especificado na conta.
void sacar(ContaBancaria *c, double valor);
// Realiza um saque da conta, desde que haja saldo suficiente.
double consultarSaldo(ContaBancaria *c);
// Retorna o saldo atual da conta.
void imprimirInfo(ContaBancaria *c);
// Imprime as informações da conta, incluindo número, titular e saldo.

void criarConta(ContaBancaria *c, int numero, char *titular){
    printf("\n\nCriando Conta:\n");
    c->numero_da_conta = numero;
    c->saldo_bancario = 0;
    strcpy(c->titular, titular);
    printf ("Conta criada com sucesso!\n");
    imprimirInfo(c);
}

void depositar(ContaBancaria *c, double valor){
    printf("\n\nOPÇÃO DEPOSITO:\n");
    if (c != NULL){
    c->saldo_bancario = c->saldo_bancario + valor;
    printf (" Depósito feito com sucesso!\n Saldo final: %.2f\n",c->saldo_bancario);
    }
    else{
        printf ("Não foi possivel fazer o Depósito");
    }
}

void sacar(ContaBancaria *c, double valor){
    printf("\n\nOPÇÃO SAQUE:\n");
    if (c->saldo_bancario >= valor){
        c->saldo_bancario = c->saldo_bancario - valor;
        printf (" Saque feito com sucesso! Saldo final: %.2f\n", c->saldo_bancario);
    }
    else{
        printf (" Saldo Insuficiente!\n");
    }
}

double consultarSaldo(ContaBancaria *c){
    
    return c->saldo_bancario;
}

void imprimirInfo(ContaBancaria *c){
    printf("\n\nInformações:\n");
    printf(" Nome do Titular: %s\n",c->titular);
    printf(" Numero da Conta: %d\n",c->numero_da_conta);
    printf(" Saldo da Conta: %.2f\n", c->saldo_bancario);
}

int main(){
    
    ContaBancaria contas[100];
    contador_contas = 0;
    
    criarConta(&contas[0],123,"Marlon");
    depositar(&contas[0], 250);
    sacar(&contas[0], 300);
    printf ("Saldo da conta: %.2f\n", consultarSaldo(&contas[0]));
    imprimirInfo(&contas[0]);
    
    return 0;
}

