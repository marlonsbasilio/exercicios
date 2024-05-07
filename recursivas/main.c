#include <stdio.h>


void recursiva_crescente(int n){
    
    if (n <= 5){
        printf (" %d\n",n);
        recursiva_crescente(n+1);
        // printf (" %d\n",n);
    }
}

void recursiva_decrescente(int n){
    
    if (n <= 5){
        // printf (" %d\n",n);
        recursiva_decrescente(n+1);
        printf (" %d\n",n);
    }
}

int main(){
    printf("\n");
    
    recursiva_crescente(1);
    
    printf("\n");
    recursiva_decrescente(1);
    
    return 0;
}
