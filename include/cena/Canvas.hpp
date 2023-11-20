#ifndef CENA_CANVAS_HPP
#define CENA_CANVAS_HPP

#include "utils/tipos.hpp"
#include "cena/Cena.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>

class Canvas {

    private:
        // Altura do canvas
        std::size_t altura;
        // Largura do canvas
        std::size_t largura;
        // Cor padrão do canvas.
        rgb cor_padrao;
        // Matriz de cores para serem pintadas no canvas.
        matriz_cores pixel_buffer;

    public:

        // --- CONSTRUTORES ---

            Canvas();

            Canvas(std::size_t altura, std::size_t largura, rgb cor_padrao = rgb{0, 0, 0});

        // --- GETTERS E SETTERS ---

            std::size_t get_altura() const;
            void set_altura(double a);

            std::size_t get_largura() const;
            void set_largura(double l);

            rgb get_cor_padrao() const;
            void set_cor_padrao(rgb c);

        // --- MÉTODOS ---

            // Calcula a matriz de cores de acordo com uma certa cena.
            void calcular_cores(Cena& cena);

            // Desenha 
            void desenhar_pixels(SDL_Renderer* renderer) const;

            // Loop principal de renderização.
            // Recebe o título da janela.
            int loop(Cena& cena, const char* titulo);

};

#endif