#include <stdio.h>
#include <stdio.h>

void calcularDigitoVerificador(int arr[]){
    int soma1 = 0;
    for(int i = 0; i < 9; i++){
        soma1 += arr[i] * (10 - i);
    }

    if((soma1 % 11) < 2){
        arr[9] = 0;
    } else {
        arr[9] = 11 - (soma1 % 11);
    }

    int soma2 = 0;

    for(int i = 0; i < 10; i++){
        soma2 += arr[i] * (11 - i);
    }

    if((soma2 % 11) < 2){
        arr[10] = 0;
    } else {
        arr[10] = 11 - (soma2 % 11);
    }   
    
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