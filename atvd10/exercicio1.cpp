#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* proximo;
};

struct Pilha {
    No* topo = nullptr;
    int quantidade = 0;
};

int lerInteiro(const char* mensagem) {
    std::string linha;
    int valor = 0;

    while (true) {
        std::cout << mensagem;
        if (!std::getline(std::cin, linha)) {
            return 0;
        }

        std::istringstream entrada(linha);
        if (entrada >> valor) {
            return valor;
        }

        std::cout << "Entrada invalida. Digite um numero inteiro.\n";
    }
}

void inserir(Pilha& pilha, int valor) {
    No* novo = new No{valor, pilha.topo};
    pilha.topo = novo;
    ++pilha.quantidade;
}

bool remover(Pilha& pilha, int& removido) {
    if (pilha.topo == nullptr) {
        return false;
    }

    No* alvo = pilha.topo;
    removido = alvo->valor;
    pilha.topo = alvo->proximo;
    delete alvo;
    --pilha.quantidade;
    return true;
}

void imprimir(const Pilha& pilha) {
    if (pilha.topo == nullptr) {
        std::cout << "Pilha vazia.\n";
        return;
    }

    std::cout << "Elementos (topo -> base): ";
    No* atual = pilha.topo;
    while (atual != nullptr) {
        std::cout << atual->valor;
        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }
        atual = atual->proximo;
    }
    std::cout << "\n";
}

void liberar(Pilha& pilha) {
    while (pilha.topo != nullptr) {
        No* proximo = pilha.topo->proximo;
        delete pilha.topo;
        pilha.topo = proximo;
    }
    pilha.quantidade = 0;
}

int main() {
    Pilha pilha;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Pilha de numeros inteiros ---\n";
        std::cout << "1 - Inserir no topo\n";
        std::cout << "2 - Remover do topo\n";
        std::cout << "3 - Imprimir os elementos\n";
        std::cout << "4 - Consultar a quantidade de elementos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Valor a inserir: ");
                inserir(pilha, valor);
                std::cout << "Valor " << valor << " inserido no topo.\n";
                break;
            }
            case 2: {
                int removido = 0;
                if (remover(pilha, removido)) {
                    std::cout << "Valor " << removido << " removido do topo.\n";
                } else {
                    std::cout << "Pilha vazia. Nada a remover.\n";
                }
                break;
            }
            case 3:
                imprimir(pilha);
                break;
            case 4:
                std::cout << "Quantidade de elementos: " << pilha.quantidade << "\n";
                break;
            case 0:
                std::cout << "Encerrando...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }

    liberar(pilha);
    return 0;
}
