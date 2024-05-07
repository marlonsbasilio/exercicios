#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    char matricula[11];
    float nota;
}ALUNO;

void inicializarAluno(ALUNO *aluno, const char *nome, const char *matricula, float nota) {
    strcpy(aluno->nome, nome);
    strcpy(aluno->matricula, matricula);
    aluno->nota = nota;
}

void func_maior_nota(ALUNO *aluno, int tamanho){
    float maior = 0;
    int marcador;

    for (int i = 0; i < tamanho; i++){
    printf ("\nNOTA DO ALUNO %s: %.2f\n", aluno[i].nome, aluno[i].nota);
        if (maior <= aluno[i].nota){
            maior = aluno[i].nota;
            marcador = i;
        }
    }
    
    printf("\n #### MAIOR NOTA ####\n");
    printf(" NOME: %s\n MATRICULA: %s\n NOTA: %.2f\n",aluno[marcador].nome, aluno[marcador].matricula, aluno[marcador].nota);
}

void func_menor_nota(ALUNO *aluno, int tamanho){
    float menor = 101;
    int marcador= 0;

    for (int i = 0; i < tamanho; i++){
    // printf ("NOTA DO ALUNO %s: %.2f\n", aluno[i].nome,aluno[i].nota);
        if (menor >= aluno[i].nota){
            menor = aluno[i].nota;
            marcador = i;
        }
    }
        
    printf("\n #### MENOR NOTA ####\n");
    printf(" NOME: %s\n MATRICULA: %s\n NOTA: %.2f\n",aluno[marcador].nome, aluno[marcador].matricula, aluno[marcador].nota);
}
int main(){

    ALUNO aluno[5];
    
    inicializarAluno(&aluno[0], "MARLON", "1112223334", 90);
    inicializarAluno(&aluno[1], "TOMAZ","2223334445",80);
    inicializarAluno(&aluno[2], "ALESSANDRO","3334445556",82);
    inicializarAluno(&aluno[3], "TINHOSO","4445556667",50);
    inicializarAluno(&aluno[4], "DANONE","5556667778",70);
    
    func_maior_nota(aluno,5);
    func_menor_nota(aluno,5);
    

    return 0;
}
