#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <array>

class Matriz3 {

    private:
        std::array<std::array<double, 3>, 3> elementos;

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

            // Operador para produto de uma matriz por um escalar.
            Matriz3 operator * (double const escalar) const;

            // Operador para produto de Hadamard de duas matrizes.
            Matriz3 operator % (Matriz3 const& matriz) const;

    // --- GETTERS E SETTERS ---

        std::array<std::array<double, 3>, 3> get_elementos() const;
        void set_elementos(std::array<std::array<double, 3>, 3> e);

    // --- OUTROS MÉTODOS ---

        // Retorna o determinante da matriz se ela for quadrada.
        double det() const;

        // Retorna o produto de Hadamard da matriz por uma outra matriz.
        Matriz3 hadamard(Matriz3 const& matriz) const;

};

#endif