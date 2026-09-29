#include <iostream>

int main() {
    constexpr int INICIO_TABUADA = 1;
    constexpr int FIM_TABUADA = 10;

    int numero = 0;

    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;

    std::cout << "Tabuada de " << numero << ":\n";

    for (int i = INICIO_TABUADA; i <= FIM_TABUADA; ++i) {
        std::cout << numero << " x " << i << " = " << (numero * i) << '\n';
    }

    return 0;
}
