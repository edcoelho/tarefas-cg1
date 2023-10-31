#ifndef RAIORAYCASTING_HPP
#define RAIORAYCASTING_HPP

#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class RaioRayCasting {

    private:
        // Ponto inicial.
        Ponto3 pInicial;
        // Vetor direção.
        Vetor3 vDirecao;

    public:

        // --- CONSTRUTORES ---

        RaioRayCasting();

        // pI: ponto inicial do raio
        // pX: outro ponto qualquer do raio
        RaioRayCasting(Ponto3 pI, Ponto3 pX);

        // --- GETTERS E SETTERS ---

        Ponto3 getPInicial();
        void setPInicial(Ponto3 pI);

        Vetor3 getVDirecao();
        void setVDirecao(Vetor3 vD);

        // --- MÉTODOS ---

        // Retorna um ponto do raio que está a uma distância "escalar" do ponto inicial.
        Ponto3 pontoDoRaio(double escalar);

};

#endif