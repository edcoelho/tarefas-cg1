#include "Solido.hpp"

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

Vetor3 Solido::vetorLuzPontual(Ponto3 ponto, LuzPontual& luz) {

    return luz.getPosicao() - ponto;

}

Vetor3 Solido::vetorReflexo(Ponto3 ponto, LuzPontual& luz) {

    Vetor3 n = this->vetorNormalPonto(ponto),
          l = this->vetorLuzPontual(ponto, luz);

    l.normalizar();

    return (n * (2.0 * l.pEscalar(n))) - l;

}

Vetor3 Solido::vetorUnit(Ponto3 p0, Ponto3 pX) {

    Vetor3 vDr = pX - p0;

    vDr.normalizar();

    return vDr;

}