#include <array>

#ifndef UTILS_H
#define UTILS_H

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Canal de cor no padrão RGB. Possui 1 byte sem sinal, podendo assumir um valor inteiro no intervalo [0, 255].
typedef unsigned char canalCor;

// Estrutura para ajudar na representação de uma cor.
struct rgb {

    canalCor red;
    canalCor green;
    canalCor blue;

    rgb() {
        red = 0;
        green = 0;
        blue = 0;
    }

    rgb(canalCor r, canalCor g, canalCor b) {
        red = r;
        green = g;
        blue = b;
    }

};

// Coordenadas de um ponto3D num plano 3D.
struct ponto3D {

    double x;
    double y;
    double z;

    ponto3D() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    ponto3D(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }

};

// Representação básica de um vetor3D num espaço 3D.
typedef std::array<double, 3> vetor3D;

// --- FUNÇÕES ---

// Retorna o vetor3D posição de um ponto3D "p".
vetor3D vetorPosicao(ponto3D p);

// Soma um vetor3D "v" a um ponto3D "p" e retorna o ponto3D resultante.
ponto3D pontoMaisVetor(ponto3D p, vetor3D v);

// Subtrai um ponto3D "pB" de um ponto3D "pA" e retorna o vetor3D resultante.
vetor3D pontoMenosPonto(ponto3D pA, ponto3D pB);

// Soma dois vetor3D "vA" e "vB" e retorna o vetor3D resultante.
vetor3D vetorMaisVetor(vetor3D vA, vetor3D vB);

// Soma um escalar "e" a um vetor3D "v".
vetor3D vetorMaisEscalar(vetor3D v, double e);

// Multiplica um vetor3D "v" por um escalar "e" e retorna o vetor3D resultante.
vetor3D vetorVezesEscalar(vetor3D v, double e);

// Realiza o produto escalar de um vetor3D "vA" por um vetor3D "vB" e retorna o valor resultante.
double produtoEscalar(vetor3D vA, vetor3D vB);

// Retorna o módulo de um vetor3D "v".
double moduloVetor(vetor3D v);

// Normaliza um vetor3D "v" e retorna o vetor3D resultante.
vetor3D normalizaVetor(vetor3D v);

#endif