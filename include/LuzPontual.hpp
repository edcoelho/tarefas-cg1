#ifndef LUZPONTUAL_HPP
#define LUZPONTUAL_HPP

#include "utils/utils.hpp"

class LuzPontual {

    private:
        // Posição do ponto de luz.
        ponto3D posicao;
        // Intensidade da luz.
        i_luz intensidade;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        LuzPontual();
        // x, y, z: coordenadas do ponto
        // Ir, Ig, Ib: intensidade de cada canal
        LuzPontual(double x, double y, double z, float Ir, float Ig, float Ib);

        // pos: posicao
        // I: intensidade
        LuzPontual(ponto3D pos, i_luz I);

        // --- GETTERS E SETTERS ---

        ponto3D getPosicao();
        void setPosicao(ponto3D pos);

        i_luz getIntensidade();
        void setIntensidade(i_luz I);

};

#endif