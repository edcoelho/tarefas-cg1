#ifndef GEOMETRIA_MALHA_RETANGULOYZ_HPP
#define GEOMETRIA_MALHA_RETANGULOYZ_HPP

#include "algebra/Ponto3.hpp"
#include "geometria/malha/MalhaEspecifica.hpp"

// Retângulo no plano YZ.
class RetanguloYZ : public MalhaEspecifica {

    private:
        Ponto3 centro_base;
        double largura;
        double altura;

        // Indica se o vetor normal aponta para o X positivo.
        // Se for true, o vetor normal aponta para o X positivo, e, em caso contrário, aponta para o X negativo.
        bool sentido_vetor_normal;

    protected:

        // --- MÉTODOS PROTEGIDOS ---

            // Calcula e inseres os vértices, arestas e faces da malha específica.
            void calcular_estrutura() override;

    public:

        // --- CONSTRUTORES ---

            RetanguloYZ();

            RetanguloYZ(Ponto3 centro_base, double largura, double altura, Material material, bool sentido_vetor_normal = true);

        // --- GETTERS E SETTERS ---

            Ponto3 get_centro_base();

            double get_largura();

            double get_altura();

            bool get_sentido_vetor_normal();

};

#endif