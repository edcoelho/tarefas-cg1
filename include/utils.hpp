#ifndef UTILS_HPP
#define UTILS_HPP

#include <eigen3/Eigen/Core>
#include <array>

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Coordenadas de um ponto num plano 3D.
// Funciona como um array da biblioteca Eigen.
typedef Eigen::Array3d ponto3D;

// Estrutura para ajudar na representação de uma cor.
typedef Eigen::Vector<u_int8_t, 3> rgb;

#endif