#include "algebra/Matriz3.hpp"
#include <stdexcept>

Matriz3::Matriz3() {

    std::size_t i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->operator()(i, j) = 0.0;

        }

    }

}

Matriz3::Matriz3(double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22) {

    this->a00 = a00;
    this->a01 = a01;
    this->a02 = a02;

    this->a10 = a10;
    this->a11 = a11;
    this->a12 = a12;

    this->a20 = a20;
    this->a21 = a21;
    this->a22 = a22;

}

Matriz3::Matriz3(std::array<std::array<double, 3>, 3> e) {

    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            this->operator()(i, j) = e[i][j];

}

double Matriz3::operator () (std::size_t linha, std::size_t coluna) const {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        if (linha == 0) {

            if (coluna == 0) return this->a00;
            if (coluna == 1) return this->a01;
            if (coluna == 2) return this->a02;

        } else if (linha == 1) {

            if (coluna == 0) return this->a10;
            if (coluna == 1) return this->a11;
            if (coluna == 2) return this->a12;

        } else {

            if (coluna == 0) return this->a20;
            if (coluna == 1) return this->a21;
            if (coluna == 2) return this->a22;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de uma Matriz3!");

    }

    // Retorno para acalmar o compilador.
    return this->a00;

}

double& Matriz3::operator () (std::size_t linha, std::size_t coluna) {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        if (linha == 0) {

            if (coluna == 0) return this->a00;
            if (coluna == 1) return this->a01;
            if (coluna == 2) return this->a02;

        } else if (linha == 1) {

            if (coluna == 0) return this->a10;
            if (coluna == 1) return this->a11;
            if (coluna == 2) return this->a12;

        } else {

            if (coluna == 0) return this->a20;
            if (coluna == 1) return this->a21;
            if (coluna == 2) return this->a22;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de uma Matriz3!");

    }

    // Retorno para acalmar o compilador.
    return this->a00;

}

Matriz3 Matriz3::operator + (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) + matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator + (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) + escalar;

    return resultado;

}

Matriz3 Matriz3::operator - (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) - matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator - (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) - escalar;

    return resultado;

}

Matriz3 Matriz3::operator * (Matriz3 const& matriz) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, 0) * matriz(0, j) + this->operator()(i, 1) * matriz(1, j) + this->operator()(i, 2) * matriz(2, j);

    return resultado;

}

Vetor3 Matriz3::operator * (Vetor3 const& vetor) const {

    Vetor3 resultado;
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator()(i, 0) * vetor[0] + this->operator()(i, 1) * vetor[1] + this->operator()(i, 2) * vetor[2];

    return resultado;

}

Matriz3 Matriz3::operator * (double const escalar) const {

    Matriz3 resultado;
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) * escalar;

    return resultado;

}

double Matriz3::det() const {

    double determinante;

    // Regra de Sarrus
    determinante = this->a00 * this->a11 * this->a22 + this->a01 * this->a12 * this->a20 + this->a02 * this->a10 * this->a21 - this->a02 * this->a11 * this->a20 - this->a00 * this->a12 * this->a21 - this->a01 * this->a10 * this->a22;

    return determinante;

}