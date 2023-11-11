#ifndef SOLIDO_HPP
#define SOLIDO_HPP

#include "RaioRayCasting.hpp"
#include "LuzPontual.hpp"
#include "Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Solido {

    private:
        Material material;

    public:

        // --- CONSTRUTORES ---

        Solido();
        Solido(Material m);

        // --- GETTERS E SETTERS ---

        Material getMaterial() const;
        void setMaterial(Material m);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo.
        // Se não houver intersecção, retorna -1.
        virtual double escalarInterseccao(RaioRayCasting& raio) const = 0;

        // Retorna o vetor unitário normal a superfície do sólido num ponto.
        virtual Vetor3 vetorNormalPonto(Ponto3 ponto) const = 0;

        // Retorna o vetor NÃO UNITÁRIO que vai de um ponto da superfície do sólido até uma luz pontual.
        virtual Vetor3 vetorLuzPontual(Ponto3 ponto, LuzPontual& luz) const;

        // Retorna o vetor unitário que é reflexo do vetor unitário que vai de um ponto da superfície do sólido até uma luz pontual
        virtual Vetor3 vetorReflexo(Ponto3 ponto, LuzPontual& luz) const;

        // Retorna o vetor unitário que vai de um ponto p0 da superfície do sólido até um ponto pX qualquer.
        virtual Vetor3 vetorUnit(Ponto3 p0, Ponto3 pX) const;

};

#endif