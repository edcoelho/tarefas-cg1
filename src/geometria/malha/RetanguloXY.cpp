#include "geometria/malha/RetanguloXY.hpp"

// --- CONSTRUTORES ---

RetanguloXY::RetanguloXY() {

    this->centro_base = Ponto3();
    this->largura = 30.0;
    this->altura = 60.0;
    this->set_material(Material());
    this->sentido_vetor_normal = true;

    this->calcular_estrutura();

}

RetanguloXY::RetanguloXY(Ponto3 centro_base, double largura, double altura, Material material, bool sentido_vetor_normal) {

    this->centro_base = centro_base;
    this->largura = largura;
    this->altura = altura;
    this->set_material(material);
    this->sentido_vetor_normal = sentido_vetor_normal;

    this->calcular_estrutura();

}

// --- GETTERS E SETTERS ---

Ponto3 RetanguloXY::get_centro_base() {

    return this->centro_base;

}

double RetanguloXY::get_largura() {

    return this->largura;

}

double RetanguloXY::get_altura() {

    return this->altura;

}

bool RetanguloXY::get_sentido_vetor_normal() {

    return this->sentido_vetor_normal;

}

void RetanguloXY::calcular_estrutura() {

    if (this->get_sentido_vetor_normal()) {

        // Inserindo vértices de forma que a normal da face aponte para o Z positivo.
        this->inserir_vertice(this->get_centro_base() + Vetor3(-1.0*this->get_largura()/2.0, 0.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(this->get_largura()/2.0, 0.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(-1.0*this->get_largura()/2.0, this->get_altura(), 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(this->get_largura()/2.0, this->get_altura(), 0.0));

    } else {

        // Inserindo vértices de forma que a normal da face aponte para o Z negativo.
        this->inserir_vertice(this->get_centro_base() + Vetor3(this->get_largura()/2.0, 0.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(-1.0*this->get_largura()/2.0, 0.0, 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(this->get_largura()/2.0, this->get_altura(), 0.0));
        this->inserir_vertice(this->get_centro_base() + Vetor3(-1.0*this->get_largura()/2.0, this->get_altura(), 0.0));

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

void RetanguloXY::recalcular_atributos() {

    this->largura = (this->vertices[0] - this->vertices[1]).norma();
    this->altura = (this->vertices[0] - this->vertices[2]).norma();

}

void RetanguloXY::transformar(Matriz4 const& matriz) {

    this->vertices.push_back(this->centro_base);

    Malha::transformar(matriz);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::transladar(double x, double y, double z) {

    this->vertices.push_back(this->centro_base);

    Malha::transladar(x, y, z);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::rotacionar(double angulo, EixoCanonico eixo) {

    this->vertices.push_back(this->centro_base);

    Malha::rotacionar(angulo, eixo);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::rotacionar(double angulo, Ponto3 ponto_eixo, Vetor3 direcao_eixo) {

    this->vertices.push_back(this->centro_base);

    Malha::rotacionar(angulo, ponto_eixo, direcao_eixo);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::escalar(double fator_x, double fator_y, double fator_z, Ponto3 ponto_amarra) {

    this->vertices.push_back(this->centro_base);

    Malha::escalar(fator_x, fator_y, fator_z, ponto_amarra);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::cisalhar(double angulo, EixoCanonico eixo1, EixoCanonico eixo2, Ponto3 ponto_amarra) {

    this->vertices.push_back(this->centro_base);

    Malha::cisalhar(angulo, eixo1, eixo2, ponto_amarra);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::espelhar(EixoCanonico eixo1, EixoCanonico eixo2) {

    this->vertices.push_back(this->centro_base);

    Malha::espelhar(eixo1, eixo2);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}

void RetanguloXY::espelhar(Vetor3 vetor_normal_plano, Ponto3 ponto_plano) {

    this->vertices.push_back(this->centro_base);

    Malha::espelhar(vetor_normal_plano, ponto_plano);

    this->centro_base = this->vertices.back();
    this->vertices.pop_back();

    this->recalcular_atributos();

}
