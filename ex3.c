#include <stdio.h>

void pesq_bin(int arr[],int tamanho){
    int n;
    int valido;

    do{
        printf("Qual numero deseja buscar? \n");
        valido = scanf("%d", &n);

        if(valido != 1){
            printf("Erro: Digite apenas numeros inteiros.\n");
            scanf("%*[^\n]"); // limpa o buffer
        }
    } while(valido != 1);
    
    int inicio = 0;
    int fim = tamanho - 1;
    int encontrado = 0;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(n == arr[meio]){
            printf("Indice: %d\n", meio);
            encontrado = 1;
            break;
        } else if(n > arr[meio]){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if(!encontrado){
        printf("Erro: Elemento nao encontrado.");
    }

}

int main(){

    int tamanho;
    
    printf("Escreva o tamanho do vetor: ");
    if(scanf("%d", &tamanho) != 1){
        printf("Erro: Digite apenas numeros inteiros.\n");
        return 0;
    }

    int arr[tamanho];

    printf("Digite os elementos do vetor em ordem crescente: \n");
    for(int i = 0; i < tamanho; i++){
        if(scanf("%d", &arr[i]) != 1){
            printf("Erro: Digite apenas numeros inteiros.\n");
            return 0;
        }

        if(i > 0 && arr[i] < arr[i-1]){
            printf("Erro: O vetor deve ser ordenado!\n");
            return 0;
        }
    }

    pesq_bin(arr,tamanho);

    return 0;
}