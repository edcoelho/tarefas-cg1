#include "geometria/malha/RetanguloYZ.hpp"

// --- CONSTRUTORES ---

RetanguloYZ::RetanguloYZ() {

    this->centro_base = Ponto3();
    this->largura = 30.0;
    this->altura = 60.0;
    this->set_material(Material());
    this->sentido_vetor_normal = true;

    this->calcular_estrutura();

}

RetanguloYZ::RetanguloYZ(Ponto3 centro_base, double largura, double altura, Material material, bool sentido_vetor_normal) {

    this->centro_base = centro_base;
    this->largura = largura;
    this->altura = altura;
    this->set_material(material);
    this->sentido_vetor_normal = sentido_vetor_normal;

    this->calcular_estrutura();

}

// --- GETTERS E SETTERS ---

Ponto3 RetanguloYZ::get_centro_base() {

    return this->centro_base;

}

double RetanguloYZ::get_largura() {

    return this->largura;

}

double RetanguloYZ::get_altura() {

    return this->altura;

}

bool RetanguloYZ::get_sentido_vetor_normal() {

    return this->sentido_vetor_normal;

}

void RetanguloYZ::calcular_estrutura() {

    if (this->get_sentido_vetor_normal()) {

        // Inserindo vértices de forma que a normal da face aponte para o X positivo.
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, -1.0*this->get_largura()/2.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, this->get_largura()/2.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, -1.0*this->get_largura()/2.0, this->get_altura()));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, this->get_largura()/2.0, this->get_altura()));

    } else {

        // Inserindo vértices de forma que a normal da face aponte para o X negativo.
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, this->get_largura()/2.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, -1.0*this->get_largura()/2.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, this->get_largura()/2.0, this->get_altura()));
        this->inserir_vertice(this->get_centro_base() + Vetor3(0.0, -1.0*this->get_largura()/2.0, this->get_altura()));

    }

    // Inserindo arestas.
    this->inserir_aresta(Aresta(1, 2));
    this->inserir_aresta(Aresta(2, 3));
    this->inserir_aresta(Aresta(3, 1));
    this->inserir_aresta(Aresta(2, 4));
    this->inserir_aresta(Aresta(4, 3));

    // Inserindo faces.
    this->inserir_face(Face(1, 2, 3));
    this->inserir_face(Face(2, 4, 5));

}