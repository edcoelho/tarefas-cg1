#include "Cone.hpp"
#include <cmath>

Cone::Cone() {

    this->setCentroBase(Ponto3(0.0, -1.0, 0.0));
    this->setVertice(Ponto3(0.0, 1.0, 0.0));
    this->setDirecao(Vetor3(0.0, 1.0, 0.0));
    this->setRaioBase(1);
    this->setAltura(2);

}

Cone::Cone(Ponto3 centroBase, Ponto3 vertice, double raioBase, Material m) {

    Vetor3 vetor_altura = vertice - centroBase;

    this->setCentroBase(centroBase);
    this->setVertice(vertice);
    this->setDirecao(vetor_altura);
    this->setRaioBase(raioBase);
    this->setAltura(vetor_altura.norma());
    this->setMaterial(m);

}

Cone::Cone(Ponto3 centroBase, Vetor3 direcao, double raioBase, double altura, Material m) {

    this->setCentroBase(centroBase);
    this->setVertice(centroBase + (direcao * altura));
    this->setDirecao(direcao);
    this->setRaioBase(raioBase);
    this->setAltura(altura);
    this->setMaterial(m);

}

Ponto3 Cone::getCentroBase() const {

    return this->centroBase;

}
void Cone::setCentroBase(Ponto3 cb, bool recalcular) {

    Vetor3 vetor_altura = this->getVertice() - cb;

    this->centroBase = cb;

    if (recalcular) {

        this->setDirecao(vetor_altura);
        this->setAltura(vetor_altura.norma());

    }

}

Ponto3 Cone::getVertice() const {

    return this->vertice;

}
void Cone::setVertice(Ponto3 v, bool recalcular) {

    Vetor3 vetor_altura = v - this->getCentroBase();

    this->vertice = v;

    if (recalcular) {

        this->setDirecao(vetor_altura);
        this->setAltura(vetor_altura.norma());

    }

}

Vetor3 Cone::getDirecao() const {

    return this->direcao;

}
void Cone::setDirecao(Vetor3 d, bool recalcular) {

    d.normalizar();
    this->direcao = d;

    if (recalcular) {

        this->setVertice(this->getCentroBase() + (d * this->getAltura()));

    }

}

double Cone::getRaioBase() const {

    return this->raioBase;

}
void Cone::setRaioBase(double r) {

    this->raioBase = r;

}

double Cone::getAltura() const {

    return this->altura;

}
void Cone::setAltura(double a, bool recalcular) {

    this->altura = a;

    if (recalcular) {

        this->setVertice(this->getCentroBase() + (this->getDirecao() * this->getAltura()));

    }

}

