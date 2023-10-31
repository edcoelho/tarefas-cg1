#ifndef PLANO_HPP
#define PLANO_HPP

#include "Material.hpp"
#include "Solido.hpp"

class Plano : public Solido {

    private:
        // Ponto conhecido do plano.
        Ponto3 pX;
        // Vetor unitário normal ao plano.
        Vetor3 vN;

    public:

        // --- CONSTRUTORES ---

        Plano();
        // p: Ponto conhecido do plano.
        // n: Vetor unitário normal ao plano.
        Plano(Ponto3 p, Vetor3 n, Material m);

        // --- GETTERS E SETTERS ---

        Ponto3 getPX();
        void setPX(Ponto3 p);

        Vetor3 getVN();
        void setVN(Vetor3 n);

        // --- MÉTODOS ---

        // Se o plano for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) override;

        // Retorna true se o plano for intersectado pelo RaioRayCasting "raio", em caso contrário retorna false.
        bool houveInterseccao(RaioRayCasting& raio) override;

        // Retorna o vetor unitário normal a superfície do plano num ponto.
        Vetor3 vetorNormalPonto(Ponto3 ponto) override;

};

#endif