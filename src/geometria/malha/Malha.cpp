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

void Malha::transladar(double x, double y, double z) {

    Matriz4 matriz_t;

    matriz_t(0, 3) = x;
    matriz_t(1, 3) = y;
    matriz_t(2, 3) = z;

    for (auto& vertice : this->vertices) {

        vertice = matriz_t * vertice;

    }

}

void Malha::rotacionar(double angulo, tipo_eixo eixo) {

    Matriz4 matriz_r;
    double cos_angulo, sen_angulo;

    cos_angulo = std::cos(angulo);
    sen_angulo = std::sin(angulo);

    if (eixo == EIXO_X) {

        matriz_r(1, 1) = cos_angulo;
        matriz_r(1, 2) = -sen_angulo;
        matriz_r(2, 1) = sen_angulo;
        matriz_r(2, 2) = cos_angulo;

    } else if (eixo == EIXO_Y) {

        matriz_r(0, 0) = cos_angulo;
        matriz_r(0, 2) = sen_angulo;
        matriz_r(2, 0) = -sen_angulo;
        matriz_r(2, 2) = cos_angulo;

    } else {

        matriz_r(0, 0) = cos_angulo;
        matriz_r(0, 1) = -sen_angulo;
        matriz_r(1, 0) = sen_angulo;
        matriz_r(1, 1) = cos_angulo;

    }

    for (auto& vertice : this->vertices) {

        vertice = matriz_r * vertice;

    }

}

/*
void Malha::rotacionar(double angulo, Ponto3 ponto_eixo, Vetor3 direcao_eixo) {

    Matriz4 matriz_r, matriz_x_linha_para_x, matriz_r_z, matriz_x_para_x_linha;
    Vetor3 i_linha, j_linha, k_linha;
    double cos_angulo, sen_angulo;

    k_linha = direcao_eixo.unitario();
    j_linha = (k_linha * Vetor3(-k_linha[1], k_linha[0], 0.0)).unitario();
    i_linha = (j_linha * k_linha).unitario();

    cos_angulo = std::cos(angulo);
    sen_angulo = std::sin(angulo);

    matriz_r_z(0, 0) = cos_angulo;
    matriz_r_z(0, 1) = -sen_angulo;
    matriz_r_z(1, 0) = sen_angulo;
    matriz_r_z(1, 1) = cos_angulo;

    for (int c = 0; c < 3; c++) {

        matriz_x_linha_para_x(c, 0) = i_linha[c];
        matriz_x_linha_para_x(c, 1) = j_linha[c];
        matriz_x_linha_para_x(c, 2) = k_linha[c];
        matriz_x_linha_para_x(c, 3) = ponto_eixo[c];

        matriz_x_para_x_linha(0, c) = i_linha[c];
        matriz_x_para_x_linha(1, c) = j_linha[c];
        matriz_x_para_x_linha(2, c) = k_linha[c];

    }

    matriz_x_para_x_linha(0, 3) = -i_linha.escalar(ponto_eixo.vetor());
    matriz_x_para_x_linha(1, 3) = -j_linha.escalar(ponto_eixo.vetor());
    matriz_x_para_x_linha(2, 3) = -k_linha.escalar(ponto_eixo.vetor());

    matriz_r = matriz_x_linha_para_x * matriz_r_z * matriz_x_para_x_linha;

    for (auto& vertice : this->vertices) {

        vertice = matriz_r * vertice;

    }

}
*/

void Malha::rotacionar(double angulo, Ponto3 ponto_eixo, Vetor3 direcao_eixo) {

    Matriz4 matriz_r;
    Vetor3 i, j, k;
    double cos_angulo, sen_angulo, i_escalar_p, j_escalar_p, k_escalar_p, a, b, c, d, e, f;

    k = direcao_eixo.unitario();
    j = (k * Vetor3(-k[1], k[0], 0.0)).unitario();
    i = (j * k).unitario();


    // Valores repetidos com frequência no cálculo da matriz.

    cos_angulo = std::cos(angulo);
    sen_angulo = std::sin(angulo);

    i_escalar_p = i.escalar(ponto_eixo.vetor());
    j_escalar_p = j.escalar(ponto_eixo.vetor());
    k_escalar_p = k.escalar(ponto_eixo.vetor());

    a = j[0] * sen_angulo + i[0] * cos_angulo;
    b = j[0] * cos_angulo - i[0] * sen_angulo;

    c = j[1] * sen_angulo + i[1] * cos_angulo;
    d = j[1] * cos_angulo - i[1] * sen_angulo;

    e = i[2] * cos_angulo + j[2] * sen_angulo;
    f = j[2] * cos_angulo - i[2] * sen_angulo;

    // 1ª linha

    matriz_r(0, 0) = (i[0] * i[0] + j[0] * j[0]) * cos_angulo + k[0] * k[0];
    matriz_r(0, 1) = i[1] * a + k[0] * k[1] + j[1] * b;
    matriz_r(0, 2) = i[2] * a + k[0] * k[2] + j[2] * b;
    matriz_r(0, 3) = ponto_eixo[0] - i_escalar_p * a - j_escalar_p * b - k[0] * k_escalar_p;

    // 2ª linha

    matriz_r(1, 0) = i[0] * c + j[0] * d + k[0] * k[1];
    matriz_r(1, 1) = (i[1] * i[1] + j[1] * j[1]) * cos_angulo + k[1] * k[1];
    matriz_r(1, 2) = i[2] * c + k[1] * k[2] + j[2] * d;
    matriz_r(1, 3) = ponto_eixo[1] - i_escalar_p * c - j_escalar_p * d - k[1] * k_escalar_p;
    
    // 3ª linha

    matriz_r(2, 0) = i[0] * e + k[0] * k[2] + j[0] * f;
    matriz_r(2, 1) = i[1] * e + k[1] * k[2] + j[1] * f;
    matriz_r(2, 2) = (i[2] * i[2] + j[2] * j[2]) * cos_angulo + k[2] * k[2];
    matriz_r(2, 3) = ponto_eixo[2] - i_escalar_p * e - j_escalar_p * f - k[2] * k_escalar_p;


    for (auto& vertice : this->vertices) {

        vertice = matriz_r * vertice;

    }

}