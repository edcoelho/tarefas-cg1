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

        // --- INSERÇÃO DE FONTES DE LUZES NA CENA ---

            // cena.inserir_fonte_luz(std::make_unique<Classe da fonte>(...))
            // ...

        // --- FIM DA INSERÇÃO DE LUZES NA CENA ---

        // --- CRIAÇÃO DE MALHAS PERSONALIZADAS ---

            // Malha malha(Material);
            // ...

            // --- INSERÇÃO DE VÉRTICES ---
            
                // malha.inserir_vertice(Ponto3);
                // ...

            // --- FIM DA INSERÇÃO DE VÉRTICES ---

            // --- INSERÇÃO DE ARESTAS ---

                // malha.inserir_aresta(Aresta);
                // ...

            // --- FIM DA INSERÇÃO DE ARESTAS ---

            // --- INSERÇÃO DE FACES ---

                // malha.inserir_face(Face);
                // ...

            // --- FIM DA INSERÇÃO DE FACES ---

        // --- FIM DA CRIAÇÃO DE MALHAS PERSONALIZADAS ---

        // --- INSERÇÃO DAS MALHAS PERSONALIZADAS NA CENA ---

            // cena.inserir_malha(Malha);
            // ...

        // --- FIM DA INSERÇÃO DAS MALHAS PERSONALIZADAS NA CENA ---

        // --- INSERÇÃ0 DE SÓLIDOS NA CENA ---

            // cena.inserir_solido(std::make_shared<Classe do sólido>(...));
            // ...

        // --- FIM DA INSERÇÃ0 DE SÓLIDOS NA CENA ---

    // --- FIM DA INSERÇÃO DE ELEMENTOS NA CENA ---

    // Entrando no loop principal do renderizador.
    return canvas.loop(cena, "CG I");

}