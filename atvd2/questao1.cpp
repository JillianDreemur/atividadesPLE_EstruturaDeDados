#include <iostream>

int somar(int valor1, int valor2) {
    return valor1 + valor2;
}

int main() {
    int numero1 = 0;
    int numero2 = 0;

    std::cout << "Digite o primeiro numero inteiro: ";
    std::cin >> numero1;

    std::cout << "Digite o segundo numero inteiro: ";
    std::cin >> numero2;

    const int resultado = somar(numero1, numero2);

    std::cout << "Resultado da soma: " << resultado << '\n';

    return 0;
}
