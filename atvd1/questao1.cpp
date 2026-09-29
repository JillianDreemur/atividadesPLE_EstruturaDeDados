#include <iostream>

int main() {
    constexpr int IDADE_MAIORIDADE = 18;

    int anoNascimento = 0;
    int anoAtual = 0;

    std::cout << "Digite o ano de nascimento: ";
    std::cin >> anoNascimento;

    std::cout << "Digite o ano atual: ";
    std::cin >> anoAtual;

    const int idade = anoAtual - anoNascimento;

    std::cout << "Idade: " << idade << " anos\n";

    if (idade >= IDADE_MAIORIDADE) {
        std::cout << "Maior de idade\n";
    } else {
        std::cout << "Menor de idade\n";
    }

    return 0;
}
