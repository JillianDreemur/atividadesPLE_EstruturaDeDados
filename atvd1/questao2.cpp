#include <iostream>
#include <iomanip>

int main() {
    constexpr double MEDIA_APROVACAO = 7.0;
    constexpr double MEDIA_RECUPERACAO = 5.0;
    constexpr int QUANTIDADE_NOTAS = 3;

    double nota1 = 0.0;
    double nota2 = 0.0;
    double nota3 = 0.0;

    std::cout << "Digite a primeira nota: ";
    std::cin >> nota1;

    std::cout << "Digite a segunda nota: ";
    std::cin >> nota2;

    std::cout << "Digite a terceira nota: ";
    std::cin >> nota3;

    const double media = (nota1 + nota2 + nota3) / QUANTIDADE_NOTAS;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Media: " << media << '\n';

    if (media >= MEDIA_APROVACAO) {
        std::cout << "Aprovado\n";
    } else if (media >= MEDIA_RECUPERACAO) {
        std::cout << "Recuperacao\n";
    } else {
        std::cout << "Reprovado\n";
    }

    return 0;
}
