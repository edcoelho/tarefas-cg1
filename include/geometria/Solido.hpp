#ifndef GEOMETRIA_SOLIDO_HPP
#define GEOMETRIA_SOLIDO_HPP

#include "geometria/Raio.hpp"
#include "luz/LuzPontual.hpp"
#include "utils/Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Solido {

    private:
        Material material;

    public:

        // --- CONSTRUTORES ---

        Solido();
        Solido(Material material);

        // --- GETTERS E SETTERS ---

        Material get_material() const;
        void set_material(Material material);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo Raio "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo.
        // Se não houver intersecção, retorna -1.
        virtual double escalar_interseccao(Raio& raio) const = 0;

        // Retorna o vetor unitário normal a superfície do sólido num ponto.
        virtual Vetor3 vetor_normal_ponto(Ponto3 ponto) const = 0;

};

#endif