#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils/utils.hpp"
#include "utils/IntensidadeLuz.hpp"

class Material {

    private:
        // K ambiente
        IntensidadeLuz kA;
        // K difusão
        IntensidadeLuz kD;
        // K especulamento (cor da luz "refletida" pelo sólido)
        IntensidadeLuz kE;
        // Expoente de espelhamento.
        double expEsp;

    public:

        // --- CONSTRUTORES ---

        Material();
        Material(IntensidadeLuz ka, IntensidadeLuz kd, IntensidadeLuz ke, double e);

        // --- GETTERS E SETTERS ---

        IntensidadeLuz getKA();
        void setKA(IntensidadeLuz k);

        IntensidadeLuz getKD();
        void setKD(IntensidadeLuz k);

        IntensidadeLuz getKE();
        void setKE(IntensidadeLuz k);

        double getExpEsp();
        void setExpEsp(double e);

};

#endif