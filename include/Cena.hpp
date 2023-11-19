#ifndef CENA_HPP
#define CENA_HPP

#include <memory>
#include <vector>
#include "Solido.hpp"
#include "Raio.hpp"
#include "LuzPontual.hpp"
#include "utils/utils.hpp"
#include "utils/IntensidadeLuz.hpp"

class Cena {

    private:
        // Vetor com ponteiros para os sólidos presentes na cena.
        std::vector<std::unique_ptr<Solido>> solidos;
        // Cor de background.
        rgb cor_fundo;
        // Luz pontual presente na cena.
        std::unique_ptr<LuzPontual> fonte_luz;
        // Intensidade da luz ambiente.
        IntensidadeLuz I_A;
        
    public:

        // --- CONSTRUTORES ---

        Cena();
        // I: intensidade da luz ambiente
        Cena(rgb cor_fundo, IntensidadeLuz I_A);

        // --- GETTERS E SETTERS ---

        rgb get_cor_fundo();
        void set_cor_fundo(rgb c);

        std::unique_ptr<LuzPontual>& get_fonte_luz();
        void set_fonte_luz(std::unique_ptr<LuzPontual> luz);

        IntensidadeLuz get_I_A();
        void set_I_A(IntensidadeLuz i);

        // --- MÉTODOS ---

        // Insere um novo sólido na cena.
        void inserir_solido(std::unique_ptr<Solido> solido);
        
        // Chaca qual sólido o raio intersectou primeiro, calcula a interação da luz com o sólido e retorna a cor rgb correspondente.
        // Se o raio não intersectar nada, retorna a cor de fundo.
        rgb cor_interseccao(Raio& raio);

};

#endif