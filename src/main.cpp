#include "include_list.hpp"

// -- CONSTANTES --

// Posição da câmera.
Ponto3 posicao_camera(0.0, 0.0, 0.0);

// Ponto para onde a câmera aponta (look at).
Ponto3 ponto_visada(0.0, 0.0, 1.0);

// Ponto de amarra do plano sargital da câmera (view up).
Ponto3 ponto_amarra_sargital(0.0, 1.0, 0.0);

// x máximo do campo de visão.
const double x_max = 30.0;
// x mínimo do campo de visão.
const double x_min = -30.0;
// y máximo do campo de visão.
const double y_max = 30.0;
// y mínimo do campo de visão.
const double y_min = -30.0;
// Distância focal da câmera.
const double distancia_focal = 30.0;

// Largura (número de colunas) em pixels do canvas.
const std::size_t largura_canvas = 500;
// Altura (número de linhas) em pixels do canvas.
const std::size_t altura_canvas = 500;

// Intensidade da luz ambiente.
IntensidadeLuz I_A(0.3f, 0.3f, 0.3f);

// Cor do background.
const rgb cor_bg{0, 0, 0};

int main(int argc, char* argv[]) {

    Canvas canvas(altura_canvas, largura_canvas, cor_bg);

    Camera camera(posicao_camera, ponto_visada, ponto_amarra_sargital, x_max, x_min, y_max, y_min, distancia_focal);

    Cena cena(camera, I_A);

    // --- CARREGAMENTO DE TEXTURAS ---

        // std::shared_ptr<Textura> creto = std::make_shared<Textura>("...");

    // --- FIM DO CARREGAMENTO DE TEXTURAS ---

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

            // cena.inserir_malha(std::make_shared<Malha>(Malha));
            // ...

        // --- FIM DA INSERÇÃO DAS MALHAS PERSONALIZADAS NA CENA ---

        // --- INSERÇÃO DE MALHAS PRÉ-DEFINIDAS NA CENA ---

            // cena.inserir_malha(std::make_shared<Classe da malha específica>(...));
            // ...

        // --- FIM DA INSERÇÃO DE MALHAS PRÉ-DEFINIDAS NA CENA --

        // --- INSERÇÃ0 DE SÓLIDOS NA CENA ---

            // cena.inserir_solido(std::make_shared<Classe do sólido>(...));
            // ...

        // --- FIM DA INSERÇÃ0 DE SÓLIDOS NA CENA ---

        // --- MANIPULAÇÃO DA CÂMERA ---

            //cena.get_camera().set_posicao(...);
            //cena.get_camera().set_ponto_visada(...);
            //cena.get_camera().set_ponto_amarra(...);
            // ...

        // --- FIM DA MANIPULAÇÃO DA CAMERA ---

    // --- FIM DA INSERÇÃO DE ELEMENTOS NA CENA ---

    // Entrando no loop principal do renderizador.
    return canvas.loop(cena, "CG I");

}