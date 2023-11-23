#include "geometria/malha/Piramide.hpp"

// --- CONSTRUTORES ---

Piramide::Piramide() {

    this->centro_base = Ponto3();
    this->largura_base = 30.0;
    this->comprimento_base = 30.0;
    this->altura = 60.0;
    this->set_material(Material());

    this->calcular_estrutura();

}

Piramide::Piramide(Ponto3 centro_base, double largura_base, double comprimento_base, double altura, Material material) {

    this->centro_base = centro_base;
    this->largura_base = largura_base;
    this->comprimento_base = comprimento_base;
    this->altura = altura;
    this->set_material(material);

    this->calcular_estrutura();

}

// --- GETTERS ---

Ponto3 Piramide::get_centro_base() {

    return this->centro_base;

}

double Piramide::get_largura_base() {

    return this->largura_base;

}

double Piramide::get_comprimento_base() {

    return this->comprimento_base;

}

double Piramide::get_altura() {

    return this->altura;

}

void Piramide::calcular_estrutura() {

    // Inserindo os vértices.
    this->inserir_vertice(centro_base + Vetor3(-1.0*this->get_largura_base()/2.0, 0.0, this->get_comprimento_base()/2.0));
    this->inserir_vertice(centro_base + Vetor3(this->get_largura_base()/2.0, 0.0, this->get_comprimento_base()/2.0));
    this->inserir_vertice(centro_base + Vetor3(-1.0*this->get_largura_base()/2.0, 0.0, -1.0*this->get_comprimento_base()/2.0));
    this->inserir_vertice(centro_base + Vetor3(this->get_largura_base()/2.0, 0.0, -1.0*this->get_comprimento_base()/2.0));

    this->inserir_vertice(centro_base + Vetor3(0.0, this->get_altura(), 0.0));

    // Inserindo as arestas.
    this->inserir_aresta(Aresta(1, 2)); // 1
    this->inserir_aresta(Aresta(2, 3)); // 2
    this->inserir_aresta(Aresta(3, 1)); // 3
    this->inserir_aresta(Aresta(2, 4)); // 4
    this->inserir_aresta(Aresta(4, 3)); // 5

    this->inserir_aresta(Aresta(1, 5)); // 6
    this->inserir_aresta(Aresta(2, 5)); // 7
    this->inserir_aresta(Aresta(3, 5)); // 8
    this->inserir_aresta(Aresta(4, 5)); // 9

    // Inserindo as faces.
    this->inserir_face(Face(1, 3, 2));
    this->inserir_face(Face(5, 4, 2));

    this->inserir_face(Face(1, 7, 6));
    this->inserir_face(Face(4, 9, 7));
    this->inserir_face(Face(5, 8, 9));
    this->inserir_face(Face(3, 6, 8));

}