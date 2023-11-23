#include "luz/FonteLuz.hpp"

FonteLuz::FonteLuz() {}

FonteLuz::FonteLuz(IntensidadeLuz intensidade) {

    this->set_intensidade(intensidade);

}

IntensidadeLuz FonteLuz::get_intensidade() const {

    return this->intensidade;

}
void FonteLuz::set_intensidade(IntensidadeLuz i) {

    this->intensidade = i;

}