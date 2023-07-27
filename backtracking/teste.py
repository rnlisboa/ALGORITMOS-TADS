def exemplo_exponencial(n):
    if n == 0:
        return 1
    else:
        return exemplo_exponencial(n - 1) + exemplo_exponencial(n - 1)

print(exemplo_exponencial(10))