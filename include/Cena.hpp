#ifndef CENA_HPP
#define CENA_HPP

#include "Solido.hpp"
#include "Esfera.hpp"
#include "RaioRayCasting.hpp"
#include "LuzPontual.hpp"
#include "utils/utils.hpp"
#include <vector>
#include <memory>

class Cena {

    private:
        // Vetor com ponteiros para os sólidos presentes na cena.
        std::vector<std::unique_ptr<Solido>> solidos;
        // Cor de background.
        rgb corFundo;
        // Luz pontual presente na cena.
        std::unique_ptr<LuzPontual> fonteLuz;
        // Intensidade da luz ambiente.
        i_luz iA;
        
    public:
        // Flag para os vetores do Eigen serem alocados adequadamente.
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        // --- CONSTRUTORES ---

        Cena();
        // cf: cor de fundo
        // I: intensidade da luz ambiente
        Cena(rgb cf, i_luz I);

        // --- GETTERS E SETTERS ---

        rgb getCorFundo();
        void setCorFundo(rgb cor);

        std::unique_ptr<LuzPontual>& getFonteLuz();
        void setFonteLuz(std::unique_ptr<LuzPontual> luz);

        i_luz getIA();
        void setIA(i_luz I);

        // --- MÉTODOS ---

        // Insere um novo sólido na cena.
        void inserirSolido(std::unique_ptr<Solido> solido);
        
        // Chaca qual sólido o raio intersectou primeiro, calcula a interação da luz com o sólido e retorna a cor rgb correspondente.
        // Se o raio não intersectar nada, retorna a cor de fundo.
        rgb corInterseccao(RaioRayCasting& raio);

};

#endif