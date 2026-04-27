#include <stdio.h>
#include <math.h>

int main(){

    float num[10];
    float soma_num = 0;
    float media;
    float soma_quadrado = 0;

    int tamanho = sizeof(num) / sizeof(num[0]);

    for(int i = 0; i < tamanho; i++){
        scanf("%f", &num[i]);
        soma_num+=num[i];
    }

    media = soma_num / tamanho;

    for(int i = 0; i < tamanho; i++){
        float diff = num[i] - media;
        soma_quadrado+= diff*diff;
    }


    float resultado = sqrtf(soma_quadrado / tamanho);
    printf("%.3f\n", resultado);

    return 0;
}