import random

def escrever_numeros_em_arquivo(n):
    with open('numeros.txt', 'w') as arquivo:
        numeros = [random.randint(0, 1000) for _ in range(n)]
        arquivo.write(str(n) + '\n')
        arquivo.write(' '.join(map(str, numeros)))

if __name__ == "__main__":
    try:
        n = int(input("Digite um número inteiro (n): "))
        escrever_numeros_em_arquivo(n)
        print(f"{n} números aleatórios foram gravados no arquivo 'numeros.txt'.")
    except ValueError:
        print("Digite um número inteiro válido.")
