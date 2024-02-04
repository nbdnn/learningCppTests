#pragma once

#include "Leilao.hpp"
#include <vector>

class Avaliador
{
private:
    float maiorValor = INT_MIN;
    float menorValor = INT_MAX;
    std::vector<Lance>  miores3Lances;
    static bool ordenaLances(const Lance&, const Lance&);
public:
    void avalia(Leilao);
    float recuperaMaiorValor() const;
    float recuperaMenorValor() const;
    std::vector<Lance> recupera3MaioresLances() const;
};