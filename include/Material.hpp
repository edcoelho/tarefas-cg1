#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils.hpp"

class Material {

    private:
        rgb cor;
        // K difusão
        i_luz kD;
        // K especulamento (cor da luz "refletida" pelo sólido)
        i_luz kE;
        // Expoente de espelhamento.
        double expEsp;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Material();
        Material(rgb c, i_luz kd, i_luz ke, double e);

        // --- GETTERS E SETTERS ---

        rgb getCor();
        void setCor(rgb c);

        i_luz getKD();
        void setKD(i_luz k);

        i_luz getKE();
        void setKE(i_luz k);

        double getExpEsp();
        void setExpEsp(double e);

};

#endif