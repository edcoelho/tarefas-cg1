#include "algebra/Ponto3.hpp"
#include <stdexcept>

Ponto3::Ponto3() {

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;

}

Ponto3::Ponto3(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;

}

Ponto3::Ponto3(std::array<double, 3> c) {

    this->x = c[0];
    this->y = c[1];
    this->z = c[2];

}

double Ponto3::operator [] (std::size_t coordenada) const {

    if (coordenada >= 0 && coordenada < 3) {

        if (coordenada == 0) {

            return this->x;

        } else if (coordenada == 1) {

            return this->y;

        } else {

            return this->z;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma coordenada inválida de um Ponto3.");

    }

}

double& Ponto3::operator [] (std::size_t coordenada) {

    if (coordenada >= 0 && coordenada < 3) {

        if (coordenada == 0) {

            return this->x;

        } else if (coordenada == 1) {

            return this->y;

        } else {

            return this->z;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma coordenada inválida de um Ponto3.");

    }

}

Ponto3 Ponto3::operator + (Vetor3 vetor)  const {

    Ponto3 temp;

    temp[0] = this->x + vetor[0];
    temp[1] = this->y + vetor[1];
    temp[2] = this->z + vetor[2];

    return temp;

}

Ponto3 Ponto3::operator - (Vetor3 vetor) const {

    Ponto3 temp;

    temp[0] = this->x - vetor[0];
    temp[1] = this->y - vetor[1];
    temp[2] = this->z - vetor[2];

    return temp;

}

Vetor3 Ponto3::operator - (Ponto3 ponto) const {

    Vetor3 temp;

    temp[0] = this->x - ponto[0];
    temp[1] = this->y - ponto[1];
    temp[2] = this->z - ponto[2];

    return temp;

}

std::array<double, 3> Ponto3::std_array() const {

    std::array<double, 3> a;

    a[0] = this->x;
    a[1] = this->y;
    a[2] = this->z;

    return a;

}

Vetor3 Ponto3::vetor() const {

    return Vetor3(this->x, this->y, this->z);

}