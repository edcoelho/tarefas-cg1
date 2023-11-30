#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <array>
#include "algebra/Vetor3.hpp"

class Matriz3 {

    private:
        double a00, a01, a02;
        double a10, a11, a12;
        double a20, a21, a22;

    public:
        // --- CONSTRUTORES ---

            Matriz3();
    
            Matriz3(double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22);

            Matriz3(std::array<std::array<double, 3>, 3> e);

        // --- OPERADORES ---

            // Operador para acessar um elemento de uma matriz.
            double operator () (std::size_t linha, std::size_t coluna) const;

            // Operador para definir o valor de um elemento de uma matriz.
            double& operator () (std::size_t linha, std::size_t coluna);

            // Operador para adição de duas matrizes.
            Matriz3 operator + (Matriz3 const& matriz) const;

            // Operador para adição de um escalar a uma matriz.
            Matriz3 operator + (double const escalar) const;

            // Operador para subtração de duas matrizes.
            Matriz3 operator - (Matriz3 const& matriz) const;

            // Operador para subtração de um escalar de uma matriz.
            Matriz3 operator - (double const escalar) const;

            // Operador para multiplicação de duas matrizes.
            Matriz3 operator * (Matriz3 const& matriz) const;

            // Operador para multiplicação da matriz por um vetor.
            Vetor3 operator * (Vetor3 const& vetor) const;

            // Operador para produto de uma matriz por um escalar.
            Matriz3 operator * (double const escalar) const;

    // --- OUTROS MÉTODOS ---

        // Retorna o determinante da matriz se ela for quadrada.
        double det() const;

};

#endif