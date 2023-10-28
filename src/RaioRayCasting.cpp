#include "RaioRayCasting.hpp"

RaioRayCasting::RaioRayCasting() {}

RaioRayCasting::RaioRayCasting(Ponto pI, Ponto pX) {

    Vetor vD(3);

    // vD = (pX - pI) / mod(pX - pI)
    vD = pX - pI;
    vD.normalizar();

    this->setPInicial(pI);
    this->setVDirecao(vD);

}

Ponto RaioRayCasting::getPInicial() {

    return this->pInicial;

}
void RaioRayCasting::setPInicial(Ponto pI) {

    this->pInicial = pI;

}

Vetor RaioRayCasting::getVDirecao() {

    return this->vDirecao;

}
void RaioRayCasting::setVDirecao(Vetor vD) {

    this->vDirecao = vD;

}

Ponto RaioRayCasting::pontoDoRaio(double escalar) {

    Ponto pX(3);

    // P(t) = Pin + dr*t
    pX = this->getPInicial() + (this->getVDirecao() * escalar);

    return pX;

}