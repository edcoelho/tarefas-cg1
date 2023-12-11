#include "geometria/malha/Piramide.hpp"

// --- CONSTRUTORES ---

Piramide::Piramide(Ponto3 centro_base, double largura_base, double comprimento_base, double altura, Material material): MalhaEspecifica("Pirâmide", material) {

    this->centro_base = centro_base;
    this->largura_base = largura_base;
    this->comprimento_base = comprimento_base;
    this->altura = altura;

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

void Piramide::recalcular_atributos() {

    this->largura_base = (this->vertices[0] - this->vertices[1]).norma();
    this->comprimento_base = (this->vertices[0] - this->vertices[2]).norma();
    this->altura = (this->centro_base - this->vertices[4]).norma();

}

IntensidadeLuz Piramide::cor_textura(Ponto3 ponto) { return this->get_material().get_k_D(); }

void Piramide::transformar(Matriz4 const& matriz) {

    this->vertices.push_back(this->centro_base);

    Malha::transformar(matriz);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::transladar(double x, double y, double z) {

    this->vertices.push_back(this->centro_base);

    Malha::transladar(x, y, z);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::rotacionar(double angulo, EixoCanonico eixo) {

    this->vertices.push_back(this->centro_base);

    Malha::rotacionar(angulo, eixo);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::rotacionar(double angulo, Ponto3 ponto_eixo, Vetor3 direcao_eixo) {

    this->vertices.push_back(this->centro_base);

    Malha::rotacionar(angulo, ponto_eixo, direcao_eixo);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::escalar(double fator_x, double fator_y, double fator_z, Ponto3 ponto_amarra) {

    this->vertices.push_back(this->centro_base);

    Malha::escalar(fator_x, fator_y, fator_z, ponto_amarra);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::cisalhar(double angulo, EixoCanonico eixo1, EixoCanonico eixo2, Ponto3 ponto_amarra) {

    this->vertices.push_back(this->centro_base);

    Malha::cisalhar(angulo, eixo1, eixo2, ponto_amarra);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::refletir(EixoCanonico eixo1, EixoCanonico eixo2) {

    this->vertices.push_back(this->centro_base);

    Malha::refletir(eixo1, eixo2);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void Piramide::refletir(Vetor3 vetor_normal_plano, Ponto3 ponto_plano) {

    this->vertices.push_back(this->centro_base);

    Malha::refletir(vetor_normal_plano, ponto_plano);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}
