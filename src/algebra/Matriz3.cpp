#include "algebra/Matriz3.hpp"
#include <stdexcept>

Matriz3::Matriz3() {

    std::size_t i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->elementos[i][j] = 0.0;

        }

    }

}

Matriz3::Matriz3(double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22) {

    this->elementos[0][0] = a00;
    this->elementos[0][1] = a01;
    this->elementos[0][2] = a02;

    this->elementos[1][0] = a10;
    this->elementos[1][1] = a11;
    this->elementos[1][2] = a12;

    this->elementos[2][0] = a20;
    this->elementos[2][1] = a21;
    this->elementos[2][2] = a22;

}

Matriz3::Matriz3(std::array<std::array<double, 3>, 3> e) {

    this->elementos = e;

}

double Matriz3::operator () (std::size_t linha, std::size_t coluna) const {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        return this->elementos[linha][coluna];

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de uma Matriz3!");

    }

}

double& Matriz3::operator () (std::size_t linha, std::size_t coluna) {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        return this->elementos[linha][coluna];

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de uma Matriz3!");

    }

}

Matriz3 Matriz3::operator + (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] + matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator + (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] + escalar;

    return resultado;

}

Matriz3 Matriz3::operator - (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] - matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator - (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] - escalar;

    return resultado;

}

Matriz3 Matriz3::operator * (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] * escalar;

    return resultado;

}

Matriz3 Matriz3::operator % (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] * matriz(i,j);

    return resultado;

}

std::array<std::array<double, 3>, 3> Matriz3::get_elementos() const {

    return this->elementos;

}
void Matriz3::set_elementos(std::array<std::array<double, 3>, 3> e) {

    this->elementos = e;

}

double Matriz3::det() const {

    double determinante;

    // Regra de Sarrus
    determinante = this->elementos[0][0] * this->elementos[1][1] * this->elementos[2][2] + this->elementos[0][1] * this->elementos[1][2] * this->elementos[2][0] + this->elementos[0][2] * this->elementos[1][0] * this->elementos[2][1] - this->elementos[0][2] * this->elementos[1][1] * this->elementos[2][0] - this->elementos[0][0] * this->elementos[1][2] * this->elementos[2][1] - this->elementos[0][1] * this->elementos[1][0] * this->elementos[2][2];

    return determinante;

}

Matriz3 Matriz3::hadamard(Matriz3 const& matriz) const {

    Matriz3 resultado;

    for (std::size_t i = 0; i < 3; i++)
        for (std::size_t j = 0; j < 3; j++)
            resultado(i, j) = this->elementos[i][j] * matriz(i,j);

    return resultado;

}