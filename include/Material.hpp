#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils.hpp"

class Material {

    private:
        rgb cor;
        // Expoente de espelhamento.
        double expEsp;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Material();
        Material(rgb c, double e);

        // --- GETTERS E SETTERS ---

        rgb getCor();
        void setCor(rgb c);

        double getExpEsp();
        void setExpEsp(double e);

};

#endif