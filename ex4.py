
def calcularDigitoVerificador(arr):
    soma1 = 0
    for i in range(0, 9):
        soma1 += arr[i] * (10 - i)
    
    if (soma1 % 11) < 2:
        arr[9] = 0
    else:
        arr[9] = 11 - (soma1 % 11)
    
    soma2 = 0
    for i in range(0, 10):
        soma2 += arr[i] * (11 - i)
    
    if (soma2 % 11) < 2:
        arr[10] = 0
    else:
        arr[10] = 11 - (soma2 % 11)

def imprimirCPF(arr):
    parte1 = ''.join(str(arr[i]) for i in range(9)) # List comprehension
    print(f"{parte1}-{arr[9]}{arr[10]}") 


if __name__ == "__main__":
    arr = [0] * 11

    entrada = input("Digite os 9 primeiros numeros de seu CPF:\n")

    if len(entrada) != 9 or not entrada.isdigit():    # .isdigit() -> verifica se todos os caracteres sao numeros
        print("Erro: Digite apenas 9 digitos numericos.")
    else:
        for i in range(0, 9):
            arr[i] = int(entrada[i])
    
        calcularDigitoVerificador(arr)
        imprimirCPF(arr)