#include "geometria/malha/Face.hpp"

Face::Face() {

    this->set_id_aresta1(0);
    this->set_id_aresta2(0);
    this->set_id_aresta3(0);

}

Face::Face(std::size_t id_aresta1, std::size_t id_aresta2, std::size_t id_aresta3) {

    this->set_id_aresta1(id_aresta1);
    this->set_id_aresta2(id_aresta2);
    this->set_id_aresta3(id_aresta3);

}

std::size_t Face::get_id_aresta1() const {

    return this->id_aresta1;

}
void Face::set_id_aresta1(std::size_t id) {

    this->id_aresta1 = id;   

}

std::size_t Face::get_id_aresta2() const {

    return this->id_aresta2;

}
void Face::set_id_aresta2(std::size_t id) {

    this->id_aresta2 = id;   

}

std::size_t Face::get_id_aresta3() const {

    return this->id_aresta3;

}
void Face::set_id_aresta3(std::size_t id) {

    this->id_aresta3 = id;   

}