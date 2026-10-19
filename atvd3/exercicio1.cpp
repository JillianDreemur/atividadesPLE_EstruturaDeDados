#include <iostream>
#include <vector>

int main() {
    constexpr int TAM = 15;
    std::vector<int> numeros(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> numeros[i];
    }

    std::cout << "\nVetor na ordem inversa:\n";
    for (int i = TAM - 1; i >= 0; --i) {
        std::cout << numeros[i];
        if (i > 0) {
            std::cout << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
