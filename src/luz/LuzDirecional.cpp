#include "luz/LuzDirecional.hpp"
#include <cmath>

LuzDirecional::LuzDirecional() {}

LuzDirecional::LuzDirecional(IntensidadeLuz intensidade, Vetor3 direcao) {

    this->set_intensidade(intensidade);
    this->set_direcao(direcao);

}

Vetor3 LuzDirecional::get_direcao() const {

    return this->direcao;

}
void LuzDirecional::set_direcao(Vetor3 d) {

    this->direcao = d.unitario();

}

bool LuzDirecional::ponto_valido(const Ponto3& ponto) const {

    return true;

}

Vetor3 LuzDirecional::direcao_ponto_luz(const Ponto3& ponto) const {

    return this->get_direcao() * -1.0;

}

double LuzDirecional::distancia_ponto_luz(const Ponto3& ponto) const {

    return INFINITY;

}