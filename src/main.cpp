#include <SDL2/SDL.h>
#include "utils/utils.hpp"
#include "Cena.hpp"
#include "RaioRayCasting.hpp"
#include "Esfera.hpp"
#include "Plano.hpp"
#include <array>
#include <memory>

// -- CONSTANTES --

// Altura da janela do pintor.
const double H_J = 60.0;
// Largura da janela do pintor.
const double W_J = 60.0;

// Largura (número de colunas) em pixels do canvas.
const int W_C = 500;
// Altura (número de linhas) em pixels do canvas.
const int H_C = 500;

// Coordenada z da janela do pintor.
const double z_J = -30.0;

// Intensidade da luz ambiente.
i_luz I_A(0.3f, 0.3f, 0.3f);

// Cor do background.
const rgb bgColor{100, 100, 100};

// Posição do olho do pintor
ponto3D ponto_olho(0, 0, 0);

// -- DEFINIÇÕES DE TIPOS --

// Tipo para representar uma matriz de cores.
typedef std::array<std::array<rgb, static_cast<std::size_t>(H_C)>, static_cast<std::size_t>(W_C)> matrizCores;

// --- FUNÇÕES ---

// Função que retorna a matriz de cores que será pintada.
matrizCores calcularMatrizCores() {

    // Criando a cena.
    Cena cena(bgColor, I_A);
    // Criando um ponteiro para um objeto raio para o ray casting.
    std::unique_ptr<RaioRayCasting> raio;
    // Criando a matriz de cores que serão pintadas na janela.
    matrizCores cores;

    // Dimensões dos retângulos da tela de mosquito na janela do pintor.
    double Dx = W_J/((double) W_C),
           Dy = H_J/((double) H_C);
    // Coordenadas do centro de um retângulo na tela de mosquito.
    double cX, cY;

    // Iterando na janela do pintor.
    for (int l = 0; l < H_C; l++) {
        
        cY = (double) H_J/2.0 - Dy/2.0 - l*Dy;
        
        for (int c = 0; c < W_C; c++) {

            cX = (double) -W_J/2.0 + Dx/2.0 + c*Dx;

            // Lançando o raio.
            raio = std::make_unique<RaioRayCasting>(ponto_olho, ponto3D(cX, cY, z_J));
            cores[c][l] = cena.corInterseccao(*raio);

        }

    }

    return cores;

}

// Função para desenhar os pixels de acordo com uma matriz de cores.
void desenharPixels(SDL_Renderer* renderer, matrizCores &m) {

    // Limpando o renderer antes de desenhar os pixels.
    SDL_RenderClear(renderer);

    for (int l = 0; l < H_C; l++)
        
        for (int c = 0; c < W_C; c++) 

            if ((0 <= l && l < H_C) && (0 <= c && c < W_C)) {

                // Definindo a cor que será pintada. Essa função segue o padrão RGBA, mas o canal alpha está sendo ignorado.
                SDL_SetRenderDrawColor(renderer, m[c][l][0], m[c][l][1], m[c][l][2], 255);

                // Pintando o pixel.
                SDL_RenderDrawPoint(renderer, c, l);

            }
    
    // Atualizando a janela com o renderer pintado.
    SDL_RenderPresent(renderer);

}

int main(int argc, char* argv[]) {

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event; // Variável para lidar com eventos na SDL.
    bool repetirLoop = true, // Variável de controle do loop principal.
         atualizarJanela = true; // Variável para controlar se a matriz de cores deve ser calculada e desenhada.
    matrizCores pixelBuffer; // Matriz de cores que será pintada.

    // Inicializando o subsistema de vídeo e de input da SDL.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {

        SDL_Log("Erro ao inicializar o SDL! SDL Error: %s", SDL_GetError());
        return EXIT_FAILURE;

    }

    // Criando uma janela.
    window = SDL_CreateWindow(
        "CG I", // Título da janela.
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // Posição inicial da janela (x, y).
        W_C, H_C, // Tamanho em pixels da janela (x, y).
        SDL_WINDOW_OPENGL // Flags
    );

    // Checando se a janela foi criada com sucesso.
    if (window == NULL) {

        SDL_Log("Erro ao criar a janela! SDL Error: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;

    }

    // Criando o contexto de renderização para a janela.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {

        SDL_Log("Erro ao criar o renderer! SDL Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;

    }
    
    // Loop principal onde é feita as interações com a janela.
    while (repetirLoop) {

        // Lidando com eventos.
        while (SDL_PollEvent(&event)) 
            
            // Para o loop principal se o botão de fechar da janela for clicado.
            if (event.type == SDL_QUIT)

                repetirLoop = false;

            else if (event.type == SDL_KEYUP)

                // Para o loop principal se a tecla "Q" for pressionada.
                if (!strcmp(SDL_GetKeyName(event.key.keysym.sym), "Q")) repetirLoop = false;

                // Força uma atualização da janela se a tecla "F5" for pressionada.
                else if (!strcmp(SDL_GetKeyName(event.key.keysym.sym), "F5")) atualizarJanela = true;

        // Calcula e desenha a matriz de cores apenas se for necessário para otimizar o programa.
        if (atualizarJanela) {

            // Chamando a função para calcular a matriz de cores que será pintada.
            pixelBuffer = calcularMatrizCores();

            // Chamando a função para pintar os pixels.
            desenharPixels(renderer, pixelBuffer);

            atualizarJanela = false;
        
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}