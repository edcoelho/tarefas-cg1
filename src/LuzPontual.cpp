#include "LuzPontual.hpp"

LuzPontual::LuzPontual() {

    this->setPosicao(Ponto(0.0, 0.0, 0.0));
    this->setIntensidade(IntensidadeLuz(1.0, 1.0, 1.0));

}

LuzPontual::LuzPontual(double x, double y, double z, float Ir, float Ig, float Ib) {

    Ponto pos(x, y, z);
    IntensidadeLuz I(Ir, Ig, Ib);

    this->setPosicao(pos);
    this->setIntensidade(I);

}

LuzPontual::LuzPontual(Ponto pos, IntensidadeLuz I) {

    this->setPosicao(pos);
    this->setIntensidade(I);

}

Ponto LuzPontual::getPosicao() {

    return this->posicao;

}
void LuzPontual::setPosicao(Ponto pos) {

    this->posicao = pos;

}

IntensidadeLuz LuzPontual::getIntensidade() {

    return this->intensidade;

}
void LuzPontual::setIntensidade(IntensidadeLuz I) {

    this->intensidade = I;

}