#include "luz/LuzSpot.hpp"
#include <cmath>

LuzSpot::LuzSpot(Vetor3 direcao, double abertura, Ponto3 posicao, IntensidadeLuz intensidade, double atenuacao_a, double atenuacao_b, double atenuacao_c) : LuzPontual(posicao, intensidade, atenuacao_a, atenuacao_b, atenuacao_c) {

    this->set_direcao(direcao);
    this->set_abertura(abertura);

}

Vetor3 LuzSpot::get_direcao() const {

    return this->direcao;

}
void LuzSpot::set_direcao(Vetor3 d) {

    this->direcao = d.unitario();

}

double LuzSpot::get_abertura() const {

    return this->abertura;

}
void LuzSpot::set_abertura(double a) {

    a = a > M_PI ? M_PI : a;
    a = a < 0.0 ? 0.0 : a;

    this->abertura = a;

}

bool LuzSpot::ponto_valido(const Ponto3& ponto) const {

    if ((ponto - this->get_posicao()).unitario().escalar(this->get_direcao()) >= std::cos(this->get_abertura())) {

        return true;

    }

    return false;

}