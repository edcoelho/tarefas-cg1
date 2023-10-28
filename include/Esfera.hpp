#ifndef ESFERA_HPP
#define ESFERA_HPP

#include "Material.hpp"
#include "Solido.hpp"
#include "utils/utils.hpp"

class Esfera : public Solido {

    private:
        Ponto centro;
        double raio;

    public:

        // --- CONSTRUTORES ---

        Esfera();
        Esfera(Ponto c, double r, Material m);

        // --- GETTERS E SETTERS ---

        Ponto getCentro();
        void setCentro(Ponto c);

        double getRaio();
        void setRaio(double r);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) override;

        // Retorna true se o sólido for intersectado ou tangenciado pelo RaioRayCasting "raio", em caso contrário retorna false.
        bool houveInterseccao(RaioRayCasting& raio) override;

        // Retorna o vetor unitário normal a superfície da esfera num ponto.
        Vetor vetorNormalPonto(Ponto ponto) override;

};

#endif