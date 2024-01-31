#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "..\src\Avaliador.hpp"

TEST_CASE("Deve recuperar maior lance de leilao em ordem crescente") {
    // Arrange
     Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 1000);
     Lance segundoLance = Lance(Usuario("Ana Maria"), 2000);
     Leilao leilao = Leilao("Fiat 147 0km");
     leilao.recebeLance(primeiroLance);
     leilao.recebeLance(segundoLance);

     Avaliador leiloeiro;

     // Act
     leiloeiro.avalia(leilao);

     // Assert
     REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar maior lance de leilao em ordem decrescente") {
    // Arrange
     Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 2000);
     Lance segundoLance = Lance(Usuario("Ana Maria"), 1000);
     Leilao leilao = Leilao("Fiat 147 0km");
     leilao.recebeLance(primeiroLance);
     leilao.recebeLance(segundoLance);

     Avaliador leiloeiro;

     // Act
     leiloeiro.avalia(leilao);

     // Assert
     REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilao em ordem decrescente") {
    // Arrange
     Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 2000);
     Lance segundoLance = Lance(Usuario("Ana Maria"), 1000);
     Leilao leilao = Leilao("Fiat 147 0km");
     leilao.recebeLance(primeiroLance);
     leilao.recebeLance(segundoLance);

     Avaliador leiloeiro;

     // Act
     leiloeiro.avalia(leilao);

     // Assert
     REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar menor lance de leilao em ordem crescente") {
    // Arrange
     Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 1000);
     Lance segundoLance = Lance(Usuario("Ana Maria"), 2000);
     Leilao leilao = Leilao("Fiat 147 0km");
     leilao.recebeLance(primeiroLance);
     leilao.recebeLance(segundoLance);

     Avaliador leiloeiro;

     // Act
     leiloeiro.avalia(leilao);

     // Assert
     REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}