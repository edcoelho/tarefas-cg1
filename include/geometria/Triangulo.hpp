#ifndef GEOMETRIA_TRIANGULO_HPP
#define GEOMETRIA_TRIANGULO_HPP

#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"
#include "geometria/Raio.hpp"
#include "geometria/Solido.hpp"

class Triangulo : public Solido {

    private:
        // Vértices do triângulo

        Ponto3 vertice1;
        Ponto3 vertice2;
        Ponto3 vertice3;

        // Vetor normal ao triângulo
        Vetor3 normal;

    public:

        // --- CONSTRUTORES ---

            Triangulo(Material material = Material());

            Triangulo(Ponto3 vertice1, Ponto3 vertice2, Ponto3 vertice3, Material material = Material());

        // --- GETTERS E SETTERS ---

            Ponto3 get_vertice1() const;
            void set_vertice1(Ponto3 v);

            Ponto3 get_vertice2() const;
            void set_vertice2(Ponto3 v);

            Ponto3 get_vertice3() const;
            void set_vertice3(Ponto3 v);

        // --- OUTROS MÉTODOS ---

            // Se o triângulo for intersectada pelo Raio "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo.
            // Se não houver intersecção, retorna -1.
            double escalar_interseccao(Raio& raio) const override;

            // Retorna o vetor unitário normal a superfície do triângulo num ponto.
            Vetor3 vetor_normal_ponto(Ponto3 ponto) const override;

};

#endif