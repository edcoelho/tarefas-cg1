#ifndef CENA_CENA_HPP
#define CENA_CENA_HPP

#include <memory>
#include <vector>
#include "geometria/Solido.hpp"
#include "geometria/Raio.hpp"
#include "luz/LuzPontual.hpp"
#include "utils/tipos.hpp"
#include "luz/IntensidadeLuz.hpp"
#include "cena/Camera.hpp"

class Cena {

    private:
        // Vetor com ponteiros para os sólidos presentes na cena.
        std::vector<std::unique_ptr<Solido>> solidos;
        // Luz pontual presente na cena.
        std::unique_ptr<LuzPontual> fonte_luz;
        // Intensidade da luz ambiente.
        IntensidadeLuz I_A;

        Camera camera;
        
    public:

        // --- CONSTRUTORES ---

        Cena();
        // I: intensidade da luz ambiente
        Cena(Camera camera, IntensidadeLuz I_A);

        // --- GETTERS E SETTERS ---

        void set_fonte_luz(std::unique_ptr<LuzPontual> luz);

        Camera get_camera() const;
        void set_camera(Camera c);

        IntensidadeLuz get_I_A() const;
        void set_I_A(IntensidadeLuz i);

        // --- MÉTODOS ---

        // Insere um novo sólido na cena.
        void inserir_solido(std::unique_ptr<Solido> solido);
        
        // Chaca qual sólido o raio intersectou primeiro, calcula a interação da luz com o sólido e retorna a cor rgb correspondente.
        // Se o raio não intersectar nada, retorna a cor de fundo.
        rgb cor_interseccao(Raio& raio, rgb cor_padrao = rgb{0, 0, 0}) const;

};

#endif