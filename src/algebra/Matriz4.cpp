#include "algebra/Matriz4.hpp"
#include <stdexcept>

Matriz4::Matriz4() {

    std::size_t i, j;

    for (i = 0; i < 4; i++) {

        for (j = 0; j < 4; j++) {
            
            if (i == j)
                this->operator()(i, j) = 1.0;
            else
                this->operator()(i, j) = 0.0;

        }    

    }

}

Matriz4::Matriz4(double a00, double a01, double a02, double a03, double a10, double a11, double a12, double a13, double a20, double a21, double a22, double a23, double a30, double a31, double a32, double a33) {

    this->a00 = a00;
    this->a01 = a01;
    this->a02 = a02;
    this->a03 = a03;

    this->a10 = a10;
    this->a11 = a11;
    this->a12 = a12;
    this->a13 = a13;

    this->a20 = a20;
    this->a21 = a21;
    this->a22 = a22;
    this->a23 = a23;

    this->a30 = a20;
    this->a31 = a31;
    this->a32 = a32;
    this->a33 = a33;

}

Matriz4::Matriz4(double valor) {

    std::size_t i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            this->operator()(i, j) = valor;

}

double Matriz4::operator () (std::size_t linha, std::size_t coluna) const {

    if (linha >= 0 && linha < 4 && coluna >= 0 && coluna < 4) {

        if (linha == 0) {

            if (coluna == 0) {
                
                return this->a00;
                
            } else if (coluna == 1) {
                
                return this->a01;
                
            } else if (coluna == 2) {
                
                return this->a02;
                
            } else {

                return this->a03;

            }

        } else if (linha == 1) {

            if (coluna == 0) {
                
                return this->a10;
                
            } else if (coluna == 1) {
                
                return this->a11;
                
            } else if (coluna == 2) {
                
                return this->a12;
                
            } else {

                return this->a13;

            }

        } else if (linha == 2) {

            if (coluna == 0) {
                
                return this->a20;
                
            } else if (coluna == 1) {
                
                return this->a21;
                
            } else if (coluna == 2) {
                
                return this->a22;
                
            } else {

                return this->a23;

            }

        } else {

            if (coluna == 0) {
                
                return this->a30;
                
            } else if (coluna == 1) {
                
                return this->a31;
                
            } else if (coluna == 2) {
                
                return this->a32;
                
            } else {

                return this->a33;

            }

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de uma Matriz4!");

    }

}

double& Matriz4::operator () (std::size_t linha, std::size_t coluna) {

    if (linha >= 0 && linha < 4 && coluna >= 0 && coluna < 4) {

        if (linha == 0) {

            if (coluna == 0) {
                
                return this->a00;
                
            } else if (coluna == 1) {
                
                return this->a01;
                
            } else if (coluna == 2) {
                
                return this->a02;
                
            } else {

                return this->a03;

            }

        } else if (linha == 1) {

            if (coluna == 0) {
                
                return this->a10;
                
            } else if (coluna == 1) {
                
                return this->a11;
                
            } else if (coluna == 2) {
                
                return this->a12;
                
            } else {

                return this->a13;

            }

        } else if (linha == 2) {

            if (coluna == 0) {
                
                return this->a20;
                
            } else if (coluna == 1) {
                
                return this->a21;
                
            } else if (coluna == 2) {
                
                return this->a22;
                
            } else {

                return this->a23;

            }

        } else {

            if (coluna == 0) {
                
                return this->a30;
                
            } else if (coluna == 1) {
                
                return this->a31;
                
            } else if (coluna == 2) {
                
                return this->a32;
                
            } else {

                return this->a33;

            }

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de uma Matriz4!");

    }

}

Matriz4 Matriz4::operator + (Matriz4 const& matriz) const {

    Matriz4 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            resultado(i, j) = this->operator()(i, j) + matriz(i,j);

    return resultado;

}

Matriz4 Matriz4::operator - (Matriz4 const& matriz) const {

    Matriz4 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            resultado(i, j) = this->operator()(i, j) - matriz(i,j);

    return resultado;

}

Matriz4 Matriz4::operator * (Matriz4 const& matriz) const {

    Matriz4 resultado(0.0);
    std::size_t i, j, k;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                resultado(i, j) = resultado(i, j) + this->operator()(i, k) * matriz(k, j);

    return resultado;

}

Ponto3 Matriz4::operator * (Ponto3 const& ponto) const {

    Ponto3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            resultado[i] = resultado[i] + this->operator()(i, j) * ponto[j];

        }

        resultado[i] = resultado[i] + this->operator()(i, 3);

    }

    return resultado;

}

Vetor3 Matriz4::operator * (Vetor3 const& vetor) const {

    Vetor3 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            resultado[i] = resultado[i] + this->operator()(i, j) * vetor[j];

        }

    }

    return resultado;

}

Matriz4 Matriz4::operator * (double const escalar) const {

    Matriz4 resultado(0.0);
    std::size_t i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            resultado(i, j) = this->operator()(i, j) * escalar;

    return resultado;

}

bool Matriz4::operator == (Matriz4 const& matriz) const {

    std::size_t i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (this->operator()(i, j) != matriz(i, j))
                return false;

    return true;

}

bool Matriz4::operator != (Matriz4 const& matriz) const {

    return !(this->operator==(matriz));

}