#include "utils/IntensidadeLuz.hpp"
#include <stdexcept>

IntensidadeLuz::IntensidadeLuz() {

    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;

}

IntensidadeLuz::IntensidadeLuz(double r, double g, double b) {

    this->r = r;
    this->g = g;
    this->b = b;
    this->consertaIntensidade();

}

IntensidadeLuz::IntensidadeLuz(std::array<double, 3> val) {

    this->r = val[0];
    this->g = val[1];
    this->b = val[2];
    this->consertaIntensidade();

}

IntensidadeLuz::IntensidadeLuz(rgb corRGB) {

    std::size_t i;

    this->r = ((double) corRGB[0]) / 255.0;
    this->g = ((double) corRGB[1]) / 255.0;
    this->b = ((double) corRGB[2]) / 255.0;

    this->consertaIntensidade();

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

    resultado.consertaIntensidade();

    return resultado;
}

IntensidadeLuz IntensidadeLuz::operator + (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r + escalar;
    resultado[1] = this->g + escalar;
    resultado[2] = this->b + escalar;

    resultado.consertaIntensidade();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator - (IntensidadeLuz const& intensidade) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r - intensidade[0];
    resultado[1] = this->g - intensidade[1];
    resultado[2] = this->b - intensidade[2];

    resultado.consertaIntensidade();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator - (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r - escalar;
    resultado[1] = this->g - escalar;
    resultado[2] = this->b - escalar;

    resultado.consertaIntensidade();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator * (IntensidadeLuz const& intensidade) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r * intensidade[0];
    resultado[1] = this->g * intensidade[1];
    resultado[2] = this->b * intensidade[2];

    resultado.consertaIntensidade();

    return resultado;

}

IntensidadeLuz IntensidadeLuz::operator * (double const escalar) const {

    IntensidadeLuz resultado;

    resultado[0] = this->r * escalar;
    resultado[1] = this->g * escalar;
    resultado[2] = this->b * escalar;

    resultado.consertaIntensidade();

    return resultado;

}

double IntensidadeLuz::getR() const {

    return this->r;

}
void IntensidadeLuz::setR(double r) {

    this->r = r;

}

double IntensidadeLuz::getG() const {

    return this->g;

}
void IntensidadeLuz::setG(double g) {

    this->g = g;

}

double IntensidadeLuz::getB() const {

    return this->b;

}
void IntensidadeLuz::setB(double b) {

    this->b = b;

}

rgb IntensidadeLuz::paraRGB() const {

    rgb cor;

    cor[0] = (canalRGB) (this->r * 255);
    cor[1] = (canalRGB) (this->g * 255);
    cor[2] = (canalRGB) (this->b * 255);

    return cor;

}

void IntensidadeLuz::consertaIntensidade() {

    if (this->r < 0.0) this->r = 0.0;
    if (this->r > 1.0) this->r = 1.0;

    if (this->g < 0.0) this->g = 0.0;
    if (this->g > 1.0) this->g = 1.0;

    if (this->b < 0.0) this->b = 0.0;
    if (this->b > 1.0) this->b = 1.0;

}