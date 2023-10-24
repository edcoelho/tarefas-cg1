#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>

class Matriz {

    private:
        std::size_t numLinhas;
        std::size_t numColunas;

    protected:
        std::vector<std::vector<double>> elementos;

        // --- MÉTODOS PROTEGIDOS ---

            // Retorna se os índices especificados são posições válidas da matriz.
            bool posicaoValida(std::size_t linha, std::size_t coluna) const;

    public:
        // --- CONSTRUTORES ---

            Matriz(size_t m, size_t n);

            Matriz(size_t m, size_t n, std::vector<std::vector<double>> e);

        // --- OPERADORES ---

            // Operador para acessar um elemento de uma matriz.
            double operator () (std::size_t linha, std::size_t coluna) const;

            // Operador para definir o valor de um elemento de uma matriz.
            double& operator () (std::size_t linha, std::size_t coluna);

            // Operador para adição de duas matrizes.
            Matriz operator + (Matriz const& matriz) const;

            // Operador para adição de um escalar a uma matriz.
            Matriz operator + (double const escalar) const;

            // Operador para subtração de duas matrizes.
            Matriz operator - (Matriz const& matriz) const;

            // Operador para subtração de um escalar de uma matriz.
            Matriz operator - (double const escalar) const;

            // Operador para produto de uma matriz por um escalar.
            Matriz operator * (double const escalar) const;

            // Operador para produto de Hadamard de duas matrizes.
            Matriz operator % (Matriz const& matriz) const;

    // --- GETTERS E SETTERS ---

        std::size_t getNumLinhas() const;
        void setNumLinhas(std::size_t m);

        std::size_t getNumColunas() const;
        void setNumColunas(std::size_t n);

        std::vector<std::vector<double>> getElementos() const;
        void setElementos(std::vector<std::vector<double>> e);

    // --- OUTROS MÉTODOS ---

        // Retorna o cofator do elemento na posição (linha, coluna) da matriz se esta for quadrada.
        double cofator(std::size_t i, std::size_t j) const;

        // Retorna o determinante da matriz se ela for quadrada.
        double det() const;

        // Retorna o produto de Hadamard da por uma outra matriz.
        Matriz hadamard(Matriz const& matriz) const;

};

#endif