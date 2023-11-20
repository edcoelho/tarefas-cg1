#ifndef LUZ_LUZPONTUAL_HPP
#define LUZ_LUZPONTUAL_HPP

#include "luz/IntensidadeLuz.hpp"
#include "luz/FonteLuz.hpp"
#include "algebra/Ponto3.hpp"

class LuzPontual : public FonteLuz {

    private:
        // Posição do ponto de luz.
        Ponto3 posicao;

    public:

        // --- CONSTRUTORES ---

            LuzPontual();

            LuzPontual(IntensidadeLuz intensidade, Ponto3 posicao);

        // --- GETTERS E SETTERS ---

            Ponto3 get_posicao() const override;
            void set_posicao(Ponto3 p) override;

};

#endif