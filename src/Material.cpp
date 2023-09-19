#include "../include/Material.hpp"

Material::Material() {

    this->setCor(rgb(150, 150, 150));
    this->setExpEsp(10);

}

Material::Material(rgb c, double e) {

    this->setCor(c);
    this->setExpEsp(e);

}

rgb Material::getCor() {
    
    return this->cor;

}
void Material::setCor(rgb c) {

    this->cor = c;

}

double Material::getExpEsp() {

    return this->expEsp;

}
void Material::setExpEsp(double e) {

    this->expEsp = e;

}