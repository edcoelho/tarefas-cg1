#ifndef SOLIDO_HPP
#define SOLIDO_HPP

#include "RaioRayCasting.hpp"
#include "LuzPontual.hpp"
#include "Material.hpp"
#include "utils/utils.hpp"

class Solido {

    private:
        Material material;

    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Solido();
        Solido(Material m);

        // --- GETTERS E SETTERS ---

        Material getMaterial();
        void setMaterial(Material m);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        virtual double escalarInterseccao(RaioRayCasting& raio) = 0;

        // Retorna true se o sólido for intersectado ou tangenciado pelo RaioRayCasting "raio", em caso contrário retorna false.
        virtual bool houveInterseccao(RaioRayCasting& raio) = 0;

        // Retorna o vetor unitário normal a superfície do sólido num ponto.
        virtual Eigen::Vector3d vetorNormalPonto(ponto3D ponto) = 0;

        // Retorna o vetor NÃO UNITÁRIO que vai de um ponto da superfície do sólido até uma luz pontual.
        virtual Eigen::Vector3d vetorLuzPontual(ponto3D ponto, LuzPontual& luz);

        // Retorna o vetor unitário que é reflexo do vetor unitário que vai de um ponto da superfície do sólido até uma luz pontual
        virtual Eigen::Vector3d vetorReflexo(ponto3D ponto, LuzPontual& luz);

        // Retorna o vetor unitário que vai de um ponto p0 da superfície do sólido até um ponto pX qualquer.
        virtual Eigen::Vector3d vetorUnit(ponto3D p0, ponto3D pX);

};

#endif