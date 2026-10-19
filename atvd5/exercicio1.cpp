#include <iostream>
#include <utility>
#include <vector>

void bubbleSortCrescente(std::vector<int>& v) {
    const int n = static_cast<int>(v.size());
    for (int i = 0; i < n - 1; ++i) {
        bool trocou = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }
}

void imprimirVetor(const std::vector<int>& v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    constexpr int TAM = 10;
    std::vector<int> numeros(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> numeros[i];
    }

    bubbleSortCrescente(numeros);

    std::cout << "\nVetor ordenado (Bubble Sort - crescente):\n";
    imprimirVetor(numeros);

    return 0;
}