double Cone::escalarInterseccao(RaioRayCasting& raio) const {

    // w = raio.p0 - centro_base
    Vetor3 w = raio.getPInicial() - this->getCentroBase();

    Plano base(this->getCentroBase(), this->getDirecao(), this->getMaterial());

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0, // Coscientes da equação de 2º grau.
           t_int = 0.0, // Distância do início do raio até o ponto de intersecção mais próximo.
           t_int1 = 0.0, t_int2 = 0.0, // Distâncias do início do raio até os pontos de intersecção.
           t_int_base = 0.0, // Distância do início do raio até o ponto de intersecção com a base do cone.

           beta = std::pow(this->getAltura(), 2) / std::pow(this->getRaioBase(), 2), // beta = altura_cone² / raio_cone²
           dr_escalar_dc = raio.getVDirecao().pEscalar(this->getDirecao()), // Resultado do produto escalar da direção do raio com a direção do cone.
           w_escalar_dr = w.pEscalar(raio.getVDirecao()), // Resultado do produto escalar do vetor com o vetor direção do raio.
           w_escalar_dc = w.pEscalar(this->getDirecao()), // Resultado do produto escalar do vetor w com o vetor direção do cone.
           v_escalar_dc = 0.0; // Resultado do produto escalar do vetor v (ponto_inicial_raio - centro_base) com a direção do cone.

    // a = beta - beta*(dr . dc)² - (dr . dc)²
    a = beta - std::pow(dr_escalar_dc, 2)*(beta + 1.0);

    // b = 2*beta*(w . dr) - 2*beta*(w . dc)*(dr . dc) - 2*(w . dc)*(dr . dc) + 2*altura_cone*(dr . dc)
    b = 2.0*(beta*(w_escalar_dr - w_escalar_dc*dr_escalar_dc) - w_escalar_dc*dr_escalar_dc + this->getAltura()*dr_escalar_dc);
    
    // c = beta*(w . w) - beta*(w . dc)² - (w . dc)² - altura_cone² + 2*altura_cone*(w . dc)
    c = beta*w.pEscalar(w) - std::pow(w_escalar_dc, 2)*(beta + 1.0) - std::pow(this->getAltura(), 2) + 2.0*this->getAltura()*w_escalar_dc;
    
    delta = std::pow(b, 2) - 4.0 * a * c;

    // Checando se houve intersecção.
    if (delta > 0.0) {

        t_int1 = (-b + std::sqrt(delta)) / (2.0 * a);
        t_int2 = (-b - std::sqrt(delta)) / (2.0 * a);

        // Checando se a primeira raíz é uma intersecção válida.
        v_escalar_dc = (raio.pontoDoRaio(t_int1) - this->getCentroBase()).pEscalar(this->getDirecao());  

        if (0.0 > v_escalar_dc || v_escalar_dc > this->getAltura()) {

            t_int1 = -1.0;

        }

        // Checando se a segunda raíz é uma intersecção válida.
        v_escalar_dc = (raio.pontoDoRaio(t_int2) - this->getCentroBase()).pEscalar(this->getDirecao());

        if (0.0 > v_escalar_dc || v_escalar_dc > this->getAltura()) {

            t_int2 = -1.0;

        }

        // Escolhendo a raíz que represente a intersecção válida mais próxima.

        if (t_int1 >= 0.0 && t_int2 >= 0.0) {

            if (t_int1 < t_int2) {

                t_int = t_int1;

            } else {

                t_int = t_int2;

            }

        } else if (t_int1 >= 0.0 || t_int2 >= 0.0) {

            // Anotando o t_int válido no corpo do cone.
            if (t_int1 >= 0.0) {

                t_int = t_int1;

            } else {

                t_int = t_int2;

            }

            // Calculando a intersecção no plano da base.
            t_int_base = base.escalarInterseccao(raio);

            // Anotando se a intersecção com a base do cone é válida.
            if (t_int_base >= 0.0 && (raio.pontoDoRaio(t_int_base) - this->getCentroBase()).norma() > this->getRaioBase()) {

                t_int_base = -1.0;

            }

            // Checando se a intersecção na base do cone foi válida e se ela é mais próxima que a intersecção já anotada do corpo.
            if (t_int_base >= 0.0 && t_int_base < t_int) {

                t_int = t_int_base;

            }

        } else {

            t_int = -1.0;

        }

    } else if (delta == 0.0) {

        t_int1 = -b / (2.0 * a);

        v_escalar_dc = (raio.pontoDoRaio(t_int1) - this->getCentroBase()).pEscalar(this->getDirecao());

        if (0.0 <= v_escalar_dc && v_escalar_dc <= this->getAltura()) {

            t_int = t_int1;

        } else {

            t_int = -1.0;

        }

    } else {

        t_int = -1.0;

    }

    return t_int;

}

Vetor3 Cone::vetorNormalPonto(Ponto3 ponto) const {

    Vetor3 ponto_vertice, n, v;
    double v_escalar_dc, erro = 1e-12;

    ponto_vertice = this->getVertice() - ponto;
    v = ponto - this->getCentroBase();
    v_escalar_dc = v.pEscalar(this->getDirecao());

    if (0.0 + erro < v_escalar_dc) {

        n = ponto_vertice.pVetorial(this->getDirecao());
        n = n.pVetorial(ponto_vertice);
        n.normalizar();

        return n;

    } else {

        return this->getDirecao() * -1.0;

    }

}
