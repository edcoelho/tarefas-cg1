#include "Plano.hpp"

Plano::Plano() {

    this->setPX(Ponto3(0.0, 0.0, 0.0));
    this->setVN(Vetor3(0.0, 1.0, 0.0));

}

Plano::Plano(Ponto3 p, Vetor3 n, Material m) {

    this->setPX(p);
    this->setVN(n);
    this->setMaterial(m);

}

Ponto3 Plano::getPX() const {

    return this->pX;

}
void Plano::setPX(Ponto3 p) {

    this->pX = p;

}

Vetor3 Plano::getVN() const {

    return this->vN;

}
void Plano::setVN(Vetor3 n) {

    this->vN = n;

}

double Plano::escalarInterseccao(RaioRayCasting& raio) const {
    
    // Escalar distância até a intersecção.
    double tInt;

    // pX: ponto conhecido do plano
    // p0: ponto inicial do raio
    // vN: vetor normal ao plano
    // vDirecao: vetor direção do raio

    // tInt = ((pX - p0) . vN) / (vDirecao . vN)

    // tInt = (pX - p0) . vN)
    tInt = (this->getPX() - raio.getPInicial()).pEscalar(this->getVN());
    // tInt = tInt / (d . vDirecao);
    tInt = tInt / raio.getVDirecao().pEscalar(this->getVN());

    if (tInt > 0) return tInt; else return -1;

}

Vetor3 Plano::vetorNormalPonto(Ponto3 ponto) const {

    return this->getVN();

}