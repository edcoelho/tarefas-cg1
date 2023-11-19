#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils/IntensidadeLuz.hpp"

class Material {

    private:
        // K ambiente
        IntensidadeLuz k_A;
        // K difusão
        IntensidadeLuz k_D;
        // K especulamento (cor da luz "refletida" pelo sólido)
        IntensidadeLuz k_E;
        // Expoente de espelhamento.
        double espelhamento;

    public:

        // --- CONSTRUTORES ---

        Material();
        Material(IntensidadeLuz ka, IntensidadeLuz kd, IntensidadeLuz ke, double espelhamento);

        // --- GETTERS E SETTERS ---

        IntensidadeLuz get_k_A();
        void set_k_A(IntensidadeLuz k);

        IntensidadeLuz get_k_D();
        void set_k_D(IntensidadeLuz k);

        IntensidadeLuz get_k_E();
        void set_k_E(IntensidadeLuz k);

        double get_espelhamento();
        void set_espelhamento(double e);

};

#endif