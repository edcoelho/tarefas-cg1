#ifndef ALGEBRA_MATRIZ3_HPP
#define ALGEBRA_MATRIZ3_HPP

#include <array>
#include "algebra/Vetor3.hpp"
#include "algebra/Ponto3.hpp"

// Uma matriz de ordem 3. Inicializa por padrão como uma matriz identidade.
class Matriz3 {

    private:
        double a00, a01, a02;
        double a10, a11, a12;
        double a20, a21, a22;

    public:
        // --- CONSTRUTORES ---

            Matriz3();
    
            Matriz3(double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22);

            Matriz3(double valor);

        // --- OPERADORES ---

            // Operador para acessar um elemento de uma Matriz3.
            double operator () (std::size_t linha, std::size_t coluna) const;

            // Operador para definir o valor de um elemento de uma Matriz3.
            double& operator () (std::size_t linha, std::size_t coluna);

            // Operador para adição de duas Matriz3.
            Matriz3 operator + (Matriz3 const& matriz) const;

            // Operador para subtração de duas Matriz3.
            Matriz3 operator - (Matriz3 const& matriz) const;

            // Operador para multiplicação de duas Matriz3.
            Matriz3 operator * (Matriz3 const& matriz) const;

            // Operador para multiplicação de uma Matriz3 por um Vetor3.
            Vetor3 operator * (Vetor3 const& vetor) const;

            // Operador para multiplicação da Matriz3 por um Ponto3.
            Ponto3 operator * (Ponto3 const& ponto) const;

            // Operador para produto de uma Matriz3 por um escalar.
            Matriz3 operator * (double const escalar) const;

};

#endif