#include "Material.hpp"

Material::Material() {

    this->setKA(IntensidadeLuz(0.0, 0.0, 0.0));
    this->setKD(rgb{150, 150, 150});
    this->setKE(IntensidadeLuz(1.0, 1.0, 1.0));
    this->setExpEsp(10);

}

Material::Material(IntensidadeLuz ka, IntensidadeLuz kd, IntensidadeLuz ke, double e) {

    this->setKA(ka);
    this->setKD(kd);
    this->setKE(ke);
    this->setExpEsp(e);

}

IntensidadeLuz Material::getKA() {

    return this->kA;
    
}
void Material::setKA(IntensidadeLuz k) {

    this->kA= k;
   
}

IntensidadeLuz Material::getKD() {

    return this->kD;
    
}
void Material::setKD(IntensidadeLuz k) {

    this->kD = k;
   
}

IntensidadeLuz Material::getKE() {

    return this->kE;
    
}
void Material::setKE(IntensidadeLuz k) {

    this->kE = k;
   
}

double Material::getExpEsp() {

    return this->expEsp;

}
void Material::setExpEsp(double e) {

    this->expEsp = e;

}