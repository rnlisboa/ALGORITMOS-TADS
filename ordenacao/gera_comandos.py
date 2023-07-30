import os

def criar_arquivo_comandos(diretorio):
    arquivo_comandos = os.path.join(diretorio, "comandos.txt")
    with open(arquivo_comandos, "w") as arquivo:
        for arquivo_teste in os.listdir(diretorio):
            if arquivo_teste.startswith("exemplo-") and arquivo_teste.endswith(".txt"):
                caminho_teste = os.path.join(diretorio, arquivo_teste)
                caminho_teste.replace('/mnt/c/users/pc/desktop/algoritmos/ordenacao', '../')
                comando = f"./teste_ordenacao < {caminho_teste}\n"
                arquivo.write(comando)

def main():
    diretorio_principal = os.getcwd()
    diretorios_casos = [diretorio for diretorio in os.listdir(diretorio_principal) if os.path.isdir(diretorio) and "caso" in diretorio]

    for diretorio_caso in diretorios_casos:
        criar_arquivo_comandos(os.path.join(diretorio_principal, diretorio_caso))

    print("Arquivos comandos.txt criados com sucesso.")

if __name__ == "__main__":
    main()
