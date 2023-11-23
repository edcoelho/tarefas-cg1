#include "geometria/malha/Malha.hpp"
#include <cmath>

Malha::Malha() {}

Malha::Malha(Material material) {

    this->set_material(material);

}

Malha::Malha(std::vector<Ponto3> vertices, std::vector<Aresta> arestas, std::vector<Face> faces, Material material) {

    this->vertices = vertices;
    this->arestas = arestas;
    this->faces = faces;
    this->set_material(material);

}

Material Malha::get_material() const {

    return this->material;

}
void Malha::set_material(Material m) {

    this->material = m;

}

std::size_t Malha::get_id_ultima_face() const {

    return this->id_ultima_face;

}
void Malha::set_id_ultima_face(std::size_t id) {

    this->id_ultima_face = id;

}

Ponto3 Malha::buscar_vertice_por_id(std::size_t id) const {

    return this->vertices[id - 1];

}
void Malha::inserir_vertice(Ponto3 v) {

    this->vertices.push_back(v);

}

Aresta Malha::buscar_aresta_por_id(std::size_t id) const {

    return this->arestas[id - 1];

}
void Malha::inserir_aresta(Aresta a) {

    this->arestas.push_back(a);

}

Face Malha::buscar_face_por_id(std::size_t id) const {

    return this->faces[id - 1];

}
void Malha::inserir_face(Face f) {

    this->faces.push_back(f);

}

double Malha::escalar_interseccao(Raio& raio) {

    double t_int = -1.0;
    double min_t_int = INFINITY;

    std::size_t id;

    // Itera sobre as faces. Os IDs começam a contar a partir de 1.
    for (id = 1; id <= this->faces.size(); id++) {

        t_int = this->triangulo_por_id_face(id).escalar_interseccao(raio);

        if (t_int >= 0.0 && t_int < min_t_int) {

            min_t_int = t_int;
            this->set_id_ultima_face(id);

        }

    }

    if (min_t_int < INFINITY) {

        return min_t_int;

    }

    return -1.0;

}

Triangulo Malha::triangulo_por_id_face(std::size_t id_face) const {

    // IDs dos vertices da face.

    std::size_t id_vertice_1, id_vertice_2, id_vertice_3;

    // IDs das arestas da face.
    std::size_t id_aresta_1, id_aresta_2;

    // IDs dos vértices das arestas.

    std::size_t id_vertice_1_aresta_1, id_vertice_2_aresta_1;
    std::size_t id_vertice_1_aresta_2, id_vertice_2_aresta_2;

    // Variáveis auxiliares.

    std::size_t aux1;
    float aux2;

    Face face;
    Aresta aresta1, aresta2;

    face = this->buscar_face_por_id(id_face);

    id_aresta_1 = face.get_id_aresta1();
    id_aresta_2 = face.get_id_aresta2();

    aresta1 = this->buscar_aresta_por_id(id_aresta_1);
    aresta2 = this->buscar_aresta_por_id(id_aresta_2);

    id_vertice_1_aresta_1 = aresta1.get_id_vertice1();
    id_vertice_2_aresta_1 = aresta1.get_id_vertice2();
    id_vertice_1_aresta_2 = aresta2.get_id_vertice1();
    id_vertice_2_aresta_2 = aresta2.get_id_vertice2();

    // Determinando vértices em sentido anti-horário.

    aux1 = id_vertice_1_aresta_1 * id_vertice_2_aresta_1;
    aux2 = (float) aux1 / (float) id_vertice_1_aresta_2;

    if (aux2 == ((float) id_vertice_1_aresta_1) || aux2 == ((float) id_vertice_2_aresta_1)) {

        id_vertice_1 = id_vertice_1_aresta_2;
        id_vertice_2 = id_vertice_2_aresta_2;
        id_vertice_3 = aux2;

    } else {

        id_vertice_1 = id_vertice_2_aresta_2;
        id_vertice_2 = id_vertice_1_aresta_2;
        id_vertice_3 = aux1 / id_vertice_2_aresta_2;
        
    }

    return Triangulo(this->buscar_vertice_por_id(id_vertice_1), this->buscar_vertice_por_id(id_vertice_2), this->buscar_vertice_por_id(id_vertice_3), this->get_material());

}