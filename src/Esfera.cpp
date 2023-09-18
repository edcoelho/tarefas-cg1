#include "../include/Esfera.hpp"
#include <eigen3/Eigen/Core>

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

double Esfera::escalarInterseccao(RaioRayCasting& raio) {

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0; // Coscientes da equação de 2º grau.

    Eigen::Vector3d vAux; // Vetor para auxiliar nos cálculos.

    // a = vDirecao . vDirecao
    a = raio.getVDirecao().dot(raio.getVDirecao());
    // b = 2 ((pInicial - centroEsf) . vDirecao)
    vAux = (raio.getPInicial() - this->getCentro()).matrix();
    b = 2.0 * vAux.dot(raio.getVDirecao());
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(this->getRaio(), 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    if (delta >= 0) return true; else return false;

}

        
bool Esfera::houveInterseccao(RaioRayCasting& raio) {

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0; // Coscientes da equação de 2º grau.

    Eigen::Vector3d vAux; // Vetor para auxiliar nos cálculos.

    // a = vDirecao . vDirecao
    a = raio.getVDirecao().dot(raio.getVDirecao());
    // b = 2 ((pInicial - centroEsf) . vDirecao)
    vAux = (raio.getPInicial() - this->getCentro()).matrix();
    b = 2.0 * vAux.dot(raio.getVDirecao());
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(this->getRaio(), 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    if (delta >= 0) return true; else return false;

}