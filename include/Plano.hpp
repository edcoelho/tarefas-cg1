#ifndef PLANO_HPP
#define PLANO_HPP

#include "Material.hpp"
#include "Solido.hpp"
#include "utils.hpp"

class Plano : public Solido {

    private:
        // Ponto conhecido do plano.
        ponto3D pX;
        // Vetor unitário normal ao plano.
        Eigen::Vector3d vN;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Plano();
        // p: Ponto conhecido do plano.
        // n: Vetor unitário normal ao plano.
        Plano(ponto3D p, Eigen::Vector3d n, Material m);

        // --- GETTERS E SETTERS ---

        ponto3D getPX();
        void setPX(ponto3D p);

        Eigen::Vector3d getVN();
        void setVN(Eigen::Vector3d n);

        // --- MÉTODOS ---

        // Se o plano for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) override;

        // Retorna true se o plano for intersectado pelo RaioRayCasting "raio", em caso contrário retorna false.
        bool houveInterseccao(RaioRayCasting& raio) override;

        // Retorna o vetor unitário normal a superfície do plano num ponto.
        Eigen::Vector3d vetorNormalPonto(ponto3D ponto) override;

};

#endif