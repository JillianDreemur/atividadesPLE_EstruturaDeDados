#include <array>
#include <iomanip>
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

    std::cout << "\nMatriz preenchida:\n";
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            std::cout << std::setw(6) << matriz[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
