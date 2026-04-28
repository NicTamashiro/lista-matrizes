#include <stdio.h>
#include <stdio.h>

void calcularDigitoVerificador(int arr[]){
    int soma1 = 0;
    for(int i = 0; i < 9; i++){
        soma1 += arr[i] * (10 - i);
    }

    int primeiroDigito;

    if((soma1 % 11) < 2){
        primeiroDigito = 0;
    } else {
        primeiroDigito = 11 - (soma1 % 11);
    }

    arr[9] = primeiroDigito;

    int segundoDigito;
    int soma2 = 0;

    for(int i = 0; i < 10; i++){
        soma2 += arr[i] * (11 - i);
    }

    if((soma2 % 11) < 2){
        segundoDigito = 0;
    } else {
        segundoDigito = 11 - (soma2 % 11);
    }   
    
    arr[10] = segundoDigito;

    for(int i = 0; i < 9; i++){
        printf("%d", arr[i]);
    }

    printf("-");

    printf("%d", arr[9]);
    printf("%d", arr[10]);
}

int main(){

    int arr[11];

    printf("Digite os 9 primeiros numeros de seu CPF: \n");
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
    }

    calcularDigitoVerificador(arr);

    return 0;
}