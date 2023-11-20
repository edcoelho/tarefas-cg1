#include "include_list.hpp"

// -- CONSTANTES --

// Altura da janela do pintor.
const double H_J = 60.0;
// Largura da janela do pintor.
const double W_J = 60.0;

// Largura (número de colunas) em pixels do canvas.
const std::size_t W_C = 500;
// Altura (número de linhas) em pixels do canvas.
const std::size_t H_C = 500;

// Coordenada z da janela do pintor.
const double z_J = 30.0;

// Intensidade da luz ambiente.
IntensidadeLuz I_A(0.3f, 0.3f, 0.3f);

// Cor do background.
const rgb cor_bg{0, 0, 0};

// Posição do olho do pintor
Ponto3 ponto_olho(0.0, 0.0, 0.0);

int main(int argc, char* argv[]) {

    Canvas canvas(H_C, W_C, cor_bg);

    Cena cena(Camera(H_J, W_J, z_J, ponto_olho), I_A);

    // --- INSERÇÃO DE ELEMENTOS NA CENA ---

        // ...

    // --- FIM DA INSERÇÃO DE ELEMENTOS NA CENA ---

    // Entrando no loop principal do renderizador.
    return canvas.loop(cena, "CG I");

}