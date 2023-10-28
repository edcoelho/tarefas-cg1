#ifndef RAIORAYCASTING_HPP
#define RAIORAYCASTING_HPP

#include "utils/utils.hpp"
#include "algebra/Ponto.hpp"
#include "algebra/Vetor.hpp"

class RaioRayCasting {

    private:
        // Ponto inicial.
        Ponto pInicial;
        // Vetor direção.
        Vetor vDirecao;

    public:

        // --- CONSTRUTORES ---

        RaioRayCasting();

        // pI: ponto inicial do raio
        // pX: outro ponto qualquer do raio
        RaioRayCasting(Ponto pI, Ponto pX);

        // --- GETTERS E SETTERS ---

        Ponto getPInicial();
        void setPInicial(Ponto pI);

        Vetor getVDirecao();
        void setVDirecao(Vetor vD);

        // --- MÉTODOS ---

        // Retorna um ponto do raio que está a uma distância "escalar" do ponto inicial.
        Ponto pontoDoRaio(double escalar);

};

#endif