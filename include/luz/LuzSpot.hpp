#ifndef LUZ_LUZSPOT_HPP
#define LUZ_LUZSPOT_HPP

#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"
#include "geometria/Raio.hpp"
#include "luz/FonteLuz.hpp"

class LuzSpot : public FonteLuz {

    private:
        Ponto3 posicao;
        Vetor3 direcao;
        // Ângulo de abertura em radianos
        double abertura;

    public:

        // --- CONSTRUTORES ---

            LuzSpot();

            LuzSpot(IntensidadeLuz intensidade, Ponto3 posicao, Vetor3 direcao, double abertura);

        // -- GETTERS E SETTERS ---

            Ponto3 get_posicao() const;
            void set_posicao(Ponto3 p);

            Vetor3 get_direcao() const;
            void set_direcao(Vetor3 d);

            double get_abertura() const;
            void set_abertura(double a);

        // --- MÉTODOS ---

            bool raio_valido(Raio& raio_luz) const override;

};

#endif