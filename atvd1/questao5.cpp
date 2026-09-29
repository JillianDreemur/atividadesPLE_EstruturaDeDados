#include <iostream>
#include <limits>

int main() {
    constexpr int QUANTIDADE_NUMEROS = 8;

    int maior = std::numeric_limits<int>::min();

    for (int i = 1; i <= QUANTIDADE_NUMEROS; ++i) {
        int numero = 0;

        std::cout << "Digite o " << i << "o numero inteiro: ";
        std::cin >> numero;

        if (numero > maior) {
            maior = numero;
        }
    }

    std::cout << "Maior numero digitado: " << maior << '\n';

    if (maior % 2 == 0) {
        std::cout << "O maior numero e par\n";
    } else {
        std::cout << "O maior numero e impar\n";
    }

    return 0;
}
