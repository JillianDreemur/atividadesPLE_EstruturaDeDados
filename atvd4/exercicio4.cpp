#include <array>
#include <iostream>

int main() {
    constexpr int LINHAS = 3;
    constexpr int COLUNAS = 4;
    std::array<std::array<int, COLUNAS>, LINHAS> matriz{};

    std::cout << "Digite os elementos da matriz " << LINHAS << "x" << COLUNAS << ":\n";
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            std::cout << "Posicao [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    int maior = matriz[0][0];
    int linhaMaior = 0;
    int colunaMaior = 0;

    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    std::cout << "\nMaior valor da matriz: " << maior << "\n";
    std::cout << "Localizacao: linha " << linhaMaior << ", coluna " << colunaMaior << "\n";

    return 0;
}
