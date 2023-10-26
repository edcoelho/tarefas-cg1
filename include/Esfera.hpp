#ifndef ESFERA_HPP
#define ESFERA_HPP

#include "Material.hpp"
#include "Solido.hpp"
#include "utils/utils.hpp"
#include <eigen3/Eigen/Core>

class Esfera : public Solido {

    private:
        ponto3D centro;
        double raio;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Esfera();
        Esfera(ponto3D c, double r, Material m);

        // --- GETTERS E SETTERS ---

        ponto3D getCentro();
        void setCentro(ponto3D c);

        double getRaio();
        void setRaio(double r);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) override;

        // Retorna true se o sólido for intersectado ou tangenciado pelo RaioRayCasting "raio", em caso contrário retorna false.
        bool houveInterseccao(RaioRayCasting& raio) override;

        // Retorna o vetor unitário normal a superfície da esfera num ponto.
        Eigen::Vector3d vetorNormalPonto(ponto3D ponto) override;

};

#endif