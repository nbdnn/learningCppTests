#pragma once

#include "Leilao.hpp"
#include <vector>

class Avaliador
{
private:
    float maiorValor = INT_MIN;
    float menorValor = INT_MAX;
public:
    void avalia(Leilao);
    float recuperaMaiorValor() const;
    float recuperaMenorValor() const;
};