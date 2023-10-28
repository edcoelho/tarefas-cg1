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

Vetor Solido::vetorLuzPontual(Ponto ponto, LuzPontual& luz) {

    return luz.getPosicao() - ponto;

}

Vetor Solido::vetorReflexo(Ponto ponto, LuzPontual& luz) {

    Vetor n = this->vetorNormalPonto(ponto),
          l = this->vetorLuzPontual(ponto, luz);

    l.normalizar();

    return (n * (2.0 * l.pEscalar(n))) - l;

}

Vetor Solido::vetorUnit(Ponto p0, Ponto pX) {

    Vetor vDr = pX - p0;

    vDr.normalizar();

    return vDr;

}