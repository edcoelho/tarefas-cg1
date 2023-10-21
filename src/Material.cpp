#include "Material.hpp"

Material::Material() {

    this->setKA(i_luz(0, 0, 0));
    this->setKD(RGBParaI(rgb(150, 150, 150)));
    this->setKE(i_luz(1, 1, 1));
    this->setExpEsp(10);

}

Material::Material(i_luz ka, i_luz kd, i_luz ke, double e) {

    this->setKA(ka);
    this->setKD(kd);
    this->setKE(ke);
    this->setExpEsp(e);

}

i_luz Material::getKA() {

    return this->kA;
    
}
void Material::setKA(i_luz k) {

    this->kA= fixIntensidade(k);
   
}

i_luz Material::getKD() {

    return this->kD;
    
}
void Material::setKD(i_luz k) {

    this->kD = fixIntensidade(k);
   
}

i_luz Material::getKE() {

    return this->kE;
    
}
void Material::setKE(i_luz k) {

    this->kE = fixIntensidade(k);
   
}

double Material::getExpEsp() {

    return this->expEsp;

}
void Material::setExpEsp(double e) {

    this->expEsp = e;

}