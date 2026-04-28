#include <stdio.h>
#include <string.h>

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

void imprimirCPF(int arr[]){
    for(int i = 0; i < 9; i++){
        printf("%d", arr[i]);
    }
    printf("-%d%d", arr[9], arr[10]);
}

int main(){

    int arr[11];
    char input[20];

    printf("Digite os 9 primeiros numeros de seu CPF:\n");
    scanf("%19s", input);

    if(strlen(input) != 9){
        printf("Erro: Digite exatamente 9 digitos.\n");
        return 1;
    }
    
    for(int i = 0; i < 9; i++){
        if(input[i] < '0' || input[i] > '9'){
            printf("Erro: Entrada invalida!\n");
            return 1;
        }
        arr[i] = input[i] - '0'; // conversao '4' - '0' -> 52 - 48 -> 4
    }

    calcularDigitoVerificador(arr);
    imprimirCPF(arr);

    return 0;
}