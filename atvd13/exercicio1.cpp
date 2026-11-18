#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    int prioridade;
    No* proximo;
};

struct FilaPrioridade {
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

void inserir(FilaPrioridade& fila, int valor, int prioridade) {
    No* novo = new No{valor, prioridade, nullptr};

    if (fila.inicio == nullptr || prioridade > fila.inicio->prioridade) {
        novo->proximo = fila.inicio;
        fila.inicio = novo;
        if (fila.fim == nullptr) {
            fila.fim = novo;
        }
    } else {
        No* atual = fila.inicio;
        while (atual->proximo != nullptr && atual->proximo->prioridade >= prioridade) {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;

        if (novo->proximo == nullptr) {
            fila.fim = novo;
        }
    }

    ++fila.quantidade;
}

bool remover(FilaPrioridade& fila, int& valorRemovido, int& prioridadeRemovida) {
    if (fila.inicio == nullptr) {
        return false;
    }

    No* alvo = fila.inicio;
    valorRemovido = alvo->valor;
    prioridadeRemovida = alvo->prioridade;
    fila.inicio = alvo->proximo;
    delete alvo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    }

    --fila.quantidade;
    return true;
}

void imprimir(const FilaPrioridade& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Fila de prioridade vazia.\n";
        return;
    }

    std::cout << "Elementos (maior prioridade primeiro):\n";
    No* atual = fila.inicio;
    while (atual != nullptr) {
        std::cout << "  valor = " << atual->valor
                  << " | prioridade = " << atual->prioridade << "\n";
        atual = atual->proximo;
    }
}

void liberar(FilaPrioridade& fila) {
    while (fila.inicio != nullptr) {
        No* proximo = fila.inicio->proximo;
        delete fila.inicio;
        fila.inicio = proximo;
    }
    fila.fim = nullptr;
    fila.quantidade = 0;
}

int main() {
    FilaPrioridade fila;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Fila de prioridade ---\n";
        std::cout << "1 - Inserir elemento\n";
        std::cout << "2 - Remover elemento de maior prioridade\n";
        std::cout << "3 - Imprimir os elementos\n";
        std::cout << "4 - Consultar a quantidade de elementos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Valor: ");
                int prioridade = lerInteiro("Prioridade (quanto maior, mais urgente): ");
                inserir(fila, valor, prioridade);
                std::cout << "Valor " << valor << " inserido com prioridade " << prioridade << ".\n";
                break;
            }
            case 2: {
                int valorRemovido = 0;
                int prioridadeRemovida = 0;
                if (remover(fila, valorRemovido, prioridadeRemovida)) {
                    std::cout << "Removido valor " << valorRemovido
                              << " (prioridade " << prioridadeRemovida << ").\n";
                } else {
                    std::cout << "Fila de prioridade vazia. Nada a remover.\n";
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
