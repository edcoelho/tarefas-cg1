#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../include/utils.h"
#include "../include/RaioRayCasting.h"
#include "../include/Esfera.h"
#include <iostream>
#include <array>

// Posição do olho do pintor
ponto3D PONTO_OLHO(0, 0, 0);

// --- DEFINIÇÕES ---

// Variáveis globais

// Largura, altura e posição da window.
// ATENÇÃO: O número de colunas e linhas devem ser múltiplos de 100, pois com quaisquer outros valores o desenho está bugando.
const int nCol = 700, // largura
          nLin = 700, // altura
          winPosX = 0,
          winPosY = 0;

// Matriz de cores.
typedef std::array<std::array<rgb, static_cast<std::size_t>(nLin)>, static_cast<std::size_t>(nCol)> matrizCores;

// --- FUNÇÕES ---

// Recebe a matriz de cores "m" e desenha no framebuffer padrão do OpenGL.
void desenharPixels(matrizCores m) {

    GLubyte* PixelBuffer = new GLubyte[nCol * nLin * 3];
    int posicao;

    for (int linha = 0; linha < nLin; linha++)
        
        for (int coluna = 0; coluna < nCol; coluna++) {

            if ((0 <= linha && linha < nLin) && (0 <= coluna && coluna < nCol)) {

                posicao = (coluna + linha * nCol) * 3;
                PixelBuffer[posicao] = m[coluna][linha].red;
                PixelBuffer[posicao + 1] = m[coluna][linha].green;
                PixelBuffer[posicao + 2] = m[coluna][linha].blue;

            }

        }

    // Pede a o OpenGL para desenhar os pixels.
    glDrawPixels(nCol, nLin, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);

    delete PixelBuffer;

}

// Função de display do GLUT.
void display() {

    // Tamanho da "janela" do pintor em metros e distância até ela.
    double wJanela = 3.0,
           hJanela = 3.0,
           dJanela = 3.0;

    // Tamanho do raio, posição do centro e cor da esfera.
    double rEsfera = 1,
           zCentroEsfera = -1*(dJanela + rEsfera + 1);

    ponto3D centroEsfera(0, 0, zCentroEsfera);
    rgb esfColor(255, 0, 0);

    // Dimensões dos retângulos da tela de mosquito na janela do pintor.
    double Dx = (double) wJanela/nCol,
           Dy = (double) hJanela/nLin;

    // Criando a esfera.
    Esfera esfera(centroEsfera, rEsfera, esfColor);
    // Criando um ponteiro para um objeto raio para o ray casting.
    RaioRayCasting* raio;
    // Criando a matriz de cores que serão pintadas na janela.
    matrizCores canvas;

    // Coordenadas do centro de um retângulo na tela de mosquito.
    double cX, cY;

    // Cor do background.
    const rgb bgColor(100, 100, 100);

    glClear(GL_COLOR_BUFFER_BIT);

    // Iterando na janela do pintor.
    for (int l = 0; l < nLin; l++) {
        
        cY = (double) hJanela/2.0 - Dy/2.0 - l*Dy;
        
        for (int c = 0; c < nCol; c++) {

            cX = (double) -1*wJanela/2.0 + Dx/2.0 + c*Dx;

            // Lançando o raio.
            raio = new RaioRayCasting(PONTO_OLHO, ponto3D(cX, cY, -1.0*dJanela));

            if (raio->houveInterseccao(esfera))
                canvas[c][l] = esfColor;
            else
                canvas[c][l] = bgColor;

            // Desalocando espaço na memória em que estava o raio.
            delete raio;

        }

    }

    // Passando a matriz de cores do canvas para ser desenhada.
    desenharPixels(canvas);
    // Realizando a transferência do conteúdo do back buffer para o front buffer.
    glutSwapBuffers();

}

int main(int argc, char *argv[]) {

    GLenum res;
    const rgb bgColor(100, 100, 100);

    // Inicializando FreeGLUT.
    glutInit(&argc, argv);

    // Configurando o display mode do GLUT.
    // GLUT_RGBA habilita o sistema RGB de cores com o canal alpha.
    // GLUT_DOUBLE habilita o uso de double buffering, que permitirá que existam dois buffers: o front buffer, que guardará o frame atualmente exibido, e o back buffer, que será onde o próximo frame será renderizado. Isso impede problemas de tearing que ocorreriam se mostrassemos o frame enquanto ele está sendo renderizado.
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // Configurando tamanho e posição da janela.
    glutInitWindowSize(nCol, nLin);
    glutInitWindowPosition(winPosX, winPosY);

    // Criando a janela.
    glutCreateWindow("CG I - Tarefa 1 - Esfera com o centro no eixo z negativo.");

    // Inicializando o GLEW. Isso deve ser feito depois da criação do contexto OpenGL.
    res = glewInit();
    if (res != GLEW_OK) {
        std::cout << "Erro ao inicializar o GLEW: " << glewGetErrorString(res) << std::endl;
        return EXIT_FAILURE;
    }

    // Configurando a cor da tela ao ser limpa. Cada valor corresponde a um float que deve variar entre 0 e 1. Como cada canal de cor tem 256 valores possíveis, cada valor deve ser um múltiplo de 1/255.
    glClearColor(((float) bgColor.red)/255.0f, ((float) bgColor.green)/255.0f, ((float) bgColor.blue)/255.0f, 1.0f);

    // Configurando uma função callback para a renderização.
    glutDisplayFunc(display);

    // Entrando no loop principal do GLUT que vai processar os eventos.
    glutMainLoop();

    return EXIT_SUCCESS;

}