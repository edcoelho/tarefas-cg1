#include "Esfera.hpp"
#include <eigen3/Eigen/Core>

Esfera::Esfera() {

    this->setCentro(ponto3D(0,0,0));
    this->setRaio(1);

}

Esfera::Esfera(ponto3D c, double r, Material m) {

    this->setCentro(c);
    this->setRaio(r);
    this->setMaterial(m);

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
           a = 0.0, b = 0.0, c = 0.0, // Coscientes da equação de 2º grau.
           raiz = 0.0, // Raíz da equação.
           aux = 0.0; // Variável para auxiliar nos cálculos.

    Eigen::Vector3d vAux; // Vetor para auxiliar nos cálculos.

    // a = vDirecao . vDirecao
    a = raio.getVDirecao().dot(raio.getVDirecao());
    // b = 2 ((pInicial - centroEsf) . vDirecao)
    vAux = raio.getPInicial() - this->getCentro();
    b = 2.0 * vAux.dot(raio.getVDirecao());
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(this->getRaio(), 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    // raiz = (-b +- sqrt(delta))/2a
    if (delta > 0) {
        
        // Escolhendo a menor raíz.
        raiz = (-1*b + std::sqrt(delta)) / (2.0*a);
        aux = (-1*b - std::sqrt(delta)) / (2.0*a);
        if (aux < raiz) raiz = aux;

    } else if (delta == 0)
        
        raiz = -b / (2.0*a);
    
    else raiz = -1;

    return raiz;

}

        
bool Esfera::houveInterseccao(RaioRayCasting& raio) {

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0; // Coscientes da equação de 2º grau.

    Eigen::Vector3d vAux; // Vetor para auxiliar nos cálculos.

    // a = vDirecao . vDirecao
    a = raio.getVDirecao().dot(raio.getVDirecao());
    // b = 2 ((pInicial - centroEsf) . vDirecao)
    vAux = raio.getPInicial() - this->getCentro();
    b = 2.0 * vAux.dot(raio.getVDirecao());
    // c = (pInicial - centroEsf) . (pInicial - centroEsf) - raioEsf²
    c = vAux.dot(vAux) - std::pow(this->getRaio(), 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    if (delta >= 0) return true; else return false;

}


Eigen::Vector3d Esfera::vetorNormalPonto(ponto3D ponto) {

    Eigen::Vector3d n;
    
    n = ponto - this->getCentro();
    n.normalize();

    return n;

}