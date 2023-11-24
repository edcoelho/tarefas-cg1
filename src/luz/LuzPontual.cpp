#include "luz/LuzPontual.hpp"
#include <cmath>

LuzPontual::LuzPontual() : FonteLuz() {}

LuzPontual::LuzPontual(IntensidadeLuz intensidade, Ponto3 posicao, double atenuacao_a, double atenuacao_b, double atenuacao_c) : FonteLuz(intensidade, atenuacao_a, atenuacao_b, atenuacao_c) {

    this->set_posicao(posicao);

}

Ponto3 LuzPontual::get_posicao() const {

    return this->posicao;

}
void LuzPontual::set_posicao(Ponto3 p) {

    this->posicao = p;

}

Vetor3 LuzPontual::direcao_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).unitario();

}

double LuzPontual::distancia_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).norma();

}

double LuzPontual::fator_atenuacao(const Ponto3& ponto) const {

    double d = this->distancia_ponto_luz(ponto);
    double atenuacao = 1.0/(this->get_atenuacao_a()*std::pow(d, 2) + this->get_atenuacao_b()*d + this->get_atenuacao_c());
    atenuacao = atenuacao > 1.0 ? 1.0 : atenuacao;
    atenuacao = atenuacao < 0.0 ? 0.0 : atenuacao;

    return atenuacao;

}