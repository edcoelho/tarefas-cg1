#include "../include/LuzPontual.hpp"

LuzPontual::LuzPontual() {

    this->setPosicao(ponto3D(0,0,0));
    this->setIntensidade(i_luz(1,1,1));

}

LuzPontual::LuzPontual(double x, double y, double z, float Ir, float Ig, float Ib) {

    ponto3D pos(x, y, z);
    i_luz I(Ir, Ig, Ib);

    this->setPosicao(pos);
    this->setIntensidade(I);

}

LuzPontual::LuzPontual(ponto3D pos, i_luz I) {

    this->setPosicao(pos);
    this->setIntensidade(I);

}

// --- GETTERS E SETTERS ---

ponto3D LuzPontual::getPosicao() {

    return this->posicao;

}
void LuzPontual::setPosicao(ponto3D pos) {

    this->posicao = pos;

}

i_luz LuzPontual::getIntensidade() {

    return this->intensidade;

}
void LuzPontual::setIntensidade(i_luz I) {

    this->intensidade = I;

}