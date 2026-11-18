#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* proximo;
};

struct Fila {
    No* inicio = nullptr;
    No* fim = nullptr;
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

void inserir(Fila& fila, int valor) {
    No* novo = new No{valor, nullptr};

    if (fila.fim == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo;
        fila.fim = novo;
    }

    ++fila.quantidade;
}

bool remover(Fila& fila, int& removido) {
    if (fila.inicio == nullptr) {
        return false;
    }

    No* alvo = fila.inicio;
    removido = alvo->valor;
    fila.inicio = alvo->proximo;
    delete alvo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    }

    --fila.quantidade;
    return true;
}

void imprimir(const Fila& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Fila vazia.\n";
        return;
    }

    std::cout << "Elementos (inicio -> fim): ";
    No* atual = fila.inicio;
    while (atual != nullptr) {
        std::cout << atual->valor;
        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }
        atual = atual->proximo;
    }
    std::cout << "\n";
}

void liberar(Fila& fila) {
    while (fila.inicio != nullptr) {
        No* proximo = fila.inicio->proximo;
        delete fila.inicio;
        fila.inicio = proximo;
    }
    fila.fim = nullptr;
    fila.quantidade = 0;
}

int main() {
    Fila fila;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Fila de numeros inteiros ---\n";
        std::cout << "1 - Inserir no final\n";
        std::cout << "2 - Remover do inicio\n";
        std::cout << "3 - Imprimir os elementos\n";
        std::cout << "4 - Consultar a quantidade de elementos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Valor a inserir: ");
                inserir(fila, valor);
                std::cout << "Valor " << valor << " inserido no final.\n";
                break;
            }
            case 2: {
                int removido = 0;
                if (remover(fila, removido)) {
                    std::cout << "Valor " << removido << " removido do inicio.\n";
                } else {
                    std::cout << "Fila vazia. Nada a remover.\n";
                }
                break;
            }
            case 3:
                imprimir(fila);
                break;
            case 4:
                std::cout << "Quantidade de elementos: " << fila.quantidade << "\n";
                break;
            case 0:
                std::cout << "Encerrando...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }

    liberar(fila);
    return 0;
}
