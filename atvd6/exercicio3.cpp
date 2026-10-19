#include <iostream>
#include <vector>

int contarOcorrencias(const std::vector<int>& v, int valor) {
    int quantidade = 0;
    for (int elemento : v) {
        if (elemento == valor) {
            ++quantidade;
        }
    }
    return quantidade;
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

    int ocorrencias = contarOcorrencias(numeros, valor);
    std::cout << "Quantidade de ocorrencias encontradas: " << ocorrencias << "\n";

    return 0;
}
