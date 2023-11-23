#ifndef GEOMETRIA_MALHA_PIRAMIDE
#define GEOMETRIA_MALHA_PIRAMIDE

#include "algebra/Ponto3.hpp"
#include "geometria/malha/MalhaEspecifica.hpp"

class Piramide : public MalhaEspecifica {

    private:
        Ponto3 centro_base;
        double largura_base;
        double comprimento_base;
        double altura;

    protected:

        // --- MÉTODOS PROTEGIDOS ---

            // Calcula e inseres os vértices, arestas e faces da malha específica.
            void calcular_estrutura() override;

    public:

        // --- CONSTRUTORES ---

            Piramide();

            Piramide(Ponto3 centro_base, double largura_base, double comprimento_base, double altura, Material material);

        // --- GETTERS E SETTERS ---

            Ponto3 get_centro_base();

            double get_largura_base();

            double get_comprimento_base();

            double get_altura();

};

#endif