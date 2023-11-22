#include "geometria/malha/Aresta.hpp"

Aresta::Aresta() {

    this->set_id_vertice1(0);
    this->set_id_vertice2(0);

}

Aresta::Aresta(std::size_t id_vertice1, std::size_t id_vertice2) {

    this->set_id_vertice1(id_vertice1);
    this->set_id_vertice2(id_vertice2);

}

std::size_t Aresta::get_id_vertice1() const {

    return this->id_vertice1;

}
void Aresta::set_id_vertice1(std::size_t id) {

    this->id_vertice1 = id;

}

std::size_t Aresta::get_id_vertice2() const {

    return this->id_vertice2;

}
void Aresta::set_id_vertice2(std::size_t id) {

    this->id_vertice2 = id;

}