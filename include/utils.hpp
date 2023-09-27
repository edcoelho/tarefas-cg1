#ifndef UTILS_HPP
#define UTILS_HPP

#include <eigen3/Eigen/Core>
#include <array>

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Coordenadas de um ponto num plano 3D.
// Funciona como um array da biblioteca Eigen.
typedef Eigen::Vector3d ponto3D;

// Canal de cor RGB. Funciona como um inteiro de 1 byte sem sinal, ou seja, um inteiro no intervalo [0, 255].
typedef u_int8_t canalRGB;

// Estrutura para ajudar na representação de uma cor.
typedef Eigen::Array<canalRGB, 3, 1> rgb;

// Estrutura para representar a intensidade de uma fonte de luz.
typedef Eigen::Array3f i_luz;

#endif