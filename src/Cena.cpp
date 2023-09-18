#include "../include/Cena.hpp"

Cena::Cena(rgb cf) {

    this->corFundo = cf;

}

void Cena::inserirSolido(std::unique_ptr<Solido> solido) {

    this->solidos.push_back(std::move(solido));

}

rgb Cena::corInterseccao(RaioRayCasting& raio) {

    // Índice do sólido intersectado primeiro.
    int indiceSolido = -1;
    // Distância do ponto inicial ao ponto de intersecção (t_int).
    double tInt, minTInt = -1.0;

    // Cor que será retornada.
    rgb cor = this->corFundo;

    // Checar intersecção apenas se houver sólidos na cena.
    if (this->solidos.size() >= 1) {

        // Checando o primeiro sólido.
        tInt = this->solidos.at(0)->escalarInterseccao(raio);
        if (tInt >= 0.0) {
            
            minTInt = tInt;
            indiceSolido = 0;

        } 

        // Checando os outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            tInt = this->solidos.at(i)->escalarInterseccao(raio);

            if (tInt >= 0.0)

                // Checando se o sólido anterior foi intersectado também.
                if (minTInt >= 0) {

                    if (tInt < minTInt) {

                        minTInt = tInt;
                        indiceSolido = i;

                    }
                
                } else {
                    
                    minTInt = tInt;
                    indiceSolido = i;

                }                

        }

        // Se algum sólido foi intersectado, pega a cor do sólido que foi intersectado primeiro.s
        if (indiceSolido >= 0) cor = this->solidos.at(indiceSolido)->getCor();

    }

    return cor;

}