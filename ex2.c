#include <stdio.h>
#include <stdlib.h>

int vagas[2][10];

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

     if (vagas[andar][vaga] == 1) {
        printf("\nEssa vaga ja esta ocupada!\n");
    } else {
        vagas[andar][vaga] = 1;
        printf("\nCarro adicionado com sucessos\n");
    }

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

    int livres = 0;
    for(int i = 0; i < colunas; i++){
        if(vagas[andar][i] == 0){
            printf("Vaga [%d] esta vazia\n", i);
            livres++;
        }
    }

    if (livres == 0) printf("  Nenhuma vaga livre neste andar.\n");
    else printf("\nTotal: %d vaga(s) livre(s).\n", livres);

    aguardar();
}

void vagasEstacionamento(){
    int colunas = sizeof(vagas[0]) / sizeof(vagas[0][0]);

    for(int i = 0; i < colunas; i++){
        if(vagas[1][i] == 0){
            printf("Terreo: vaga [%d] esta disponivel\n", i);
        }
    }

    printf("\n");

    for(int i = 0; i < colunas; i++){
        if(vagas[0][i] == 0){
            printf("Subsolo: vaga [%d] esta disponivel\n", i);
        }
    }

    aguardar();
}

int main(){

    int escolha;


    do {
        limparTela();
        printf("Escolha uma opcao\n");
        printf("\n");
        printf("  [1]  Adicionar carro\n");
        printf("  [2]  Remover carro\n");
        printf("  [3]  Vagas por andar\n");
        printf("  [4]  Vagas no estacionamento\n");
        printf("  [0]  Sair\n");
        printf("\n");
        if(scanf("%d", &escolha) != 1){
            printf("Erro: Digite apenas os numeros indicados.");
            return 0;
        }

        switch (escolha){
            case 1:
            
            adicionarCarro();
            break;
            case 2:
            removerCarro();
            break;
            case 3:
            vagasPorAndar();
            break;
            case 4:
            vagasEstacionamento();
            break;
            case 0:
            printf("Encerrando o sistema. Ate logo!\n\n");
            break;
            default:
            printf("Erro: Opcao invalida.\n\n");
            aguardar();
        }

    } while (escolha != 0);

    return 0;
}