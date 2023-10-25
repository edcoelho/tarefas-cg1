#include "algebra/Matriz.hpp"
#include <stdexcept>

bool Matriz::posicaoValida(std::size_t linha, std::size_t coluna) const {

    if (linha >= 0 && linha < this->numLinhas && coluna >= 0 && coluna < this->numColunas) {

        return true;

    } else {

        return false;

    }

}

Matriz::Matriz(size_t m, size_t n) {

    this->numLinhas = m;
    this->numColunas = n;

    this->elementos = std::vector<std::vector<double>> (m, std::vector<double> (n, 0));

}

Matriz::Matriz(size_t m, size_t n, std::vector<std::vector<double>> e) {

    this->numLinhas = m;
    this->numColunas = n;
    this->elementos = e;

}

double Matriz::operator () (std::size_t linha, std::size_t coluna) const {

    if (this->posicaoValida(linha, coluna)) {

        return this->elementos[linha][coluna];

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de uma matriz!");

    }

}

double& Matriz::operator () (std::size_t linha, std::size_t coluna) {

    if (this->posicaoValida(linha, coluna)) {

        return this->elementos[linha][coluna];

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de uma matriz!");

    }

}

Matriz Matriz::operator + (Matriz const& matriz) const {

    Matriz temp(this->numLinhas, this->numColunas);

    if (this->getNumColunas() == matriz.getNumColunas() && this->getNumLinhas() == matriz.getNumLinhas()) {

        for (std::size_t i = 0; i < this->numLinhas; i++)
            for (std::size_t j = 0; j < this->numColunas; j++)
                temp(i, j) = this->elementos[i][j] + matriz(i,j);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de somar duas matrizes de tamanhos diferentes!");

    }

}

Matriz Matriz::operator + (double const escalar) const {

    Matriz temp(this->numLinhas, this->numColunas);

    for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] + escalar;

    return temp;

}

Matriz Matriz::operator - (Matriz const& matriz) const {

    Matriz temp(this->numLinhas, this->numColunas);

    if (this->getNumColunas() == matriz.getNumColunas() && this->getNumLinhas() == matriz.getNumLinhas()) {

        for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] - matriz(i,j);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de subtrair duas matrizes de tamanhos diferentes!");

    }

}

Matriz Matriz::operator - (double const escalar) const {

    Matriz temp(this->numLinhas, this->numColunas);

    for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] - escalar;

    return temp;

}

Matriz Matriz::operator * (double const escalar) const {

    Matriz temp(this->numLinhas, this->numColunas);

    for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] * escalar;

    return temp;

}

Matriz Matriz::operator % (Matriz const& matriz) const {

    Matriz temp(this->numLinhas, this->numColunas);

    if (this->getNumColunas() == matriz.getNumColunas() && this->getNumLinhas() == matriz.getNumLinhas()) {

        for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] * matriz(i,j);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de fazer o produto de Hadamard de duas matrizes de tamanhos diferentes!");

    }

}

std::size_t Matriz::getNumLinhas() const {

    return this->numLinhas;

}
void Matriz::setNumLinhas(std::size_t m) {

    this->numLinhas = m;

}

std::size_t Matriz::getNumColunas() const {

    return this->numColunas;

}
void Matriz::setNumColunas(std::size_t n) {

    this->numColunas = n;

}

std::vector<std::vector<double>> Matriz::getElementos() const {

    return this->elementos;

}
void Matriz::setElementos(std::vector<std::vector<double>> e) {

    this->elementos = e;

}

double Matriz::cofator(std::size_t linha, std::size_t coluna) const {

    double cofator;
    int sinal;
    std::size_t i = 0, j = 0, i_linha = 0, j_linha = 0;
    Matriz sub_matriz(this->numLinhas - 1, this->numColunas - 1);

    if (this->numLinhas != this->numColunas) {

        throw std::invalid_argument("Erro: Não é possível calcular o cofator de um elemento de uma matriz não quadrada!");

    }

    if (!this->posicaoValida(linha, coluna)) {

        throw std::invalid_argument("Erro: Tentativa de calcular o cofator de um elemento em uma posição inválida de uma matriz!");

    }

    for (i = 0; i < this->numLinhas; i++) {

        if (i == linha) i++;

        if (i < this->numLinhas) {
            
            for (j = 0; j < this->numColunas; j++) {

                if (j == coluna) j++;

                if (j < this->numColunas) {

                    sub_matriz(i_linha, j_linha) = this->elementos[i][j];
                    j_linha++;

                }

            }

        }

        i_linha++;
        j_linha = 0;

    }

    cofator = sub_matriz.det();

    if ((linha + coluna) % 2 != 0)

        cofator = -1 * cofator;

    return cofator;

}

double Matriz::det() const {

    double determinante = 0.0;

    if (this->numLinhas != this->numColunas) {

        throw std::invalid_argument("Erro: Não é possível calcular o determinante de uma matriz não quadrada!");

    }

    if (this->numLinhas == 1) {
        
        determinante = this->elementos[0][0];
    
    } else if (this->numLinhas == 2) {

        determinante = (this->elementos[0][0] * this->elementos[1][1]) - (this->elementos[0][1] * this->elementos[1][0]);

    } else if (this->numLinhas == 3) {

        // Regra de Sarrus
        determinante = this->elementos[0][0] * this->elementos[1][1] * this->elementos[2][2] + this->elementos[0][1] * this->elementos[1][2] * this->elementos[2][0] + this->elementos[0][2] * this->elementos[1][0] * this->elementos[2][1] - this->elementos[0][2] * this->elementos[1][1] * this->elementos[2][0] - this->elementos[0][0] * this->elementos[1][2] * this->elementos[2][1] - this->elementos[0][1] * this->elementos[1][0] * this->elementos[2][2];

    } else {

        // Expansão por cofatores.
        for (std::size_t i = 0; i < this->numLinhas; i++) {

            determinante = determinante + this->elementos[i][0] * this->cofator(i, 0);

        }

    }

    return determinante;

}

Matriz Matriz::hadamard(Matriz const& matriz) const {

    Matriz temp(this->numLinhas, this->numColunas);

    for (std::size_t i = 0; i < this->numLinhas; i++)
        for (std::size_t j = 0; j < this->numColunas; j++)
            temp(i, j) = this->elementos[i][j] * matriz(i,j);

    return temp;

}