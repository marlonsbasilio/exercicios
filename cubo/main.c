#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    
    float a, b, c;
    float area[6];
    float area_total;
    float volume;
}CUBO;

void inicializa(CUBO *cubo);
void recebe_lados(CUBO *cubo, float a, float b, float c);
void calculo_areas(CUBO *cubo);
void calculo_volume(CUBO *cubo);

void inicializa(CUBO *cubo){
    
    cubo->volume = 0;
    cubo->area_total = 0;
}

void recebe_lados(CUBO *cubo, float a, float b, float c){
    
    cubo->a = a;
    cubo->b = b;
    cubo->c = c;
}

void calculo_areas(CUBO *cubo){
    float a,b,c;
    
    a = cubo->a;
    b = cubo->b;
    c = cubo->c;
    
    cubo->area[0] = a*b;
    cubo->area[1] = b*c;
    cubo->area[2] = a*c;
    cubo->area[3] = a*b;
    cubo->area[4] = b*c;
    cubo->area[5] = a*c;
    
    for (int i = 0; i < 6; i++){
        cubo->area_total += cubo->area[i];
        printf (" LADO %d: AREA: %.2f\n", i, cubo->area[i]);
    }
    
    printf("\n AREA TOTAL DO CUBO: %.2f\n",cubo->area_total);

}

void calculo_volume(CUBO *cubo){
    
    cubo->volume = cubo->a * cubo->b * cubo->c;
    
    printf ("\n VOLUME DO CUBO É: %.2f \n",cubo->volume);
}


int main(){

    CUBO cubo;
    inicializa(&cubo);
    recebe_lados(&cubo,3,3,3);
    calculo_areas(&cubo);
    calculo_volume(&cubo);
    
    
    return 0;
}

