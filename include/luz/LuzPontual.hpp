#ifndef LUZ_LUZPONTUAL_HPP
#define LUZ_LUZPONTUAL_HPP

#include "luz/IntensidadeLuz.hpp"
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
        // r, g, b: intensidade de cada canal de cor da luz
        LuzPontual(double x, double y, double z, double r, double g, double b);

        // pos: posicao
        // I: intensidade
        LuzPontual(Ponto3 posicao, IntensidadeLuz intensidade);

        // --- GETTERS E SETTERS ---

        Ponto3 get_posicao() const;
        void set_posicao(Ponto3 p);

        IntensidadeLuz get_intensidade() const;
        void set_intensidade(IntensidadeLuz i);

};

#endif