#include "../include/Solido.hpp"
#include <eigen3/Eigen/Core>

Solido::Solido() {}

Solido::Solido(Material m) {

    this->setMaterial(m);

}

Material Solido::getMaterial() {
    
    return this->material;

}

void Solido::setMaterial(Material m) {

    this->material = m;

}

Eigen::Vector3d Solido::vetorLuzPontual(ponto3D ponto, LuzPontual& luz) {

    return luz.getPosicao() - ponto;

}

Eigen::Vector3d Solido::vetorReflexo(ponto3D ponto, LuzPontual& luz) {

    Eigen::Vector3d n = this->vetorNormalPonto(ponto),
                    l = this->vetorLuzPontual(ponto, luz);

    l.normalize();

    return ((2 * l.dot(n)) * n) - l;

}

Eigen::Vector3d Solido::vetorUnit(ponto3D p0, ponto3D pX) {

    Eigen::Vector3d vDr = pX - p0;

    vDr.normalize();

    return vDr;

}