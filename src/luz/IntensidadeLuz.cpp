#include "luz/IntensidadeLuz.hpp"
#include <stdexcept>

IntensidadeLuz::IntensidadeLuz(double r, double g, double b) {

    this->r = r;
    this->g = g;
    this->b = b;
    this->consertar();

}

IntensidadeLuz::IntensidadeLuz(double valor) {

    for (int i = 0; i < 3; i++) {

        this->operator[](i) = valor;

    }
    this->consertar();

}

IntensidadeLuz::IntensidadeLuz(rgb cor_rgb) {

    this->r = ((double) cor_rgb[0]) / 255.0;
    this->g = ((double) cor_rgb[1]) / 255.0;
    this->b = ((double) cor_rgb[2]) / 255.0;

    this->consertar();

}

double IntensidadeLuz::operator [] (std::size_t canal) const {

    if (canal >= 0 && canal < 3) {

        if (canal == 0) {

            return this->r;

        } else if (canal == 1) {

            return this->g;

        } else {

            return this->b;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a um canal inválido de uma intesidade de luz!");

    }

}

double& IntensidadeLuz::operator [] (std::size_t canal) {

    if (canal >= 0 && canal < 3) {

        if (canal == 0) {

            return this->r;

        } else if (canal == 1) {

            return this->g;

        } else {

            return this->b;

        }

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a um canal inválido de uma intesidade de luz!");

    }

}

IntensidadeLuz IntensidadeLuz::operator + (IntensidadeLuz const& intensidade) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r + intensidade[0];
    resultado[1] = this->g + intensidade[1];
    resultado[2] = this->b + intensidade[2];

    resultado.consertar();

    return resultado;
}

IntensidadeLuz IntensidadeLuz::operator + (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r + escalar;
    resultado[1] = this->g + escalar;
    resultado[2] = this->b + escalar;

    resultado.consertar();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator - (IntensidadeLuz const& intensidade) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r - intensidade[0];
    resultado[1] = this->g - intensidade[1];
    resultado[2] = this->b - intensidade[2];

    resultado.consertar();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator - (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r - escalar;
    resultado[1] = this->g - escalar;
    resultado[2] = this->b - escalar;

    resultado.consertar();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator * (IntensidadeLuz const& intensidade) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r * intensidade[0];
    resultado[1] = this->g * intensidade[1];
    resultado[2] = this->b * intensidade[2];

    resultado.consertar();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator * (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r * escalar;
    resultado[1] = this->g * escalar;
    resultado[2] = this->b * escalar;

    resultado.consertar();

    return resultado;

}

rgb IntensidadeLuz::cor_rgb() const {

    rgb cor;

    cor[0] = (canal_RGB) (this->r * 255);
    cor[1] = (canal_RGB) (this->g * 255);
    cor[2] = (canal_RGB) (this->b * 255);

    return cor;

}

void IntensidadeLuz::consertar() {

    if (this->r < 0.0) this->r = 0.0;
    if (this->r > 1.0) this->r = 1.0;

    if (this->g < 0.0) this->g = 0.0;
    if (this->g > 1.0) this->g = 1.0;

    if (this->b < 0.0) this->b = 0.0;
    if (this->b > 1.0) this->b = 1.0;

}