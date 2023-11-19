#include "utils/Material.hpp"

Material::Material() {

    this->set_k_A(IntensidadeLuz(0.0, 0.0, 0.0));
    this->set_k_D(rgb{150, 150, 150});
    this->set_k_E(IntensidadeLuz(1.0, 1.0, 1.0));
    this->set_espelhamento(10);

}

Material::Material(IntensidadeLuz ka, IntensidadeLuz kd, IntensidadeLuz ke, double espelhamento) {

    this->set_k_A(ka);
    this->set_k_D(kd);
    this->set_k_E(ke);
    this->set_espelhamento(espelhamento);

}

IntensidadeLuz Material::get_k_A() {

    return this->k_A;
    
}
void Material::set_k_A(IntensidadeLuz k) {

    this->k_A= k;
   
}

IntensidadeLuz Material::get_k_D() {

    return this->k_D;
    
}
void Material::set_k_D(IntensidadeLuz k) {

    this->k_D = k;
   
}

IntensidadeLuz Material::get_k_E() {

    return this->k_E;
    
}
void Material::set_k_E(IntensidadeLuz k) {

    this->k_E = k;
   
}

double Material::get_espelhamento() {

    return this->espelhamento;

}
void Material::set_espelhamento(double e) {

    this->espelhamento = e;

}