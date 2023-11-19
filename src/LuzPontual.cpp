#include "LuzPontual.hpp"

LuzPontual::LuzPontual() {

    this->set_posicao(Ponto3(0.0, 0.0, 0.0));
    this->set_intensidade(IntensidadeLuz(1.0, 1.0, 1.0));

}

LuzPontual::LuzPontual(double x, double y, double z, double r, double g, double b) {

    this->set_posicao(Ponto3(x, y, z));
    this->set_intensidade(IntensidadeLuz(r, g, b));

}

LuzPontual::LuzPontual(Ponto3 posicao, IntensidadeLuz intensidade) {

    this->set_posicao(posicao);
    this->set_intensidade(intensidade);

}

Ponto3 LuzPontual::get_posicao() const {

    return this->posicao;

}
void LuzPontual::set_posicao(Ponto3 p) {

    this->posicao = p;

}

IntensidadeLuz LuzPontual::get_intensidade() const {

    return this->intensidade;

}
void LuzPontual::set_intensidade(IntensidadeLuz i) {

    this->intensidade = i;

}