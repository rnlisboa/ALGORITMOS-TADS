import os
import matplotlib.pyplot as plt

diretorio_atual = os.path.dirname(os.path.realpath(__file__))


# Função para ler os dados de um arquivo e retornar as listas de tamanhos e tempos de execução
def ler_dados_arquivo(caminho_arquivo):
    tamanhos_input = []
    tempos_execucao = []
    with open(caminho_arquivo, 'r') as arquivo:
        for linha in arquivo:
            tamanho, tempo = linha.strip().split(',')
            tamanhos_input.append(int(tamanho))
            tempos_execucao.append(float(tempo))
    return tamanhos_input, tempos_execucao

# Diretórios onde estão os arquivos de cada função
diretorio_insercao = diretorio_atual + '\\insercao'
diretorio_selecao = diretorio_atual + '\\selecao'
diretorio_merge = diretorio_atual + '\\merge'

# Listas para armazenar os tamanhos e tempos de execução de cada função
tamanhos_insercao, tempos_insercao = [], []
tamanhos_selecao, tempos_selecao = [], []
tamanhos_merge, tempos_merge = [], []

# Lendo os dados para cada função

caminho_arquivo = os.path.join(diretorio_insercao, 'caso05.txt')
tamanhos, tempos = ler_dados_arquivo(caminho_arquivo)
tamanhos_insercao.extend(tamanhos)
tempos_insercao.extend(tempos)


caminho_arquivo = os.path.join(diretorio_selecao, 'caso05.txt')
tamanhos, tempos = ler_dados_arquivo(caminho_arquivo)
tamanhos_selecao.extend(tamanhos)
tempos_selecao.extend(tempos)


caminho_arquivo = os.path.join(diretorio_merge, 'caso05.txt')
tamanhos, tempos = ler_dados_arquivo(caminho_arquivo)
tamanhos_merge.extend(tamanhos)
tempos_merge.extend(tempos)

# Plotando o gráfico com três curvas
plt.plot(tamanhos_insercao, tempos_insercao, label='Inserção', marker='o')
plt.plot(tamanhos_selecao, tempos_selecao, label='Seleção', marker='o')
plt.plot(tamanhos_merge, tempos_merge, label='Merge', marker='o')

plt.xlabel('Tamanho da lista')
plt.ylabel('Tempo de Execução (segundos)')
plt.title('Gráfico de Tempo de Execução - caso 05')
plt.grid(True)
plt.legend()
plt.show()
