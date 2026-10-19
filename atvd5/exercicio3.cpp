#include <iostream>
#include <vector>

void insertionSortCrescente(std::vector<int>& v) {
    const int n = static_cast<int>(v.size());
    for (int i = 1; i < n; ++i) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = chave;
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
    std::vector<int> original(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> original[i];
    }

    std::vector<int> ordenado = original;
    insertionSortCrescente(ordenado);

    std::cout << "\nVetor original:\n";
    imprimirVetor(original);

    std::cout << "Vetor ordenado (Insertion Sort - crescente):\n";
    imprimirVetor(ordenado);

    return 0;
}
