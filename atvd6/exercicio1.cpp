#include <iostream>
#include <vector>

int buscaSequencial(const std::vector<int>& v, int valor) {
    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

int main() {
    constexpr int TAM = 10;
    std::vector<int> numeros(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> numeros[i];
    }

    int valor = 0;
    std::cout << "\nDigite o valor a pesquisar: ";
    std::cin >> valor;

    int posicao = buscaSequencial(numeros, valor);
    if (posicao != -1) {
        std::cout << "Valor encontrado na posicao " << posicao << ".\n";
    } else {
        std::cout << "Valor nao foi encontrado.\n";
    }

    return 0;
}
