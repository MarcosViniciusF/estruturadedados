class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

class Arvore:
    def __init__(self):
        self.raiz = None

    def inserir(self, valor):
        if self.raiz is None:
            self.raiz = No(valor)
        else:
            self._inserir_recursivo(valor, self.raiz)

    def _inserir_recursivo(self, valor, no_atual):
        if valor < no_atual.valor:
            if no_atual.esquerda is None:
                no_atual.esquerda = No(valor)
            else:
                self._inserir_recursivo(valor, no_atual.esquerda)
        else:
            if no_atual.direita is None:
                no_atual.direita = No(valor)
            else:
                self._inserir_recursivo(valor, no_atual.direita)

    def listar_ordem(self):
        self._listar_ordem_recursivo(self.raiz)

    def _listar_ordem_recursivo(self, no_atual):
        if no_atual:
            self._listar_ordem_recursivo(no_atual.esquerda)
            print(no_atual.valor, end=" ")
            self._listar_ordem_recursivo(no_atual.direita)

    def listar_preordem(self):
        self._listar_preordem_recursivo(self.raiz)

    def _listar_preordem_recursivo(self, no_atual):
        if no_atual:
            print(no_atual.valor, end=" ")
            self._listar_preordem_recursivo(no_atual.esquerda)
            self._listar_preordem_recursivo(no_atual.direita)

    def listar_posordem(self):
        self._listar_posordem_recursivo(self.raiz)

    def _listar_posordem_recursivo(self, no_atual):
        if no_atual:
            self._listar_posordem_recursivo(no_atual.esquerda)
            self._listar_posordem_recursivo(no_atual.direita)
            print(no_atual.valor, end=" ")

    def remover(self, valor):
        self.raiz = self._remover_recursivo(valor, self.raiz)

    def _remover_recursivo(self, valor, no_atual):
        if no_atual is None:
            return no_atual
        elif valor < no_atual.valor:
            no_atual.esquerda = self._remover_recursivo(valor, no_atual.esquerda)
        elif valor > no_atual.valor:
            no_atual.direita = self._remover_recursivo(valor, no_atual.direita)
        else:
            if no_atual.esquerda is None:
                return no_atual.direita
            elif no_atual.direita is None:
                return no_atual.esquerda
            else:
                sucessor = self._encontrar_sucessor(no_atual.direita)
                no_atual.valor = sucessor.valor
                no_atual.direita = self._remover_recursivo(sucessor.valor, no_atual.direita)
        return no_atual

    def _encontrar_sucessor(self, no_atual):
        while no_atual.esquerda:
            no_atual = no_atual.esquerda
        return no_atual

    def esvaziar(self):
        self.raiz = None


def exibir_menu():
    print("Escolha uma opção:")
    print("1 - Inserir um nó")
    print("2 - Listar a árvore (em ordem)")
    print("3 - Listar a árvore (pré-ordem)")
    print("4 - Listar a árvore (pós-ordem)")
    print("5 - Remover um nó")
    print("6 - Esvaziar a árvore")
    print("7 - Sair")
    opcao = int(input("Opção: "))
    return opcao


arvore = Arvore()

while True:
    opcao = exibir_menu()

    if opcao == 1:
        valor = int(input("Digite o valor a ser inserido: "))
        arvore.inserir(valor)
        print("Valor inserido com sucesso!")
    elif opcao == 2:
        print("Árvore (em ordem):")
        arvore.listar_ordem()
        print()
    elif opcao == 3:
        print("Árvore (pré-ordem):")
        arvore.listar_preordem()
        print()
    elif opcao == 4:
        print("Árvore (pós-ordem):")
        arvore.listar_posordem()
        print()
    elif opcao == 5:
        valor = int(input("Digite o valor a ser removido: "))
        arvore.remover(valor)
        print("Valor removido com sucesso!")
    elif opcao == 6:
        arvore.esvaziar()
        print("Árvore esvaziada!")
    elif opcao == 7:
        print("Saindo...")
        break
    else:
        print("Opção inválida. Tente novamente!")
