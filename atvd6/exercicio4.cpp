#include <iostream>
#include <vector>

bool buscaSequencial(const std::vector<int>& v, int valor) {
    for (int elemento : v) {
        if (elemento == valor) {
            return true;
        }
    }
    return false;
}

std::vector<int> lerVetor(const char* nome) {
    int tam = 0;
    std::cout << "Tamanho do " << nome << ": ";
    std::cin >> tam;

    std::vector<int> v(tam);
    std::cout << "Digite os " << tam << " elementos do " << nome << ":\n";
    for (int i = 0; i < tam; ++i) {
        std::cout << "Posicao [" << i << "]: ";
        std::cin >> v[i];
    }
    return v;
}

int main() {
    std::vector<int> primeiro = lerVetor("primeiro vetor");
    std::vector<int> segundo = lerVetor("segundo vetor");

    std::vector<int> exclusivos;
    for (int valor : primeiro) {
        if (!buscaSequencial(segundo, valor) && !buscaSequencial(exclusivos, valor)) {
            exclusivos.push_back(valor);
        }
    }

    std::cout << "\nValores do primeiro vetor que nao estao no segundo (sem repeticao):\n";
    if (exclusivos.empty()) {
        std::cout << "Nenhum valor exclusivo.\n";
    } else {
        for (std::size_t i = 0; i < exclusivos.size(); ++i) {
            std::cout << exclusivos[i];
            if (i + 1 < exclusivos.size()) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "Quantidade de valores exclusivos: " << exclusivos.size() << "\n";

    return 0;
}
