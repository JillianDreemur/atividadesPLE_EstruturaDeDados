#include <iostream>
#include <utility>
#include <vector>

void selectionSortDecrescente(std::vector<int>& v) {
    const int n = static_cast<int>(v.size());
    for (int i = 0; i < n - 1; ++i) {
        int indiceMaior = i;
        for (int j = i + 1; j < n; ++j) {
            if (v[j] > v[indiceMaior]) {
                indiceMaior = j;
            }
        }
        if (indiceMaior != i) {
            std::swap(v[i], v[indiceMaior]);
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
    constexpr int TAM = 8;
    std::vector<int> numeros(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> numeros[i];
    }

    selectionSortDecrescente(numeros);

    std::cout << "\nVetor ordenado (Selection Sort - decrescente):\n";
    imprimirVetor(numeros);

    return 0;
}
