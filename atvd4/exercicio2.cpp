#include <array>
#include <iostream>

int main() {
    constexpr int LINHAS = 3;
    constexpr int COLUNAS = 3;
    std::array<std::array<int, COLUNAS>, LINHAS> matriz{};

    std::cout << "Digite os elementos da matriz " << LINHAS << "x" << COLUNAS << ":\n";
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            std::cout << "Posicao [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    int soma = 0;
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            soma += matriz[i][j];
        }
    }

    std::cout << "\nSoma de todos os elementos da matriz: " << soma << "\n";

    return 0;
}
