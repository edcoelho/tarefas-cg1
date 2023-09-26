#include <SDL2/SDL.h>
#include "../include/utils.hpp"
#include "../include/Cena.hpp"
#include "../include/RaioRayCasting.hpp"
#include "../include/Esfera.hpp"
#include "../include/Plano.hpp"
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

// Valores da esfera.

    // Raio da esfera.
    const double R = 40.0;

    // Centro da esfera.
    const ponto3D C(0, 0, -100.0);

    // Valores de reflectividade da esfera.

        // Valor de reflectividade ambiente da esfera.
        const i_luz EK_a(0.7f, 0.2f, 0.2f);

        // Valor de reflectividade difusa da esfera.
        const i_luz EK_d(0.7f, 0.2f, 0.2f);

        // Valor de reflectividade especular da esfera.
        const i_luz EK_e(0.7f, 0.2f, 0.2f);

        // Expoente de espelhamento (shininess) da esfera.
        const double Em = 10.0;

// Valores do plano do chão.

    // Ponto conhecido do plano do chão.
    const ponto3D CP_pi(0.0, -R, 0.0);

    // Vetor unitário normal ao plano do chão.
    const Eigen::Vector3d Cn_bar(0.0, 1.0, 0.0);

    // Valores de reflectividade do plano do chão.

        // Valor de reflectividade ambiente do plano do chão.
        const i_luz CK_a(0.2, 0.7, 0.2);

        // Valor de reflectividade difusa do plano do chão.
        const i_luz CK_d(0.2, 0.7, 0.2);
        
        // Valor de reflectividade especular do plano do chão.
        const i_luz CK_e(0.0, 0.0, 0.0);

        // Expoente de espelhamento (shininess) do plano do chão.
        const double Cm = 1.0;

// Valores do plano do fundo.

    // Ponto conhecido do plano do fundo.
    const ponto3D FP_pi(0.0, 0.0, -200.0);

    // Vetor unitário normal ao plano do fundo.
    const Eigen::Vector3d Fn_bar(0.0, 0.0, 1.0);

    // Valores de reflectividade do plano do fundo.

        // Valor de reflectividade ambiente do plano do fundo.
        const i_luz FK_a(0.3, 0.3, 0.7);

        // Valor de reflectividade difusa do plano do fundo.
        const i_luz FK_d(0.3, 0.3, 0.7);
        
        // Valor de reflectividade especular do plano do fundo.
        const i_luz FK_e(0.0, 0.0, 0.0);

        // Expoente de espelhamento (shininess) do plano do fundo.
        const double Fm = 1.0;

// Intensidade da fonte de luz pontual.
i_luz I_F(0.7, 0.7, 0.7);

// Posição da fonte de luz pontual.
ponto3D P_F(0.0, 60.0, -30.0);

// Intensidade da luz ambiente.
i_luz I_A(0.3f, 0.3f, 0.3f);

// Cor do background.
const rgb bgColor(100, 100, 100);

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

    // Inserindo o ponto de luz na cena.
    cena.setFonteLuz(std::make_unique<LuzPontual>(P_F, I_F));

    // Inserindo a esfera na cena.
    cena.inserirSolido(std::make_unique<Esfera>(C, R, Material(EK_a, EK_d, EK_e, Em)));

    // Inserindo plano do chão.
    cena.inserirSolido(std::make_unique<Plano>(CP_pi, Cn_bar, Material(CK_a, CK_d, CK_e, Cm)));

    // Inserindo plano do fundo.
    cena.inserirSolido(std::make_unique<Plano>(FP_pi, Fn_bar, Material(FK_a, FK_d, FK_e, Fm)));

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
        "Janela", // Título da janela.
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