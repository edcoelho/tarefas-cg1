#include "Solido.hpp"

Solido::Solido() {}

Solido::Solido(Material material) {

    this->set_material(material);

}

Material Solido::get_material() const {
    
    return this->material;

}

void Solido::set_material(Material material) {

    this->material = material;

}