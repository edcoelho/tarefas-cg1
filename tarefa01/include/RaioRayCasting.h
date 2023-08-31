#include "utils.h"
#include "Esfera.h"

#ifndef RAIORAYCASTING_H
#define RAIORAYCASTING_H

class RaioRayCasting {

    private:
        // Ponto inicial.
        ponto3D pInicial;
        // Vetor direção.
        vetor3D vDirecao;

    public:
        // --- CONSTRUTORES ---

        // pI: ponto inicial do raio
        // vD: vetor direção
        RaioRayCasting(ponto3D pI, vetor3D vD);
        // pI: ponto inicial do raio
        // pX: outro ponto qualquer do raio
        RaioRayCasting(ponto3D pI, ponto3D pX);

        // --- MÉTODOS ---

        // Se o raio intersectar a esfera "esf", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo.
        // Se o raio tangenciar a esfera "esf", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto onde o raio tangenciou.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(Esfera esf);

        // Retorna true se o raio intersectar ou tangenciar a esfera "esf", caso contrário retorna false.
        bool houveInterseccao(Esfera esf);

        // --- GETTERS E SETTERS ---

        ponto3D getPInicial();
        void setPInicial(ponto3D pI);

        vetor3D getVDirecao();
        void setVDirecao(vetor3D vD);

};

#endif