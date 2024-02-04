#include "catch.hpp"
#include "..\src\Leilao.hpp"

TEST_CASE("Leilao nao deve receber lances consecutivos do mesmo usuario") {
    // Arrange
    Leilao leilao("Fiat 147 0km");
    Usuario vinicius("Vinicius Dias");

    Lance primeiroLance(vinicius, 1000);
    Lance segundoLance(vinicius, 1500);

    //Act
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    //Assert
    REQUIRE(1 == leilao.recuperaLances().size());
    REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}