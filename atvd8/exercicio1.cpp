#include <iostream>
#include <sstream>
#include <string>

struct Aluno {
    std::string nome;
    int idade = 0;
};

struct No {
    Aluno aluno;
    No* anterior;
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

std::string lerTexto(const char* mensagem) {
    std::string texto;
    while (texto.empty()) {
        std::cout << mensagem;
        std::getline(std::cin, texto);
        if (texto.empty()) {
            std::cout << "O nome nao pode ficar vazio.\n";
        }
    }
    return texto;
}

Aluno lerAluno() {
    Aluno aluno;
    aluno.nome = lerTexto("Nome do aluno: ");
    aluno.idade = lerInteiro("Idade do aluno: ");
    return aluno;
}

void inserirInicio(Lista& lista, const Aluno& aluno) {
    No* novo = new No{aluno, nullptr, lista.inicio};
    if (lista.inicio != nullptr) {
        lista.inicio->anterior = novo;
    } else {
        lista.fim = novo;
    }
    lista.inicio = novo;
    ++lista.quantidade;
}

void inserirFim(Lista& lista, const Aluno& aluno) {
    No* novo = new No{aluno, lista.fim, nullptr};
    if (lista.fim != nullptr) {
        lista.fim->proximo = novo;
    } else {
        lista.inicio = novo;
    }
    lista.fim = novo;
    ++lista.quantidade;
}

bool removerInicio(Lista& lista) {
    if (lista.inicio == nullptr) {
        return false;
    }

    No* alvo = lista.inicio;
    lista.inicio = alvo->proximo;
    if (lista.inicio != nullptr) {
        lista.inicio->anterior = nullptr;
    } else {
        lista.fim = nullptr;
    }

    delete alvo;
    --lista.quantidade;
    return true;
}

bool removerFim(Lista& lista) {
    if (lista.fim == nullptr) {
        return false;
    }

    No* alvo = lista.fim;
    lista.fim = alvo->anterior;
    if (lista.fim != nullptr) {
        lista.fim->proximo = nullptr;
    } else {
        lista.inicio = nullptr;
    }

    delete alvo;
    --lista.quantidade;
    return true;
}

void imprimir(const Lista& lista) {
    if (lista.inicio == nullptr) {
        std::cout << "Lista vazia.\n";
        return;
    }

    std::cout << "Alunos (do inicio para o final):\n";
    for (No* atual = lista.inicio; atual != nullptr; atual = atual->proximo) {
        std::cout << "- " << atual->aluno.nome
                  << " (" << atual->aluno.idade << " anos)\n";
    }
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
        std::cout << "\n--- Lista duplamente encadeada de alunos ---\n";
        std::cout << "1 - Inserir aluno no inicio\n";
        std::cout << "2 - Inserir aluno no final\n";
        std::cout << "3 - Remover aluno do inicio\n";
        std::cout << "4 - Remover aluno do final\n";
        std::cout << "5 - Imprimir todos os alunos\n";
        std::cout << "0 - Sair\n";

        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: {
                Aluno aluno = lerAluno();
                inserirInicio(lista, aluno);
                std::cout << "Aluno " << aluno.nome << " inserido no inicio.\n";
                break;
            }
            case 2: {
                Aluno aluno = lerAluno();
                inserirFim(lista, aluno);
                std::cout << "Aluno " << aluno.nome << " inserido no final.\n";
                break;
            }
            case 3:
                if (removerInicio(lista)) {
                    std::cout << "Aluno do inicio removido.\n";
                } else {
                    std::cout << "Lista vazia. Nada foi removido.\n";
                }
                break;
            case 4:
                if (removerFim(lista)) {
                    std::cout << "Aluno do final removido.\n";
                } else {
                    std::cout << "Lista vazia. Nada foi removido.\n";
                }
                break;
            case 5:
                imprimir(lista);
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
