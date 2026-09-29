#include <iostream>
#include <iomanip>

void tabuada(int numero) {
    constexpr int INICIO_TABUADA = 1;
    constexpr int FIM_TABUADA = 10;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nTabuada de soma de " << numero << ":\n";
    for (int i = INICIO_TABUADA; i <= FIM_TABUADA; ++i) {
        std::cout << numero << " + " << i << " = " << (numero + i) << '\n';
    }

    std::cout << "\nTabuada de subtracao de " << numero << ":\n";
    for (int i = INICIO_TABUADA; i <= FIM_TABUADA; ++i) {
        std::cout << numero << " - " << i << " = " << (numero - i) << '\n';
    }

    std::cout << "\nTabuada de multiplicacao de " << numero << ":\n";
    for (int i = INICIO_TABUADA; i <= FIM_TABUADA; ++i) {
        std::cout << numero << " x " << i << " = " << (numero * i) << '\n';
    }

    std::cout << "\nTabuada de divisao de " << numero << ":\n";
    for (int i = INICIO_TABUADA; i <= FIM_TABUADA; ++i) {
        const double resultado = static_cast<double>(numero) / i;
        std::cout << numero << " / " << i << " = " << resultado << '\n';
    }
}

int main() {
    int numero = 0;

    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;

    tabuada(numero);

    return 0;
}
