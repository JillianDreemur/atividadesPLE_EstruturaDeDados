#include <iostream>
#include <sstream>
#include <string>

struct No {
    int valor;
    No* anterior;
    No* proximo;
};

struct FilaDupla {
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

void inserirInicio(FilaDupla& fila, int valor) {
    No* novo = new No{valor, nullptr, fila.inicio};

    if (fila.inicio == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.inicio->anterior = novo;
        fila.inicio = novo;
    }

    ++fila.quantidade;
}

void inserirFim(FilaDupla& fila, int valor) {
    No* novo = new No{valor, fila.fim, nullptr};

    if (fila.fim == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo;
        fila.fim = novo;
    }

    ++fila.quantidade;
}

bool removerInicio(FilaDupla& fila, int& removido) {
    if (fila.inicio == nullptr) {
        return false;
    }

    No* alvo = fila.inicio;
    removido = alvo->valor;
    fila.inicio = alvo->proximo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    } else {
        fila.inicio->anterior = nullptr;
    }

    delete alvo;
    --fila.quantidade;
    return true;
}

bool removerFim(FilaDupla& fila, int& removido) {
    if (fila.fim == nullptr) {
        return false;
    }

    No* alvo = fila.fim;
    removido = alvo->valor;
    fila.fim = alvo->anterior;

    if (fila.fim == nullptr) {
        fila.inicio = nullptr;
    } else {
        fila.fim->proximo = nullptr;
    }

    delete alvo;
    --fila.quantidade;
    return true;
}

void imprimirFrente(const FilaDupla& fila) {
    if (fila.inicio == nullptr) {
        std::cout << "Fila dupla vazia.\n";
        return;
    }

    std::cout << "Elementos (inicio -> fim): ";
    No* atual = fila.inicio;
    while (atual != nullptr) {
        std::cout << atual->valor;
        if (atual->proximo != nullptr) {
            std::cout << " <-> ";
        }
        atual = atual->proximo;
    }
    std::cout << "\n";
}

void imprimirTras(const FilaDupla& fila) {
    if (fila.fim == nullptr) {
        std::cout << "Fila dupla vazia.\n";
        return;
    }

    std::cout << "Elementos (fim -> inicio): ";
    No* atual = fila.fim;
    while (atual != nullptr) {
        std::cout << atual->valor;
        if (atual->anterior != nullptr) {
            std::cout << " <-> ";
        }
        atual = atual->anterior;
    }
    std::cout << "\n";
}

void liberar(FilaDupla& fila) {
    while (fila.inicio != nullptr) {
        No* proximo = fila.inicio->proximo;
        delete fila.inicio;
        fila.inicio = proximo;
    }
    fila.fim = nullptr;
    fila.quantidade = 0;
}

int main() {
    FilaDupla fila;
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- Fila dupla nao circular de numeros inteiros ---\n";
        std::cout << "1 - Inserir no inicio\n";
        std::cout << "2 - Inserir no final\n";
        std::cout << "3 - Remover do inicio\n";
        std::cout << "4 - Remover do final\n";
        std::cout << "5 - Imprimir do inicio para o fim\n";
        std::cout << "6 - Imprimir do fim para o inicio\n";
        std::cout << "7 - Consultar a quantidade de elementos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                int valor = lerInteiro("Valor a inserir no inicio: ");
                inserirInicio(fila, valor);
                std::cout << "Valor " << valor << " inserido no inicio.\n";
                break;
            }
            case 2: {
                int valor = lerInteiro("Valor a inserir no final: ");
                inserirFim(fila, valor);
                std::cout << "Valor " << valor << " inserido no final.\n";
                break;
            }
            case 3: {
                int removido = 0;
                if (removerInicio(fila, removido)) {
                    std::cout << "Valor " << removido << " removido do inicio.\n";
                } else {
                    std::cout << "Fila dupla vazia. Nada a remover.\n";
                }
                break;
            }
            case 4: {
                int removido = 0;
                if (removerFim(fila, removido)) {
                    std::cout << "Valor " << removido << " removido do final.\n";
                } else {
                    std::cout << "Fila dupla vazia. Nada a remover.\n";
                }
                break;
            }
            case 5:
                imprimirFrente(fila);
                break;
            case 6:
                imprimirTras(fila);
                break;
            case 7:
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
