#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils.hpp"

class Material {

    private:
        rgb cor;
        // K especulamento (cor da luz "refletida" pelo sólido)
        rgb kE;
        // Expoente de espelhamento.
        double expEsp;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Material();
        Material(rgb c, rgb k, double e);

        // --- GETTERS E SETTERS ---

        rgb getCor();
        void setCor(rgb c);

        rgb getKE();
        void setKE(rgb k);

        double getExpEsp();
        void setExpEsp(double e);

};

#endif