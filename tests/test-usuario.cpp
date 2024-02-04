#include "catch.hpp"
#include "..\src\Usuario.hpp"

TEST_CASE("Usuario deve saber informar seu primeiro nome") {
    //Arrange
    Usuario vinicius = GENERATE("Vinicius Dias", "Vinicius");

    //Act
    std::string primeiroNome = vinicius.recuperaPrimeiroNome();

    //Assert
    REQUIRE("Vinicius" == primeiroNome);
}