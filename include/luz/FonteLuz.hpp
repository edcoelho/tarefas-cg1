#ifndef LUZ_FONTELUZ_HPP
#define LUZ_FONTELUZ_HPP

#include "luz/IntensidadeLuz.hpp"
#include "geometria/Raio.hpp"
#include "algebra/Ponto3.hpp"

class FonteLuz {

    private:
        IntensidadeLuz intensidade;

    public:

        // --- CONSTRUTORES ---

            FonteLuz();

            FonteLuz(IntensidadeLuz intensidade);

        // --- GETTERS E SETTERS ---

            IntensidadeLuz get_intensidade() const;
            void set_intensidade(IntensidadeLuz i);

            virtual Ponto3 get_posicao() const = 0;
            virtual void set_posicao(Ponto3 p) = 0;

        // --- MÉTODOS ---

            // Retorna true se o raio for um raio de luz válido da fonte de luz.
            virtual bool raio_valido(Raio& raio_luz) const;

};

#endif