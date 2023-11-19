#ifndef UTILS_HPP
#define UTILS_HPP

#include <array>

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Canal de cor RGB. Funciona como um inteiro de 1 byte sem sinal, ou seja, um inteiro no intervalo [0, 255].
typedef unsigned char canal_RGB;

// Estrutura para ajudar na representação de uma cor.
typedef std::array<canal_RGB, 3> rgb;

#endif