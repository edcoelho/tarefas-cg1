#ifndef GEOMETRIA_MALHA_RETANGULOXZ_HPP
#define GEOMETRIA_MALHA_RETANGULOXZ_HPP

#include "algebra/Ponto3.hpp"
#include "geometria/malha/MalhaEspecifica.hpp"

// Retângulo no plano XZ.
class RetanguloXZ : public MalhaEspecifica {

    private:
        Ponto3 centro_base;
        double largura;
        double altura;

        // Indica se o vetor normal aponta para o Y positivo.
        // Se for true, o vetor normal aponta para o Y positivo, e, em caso contrário, aponta para o Y negativo.
        bool sentido_vetor_normal;

    protected:

        // --- MÉTODOS PROTEGIDOS ---

            // Calcula e inseres os vértices, arestas e faces da malha específica.
            void calcular_estrutura() override;

    public:

        // --- CONSTRUTORES ---

            RetanguloXZ();

            RetanguloXZ(Ponto3 centro_base, double largura, double altura, Material material, bool sentido_vetor_normal = true);

        // --- GETTERS E SETTERS ---

            Ponto3 get_centro_base();

            double get_largura();

            double get_altura();

            bool get_sentido_vetor_normal();

};

#endif