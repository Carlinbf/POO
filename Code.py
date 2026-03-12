def fibonacci(n):
    seq = [0, 1]
    while seq[-1] + seq[-2] <= n:
        seq.append(seq[-1] + seq[-2])
    return seq

# Exemplo de uso
limite = int(input("Digite um número limite: "))
print("Sequência de Fibonacci até", limite, ":")
print(fibonacci(limite)) alk sknvsnvsnvosnvnsfnvis