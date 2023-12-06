#include "cena/Canvas.hpp"

Canvas::Canvas() {

    this->set_altura(500);
    this->set_largura(500);
    this->set_cor_padrao(rgb{0, 0, 0});

    this->pixel_buffer = std::vector<std::vector<rgb>>(500, std::vector<rgb>(500, rgb{0, 0, 0}));

}

Canvas::Canvas(std::size_t altura, std::size_t largura, rgb cor_padrao) {

    this->set_altura(altura);
    this->set_largura(largura);
    this->set_cor_padrao(cor_padrao);

    this->pixel_buffer = std::vector<std::vector<rgb>>(altura, std::vector<rgb>(largura, cor_padrao));

}

std::size_t Canvas::get_altura() const {

    return this->altura;

}
void Canvas::set_altura(double a) {

    this->altura = a;

}

std::size_t Canvas::get_largura() const {

    return this->largura;

}
void Canvas::set_largura(double l) {

    this->largura = l;

}

rgb Canvas::get_cor_padrao() const {

    return this->cor_padrao;

}
void Canvas::set_cor_padrao(rgb c) {

    this->cor_padrao = c;

}

void Canvas::calcular_cores(Cena& cena) {

    // Raio para o ray casting.
    Raio raio;

    // Dimensões dos pixels no canvas.

    double D_x = cena.get_camera().get_largura_fov()/(this->get_largura()),
           D_y = cena.get_camera().get_altura_fov()/(this->get_altura());

    // Coordenadas do centro de um ponto na janela do campo de visão correspondente a um pixel no canvas.
    double cX, cY;

    Ponto3 centro_pixel;

    // Iterando no campo de visão.
    for (std::size_t l = 0; l < this->get_altura(); l++) {
        
        cY = (double) cena.get_camera().get_altura_fov()/2.0 - D_y/2.0 - l*D_y;
        
        for (std::size_t c = 0; c < this->get_largura(); c++) {

            cX = (double) -1.0 * cena.get_camera().get_largura_fov()/2.0 + D_x/2.0 + c*D_x;

            centro_pixel[0] = cX;
            centro_pixel[1] = cY;
            centro_pixel[2] = -cena.get_camera().get_distancia_fov();

            // Convertendo o ponto do centro do pixel para coordenadas de mundo.
            centro_pixel = cena.get_camera().get_matriz_camera_mundo() * centro_pixel;

            // Lançando o raio em coordenadas de mundo.
            raio = Raio(cena.get_camera().get_posicao(), centro_pixel);
            this->pixel_buffer[c][l] = cena.cor_interseccao(raio, this->get_cor_padrao());

        }

    }

}

void Canvas::desenhar_pixels(SDL_Renderer* renderer) const {

    // Limpando o renderer antes de desenhar os pixels.
    SDL_RenderClear(renderer);

    for (std::size_t l = 0; l < this->get_altura(); l++)
        
        for (std::size_t c = 0; c < this->get_largura(); c++) 

            if ((0 <= l && l < this->get_altura()) && (0 <= c && c < this->get_largura())) {

                // Definindo a cor que será pintada. Essa função segue o padrão RGBA, mas o canal alpha está sendo ignorado.
                SDL_SetRenderDrawColor(renderer, this->pixel_buffer[c][l][0], this->pixel_buffer[c][l][1], this->pixel_buffer[c][l][2], 255);

                // Pintando o pixel.
                SDL_RenderDrawPoint(renderer, c, l);

            }
    
    // Atualizando a janela com o renderer pintado.
    SDL_RenderPresent(renderer);

}

int Canvas::loop(Cena& cena, const char* titulo) {

    // Ponteiro para uma janela do SDL.
    SDL_Window* window;
    // Ponteiro para um contexto de renderização.
    SDL_Renderer* renderer;
    // Objeto para lidar com eventos.
    SDL_Event event;

    bool repetir_loop = true; // Variável de controle do loop principal.
    bool recalcular_cores = true; // Variável para controlar se a matriz de cores deve ser calculada.
    bool renderizar_pixel_buffer = true; // Variável para controlar se a matriz de cores deve ser desenhada.

    // Inicializando o subsistema de vídeo e de input da SDL.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {

        SDL_Log("Erro ao inicializar o SDL! SDL Error: %s", SDL_GetError());
        return EXIT_FAILURE;

    }

    // Criando uma janela.
    window = SDL_CreateWindow(
        titulo, // Título da janela.
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // Posição inicial da janela (x, y).
        this->get_largura(), this->get_altura(), // Tamanho em pixels da janela (x, y).
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
    while (repetir_loop) {

        // Lidando com eventos.
        while (SDL_PollEvent(&event)) {
            
            // Para o loop principal se o botão de fechar da janela for clicado.
            if (event.type == SDL_QUIT) {

                repetir_loop = false;

            } else if (event.type == SDL_KEYUP) {

                // Para o loop principal se a tecla "Q" for pressionada.
                if (!strcmp(SDL_GetKeyName(event.key.keysym.sym), "Q")) {
                    
                    repetir_loop = false;

                // Força uma atualização da janela se a tecla "F5" for pressionada.
                } else if (!strcmp(SDL_GetKeyName(event.key.keysym.sym), "F5")) {
                    
                    recalcular_cores = true;

                }

            } else if (event.type == SDL_WINDOWEVENT) {

                if (event.window.event == SDL_WINDOWEVENT_SHOWN) {

                    // Força o pixel buffer a ser renderizado novamente quando a tela é maximizada para evitar o bug da tela transparente.
                    renderizar_pixel_buffer = true;

                }

            }

        }

        // Calcula e desenha a matriz de cores apenas se for necessário para otimizar o programa.
        if (recalcular_cores) {

            // Chamando a função para calcular a matriz de cores que será pintada.
            this->calcular_cores(cena);

            renderizar_pixel_buffer = true;
            recalcular_cores = false;
        
        }

        if (renderizar_pixel_buffer) {

            // Chamando a função para pintar os pixels.
            this->desenhar_pixels(renderer);

            renderizar_pixel_buffer = false;

        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}