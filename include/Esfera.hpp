#ifndef ESFERA_HPP
#define ESFERA_HPP

#include "Material.hpp"
#include "Solido.hpp"

class Esfera : public Solido {

    private:
        Ponto3 centro;
        double raio;

    public:

        // --- CONSTRUTORES ---

        Esfera();
        Esfera(Ponto3 c, double r, Material m);

        // --- GETTERS E SETTERS ---

        Ponto3 getCentro() const;
        void setCentro(Ponto3 c);

        double getRaio() const;
        void setRaio(double r);

        // --- MÉTODOS ---

        // Se a esfera for intersectada pelo Raio "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(Raio& raio) const override;

        // Retorna o vetor unitário normal a superfície da esfera num ponto.
        Vetor3 vetorNormalPonto(Ponto3 ponto) const override;

};

#endif