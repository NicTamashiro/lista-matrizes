def pesq_bin(arr, tamanho):
    while True:
        try:
            n = int(input("Qual numero deseja buscar? "))
            break
        except ValueError:
            print("Erro: Digite apenas numeros inteiros. Tente novamente!")
    
    inicio = 0
    fim = tamanho - 1
    encontrado = False

    while inicio <= fim:
        meio = (inicio + fim) // 2

        if n == arr[meio]:
            print(f"Indice: {meio}")
            encontrado = True
            break
        elif n > arr[meio]:
            inicio = meio + 1
        else:
            fim = meio - 1
    
    if not encontrado:
        print("Erro: Elemento nao encontrado.")

if __name__ == "__main__":
    tamanho = 0

    while tamanho <= 0:
        try:
            tamanho = int(input("Escreva o tamanho do vetor: "))
            if tamanho <= 0:
                print("Erro: O tamanho deve ser maior que zero.")
        except ValueError:
            print("Erro: Digite apenas numeros inteiros.")
    
    arr = []

    print("Digite os elementos do vetor em ordem crescente:")
    i = 0
    while i < tamanho:
        try:
            elemento = int(input())
            if i > 0 and elemento < arr[i - 1]:
                print(f"Erro: O vetor deve ser ordenado. {elemento} < {arr[i-1]}.")
            else:
                arr.append(elemento)
                i += 1
        except ValueError:
            print("Erro: Digite apenas numeros inteiros.")

    pesq_bin(arr, tamanho)