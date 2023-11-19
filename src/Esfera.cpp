#include "Esfera.hpp"
#include <cmath>

Esfera::Esfera() {

    this->set_centro(Ponto3(0.0, 0.0, 0.0));
    this->set_raio(1.0);

}

Esfera::Esfera(Ponto3 centro, double raio, Material material) {

    this->set_centro(centro);
    this->set_raio(raio);
    this->set_material(material);

}

Ponto3 Esfera::get_centro() const {

    return this->centro;

}
void Esfera::set_centro(Ponto3 centro) {

    this->centro = centro;

}

double Esfera::get_raio() const {

    return this->raio;

}
void Esfera::set_raio(double raio) {

    this->raio = raio;

}

double Esfera::escalar_interseccao(Raio& raio) const {

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0, // Coscientes da equação de 2º grau.
           raiz = 0.0, // Raíz da equação.
           aux = 0.0; // Variável para auxiliar nos cálculos.

    Vetor3 v_aux; // Vetor para auxiliar nos cálculos.

    // a = dr . dr
    a = raio.get_direcao().escalar(raio.get_direcao());
    // b = 2 ((ponto_inicial - centro_esfera) . dr)
    v_aux = raio.get_ponto_inicial() - this->get_centro();
    b = 2.0 * v_aux.escalar(raio.get_direcao());
    // c = (ponto_inicial - centro_esfera) . (ponto_inicial - centro_esfera) - raio_esfera²
    c = v_aux.escalar(v_aux) - std::pow(this->get_raio(), 2);

    //delta = b² - 4ac
    delta = std::pow(b, 2) - 4*a*c;

    // raiz = (-b +- sqrt(delta))/2a
    if (delta > 0) {
        
        // Escolhendo a menor raíz.
        raiz = (-1*b + std::sqrt(delta)) / (2.0*a);
        aux = (-1*b - std::sqrt(delta)) / (2.0*a);
        if (aux < raiz) raiz = aux;

    } else if (delta == 0)
        
        raiz = -b / (2.0*a);
    
    else raiz = -1;

    return raiz;

}

Vetor3 Esfera::vetor_normal_ponto(Ponto3 ponto) const {

    return (ponto - this->get_centro()).unitario();

}