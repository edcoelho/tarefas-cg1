#include "../include/RaioRayCasting.hpp"
#include <eigen3/Eigen/Core>

RaioRayCasting::RaioRayCasting(ponto3D pI, Eigen::Vector3d vD) {

    this->setPInicial(pI);
    this->setVDirecao(vD);

}
RaioRayCasting::RaioRayCasting(ponto3D pI, ponto3D pX) {

    Eigen::Vector3d vD;

    // vD = (pX - pI) / mod(pX - pI)
    vD = (pX - pI).matrix();
    vD.normalize();

    this->setPInicial(pI);
    this->setVDirecao(vD);

}

ponto3D RaioRayCasting::getPInicial() {

    return this->pInicial;

}
void RaioRayCasting::setPInicial(ponto3D pI) {

    this->pInicial = pI;

}

Eigen::Vector3d RaioRayCasting::getVDirecao() {

    return this->vDirecao;

}
void RaioRayCasting::setVDirecao(Eigen::Vector3d vD) {

    this->vDirecao = vD;

}