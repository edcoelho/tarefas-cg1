#ifndef LUZPONTUAL_HPP
#define LUZPONTUAL_HPP

#include "utils/IntensidadeLuz.hpp"
#include "algebra/Ponto3.hpp"

class LuzPontual {

    private:
        // Posição do ponto de luz.
        Ponto3 posicao;
        // Intensidade da luz.
        IntensidadeLuz intensidade;

    public:

        // --- CONSTRUTORES ---

        LuzPontual();
        // x, y, z: coordenadas do ponto
        // Ir, Ig, Ib: intensidade de cada canal
        LuzPontual(double x, double y, double z, double Ir, double Ig, double Ib);

        // pos: posicao
        // I: intensidade
        LuzPontual(Ponto3 pos, IntensidadeLuz I);

        // --- GETTERS E SETTERS ---

        Ponto3 getPosicao() const;
        void setPosicao(Ponto3 pos);

        IntensidadeLuz getIntensidade() const;
        void setIntensidade(IntensidadeLuz I);

};

#endif