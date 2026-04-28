import os

vagas = [
    [0,0,0,0,0,0,0,0,0,0], # subsolo (0)
    [0,0,0,0,0,0,0,0,0,0]  # subsolo (1)
]

def limpar_tela():
    if(os.name == 'nt'):    # Windows
        os.system("cls")    
    else:
        os.system("clear")  # Linux / Mac

def aguardar():
    input("Pressione ENTER para continuar...")

def adicionarCarro():
    while True: # Semelhante ao Do-While em C
        andar = int(input("Qual o andar da vaga (1 = terreo / 0 = subsolo): "))
        if andar == 0 or andar == 1:
            break
        print("Erro: Andar invalido. Tente novamente!")
    
    while True:
        vaga = int(input("Qual o numero da vaga (0 - 9): "))
        if vaga >= 0 and vaga <= 9:
            break
        print("Erro: Vaga invalida. Tente novamente!")
    
    if vagas[andar][vaga] == 1:
        print("\nEssa vaga ja esta ocupada!")
    else:
        vagas[andar][vaga] = 1
        print("\nCarro adicionado com sucesso!")

    aguardar()

def removerCarro():
    while True:
        andar = int(input("Qual o andar da vaga que deseja remover (1 = terreo / 0 = subsolo): "))
        if andar == 0 or andar == 1:
            break
        print("Erro: Andar invalido. Tente novamente!")
    
    while True:
        vaga = int(input("Qual o numero da vaga que deseja remover (0 - 9): "))
        if vaga >= 0 and vaga <= 9:
            break
        print("Erro: Vaga invalida. Tente novamente!")

    if vagas[andar][vaga] == 0:
        print("\nEssa vaga ja esta vazia!")
    else:
        vagas[andar][vaga] = 0
        print("\nCarro removido com sucesso!")
    
    aguardar()

def vagasPorAndar():
    colunas = len(vagas[0]) # colunas = 10

    while True:
        andar = int(input("Qual andar deseja verificar quais vagas estao livres (1 = terreo / 0 = subsolo): "))
        if andar == 0 or andar == 1:
            break
        print("Erro: Andar invalido. Tente novamente!")
    
    livres = 0
    for i in range(0, colunas):
        if vagas[andar][i] == 0:
            print(f"Vaga {[i]} esta vazia")
            livres+=1
    
    if livres == 0:
        print("Nenhuma vagas livre neste andar.")
    else:
        print(f"\nTotal: {livres} vaga(s) livres(s).")
    
    aguardar()

def vagasEstacionamento():
    colunas = len(vagas[0])
    total = 0

    livres1 = 0
    print("Terreo:")
    for i in range(0, colunas):
        if vagas[1][i] == 0:
            print(f"  Vaga {[i]} disponivel")
            livres1 += 1

    if livres1 == 0:
        print("Nenhuma vaga livre.\n")
    total += livres1

    print("\nSubsolo:")
    livres0 = 0
    for i in range(0, colunas):
        if vagas[0][i] == 0:
            print(f"  Vaga {[i]} disponivel")
            livres0 += 1
    
    if livres0 == 0:
        print("Nenhuma vaga livre.\n")
    total += livres0

    print(f"\nTotal geral: {total} vaga(s) livre(s).")

    aguardar()

if __name__ == "__main__":

    while True:
        limpar_tela()
        print("Escolha uma opcao\n")
        print("  [1]  Adicionar carro")
        print("  [2]  Remover carro")
        print("  [3]  Vagas por andar")
        print("  [4]  Vagas no estacionamento")
        print("  [0]  Sair\n")

        escolha = int(input())

        match escolha:
            case 1:
                adicionarCarro()
            case 2:
                removerCarro()
            case 3:
                vagasPorAndar()
            case 4:
                vagasEstacionamento()
            case 0:
                print("Encerrando o sistema. Ate logo!\n")
                break
            case _:
                print("Erro: Opcao invalida.\n")
                aguardar()