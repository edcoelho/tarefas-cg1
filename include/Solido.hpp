#include "RaioRayCasting.hpp"
#include "utils.hpp"

#ifndef SOLIDO_HPP
#define SOLIDO_HPP

class Solido {

    private:
        rgb cor;

    public:

        // --- GETTERS E SETTERS ---

        rgb getCor();
        void setCor(rgb c);

        // --- MÉTODOS ---

        // Se o sólido for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        virtual double escalarInterseccao(RaioRayCasting& raio) = 0;

        // Retorna true se o sólido for intersectado ou tangenciado pelo RaioRayCasting "raio", em caso contrário retorna false.
        virtual bool houveInterseccao(RaioRayCasting& raio) = 0;

};

#endif