#ifndef CENA_HPP
#define CENA_HPP

#include "Solido.hpp"
#include "Esfera.hpp"
#include "RaioRayCasting.hpp"
#include "utils.hpp"
#include <vector>
#include <memory>

class Cena {

    private:
        // Vetor com ponteiros para os sólidos presentes na cena.
        std::vector<std::unique_ptr<Solido>> solidos;
        // Cor de background.
        rgb corFundo;
        
    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        // cf: cor de fundo
        Cena(rgb cf);

        // --- MÉTODOS ---

        // Insere um novo sólido na cena.
        void inserirSolido(std::unique_ptr<Solido> solido);
        
        // Checa quais sólidos um raio intersectou e retorna a cor do sólido que o raio intersectou primeiro.
        // Se o raio não intersectar nada, retorna a cor de fundo.
        rgb corInterseccao(RaioRayCasting& raio);

};

#endif