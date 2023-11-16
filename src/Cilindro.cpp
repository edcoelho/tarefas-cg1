#include "Cilindro.hpp"
#include <cmath>

Cilindro::Cilindro() {

    this->setCentroBase(Ponto3(0.0, -1.0, 0.0));
    this->setCentroTopo(Ponto3(0.0, 1.0, 0.0));
    this->setDirecao(Vetor3(0.0, 1.0, 0.0));
    this->setAltura(2);
    this->setRaio(1);

}

Cilindro::Cilindro(Ponto3 centroBase, Ponto3 centroTopo, double raio, Material material) {

    Vetor3 vetorAltura = centroTopo - centroBase;

    this->setCentroBase(centroBase);
    this->setCentroTopo(centroTopo);
    this->setDirecao(vetorAltura);
    this->setAltura(vetorAltura.norma());
    this->setRaio(raio);
    this->setMaterial(material);

}

Cilindro::Cilindro(Ponto3 centroBase, Vetor3 direcao, double raio, double altura, Material material) {

    this->setCentroBase(centroBase);
    this->setDirecao(direcao);
    this->setRaio(raio);
    this->setAltura(altura);
    this->setMaterial(material);
    this->setCentroTopo(centroBase + (this->getDirecao() * altura));
    
}

Ponto3 Cilindro::getCentroBase() const {

    return this->centroBase;

}
void Cilindro::setCentroBase(Ponto3 cb, bool recalcular) {

    Vetor3 vetorAltura = this->getCentroTopo() - cb;

    this->centroBase = cb;

    if (recalcular) {

        this->setDirecao(vetorAltura);
        this->setAltura(vetorAltura.norma());

    }

}

Ponto3 Cilindro::getCentroTopo() const {

    return this->centroTopo;

}
void Cilindro::setCentroTopo(Ponto3 ct, bool recalcular) {

    Vetor3 vetorAltura = ct - this->getCentroBase();

    this->centroTopo = ct;

    if (recalcular) {

        this->setDirecao(vetorAltura);
        this->setAltura(vetorAltura.norma());

    }

}

Vetor3 Cilindro::getDirecao() const {

    return this->direcao;

}
void Cilindro::setDirecao(Vetor3 d, bool recalcular) {

    d.normalizar();
    this->direcao = d;

    if (recalcular) {

        this->setCentroTopo(this->getCentroBase() + (d * this->getAltura()));

    }

}

double Cilindro::getAltura() const {

    return this->altura;

}
void Cilindro::setAltura(double a, bool recalcular) {

    this->altura = a;

    if (recalcular) {

        this->setCentroTopo(this->getCentroBase() + (this->getDirecao() * this->getAltura()));

    }

}

double Cilindro::getRaio() const {

    return this->raio;
    
}
void Cilindro::setRaio(double r) {

    this->raio = r;

}

