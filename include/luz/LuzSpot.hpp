#ifndef LUZ_LUZSPOT_HPP
#define LUZ_LUZSPOT_HPP

#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"
#include "geometria/Raio.hpp"
#include "luz/FonteLuz.hpp"

class LuzSpot : public FonteLuz {

    private:
        Ponto3 posicao;
        // Direção do eixo da luz.
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

            // Retorna true se o ponto for capaz de ser iluminado pela fonte de luz no caso de não haver obstrução de luz.
            bool ponto_valido(const Ponto3& ponto) const override;
            
            // Retorna o vetor direção que aponta do ponto para a fonte de luz spot.
            Vetor3 direcao_ponto_luz(const Ponto3& ponto) const override;

            // Retorna a distância entre o ponto e a fonte de luz spot.
            double distancia_ponto_luz(const Ponto3& ponto) const override;

};

#endif