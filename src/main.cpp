#include <SDL2/SDL.h>
#include "../include/utils.hpp"
#include "../include/Cena.hpp"
#include "../include/RaioRayCasting.hpp"
#include "../include/Esfera.hpp"
#include <array>
#include <memory>

// -- CONSTANTES --

// Largura, altura e posição da window.
const int nCol = 700, // largura
          nLin = 700; // altura

// Cor da esfera e cor do background.
const rgb esfColor(255, 0, 0),
          bgColor(100, 100, 100);

// -- VARIÁVEIS GLOBAIS --

// Tamanho da "janela" do pintor em metros e distância até o olho.
double wJanela = 3.0,
       hJanela = (nLin / nCol) * 3.0,
       dJanela = 3.0;

// Tamanho do raio da esfera.
double rEsfera = 1;

// Intensidade da fonte de luz pontual.
i_luz I_F(0.7, 0.7, 0.7);

// Posição da fonte de luz pontual.
ponto3D P_F(0, 5, 0);

// Posição do centro da esfera.
ponto3D centroEsfera(0, 0, -(dJanela + rEsfera + 1));

// Posição do olho do pintor
ponto3D ponto_olho(0, 0, 0);

// -- DEFINIÇÕES DE TIPOS -- //

// Tipo para representar uma matriz de cores.
typedef std::array<std::array<rgb, static_cast<std::size_t>(nLin)>, static_cast<std::size_t>(nCol)> matrizCores;

// --- FUNÇÕES ---

// Função que retorna a matriz de cores que será pintada.
matrizCores calcularMatrizCores() {

    // Criando a cena.
    Cena cena(bgColor);
    // Criando um ponteiro para um objeto raio para o ray casting.
    std::unique_ptr<RaioRayCasting> raio;
    // Criando a matriz de cores que serão pintadas na janela.
    matrizCores cores;

    // Dimensões dos retângulos da tela de mosquito na janela do pintor.
    double Dx = wJanela/((double) nCol),
           Dy = hJanela/((double) nLin);
    // Coordenadas do centro de um retângulo na tela de mosquito.
    double cX, cY;

    // Inserindo o ponto de luz na cena.
    cena.setFonteLuz(std::make_unique<LuzPontual>(P_F, I_F));

    // Inserindo a esfera na cena.
    cena.inserirSolido(std::make_unique<Esfera>(centroEsfera, rEsfera, Material(esfColor, rgb(255, 255, 255), 5)));

    // Iterando na janela do pintor.
    for (int l = 0; l < nLin; l++) {
        
        cY = (double) hJanela/2.0 - Dy/2.0 - l*Dy;
        
        for (int c = 0; c < nCol; c++) {

            cX = (double) -wJanela/2.0 + Dx/2.0 + c*Dx;

            // Lançando o raio.
            raio = std::make_unique<RaioRayCasting>(ponto_olho, ponto3D(cX, cY, -dJanela));
            cores[c][l] = cena.corInterseccao(*raio);

        }

    }

    return cores;

}

// Função para desenhar os pixels de acordo com uma matriz de cores.
void desenharPixels(SDL_Renderer* renderer, matrizCores &m) {

    // Limpando o renderer antes de desenhar os pixels.
    SDL_RenderClear(renderer);

    for (int l = 0; l < nLin; l++)
        
        for (int c = 0; c < nCol; c++) 

            if ((0 <= l && l < nLin) && (0 <= c && c < nCol)) {

                // Definindo a cor que será pintada. Essa função segue o padrão RGBA, mas o canal alpha está sendo ignorado.
                SDL_SetRenderDrawColor(renderer, m[c][l](0), m[c][l](1), m[c][l](2), 255);

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
        "CG I - Tarefa 02 - Esfera iluminada por uma fonte de luz pontual.", // Título da janela.
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // Posição inicial da janela (x, y).
        nCol, nLin, // Tamanho em pixels da janela (x, y).
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