#include <array>
#include <iostream>

int main() {
    constexpr int LINHAS = 4;
    constexpr int COLUNAS = 4;
    std::array<std::array<int, COLUNAS>, LINHAS> matriz{};

    std::cout << "Digite os elementos da matriz " << LINHAS << "x" << COLUNAS << ":\n";
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            std::cout << "Posicao [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    int pares = 0;
    int impares = 0;
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            if (matriz[i][j] % 2 == 0) {
                ++pares;
            } else {
                ++impares;
            }
        }
    }

    std::cout << "\nQuantidade de numeros pares: " << pares << "\n";
    std::cout << "Quantidade de numeros impares: " << impares << "\n";

    return 0;
}
