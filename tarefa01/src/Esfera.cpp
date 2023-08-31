#include "../include/Esfera.h"

Esfera::Esfera(ponto3D c, double r, rgb cr) {

    this->setCentro(c);
    this->setRaio(r);
    this->setCor(cr);

}

ponto3D Esfera::getCentro() {

    return this->centro;

}
void Esfera::setCentro(ponto3D c) {

    this->centro = c;

}

double Esfera::getRaio() {

    return this->raio;

}
void Esfera::setRaio(double r) {

    this->raio = r;

}

rgb Esfera::getCor() {

    return this->cor;

}
void Esfera::setCor(rgb c) {

    this->cor = c;

}