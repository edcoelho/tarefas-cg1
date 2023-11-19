#ifndef INTENSIDADELUZ_HPP
#define INTENSIDADELUZ_HPP

#include <array>
#include "utils/utils.hpp"

class IntensidadeLuz {

    private:
        double r;
        double g;
        double b;

    public:
        // --- CONSTRUTORES ---

            IntensidadeLuz();

            IntensidadeLuz(double r, double g, double b);

            IntensidadeLuz(std::array<double, 3> val);

            IntensidadeLuz(rgb cor_rgb);

        // --- OPERADORES ---

            // Operador para acessar um canal da intensidade de luz.
            double operator [] (std::size_t indice) const;

            // Operador para definir o valor de um canal da intensidade de luz.
            double& operator [] (std::size_t indice);

            // Operador para adicionar intensidades de luz.
            IntensidadeLuz operator + (IntensidadeLuz const& intensidade) const;

            // Operador para adicionar um escalar aos canais de intensidade de luz.
            IntensidadeLuz operator + (double const escalar) const;

            // Operador para subtrair intensidades de luz.
            IntensidadeLuz operator - (IntensidadeLuz const& intensidade) const;

            // Operador para subtrair um escalar dos canais de intensidade de luz.
            IntensidadeLuz operator - (double const escalar) const;

            // Operador para multiplicar intensidades de luz (produto de hadamard).
            IntensidadeLuz operator * (IntensidadeLuz const& intensidade) const;

            // Operador para multiplicar um escalar aos canais de intensidade de luz.
            IntensidadeLuz operator * (double const escalar) const;

        // --- GETTERS E SETTERS ---

            double get_r() const;
            void set_r(double r);

            double get_g() const;
            void set_g(double g);

            double get_b() const;
            void set_b(double b);

        // --- OUTROS MÉTODOS ---

            // Retorna uma cor RGB correspondente à intensidade de luz.
            rgb cor_rgb() const;

            // Conserta os valores dos canais da intensidade de luz limitando-os ao intervalo [0,1].
            void consertar();

};

#endif