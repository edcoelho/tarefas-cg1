#include "luz/LuzPontual.hpp"

LuzPontual::LuzPontual() {}

LuzPontual::LuzPontual(IntensidadeLuz intensidade, Ponto3 posicao) {

    this->set_posicao(posicao);
    this->set_intensidade(intensidade);

}

Ponto3 LuzPontual::get_posicao() const {

    return this->posicao;

}
void LuzPontual::set_posicao(Ponto3 p) {

    this->posicao = p;

}

bool LuzPontual::ponto_valido(const Ponto3& ponto) const {

    return true;

}

Vetor3 LuzPontual::direcao_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).unitario();

}

double LuzPontual::distancia_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).norma();

}