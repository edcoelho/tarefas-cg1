#include "luz/LuzSpot.hpp"
#include <cmath>

LuzSpot::LuzSpot(IntensidadeLuz intensidade, Ponto3 posicao, Vetor3 direcao, double abertura) {
    this->set_intensidade(intensidade);
    this->set_posicao(posicao);
    this->set_direcao(direcao);
    this->set_abertura(abertura);
}

Ponto3 LuzSpot::get_posicao() const {

    return this->posicao;

}
void LuzSpot::set_posicao(Ponto3 p) {

    this->posicao = p;

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

    this->abertura = a;

}

bool LuzSpot::ponto_valido(const Ponto3& ponto) const {

    if ((ponto - this->get_posicao()).unitario().escalar(this->get_direcao()) >= std::cos(this->get_abertura())) {

        return true;

    }

    return false;

}

Vetor3 LuzSpot::direcao_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).unitario();

}

double LuzSpot::distancia_ponto_luz(const Ponto3& ponto) const {

    return (this->get_posicao() - ponto).norma();

}