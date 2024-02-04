#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "..\src\Avaliador.hpp"

Leilao emOrdemCrescente()
{
    Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 1000);
    Lance segundoLance = Lance(Usuario("Ana Maria"), 2000);
    Leilao leilao = Leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

Leilao emOrdemDecrescente()
{
    Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 2000);
    Lance segundoLance = Lance(Usuario("Ana Maria"), 1000);
    Leilao leilao = Leilao("Fiat 147 0km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);

    return leilao;
}

TEST_CASE("Avaliado")
{
    //Arrange
    Avaliador leiloeiro;

    SECTION("leiloes ordenados") {
        Leilao leilao = GENERATE(emOrdemCrescente(),emOrdemDecrescente());

        SECTION("Deve recuperar maior lance de leilao") {
            // Act
            leiloeiro.avalia(leilao);

            // Assert
            REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilao") {
            // Act
            leiloeiro.avalia(leilao);

            // Assert
            REQUIRE(1000 == leiloeiro.recuperaMenorValor());
        }
    }

    SECTION("Deve recuperar os 3 maiores lances") {
        // Arrange
        Lance primeiroLance = Lance(Usuario("Vinicius Dias"), 1000);
        Lance segundoLance = Lance(Usuario("Ana Maria"), 2000);
        Lance terceiroLance = Lance(Usuario("Adalberto"), 1500);
        Lance quartoLance = Lance(Usuario("Maria Cecilia"), 2500);
        Leilao leilao = Leilao("Fiat 147 0km");
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(segundoLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        Avaliador leiloeiro;

        // Act
        leiloeiro.avalia(leilao);

        // Assert
        std::vector<Lance> maiores3Lances = leiloeiro.recupera3MaioresLances();
        REQUIRE(3 == maiores3Lances.size());
        REQUIRE(1500 == maiores3Lances[2].recuperaValor());
        REQUIRE(2000 == maiores3Lances[1].recuperaValor());
        REQUIRE(2500 == maiores3Lances[0].recuperaValor());
    }
}

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

TEST_CASE("Usuario deve saber informar seu primeiro nome") {
    //Arrange
    Usuario vinicius = GENERATE("Vinicius Dias", "Vinicius");

    //Act
    std::string primeiroNome = vinicius.recuperaPrimeiroNome();

    //Assert
    REQUIRE("Vinicius" == primeiroNome);
}