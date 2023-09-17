#include "utils.hpp"
#include <eigen3/Eigen/Core>

#ifndef ESFERA_HPP
#define ESFERA_HPP

class Esfera {

    private:
        ponto3D centro;
        double raio;
        rgb cor;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Esfera(ponto3D c, double r, rgb cr);

        // --- GETTERS E SETTERS ---

        ponto3D getCentro();
        void setCentro(ponto3D c);

        double getRaio();
        void setRaio(double r);

        rgb getCor();
        void setCor(rgb c);

};

#endif