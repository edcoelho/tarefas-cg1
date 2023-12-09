#include "luz/FonteLuz.hpp"
#include <cmath>

FonteLuz::FonteLuz(IntensidadeLuz intensidade, double atenuacao_a, double atenuacao_b, double atenuacao_c) {

    this->set_intensidade(intensidade);
    this->set_atenuacao_a(atenuacao_a);
    this->set_atenuacao_b(atenuacao_b);
    this->set_atenuacao_c(atenuacao_c);

}

IntensidadeLuz FonteLuz::get_intensidade() const {

    return this->intensidade;

}
void FonteLuz::set_intensidade(IntensidadeLuz i) {

    this->intensidade = i;

}

double FonteLuz::get_atenuacao_a() const {

    return this->atenuacao_a;

}
void FonteLuz::set_atenuacao_a(double a) {

    this->atenuacao_a = a;

}

double FonteLuz::get_atenuacao_b() const {

    return this->atenuacao_b;

}
void FonteLuz::set_atenuacao_b(double b) {

    this->atenuacao_b = b;

}

double FonteLuz::get_atenuacao_c() const {

    return this->atenuacao_c;

}
void FonteLuz::set_atenuacao_c(double c) {

    this->atenuacao_c = c;

}

bool FonteLuz::ponto_valido(const Ponto3& ponto) const {

    return true;

}