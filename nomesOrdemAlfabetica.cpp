#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int qtdNomes, i;
    std::cout << "Digite a quantidade de nomes: " << std::endl;
    std::cin >> qtdNomes;

    std::vector<std::string> nomes(qtdNomes);
    std::vector<std::string> primeiraLetra(qtdNomes);

    std::vector<std::string> letras[26]; // Vetor de vetores para armazenar os nomes de cada letra

    for (i = 0; i < qtdNomes; i++) {
        std::cout << "Digite o " << i + 1 << "° nome" << std::endl;
        std::cin >> nomes[i];

        primeiraLetra[i] = nomes[i].substr(0, 1);

        char letra = primeiraLetra[i][0];
        if (letra >= 'a' && letra <= 'z') {
            letras[letra - 'a'].push_back(nomes[i]); // Adiciona o nome ao vetor correspondente à primeira letra
        }
    }

    // Ordena os nomes em cada vetor de letras
    for (auto& vetorLetras : letras) {
        std::sort(vetorLetras.begin(), vetorLetras.end());
    }

    // Imprime os nomes em ordem alfabética
    for (const auto& vetorLetras : letras) {
        for (const auto& nome : vetorLetras) {
            std::cout << nome << std::endl;
        }
    }

    return 0;
}

