#ifndef RAIORAYCASTING_HPP
#define RAIORAYCASTING_HPP

#include <eigen3/Eigen/Core>
#include "utils/utils.hpp"

class RaioRayCasting {

    private:
        // Ponto inicial.
        ponto3D pInicial;
        // Vetor direção.
        Eigen::Vector3d vDirecao;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        RaioRayCasting();

        // pI: ponto inicial do raio
        // pX: outro ponto qualquer do raio
        RaioRayCasting(ponto3D pI, ponto3D pX);

        // --- GETTERS E SETTERS ---

        ponto3D getPInicial();
        void setPInicial(ponto3D pI);

        Eigen::Vector3d getVDirecao();
        void setVDirecao(Eigen::Vector3d vD);

        // --- MÉTODOS ---

        // Retorna um ponto do raio que está a uma distância "escalar" do ponto inicial.
        ponto3D pontoDoRaio(double escalar);

};

#endif