#include "luz/LuzDirecional.hpp"
#include <cmath>

LuzDirecional::LuzDirecional() : FonteLuz() {}

LuzDirecional::LuzDirecional(IntensidadeLuz intensidade, Vetor3 direcao) : FonteLuz(intensidade, 0.0, 0.0, 1.0) {

    this->set_direcao(direcao);

}

Vetor3 LuzDirecional::get_direcao() const {

    return this->direcao;

}
void LuzDirecional::set_direcao(Vetor3 d) {

    this->direcao = d.unitario();

}

Vetor3 LuzDirecional::direcao_ponto_luz(const Ponto3& ponto) const {

    return this->get_direcao() * -1.0;

}

double LuzDirecional::distancia_ponto_luz(const Ponto3& ponto) const {

    return INFINITY;

}

double LuzDirecional::fator_atenuacao(const Ponto3& ponto) const {

    return 1.0;

}