import time

def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

limite = 1000000
start_time = time.time()
for i in range(1,limite):   
    if (is_prime(i)): print(i)
end_time = time.time()
tempo = end_time - start_time
print()
print(f"Tempo de execução: {tempo:.2f} segundos")