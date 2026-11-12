#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* proximo;
};

struct ListaCircular {
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

void inserirInicio(ListaCircular& lista, int valor) {
    No* novo = new No{valor, nullptr};

    if (lista.inicio == nullptr) {
        novo->proximo = novo;
        lista.inicio = novo;
        lista.fim = novo;
    } else {
        novo->proximo = lista.inicio;
        lista.inicio = novo;
        lista.fim->proximo = lista.inicio;
    }

    ++lista.quantidade;
}

void inserirFim(ListaCircular& lista, int valor) {
    No* novo = new No{valor, nullptr};

    if (lista.inicio == nullptr) {
        novo->proximo = novo;
        lista.inicio = novo;
        lista.fim = novo;
    } else {
        novo->proximo = lista.inicio;
        lista.fim->proximo = novo;
        lista.fim = novo;
    }

    ++lista.quantidade;
}

void imprimir(const ListaCircular& lista) {
    if (lista.inicio == nullptr) {
        std::cout << "Lista vazia.\n";
        return;
    }

    std::cout << "Elementos: ";
    No* atual = lista.inicio;
    do {
        std::cout << atual->valor;
        if (atual->proximo != lista.inicio) {
            std::cout << " -> ";
        }
        atual = atual->proximo;
    } while (atual != lista.inicio);
    std::cout << " -> (volta ao inicio)\n";
}

int contar(const ListaCircular& lista) {
    if (lista.inicio == nullptr) {
        return 0;
    }

    int total = 0;
    No* atual = lista.inicio;
    do {
        ++total;
        atual = atual->proximo;
    } while (atual != lista.inicio);
    return total;
}

void liberar(ListaCircular& lista) {
    if (lista.inicio == nullptr) {
        return;
    }

    No* atual = lista.inicio->proximo;
    while (atual != lista.inicio) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    delete lista.inicio;
    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.quantidade = 0;
}

int main() {
    ListaCircular lista;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Lista circular simplesmente encadeada ---\n";
        std::cout << "1 - Inserir no inicio\n";
        std::cout << "2 - Inserir no final\n";
        std::cout << "3 - Imprimir todos os elementos\n";
        std::cout << "4 - Consultar a quantidade de elementos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Valor a inserir no inicio: ");
                inserirInicio(lista, valor);
                std::cout << "Valor " << valor << " inserido no inicio.\n";
                break;
            }
            case 2: {
                int valor = lerInteiro("Valor a inserir no final: ");
                inserirFim(lista, valor);
                std::cout << "Valor " << valor << " inserido no final.\n";
                break;
            }
            case 3:
                imprimir(lista);
                break;
            case 4:
                std::cout << "Quantidade de elementos: " << contar(lista) << "\n";
                break;
            case 0:
                std::cout << "Encerrando...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }

    liberar(lista);
    return 0;
}
