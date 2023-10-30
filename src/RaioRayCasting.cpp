#include "RaioRayCasting.hpp"

RaioRayCasting::RaioRayCasting() {

    this->setPInicial(Ponto3());
    this->setVDirecao(Vetor3());

}

RaioRayCasting::RaioRayCasting(Ponto3 pI, Ponto3 pX) {

    Vetor3 vD;

    // vD = (pX - pI) / mod(pX - pI)
    vD = pX - pI;
    vD.normalizar();

    this->setPInicial(pI);
    this->setVDirecao(vD);

}

Ponto3 RaioRayCasting::getPInicial() {

    return this->pInicial;

}
void RaioRayCasting::setPInicial(Ponto3 pI) {

    this->pInicial = pI;

}

Vetor3 RaioRayCasting::getVDirecao() {

    return this->vDirecao;

}
void RaioRayCasting::setVDirecao(Vetor3 vD) {

    this->vDirecao = vD;

}

Ponto3 RaioRayCasting::pontoDoRaio(double escalar) {

    Ponto3 pX;

    // P(t) = Pin + dr*t
    pX = this->getPInicial() + (this->getVDirecao() * escalar);

    return pX;

}