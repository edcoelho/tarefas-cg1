#ifndef LUZ_FONTELUZ_HPP
#define LUZ_FONTELUZ_HPP

#include "luz/IntensidadeLuz.hpp"
#include "geometria/Raio.hpp"
#include "algebra/Vetor3.hpp"
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

        // --- MÉTODOS ---

            // Retorna true se o ponto for capaz de ser iluminado pela fonte de luz no caso de não haver obstrução de luz.
            virtual bool ponto_valido(const Ponto3& ponto) const = 0;

            // Retorna o vetor direção que aponta do ponto para a fonte de luz.
            virtual Vetor3 direcao_ponto_luz(const Ponto3& ponto) const = 0;

            // Retorna a distância entre o ponto e a fonte de luz.
            virtual double distancia_ponto_luz(const Ponto3& ponto) const = 0;

};

#endif