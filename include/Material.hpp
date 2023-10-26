#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "utils/utils.hpp"

class Material {

    private:
        // K ambiente
        i_luz kA;
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
        Material(i_luz ka, i_luz kd, i_luz ke, double e);

        // --- GETTERS E SETTERS ---

        i_luz getKA();
        void setKA(i_luz k);

        i_luz getKD();
        void setKD(i_luz k);

        i_luz getKE();
        void setKE(i_luz k);

        double getExpEsp();
        void setExpEsp(double e);

};

#endif