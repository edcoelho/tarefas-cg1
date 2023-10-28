#include "Plano.hpp"

Plano::Plano() {

    this->setPX(Ponto(0.0, 0.0, 0.0));
    this->setVN(Vetor(0.0, 1.0, 0.0));

}

Plano::Plano(Ponto p, Vetor n, Material m) {

    this->setPX(p);
    this->setVN(n);
    this->setMaterial(m);

}

Ponto Plano::getPX() {

    return this->pX;

}
void Plano::setPX(Ponto p) {

    this->pX = p;

}

Vetor Plano::getVN() {

    return this->vN;

}
void Plano::setVN(Vetor n) {

    this->vN = n;

}

double Plano::escalarInterseccao(RaioRayCasting& raio) {
    
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

bool Plano::houveInterseccao(RaioRayCasting& raio) {

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

    if (tInt > 0) return true; else return false;
    
}

Vetor Plano::vetorNormalPonto(Ponto ponto) {

    return this->getVN();

}