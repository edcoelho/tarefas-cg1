#include "../include/Material.hpp"

Material::Material() {

    this->setCor(rgb(150, 150, 150));
    this->setKE(rgb(255, 255, 255));
    this->setExpEsp(10);

}

Material::Material(rgb c, rgb k, double e) {

    this->setCor(c);
    this->setKE(k);
    this->setExpEsp(e);

}

rgb Material::getCor() {
    
    return this->cor;

}
void Material::setCor(rgb c) {

    this->cor = c;

}

rgb Material::getKE() {

    return this->kE;
    
}
void Material::setKE(rgb k) {

    this->kE = k;
   
}

double Material::getExpEsp() {

    return this->expEsp;

}
void Material::setExpEsp(double e) {

    this->expEsp = e;

}