import math

num = []

for i in range(0, 10):
    n = float(input())
    num.append(n)

media = sum(num) / len(num)

soma_quadrado = 0
for i in num:
    diff = i - media
    soma_quadrado += diff * diff

resultado = math.sqrt(soma_quadrado / len(num))
print(resultado)