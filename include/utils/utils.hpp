#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <array>
#include <memory>

// --- DEFINIÇÕES DE TIPOS E ESTRUTURAS ---

// Canal de cor RGB. Funciona como um inteiro de 1 byte sem sinal, ou seja, um inteiro no intervalo [0, 255].
typedef uint8_t canalRGB;

// Estrutura para ajudar na representação de uma cor.
typedef std::array<canalRGB, 3> rgb;

#endif