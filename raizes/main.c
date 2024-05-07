
#include <stdio.h>
#include <math.h>

// 9x2 + 8x - 1 = 0
// delta = B2 - 4AC
// x1 = ((-B +(raiz(delta))/2a)  
// x2 = ((-B -(raiz(delta))/2a)

int raizes(float A, float B, float C, float *X1, float *X2){
    
    float delta = ((B*B) - (4*A*C));

    printf ("VALOR DO DELTA: %.2f\n", delta);
    
    if (delta < 0){
        // Não há raizes reais
        return 0;
    }
    
    else if (delta == 0){
        // a equação possui 1 raiz real
        float raiz_1 = ((-B) / (2 * A));
        *X1 = raiz_1;
        *X2 = raiz_1;
        return 1; 
    }
    else{
        // a equacao possui 2 raizes reais
        
        float raiz_delta = sqrt(delta);
    
        printf ("RAIZ DE DELTA: %.2f\n", raiz_delta);
        
        float raiz_1 = ((-B + raiz_delta) / (2 * A));
        
        float raiz_2 = ((-B - raiz_delta) / (2 * A));
        
        *X1 = raiz_1;
        *X2 = raiz_2;
        
        printf ("RAIZ 1: %.2f\n",raiz_1);
        printf ("RAIZ 2: %.2f\n",raiz_2);
    }
}

int main()
{
    float x1;
    float x2;
    float A = 9;
    float B = 8;
    float C = -1;
    
    int quant_raizes = raizes(A,B,C,&x1,&x2);
    
    if (quant_raizes == 0){
        printf ("Não existem raizes\n");
    }
    else if(quant_raizes == 1){
        printf ("Existe apenas uma raiz\n");
        printf ("VALOR DA RAIZ: %.2f\n",x1);
    }
    else{
        printf ("Existem duas raizes\n");
        printf ("VALOR DA RAIZ 1: %.2f\n",x1);
        printf ("VALOR DA RAIZ 2: %.2f\n",x2);
    }
    
    return 0;
}
