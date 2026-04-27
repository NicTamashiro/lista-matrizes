#include <stdio.h>
#include <stdlib.h>

int vagas[10][10];

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
    int andar;
    int vaga;
    do{
        printf("Qual o andar da vaga (1 = terreo / 0 = subsolo): ");
        scanf("%d", &andar);
        if(andar != 0 && andar != 1) printf("Andar invalido. Tente novamente.\n");
    } while(andar != 0 && andar != 1);

    do{
        printf("Qual o numero da vaga (0 - 9): ");
        scanf("%d", &vaga);
        if(vaga < 0 || vaga > 9) printf("Vaga invalida. Tente novamente.\n");
    } while(vaga < 0 || vaga > 9);

    vagas[andar][vaga] = 1;

    printf("\nCarro adicionado com sucesso!\n");

    aguardar();
}

void removerCarro(){

    int andar;
    int vaga;
    do{
        printf("Qual o andar da vaga que deseja remover (1 = terreo / 0 = subsolo): ");
        scanf("%d", &andar);
        if(andar != 0 && andar != 1) printf("Andar invalido. Tente novamente.\n");
    } while(andar != 0 && andar != 1);

    do{
        printf("Qual o numero da vaga que deseja remover (0 - 9): ");
        scanf("%d", &vaga);
        if(vaga < 0 || vaga > 9) printf("Vaga invalida. Tente novamente.\n");
    } while(vaga < 0 || vaga > 9);

    if(vagas[andar][vaga] == 0){
        printf("Essa vaga ja esta vazia!\n");
    } else {
        vagas[andar][vaga] = 0;
        printf("\nCarro removido com sucesso!\n");
    }

    aguardar();
}

void vagasPorAndar(){
    int andar;
    int colunas = sizeof(vagas[0]) / sizeof(vagas[0][0]);
    do{

        printf("Qual andar deseja verificar quais vagas estao livres (1 = terreo / 0 = subsolo): ");
        scanf("%d", &andar);
        if(andar != 0 && andar != 1) printf("Andar invalido. Tente novamente.\n");
    } while(andar != 0 && andar != 1);

    for(int i = 0; i < colunas; i++){
        if(vagas[andar][i] == 0){
            printf("Vaga [%d] esta vazia\n", i);
        }
    }
    aguardar();
}

void vagasEstacionamento(){
    printf("vagas totais\n\n");
    aguardar();
}

int main(){

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