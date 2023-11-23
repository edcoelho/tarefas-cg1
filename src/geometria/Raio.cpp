#include "geometria/Raio.hpp"

Raio::Raio() {

    this->set_ponto_inicial(Ponto3());
    this->set_direcao(Vetor3());

}

Raio::Raio(Ponto3 ponto_inicial, Ponto3 ponto_x) {

    this->set_ponto_inicial(ponto_inicial);
    // vD = (ponto_x - ponto_inicial) / ||(ponto_x - ponto_inicial)||
    this->set_direcao((ponto_x - ponto_inicial).unitario());

}

Raio::Raio(Ponto3 ponto_inicial, Vetor3 direcao) {

    this->set_ponto_inicial(ponto_inicial);
    this->set_direcao(direcao.unitario());

}

Ponto3 Raio::get_ponto_inicial() {

    return this->ponto_inicial;

}
void Raio::set_ponto_inicial(Ponto3 p) {

    this->ponto_inicial = p;

}

Vetor3 Raio::get_direcao() {

    return this->direcao;

}
void Raio::set_direcao(Vetor3 d) {

    this->direcao = d.unitario();

}

Ponto3 Raio::ponto_do_raio(double escalar) {

    // P(t) = ponto_inicial + dr*t
    return this->get_ponto_inicial() + (this->get_direcao() * escalar);

}