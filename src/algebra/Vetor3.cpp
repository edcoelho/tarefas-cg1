#include "algebra/Vetor3.hpp"
#include "algebra/Ponto3.hpp"
#include <stdexcept>
#include <cmath>

Vetor3::Vetor3(double valor) {

    std::size_t i;

    for (i = 0; i < 3; i++)
        this->operator[](i) = valor;

}

Vetor3::Vetor3(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;

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

    Vetor3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) + vetor[i];

    return resultado;

}

Vetor3 Vetor3::operator - (Vetor3 const& vetor) const {

    Vetor3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) - vetor[i];

    return resultado;

}

Vetor3 Vetor3::operator * (Vetor3 const vetor) const {

    Vetor3 resultado(0.0);

    resultado[0] = (this->y * vetor[2]) - (this->z * vetor[1]);
    resultado[1] = (this->z * vetor[0]) - (this->x * vetor[2]);
    resultado[2] = (this->x * vetor[1]) - (this->y * vetor[0]);

    return resultado;

}

Vetor3 Vetor3::operator * (double const escalar) const {

    Vetor3 resultado(0.0);
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado[i] = this->operator[](i) * escalar;

    return resultado;

}

bool Vetor3::operator == (Vetor3 const& vetor) const {

    std::size_t i;

    for (i = 0; i < 3; i++)
        if (this->operator[](i) != vetor[i])
            return false;

    return true;

}

bool Vetor3::operator != (Vetor3 const& vetor) const {

    return !(this->operator==(vetor));

}

double Vetor3::norma() const {

    double norma = 0.0;
    std::size_t i;

    for (i = 0; i < 3; i++)
        norma = norma + this->operator[](i) * this->operator[](i);

    return std::sqrt(norma);

}

void Vetor3::normalizar() {

    double norma = this->norma();
    std::size_t i;

    for (i = 0; i < 3; i++)
        this->operator[](i) = this->operator[](i)/norma;

}

Ponto3 Vetor3::ponto() const {

    return Ponto3(this->x, this->y, this->z);

}

Vetor3 Vetor3::unitario() const {

    Vetor3 vetor(this->x, this->y, this->z);
    double norma = vetor.norma();
    std::size_t i;

    for (i = 0; i < 3; i++)
        vetor[i] = vetor[i]/norma;

    return vetor;

};

double Vetor3::escalar(Vetor3 vetor) const {

    double resultado = 0.0;
    std::size_t i;

    for (i = 0; i < 3; i++)
        resultado = resultado + this->operator[](i) * vetor[i];

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