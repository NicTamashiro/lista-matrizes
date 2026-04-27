#include <stdio.h>
#include <stdlib.h>

void limparTela(){
    #ifdef _WIN32
    system("cls");   // roda isso no Windows
    #else
    system("clear"); // roda isso no Linux/Mac
    #endif
}

void aguardar() {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    while (getchar() != '\n');
}

void adicionarCarro(){
    printf("Adicinando\n\n");
    aguardar();
}
void removerCarro(){
    printf("removendo\n\n");
    aguardar();
}
void vagasPorAndar(){
    printf("vagas por andar\n\n");
    aguardar();
}
void vagasEstacionamento(){
    printf("vagas totais\n\n");
    aguardar();
}

int main(){

    int vagas[10][10];
    int escolha;


    do {
        printf("Escolha uma opcao\n");
        printf("\n");
        printf("  [1]  Adicionar carro\n");
        printf("  [2]  Remover carro\n");
        printf("  [3]  Vagas por andar\n");
        printf("  [4]  Vagas no estacionamento\n");
        printf("  [0]  Sair\n");
        printf("\n");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
            limparTela();
            adicionarCarro();
            break;
            case 2:
            limparTela();
            removerCarro();
            break;
            case 3:
            limparTela();
            vagasPorAndar();
            break;
            case 4:
            limparTela();
            vagasEstacionamento();
            break;
            case 0:
            limparTela();
            printf("Encerrando o sistema. Ate logo!\n\n");
            break;
            default:
            limparTela();
            printf("Erro: Opcao invalida.\n\n");
        }

    } while (escolha != 0);

    return 0;
}