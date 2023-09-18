#ifndef UTILS_HPP
#define UTILS_HPP

#include <eigen3/Eigen/Core>
#include <array>

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Coordenadas de um ponto num plano 3D.
// Funciona como um array da biblioteca Eigen.
typedef Eigen::Array3d ponto3D;

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

#endif