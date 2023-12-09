#include "geometria/Triangulo.hpp"
#include "geometria/Plano.hpp"
#include <cmath>

Triangulo::Triangulo(Material material) : Solido(material) {

    this->vertice1 = Ponto3(1.0, 0.0, 0.0);
    this->vertice2 = Ponto3(0.0, 1.0, 0.0);
    this->vertice3 = Ponto3(0.0, 0.0, 1.0);

    this->normal = (this->vertice2 - this->vertice1).vetorial(this->vertice3 - this->vertice1).unitario();

}

Triangulo::Triangulo(Ponto3 vertice1, Ponto3 vertice2, Ponto3 vertice3, Material material) : Solido(material) {

    this->vertice1 = vertice1;
    this->vertice2 = vertice2;
    this->vertice3 = vertice3;

    this->normal = (vertice2 - vertice1).vetorial(vertice3 - vertice1).unitario();

}

Ponto3 Triangulo::get_vertice1() const {

    return this->vertice1;

}
void Triangulo::set_vertice1(Ponto3 v) {

    this->vertice1 = v;
    this->normal = (vertice2 - vertice1).vetorial(vertice3 - vertice1).unitario();

}

Ponto3 Triangulo::get_vertice2() const {

    return this->vertice2;

}
void Triangulo::set_vertice2(Ponto3 v) {

    this->vertice2 = v;
    this->normal = (vertice2 - vertice1).vetorial(vertice3 - vertice1).unitario();

}

Ponto3 Triangulo::get_vertice3() const {

    return this->vertice3;

}
void Triangulo::set_vertice3(Ponto3 v) {

    this->vertice3 = v;
    this->normal = (vertice2 - vertice1).vetorial(vertice3 - vertice1).unitario();

}

double Triangulo::escalar_interseccao(Raio& raio) const {

    // Plano do triângulo.
    Plano plano(this->vertice1, this->normal);

    // Escalar distância até a intersecção.
    double t_int;

    // Área do triângulo vezes dois.
    double area_triangulo_vezes_2;

    // Ponto de intersecção.
    Ponto3 p_int;

    // Vetores para auxiliar nos cálculos.
    Vetor3 r1, r2, v;

    // Coordenadas baricêntricas.
    double c1, c2, c3;

    t_int = plano.escalar_interseccao(raio);

    if (t_int >= 0) {

        p_int = raio.ponto_do_raio(t_int);
        
        r1 = this->get_vertice2() - this->get_vertice1();
        r2 = this->get_vertice3() - this->get_vertice1();
        v = p_int - this->get_vertice1();

        area_triangulo_vezes_2 = r1.vetorial(r2).escalar(this->normal);

        c1 = v.vetorial(r2).escalar(this->normal) / area_triangulo_vezes_2;
        c2 = r1.vetorial(v).escalar(this->normal) / area_triangulo_vezes_2;
        c3 = 1.0 - c1 - c2;

        if (c1 >= 0.0 && c2 >= 0.0 && c3 >= 0.0 && std::abs(c1 + c2 + c3 - 1.0) <= 1.0e-12) {

            return t_int;

        }

    }

    return -1.0;

}

Vetor3 Triangulo::vetor_normal_ponto(Ponto3 ponto) const {

    return this->normal;

}