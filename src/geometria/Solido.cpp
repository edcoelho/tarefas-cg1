#include "geometria/Solido.hpp"

Solido::Solido(const char* nome, Material material) {

    this->nome = nome;
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

std::string Solido::get_nome() const {

    return this->nome;

}