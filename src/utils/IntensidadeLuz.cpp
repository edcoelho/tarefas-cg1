#include "utils/IntensidadeLuz.hpp"

bool IntensidadeLuz::posicaoValida(std::size_t indice) const {

    if (indice >= 0 && indice < 3) {

        return true;

    } else {

        return false;

    }
    
}

IntensidadeLuz::IntensidadeLuz() {}

IntensidadeLuz::IntensidadeLuz(std::array<double, 3> val) {

    this->valores = val;
    this->consertaIntensidade();

}

double IntensidadeLuz::operator () (std::size_t indice) const {

    if (this->posicaoValida(indice)) {

        return this->valores[indice];

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a um canal inválido de uma intesidade de luz!");

    }

}
double IntensidadeLuz::operator [] (std::size_t indice) const {

    return this->operator()(indice);

}

double& IntensidadeLuz::operator () (std::size_t indice) {

    if (this->posicaoValida(indice)) {

        return this->valores[indice];

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a um canal inválido de uma intesidade de luz!");

    }

}
double& IntensidadeLuz::operator [] (std::size_t indice) {

    return this->operator()(indice);

}

IntensidadeLuz IntensidadeLuz::operator + (IntensidadeLuz const& intensidade) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp[i] = this->valores[i] + intensidade[i];

    this->consertaIntensidade();

    return temp;

}

IntensidadeLuz IntensidadeLuz::operator + (double const escalar) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp(i) = this->valores[i] + escalar;

    this->consertaIntensidade();

    return temp;

}

IntensidadeLuz IntensidadeLuz::operator - (IntensidadeLuz const& intensidade) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp(i) = this->valores[i] - intensidade[i];

    this->consertaIntensidade();

    return temp;

}

IntensidadeLuz IntensidadeLuz::operator - (double const escalar) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp(i) = this->valores[i] - escalar;

    this->consertaIntensidade();

    return temp;

}

IntensidadeLuz IntensidadeLuz::operator * (IntensidadeLuz const& intensidade) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp(i) = this->valores[i] * intensidade[i];

    this->consertaIntensidade();

    return temp;

}

IntensidadeLuz IntensidadeLuz::operator * (double const escalar) {

    IntensidadeLuz temp;

    for (std::size_t i = 0; i < 3; i++)
        temp(i) = this->valores[i] * escalar;

    this->consertaIntensidade();

    return temp;

}

std::array<double, 3> IntensidadeLuz::getValores() const {

    return this->valores;

}
void IntensidadeLuz::setValores(std::array<double, 3> val) {

    this->valores = val;
    
}

rgb IntensidadeLuz::paraRGB() const {

    rgb cor;

    for (int i = 0; i < 3; i++) cor[i] = (canalRGB) (this->valores[i] * 255);

    return cor;

}

void IntensidadeLuz::consertaIntensidade() {

    for (int i = 0; i < 3; i++) {

        if (this->valores[i] < 0.0f) this->valores[i] = 0.0f;
        if (this->valores[i] > 1.0f) this->valores[i] = 1.0f;

    }

}