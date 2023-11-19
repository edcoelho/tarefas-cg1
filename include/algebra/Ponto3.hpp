#ifndef ALGEBRA_PONTO3_HPP
#define ALGEBRA_PONTO3_HPP

#include "Vetor3.hpp"
#include <array>

class Ponto3 {

    private:
        double x;
        double y;
        double z;

    public:
        // --- CONSTRUTORES ---

            Ponto3();

            Ponto3(double x, double y, double z);

            Ponto3(std::array<double, 3> c);

        // --- OPERADORES ---

            // Operador para acessar uma coordenada de um ponto.
            double operator [] (std::size_t linha) const;

            // Operador para definir o valor de uma coordenada de um ponto.
            double& operator [] (std::size_t linha);

            // Operador para adicionar um vetor a um ponto.
            Ponto3 operator + (Vetor3 vetor) const;

            // Operador para subtrair um vetor de um ponto.
            Ponto3 operator - (Vetor3 vetor) const;

            // Operador para subtrair um ponto de outro ponto.
            Vetor3 operator - (Ponto3 ponto) const;

        // --- GETTERS E SETTERS ---

            double get_x() const;
            void set_x(double x);

            double get_y() const;
            void set_y(double y);

            double get_z() const;
            void set_z(double z);

        // --- OUTROS MÉTODOS ---

            // Retorna um std::array<double, 3> com as coordenadas do ponto.

            std::array<double, 3> std_array() const;

            // Retorna um Vetor cujos elementos são as coordenadas do ponto.

            Vetor3 vetor() const;

};

#endif