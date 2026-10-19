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

    std::vector<int> comuns;
    for (int valor : primeiro) {
        if (buscaSequencial(segundo, valor) && !buscaSequencial(comuns, valor)) {
            comuns.push_back(valor);
        }
    }

    std::cout << "\nValores que aparecem nos dois vetores (sem repeticao):\n";
    if (comuns.empty()) {
        std::cout << "Nenhum valor em comum.\n";
    } else {
        for (std::size_t i = 0; i < comuns.size(); ++i) {
            std::cout << comuns[i];
            if (i + 1 < comuns.size()) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
