#include <iostream>

int main() {
    constexpr int QUANTIDADE_NUMEROS = 10;

    int quantidadePares = 0;
    int quantidadeImpares = 0;
    int soma = 0;

    for (int i = 1; i <= QUANTIDADE_NUMEROS; ++i) {
        int numero = 0;

        std::cout << "Digite o " << i << "o numero inteiro: ";
        std::cin >> numero;

        soma += numero;

        if (numero % 2 == 0) {
            ++quantidadePares;
        } else {
            ++quantidadeImpares;
        }
    }

    std::cout << "Quantidade de pares: " << quantidadePares << '\n';
    std::cout << "Quantidade de impares: " << quantidadeImpares << '\n';
    std::cout << "Soma de todos os numeros: " << soma << '\n';

    return 0;
}