double Cilindro::escalarInterseccao(RaioRayCasting& raio) const {

    // w = P0 - centro_base
    Vetor3 w = raio.getPInicial() - this->getCentroBase();

    Plano base(this->getCentroBase(), this->getDirecao(), this->getMaterial()),
          topo(this->getCentroTopo(), this->getDirecao(), this->getMaterial());

    double delta = 0.0, // Delta da equação de 2º grau.
           a = 0.0, b = 0.0, c = 0.0, // Coscientes da equação de 2º grau.
           t_int = 0.0, // Distância do início do raio até o ponto de intersecção mais próximo.
           t_int1 = 0.0, t_int2 = 0.0, // Distâncias do início do raio até os pontos de intersecção.
           t_int_base = 0.0, // Distância do início do raio até o ponto de intersecção com a base do cilíndro.
           t_int_topo = 0.0, // Distância do início do raio até o ponto de intersecção com o topo do cilíndro.

           dr_escalar_dc = raio.getVDirecao().pEscalar(this->getDirecao()), // Resultado do produto escalar da direção do raio com a direção do cilíndro.
           w_escalar_dc = w.pEscalar(this->getDirecao()), // Resultado do produto escalar do vetor w com a direção do cilíndro.
           v_escalar_dc = 0.0; // Resultado do produto escalar do vetor v (ponto_inicial_raio - centro_base) com a direção do cilíndro.

    // Checando o raio é paralelo ao eixo do cilíndro.
    if (std::abs(dr_escalar_dc) != 1.0) {

        // a = direcao_raio . direcao_raio - (direcao_raio . direcao_cilindro)²
        a = raio.getVDirecao().pEscalar(raio.getVDirecao()) - std::pow(dr_escalar_dc, 2);

        // b = 2(w . direcao_raio) - 2(w . direcao_cilindro)(direcao_raio . direcao_cilindro)
        b = 2.0 * w.pEscalar(raio.getVDirecao()) - 2.0 * w_escalar_dc * dr_escalar_dc;

        // c = (w . w) - (w . direcao_cilindro)² - raio_cilindro²
        c = w.pEscalar(w) - std::pow(w_escalar_dc, 2) - std::pow(this->getRaio(), 2);

        delta = std::pow(b, 2) - 4.0 * a * c;

        if (delta > 0.0) {

            t_int1 = (-b + std::sqrt(delta)) / (2.0 * a);
            t_int2 = (-b - std::sqrt(delta)) / (2.0 * a);

            // Anotando se a primeira raíz é uma intersecção válida.
            v_escalar_dc = (raio.pontoDoRaio(t_int1) - this->getCentroBase()).pEscalar(this->getDirecao());

            if (0.0 > v_escalar_dc || v_escalar_dc > this->getAltura()) {

                t_int1 = -1.0;

            }

            // Anotando se a segunda raíz é uma intersecção válida.
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

            } else {

                t_int_base = base.escalarInterseccao(raio);
                t_int_topo = topo.escalarInterseccao(raio);

                // Checando se a intersecção com a base do cilíndro é válida.
                if (t_int_base >= 0.0 && (raio.pontoDoRaio(t_int_base) - this->getCentroBase()).norma() > this->getRaio()) {

                    t_int_base = -1.0;

                }

                // Checando se a intersecção com o topo do cilíndro é válida.
                if (t_int_topo >= 0.0 && (raio.pontoDoRaio(t_int_topo) - this->getCentroTopo()).norma() > this->getRaio()) {

                    t_int_topo = -1.0;

                }

                // Checando se o raio intersectou a base e o topo ao mesmo tempo.
                if (t_int_base >= 0.0 && t_int_topo >= 0.0) {

                    // Anotando a intersecção mais próxima.
                    if (t_int_base < t_int_topo) {

                        t_int = t_int_base;

                    } else {

                        t_int = t_int_topo;

                    }

                } else {

                    // Checando se o raio intersectou a base ou o topo ou nenhum dos dois.
                    if (t_int_base >= 0.0) {

                        t_int = t_int_base;

                    } else if (t_int_topo >= 0.0) {

                        t_int = t_int_topo;
                        
                    } else {
                        
                        t_int = -1.0;

                    }

                    // Checando se a base ou o topo foram intersectados.
                    if (t_int >= 0.0) {

                        // Checando qual das intersecções na superfíce do cilíndro é válida.
                        if (t_int1 >= 0.0) {

                            // Checando se a intersecção na superfície do cilíndro está mais próxima do que a intersecção na base ou no topo.
                            if (t_int1 < t_int) {

                                t_int = t_int1;

                            }

                        } else if (t_int2 >= 0.0) {

                            // Checando se a intersecção na superfície do cilíndro está mais próxima do que a intersecção na base ou no topo.
                            if (t_int2 < t_int) {

                                t_int = t_int2;

                            }

                        }

                    }

                } 


            }

        } else if (delta == 0.0) {

            // Calculando a única intersecção com o corpo do cilíndro.
            t_int1 = -b / (2.0 * a);

            v_escalar_dc = (raio.pontoDoRaio(t_int1) - this->getCentroBase()).pEscalar(this->getDirecao());

            // Checando se a intersecção é válida.
            if (0.0 <= v_escalar_dc && v_escalar_dc <= this->getAltura()) {

                t_int = t_int1;

            } else {

                t_int = -1.0;

            }

        } else {

            t_int = -1.0;

        }

    } else {

        t_int_base = base.escalarInterseccao(raio);
        t_int_topo = topo.escalarInterseccao(raio);

        // Anotando se a intersecção com a base do cilíndro é válida.
        if (t_int_base >= 0.0 && (raio.pontoDoRaio(t_int_base) - this->getCentroBase()).norma() > this->getRaio()) {

            t_int_base = -1.0;

        }

        // Anotando se a intersecção com o topo do cilíndro é válida.
        if (t_int_topo >= 0.0 && (raio.pontoDoRaio(t_int_topo) - this->getCentroTopo()).norma() > this->getRaio()) {

            t_int_topo = -1.0;

        }

        if (t_int_base >= 0.0 && t_int_topo >= 0.0) {

            if (t_int_base < t_int_topo) {

                t_int = t_int_base;

            } else {

                t_int = t_int_topo;

            }

        } else if (t_int_base >= 0.0) {

            t_int = t_int_base;

        } else if (t_int_topo >= 0.0) {

            t_int = t_int_topo;
            
        } else {

            t_int = -1.0;

        }

    }

    return t_int;

}

Vetor3 Cilindro::vetorNormalPonto(Ponto3 ponto) const {

    Vetor3 v, p_v, h;
    double v_escalar_dc, erro = 1e-12;

    v = ponto - this->getCentroBase();
    v_escalar_dc = v.pEscalar(this->getDirecao());
    p_v = this->getDirecao() * v_escalar_dc;
    h = v - p_v;

    if (0.0 + erro < v_escalar_dc && v_escalar_dc < this->getAltura() - erro) {

        h.normalizar();

        return h;

    } else if (v_escalar_dc <= 0.0 + erro) {

        return this->getDirecao() * -1.0;

    } else {

        return this->getDirecao();

    }

}