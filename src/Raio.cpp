#include "Raio.hpp"

Raio::Raio() {

    this->setPInicial(Ponto3());
    this->setVDirecao(Vetor3());

}

Raio::Raio(Ponto3 pI, Ponto3 pX) {

    Vetor3 vD;

    // vD = (pX - pI) / mod(pX - pI)
    vD = pX - pI;
    vD.normalizar();

    this->setPInicial(pI);
    this->setVDirecao(vD);

}

Ponto3 Raio::getPInicial() {

    return this->pInicial;

}
void Raio::setPInicial(Ponto3 pI) {

    this->pInicial = pI;

}

Vetor3 Raio::getVDirecao() {

    return this->vDirecao;

}
void Raio::setVDirecao(Vetor3 vD) {

    this->vDirecao = vD;

}

Ponto3 Raio::pontoDoRaio(double escalar) {

    Ponto3 pX;

    // P(t) = Pin + dr*t
    pX = this->getPInicial() + (this->getVDirecao() * escalar);

    return pX;

}