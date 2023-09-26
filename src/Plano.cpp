#include "../include/Plano.hpp"

Plano::Plano() {

    this->setPX(ponto3D(0,0,0));
    this->setVN(Eigen::Vector3d(0,1,0));

}

Plano::Plano(ponto3D p, Eigen::Vector3d n, Material m) {

    this->setPX(p);
    this->setVN(n);
    this->setMaterial(m);

}

ponto3D Plano::getPX() {

    return this->pX;

}
void Plano::setPX(ponto3D p) {

    this->pX = p;

}

Eigen::Vector3d Plano::getVN() {

    return this->vN;

}
void Plano::setVN(Eigen::Vector3d n) {

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
    tInt = (this->getPX() - raio.getPInicial()).dot(this->getVN());
    // tInt = tInt / (d . vDirecao);
    tInt = tInt / raio.getVDirecao().dot(this->getVN());

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
    tInt = (this->getPX() - raio.getPInicial()).dot(this->getVN());
    // tInt = tInt / (d . vDirecao);
    tInt = tInt / raio.getVDirecao().dot(this->getVN());

    if (tInt > 0) return true; else return false;
    
}

Eigen::Vector3d Plano::vetorNormalPonto(ponto3D ponto) {

    return this->getVN();

}