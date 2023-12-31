#include "algebra/Ponto3.hpp"
#include <stdexcept>

Ponto3::Ponto3(double valor) {

    std::size_t i;

    for (i = 0; i < 3; i++)
        this->operator[](i) = valor;

}

Ponto3::Ponto3(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;

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

Ponto3 Ponto3::operator + (Vetor3 const& vetor)  const {

    Ponto3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) + vetor[i];

    return resultado;

}

Ponto3 Ponto3::operator - (Vetor3 const& vetor) const {

    Ponto3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) - vetor[i];

    return resultado;

}

Vetor3 Ponto3::operator - (Ponto3 const& ponto) const {

    Vetor3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) - ponto[i];

    return resultado;

}

bool Ponto3::operator == (Ponto3 const& ponto) const {

    std::size_t i;

    for (i = 0; i < 3; i++)
        if (this->operator[](i) != ponto[i])
            return false;

    return true;

}

bool Ponto3::operator != (Ponto3 const& ponto) const {

    return !(this->operator==(ponto));

}

Vetor3 Ponto3::vetor() const {

    return Vetor3(this->x, this->y, this->z);

}