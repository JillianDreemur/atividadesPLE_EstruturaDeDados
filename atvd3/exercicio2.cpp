#include <iostream>
#include <vector>

int main() {
    constexpr int TAM = 5;
    std::vector<int> numeros(TAM);

    std::cout << "Digite " << TAM << " numeros inteiros:\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> numeros[i];
    }

    int soma = 0;
    int subtracao = numeros[0];
    long long multiplicacao = 1;

    for (int i = 0; i < TAM; ++i) {
        soma += numeros[i];
        multiplicacao *= numeros[i];
        if (i > 0) {
            subtracao -= numeros[i];
        }
    }

    std::cout << "\nSoma de todos os itens: " << soma << "\n";
    std::cout << "Subtracao entre todos os itens: " << subtracao << "\n";
    std::cout << "Multiplicacao de todos os itens: " << multiplicacao << "\n";

    return 0;
}
