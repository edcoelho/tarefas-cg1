#include "Solido.hpp"

Solido::Solido() {}

Solido::Solido(Material material) {

    this->set_material(material);

}

Material Solido::get_material() const {
    
    return this->material;

}

void Solido::set_material(Material material) {

    this->material = material;

}

Vetor3 Solido::vetor_luz_pontual(Ponto3 ponto, LuzPontual& luz) const {

    return luz.get_posicao() - ponto;

}

Vetor3 Solido::vetor_reflexo(Ponto3 ponto, LuzPontual& luz) const {

    Vetor3 n = this->vetor_normal_ponto(ponto),
           l = this->vetor_luz_pontual(ponto, luz);

    l.normalizar();

    return (n * (2.0 * l.escalar(n))) - l;

}

Vetor3 Solido::vetor_unitario(Ponto3 p0, Ponto3 pX) const {

    return (pX - p0).unitario();

}