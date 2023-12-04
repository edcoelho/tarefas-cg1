#include "algebra/Matriz3.hpp"
#include <stdexcept>

Matriz3::Matriz3() {

    std::size_t i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            if (i == j)
                this->operator()(i, j) = 1.0;
            else
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

Matriz3::Matriz3(double valor) {

    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            this->operator()(i, j) = valor;

}

double Matriz3::operator () (std::size_t linha, std::size_t coluna) const {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        if (linha == 0) {

            if (coluna == 0) {
                
                return this->a00;
                
            } else if (coluna == 1) {
                
                return this->a01;
                
            } else {
                
                return this->a02;
                
            }

        } else if (linha == 1) {

            if (coluna == 0) {
                
                return this->a10;
                
            } else if (coluna == 1) {
                
                return this->a11;
                
            } else {
                
                return this->a12;
                
            }

        } else {

            if (coluna == 0) {
                
                return this->a20;
                
            } else if (coluna == 1) {
                
                return this->a21;
                
            } else {
                
                return this->a22;
                
            }

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de uma Matriz3!");

    }

}

double& Matriz3::operator () (std::size_t linha, std::size_t coluna) {

    if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {

        if (linha == 0) {

            if (coluna == 0) {
                
                return this->a00;
                
            } else if (coluna == 1) {
                
                return this->a01;
                
            } else {
                
                return this->a02;
                
            }

        } else if (linha == 1) {

            if (coluna == 0) {
                
                return this->a10;
                
            } else if (coluna == 1) {
                
                return this->a11;
                
            } else {
                
                return this->a12;
                
            }

        } else {

            if (coluna == 0) {
                
                return this->a20;
                
            } else if (coluna == 1) {
                
                return this->a21;
                
            } else {
                
                return this->a22;
                
            }

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de uma Matriz3!");

    }

}

Matriz3 Matriz3::operator + (Matriz3 const& matriz) const {

    Matriz3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) + matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator - (Matriz3 const& matriz) const {

    Matriz3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) - matriz(i,j);

    return resultado;

}

Matriz3 Matriz3::operator * (Matriz3 const& matriz) const {

    Matriz3 resultado(0.0);
    std::size_t i, j, k;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                resultado(i, j) = resultado(i, j) + this->operator()(i, k) * matriz(k, j);

    return resultado;

}

Vetor3 Matriz3::operator * (Vetor3 const& vetor) const {

    Vetor3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado[i] = resultado[i] + this->operator()(i, j) * vetor[j];

    return resultado;

}

Ponto3 Matriz3::operator * (Ponto3 const& ponto) const {

    Ponto3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado[i] = resultado[i] + this->operator()(i, j) * ponto[j];

    return resultado;

}

Matriz3 Matriz3::operator * (double const escalar) const {

    Matriz3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            resultado(i, j) = this->operator()(i, j) * escalar;

    return resultado;

}
