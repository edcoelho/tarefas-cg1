#include "geometria/Solido.hpp"

Solido::Solido(Material material) {

    this->set_material(material);

}

Material Solido::get_material() const {
    
    return this->material;

}

void Solido::set_material(Material material) {

    this->material = material;

}

bool Solido::tem_textura() const {

    if (this->material.get_textura() != nullptr) {

        return true;

    } else {

        return false;

    }

}