#include <cctype>
#include <iostream>
#include <vector>

bool ehVogal(char c) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool ehConsoante(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return std::isalpha(uc) && !ehVogal(c);
}

int main() {
    constexpr int TAM = 10;
    std::vector<char> caracteres(TAM);

    std::cout << "Digite " << TAM << " caracteres (um por vez):\n";
    for (int i = 0; i < TAM; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> caracteres[i];
    }

    int qtdConsoantes = 0;
    for (char c : caracteres) {
        if (ehConsoante(c)) {
            ++qtdConsoantes;
        }
    }

    std::cout << "\nQuantidade de consoantes lidas: " << qtdConsoantes << "\n";

    return 0;
}
