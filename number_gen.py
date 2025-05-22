import random

# Genera 100 números únicos entre 1 y 1000
numeros = random.sample(range(0, 20000), 500)

# Imprime los números separados por espacios, sin comas
print(*numeros, sep=' ')

