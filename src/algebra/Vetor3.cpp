#include "algebra/Vetor3.hpp"
#include "algebra/Ponto3.hpp"
#include <stdexcept>
#include <cmath>

Vetor3::Vetor3() {

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

}

Vetor3::Vetor3(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;

}

Vetor3::Vetor3(std::array<double, 3> e) {

    this->x = e[0];
    this->y = e[1];
    this->z = e[2];

}

double Vetor3::operator [] (std::size_t indice) const {

    if (indice >= 0 && indice < 3) {

        if (indice == 0) {

            return this->x;

        } else if (indice == 1) {

            return this->y;

        } else {

            return this->z;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a um índice inválido de um Vetor3.");

    }


}

double& Vetor3::operator [] (std::size_t indice) {

    if (indice >= 0 && indice < 3) {

        if (indice == 0) {

            return this->x;

        } else if (indice == 1) {

            return this->y;

        } else {

            return this->z;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a um índice inválido de um Vetor3.");

    }

}

Vetor3 Vetor3::operator + (Vetor3 const& vetor) const {

    Vetor3 resultado;

    resultado[0] = this->x + vetor[0];
    resultado[1] = this->y + vetor[1];
    resultado[2] = this->z + vetor[2];

    return resultado;

}

Vetor3 Vetor3::operator + (double const escalar) const {

    Vetor3 resultado;

    resultado[0] = this->x + escalar;
    resultado[1] = this->y + escalar;
    resultado[2] = this->z + escalar;

    return resultado;

}

Vetor3 Vetor3::operator - (Vetor3 const& vetor) const {

    Vetor3 resultado;

    resultado[0] = this->x - vetor[0];
    resultado[1] = this->y - vetor[1];
    resultado[2] = this->z - vetor[2];

    return resultado;

}

Vetor3 Vetor3::operator - (double const escalar) const {

    Vetor3 resultado;

    resultado[0] = this->x - escalar;
    resultado[1] = this->y - escalar;
    resultado[2] = this->z - escalar;

    return resultado;

}

Vetor3 Vetor3::operator * (Vetor3 const vetor) const {

    Vetor3 resultado;

    resultado[0] = (this->y * vetor[2]) - (this->z * vetor[1]);
    resultado[1] = (this->z * vetor[0]) - (this->x * vetor[2]);
    resultado[2] = (this->x * vetor[1]) - (this->y * vetor[0]);

    return resultado;

}

Vetor3 Vetor3::operator * (double const escalar) const {

    Vetor3 resultado;

    resultado[0] = this->x * escalar;
    resultado[1] = this->y * escalar;
    resultado[2] = this->z * escalar;

    return resultado;

}

double Vetor3::norma() const {

    double norma;

    norma = this->x * this->x;
    norma = norma + (this->y * this->y);
    norma = norma + (this->z * this->z);

    return std::sqrt(norma);

}

void Vetor3::normalizar() {

    double norma;

    norma = this->norma();

    this->x = this->x / norma;
    this->y = this->y / norma;
    this->z = this->z / norma;

}

Ponto3 Vetor3::ponto() const {

    return Ponto3(this->x, this->y, this->z);

}

Vetor3 Vetor3::unitario() const {

    Vetor3 vetor(this->x, this->y, this->z);
    double norma = vetor.norma();

    vetor[0] = this->x / norma;
    vetor[1] = this->y / norma;
    vetor[2] = this->z / norma;

    return vetor;

};

double Vetor3::escalar(Vetor3 vetor) const {

    double resultado;

    resultado = this->x * vetor[0];
    resultado = resultado + this->y * vetor[1];
    resultado = resultado + this->z * vetor[2];

    return resultado;

}

Vetor3 Vetor3::vetorial(Vetor3 vetor) const {

    Vetor3 resultado;

    resultado[0] = (this->y * vetor[2]) - (this->z * vetor[1]);
    resultado[1] = (this->z * vetor[0]) - (this->x * vetor[2]);
    resultado[2] = (this->x * vetor[1]) - (this->y * vetor[0]);

    return resultado;

}

Vetor3 Vetor3::reflexo(Vetor3 v) const {

    v.normalizar();

    return (v * 2.0 * this->escalar(v)) - *this;

}