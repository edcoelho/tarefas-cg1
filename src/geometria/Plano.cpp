#include "geometria/Plano.hpp"

Plano::Plano(Material material) : Solido(material) {

    this->set_ponto(Ponto3(0.0, 0.0, 0.0));
    this->set_normal(Vetor3(0.0, 1.0, 0.0));

}

Plano::Plano(Ponto3 ponto, Vetor3 normal, Material material) : Solido(material) {

    this->set_ponto(ponto);
    this->set_normal(normal);

}

Ponto3 Plano::get_ponto() const {

    return this->ponto;

}
void Plano::set_ponto(Ponto3 p) {

    this->ponto = p;

}

Vetor3 Plano::get_normal() const {

    return this->normal;

}
void Plano::set_normal(Vetor3 n) {

    this->normal = n.unitario();

}

double Plano::escalar_interseccao(Raio& raio) const {
    
    // Escalar distância até a intersecção.
    double t_int;

    // pX: ponto conhecido do plano
    // p0: ponto inicial do raio
    // vN: vetor normal ao plano
    // dr: vetor direção do raio

    // t_int = ((pX - p0) . vN) / (dr . vN)

    // t_int = (pX - p0) . vN)
    t_int = (this->get_ponto() - raio.get_ponto_inicial()).escalar(this->get_normal());
    // t_int = t_int / (d . dr);
    t_int = t_int / raio.get_direcao().escalar(this->get_normal());

    if (t_int > 0) return t_int; else return -1;

}

Vetor3 Plano::vetor_normal_ponto(Ponto3 ponto) const {

    return this->get_normal();

}