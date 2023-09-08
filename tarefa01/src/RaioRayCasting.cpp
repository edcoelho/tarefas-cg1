#include <eigen3/Eigen/Core>
#include <cmath>
#include "../include/RaioRayCasting.h"
#include "../include/Esfera.h"

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

double RaioRayCasting::escalarInterseccao(Esfera esf) {

    double delta = 0.0, a = 0.0, b = 0.0, c = 0.0, raiz = 0.0, raioEsf = esf.getRaio(), aux;
    Eigen::Vector3d vDr = this->getVDirecao(), vAux;
    ponto3D pInicial = this->getPInicial(), centroEsf = esf.getCentro();

    // a = vDirecao . vDirecao
    a = vDr.dot(vDr);
    // b = 2 ((pInicial - centroEsf) . vDr)
    vAux = (pInicial - centroEsf).matrix();
    b = 2.0 * vAux.dot(vDr);
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(raioEsf, 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    // raiz = (-b +- sqrt(delta))/2a
    if (delta > 0) {
        
        // Escolhendo a menor raíz.
        raiz = (-1*b + std::sqrt(delta)) / 2*a;
        aux = (-1*b - std::sqrt(delta)) / 2*a;
        if (aux < raiz) raiz = aux;

    } else if (delta = 0)
        
        raiz = -1*b / 2*a;

    else

        raiz = -1;


    return raiz;
}

bool RaioRayCasting::houveInterseccao(Esfera esf) {

    double delta = 0.0, a = 0.0, b = 0.0, c = 0.0, raioEsf = esf.getRaio();
    Eigen::Vector3d vDr = this->getVDirecao(), vAux;
    ponto3D pInicial = this->getPInicial(), centroEsf = esf.getCentro();

    // a = vDirecao . vDirecao
    a = vDr.dot(vDr);
    // b = 2 ((pInicial - centroEsf) . vDr)
    vAux = (pInicial - centroEsf).matrix();
    b = 2.0 * vAux.dot(vDr);
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(raioEsf, 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    if (delta >= 0) return true; else return false;

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