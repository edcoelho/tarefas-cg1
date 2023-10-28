#ifndef LUZPONTUAL_HPP
#define LUZPONTUAL_HPP

#include "utils/utils.hpp"
#include "utils/IntensidadeLuz.hpp"
#include "algebra/Ponto.hpp"

class LuzPontual {

    private:
        // Posição do ponto de luz.
        Ponto posicao;
        // Intensidade da luz.
        IntensidadeLuz intensidade;

    public:

        // --- CONSTRUTORES ---

        LuzPontual();
        // x, y, z: coordenadas do ponto
        // Ir, Ig, Ib: intensidade de cada canal
        LuzPontual(double x, double y, double z, float Ir, float Ig, float Ib);

        // pos: posicao
        // I: intensidade
        LuzPontual(Ponto pos, IntensidadeLuz I);

        // --- GETTERS E SETTERS ---

        Ponto getPosicao();
        void setPosicao(Ponto pos);

        IntensidadeLuz getIntensidade();
        void setIntensidade(IntensidadeLuz I);

};

#endif