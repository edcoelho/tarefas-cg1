#include "LuzPontual.hpp"

LuzPontual::LuzPontual() {

    this->setPosicao(Ponto3(0.0, 0.0, 0.0));
    this->setIntensidade(IntensidadeLuz(1.0, 1.0, 1.0));

}

LuzPontual::LuzPontual(double x, double y, double z, double Ir, double Ig, double Ib) {

    Ponto3 pos(x, y, z);
    IntensidadeLuz I(Ir, Ig, Ib);

    this->setPosicao(pos);
    this->setIntensidade(I);

}

LuzPontual::LuzPontual(Ponto3 pos, IntensidadeLuz I) {

    this->setPosicao(pos);
    this->setIntensidade(I);

}

Ponto3 LuzPontual::getPosicao() {

    return this->posicao;

}
void LuzPontual::setPosicao(Ponto3 pos) {

    this->posicao = pos;

}

IntensidadeLuz LuzPontual::getIntensidade() {

    return this->intensidade;

}
void LuzPontual::setIntensidade(IntensidadeLuz I) {

    this->intensidade = I;

}