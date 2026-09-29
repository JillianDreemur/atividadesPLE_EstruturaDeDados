#include <iostream>
#include <string>

std::string verificarPar(int numero) {
    if (numero % 2 == 0) {
        return "par";
    }

    return "impar";
}

int main() {
    int numero = 0;

    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;

    const std::string resultado = verificarPar(numero);

    std::cout << "O numero " << numero << " e " << resultado << '\n';

    return 0;
}
