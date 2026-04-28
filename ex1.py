import math

arr = []
soma_num = 0;

for i in range(0,10):
    arr.append(float(input()))
    soma_num += arr[i]

media = soma_num / len(arr)

soma_quadrado = 0;

for i in range(0,10):
    diff = arr[i] - media
    soma_quadrado += diff*diff

resultado = math.sqrt(soma_quadrado / len(arr))
print(f"{resultado:.3f}")
