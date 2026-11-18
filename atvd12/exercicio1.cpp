#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* proximo;
};

struct FilaCircular {
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

void inserir(FilaCircular& fila, int valor) {
    No* novo = new No{valor, nullptr};

    if (fila.fim == nullptr) {
        novo->proximo = novo;
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        novo->proximo = fila.inicio;
        fila.fim->proximo = novo;
        fila.fim = novo;
    }

    ++fila.quantidade;
}

bool remover(FilaCircular& fila, int& removido) {
    if (fila.inicio == nullptr) {
        return false;
    }

    No* alvo = fila.inicio;
    removido = alvo->valor;

    if (fila.inicio == fila.fim) {
        fila.inicio = nullptr;
        fila.fim = nullptr;
    } else {
        fila.inicio = alvo->proximo;
        fila.fim->proximo = fila.inicio;
    }

    delete alvo;
    --fila.quantidade;
    return true;
}

void imprimir(const FilaCircular& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Fila vazia.\n";
        return;
    }

    std::cout << "Elementos (inicio -> fim): ";
    No* atual = fila.inicio;
    do {
        std::cout << atual->valor;
        if (atual->proximo != fila.inicio) {
            std::cout << " -> ";
        }
        atual = atual->proximo;
    } while (atual != fila.inicio);

    std::cout << " (fim ligado ao inicio)\n";
}

void liberar(FilaCircular& fila) {
    if (fila.inicio == nullptr) {
        return;
    }

    No* atual = fila.inicio->proximo;
    while (atual != fila.inicio) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    delete fila.inicio;
    fila.inicio = nullptr;
    fila.fim = nullptr;
    fila.quantidade = 0;
}

int main() {
    FilaCircular fila;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Fila circular de numeros inteiros ---\n";
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
