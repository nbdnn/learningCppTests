#include "Avaliador.hpp"

void Avaliador::avalia(Leilao leilao)
{
    maiorValor = 0;

    std::vector<Lance> lances = leilao.recuperaLances();

    for (Lance lance : lances){
        if (lance.recuperaValor() > maiorValor) {
            maiorValor = lance.recuperaValor();
        }
        if (lance.recuperaValor() < menorValor) {
            menorValor = lance.recuperaValor();
        }
    }
}

float Avaliador::recuperaMaiorValor() const
{
    return maiorValor;
}

float Avaliador::recuperaMenorValor() const
{
    return menorValor;
}