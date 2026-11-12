#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* proximo;
};

struct Lista {
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

void inserirInicio(Lista& lista, int valor) {
    No* novo = new No{valor, lista.inicio};
    lista.inicio = novo;
    if (lista.fim == nullptr) {
        lista.fim = novo;
    }
    ++lista.quantidade;
}

void inserirFim(Lista& lista, int valor) {
    No* novo = new No{valor, nullptr};
    if (lista.fim == nullptr) {
        lista.inicio = novo;
        lista.fim = novo;
    } else {
        lista.fim->proximo = novo;
        lista.fim = novo;
    }
    ++lista.quantidade;
}

void imprimir(const Lista& lista) {
    if (lista.inicio == nullptr) {
        std::cout << "Lista vazia.\n";
        return;
    }

    std::cout << "Elementos: ";
    for (No* atual = lista.inicio; atual != nullptr; atual = atual->proximo) {
        std::cout << atual->valor;
        if (atual->proximo != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

int buscar(const Lista& lista, int valor) {
    int posicao = 0;
    for (No* atual = lista.inicio; atual != nullptr; atual = atual->proximo, ++posicao) {
        if (atual->valor == valor) {
            return posicao;
        }
    }
    return -1;
}

bool remover(Lista& lista, int valor) {
    No* anterior = nullptr;
    No* atual = lista.inicio;
    while (atual != nullptr && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        return false;
    }

    if (anterior == nullptr) {
        lista.inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    if (atual == lista.fim) {
        lista.fim = anterior;
    }

    delete atual;
    --lista.quantidade;
    return true;
}

void liberar(Lista& lista) {
    No* atual = lista.inicio;
    while (atual != nullptr) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    lista.inicio = nullptr;
    lista.fim = nullptr;
    lista.quantidade = 0;
}

int main() {
    Lista lista;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Lista simplesmente encadeada ---\n";
        std::cout << "1 - Inserir no inicio\n";
        std::cout << "2 - Inserir no final\n";
        std::cout << "3 - Imprimir todos os elementos\n";
        std::cout << "4 - Consultar a quantidade de elementos\n";
        std::cout << "5 - Buscar um elemento pelo valor\n";
        std::cout << "6 - Remover um elemento especifico\n";
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
                std::cout << "Quantidade de elementos: " << lista.quantidade << "\n";
                break;
            case 5: {
                int valor = lerInteiro("Valor a buscar: ");
                int posicao = buscar(lista, valor);
                if (posicao == -1) {
                    std::cout << "Valor " << valor << " nao encontrado na lista.\n";
                } else {
                    std::cout << "Valor " << valor << " encontrado na posicao " << posicao << ".\n";
                }
                break;
            }
            case 6: {
                int valor = lerInteiro("Valor a remover: ");
                if (remover(lista, valor)) {
                    std::cout << "Valor " << valor << " removido da lista.\n";
                } else {
                    std::cout << "Valor " << valor << " nao encontrado. Nada foi removido.\n";
                }
                break;
            }
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
