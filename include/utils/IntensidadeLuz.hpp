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

            IntensidadeLuz(rgb corRGB);

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

            double getR() const;
            void setR(double r);

            double getG() const;
            void setG(double g);

            double getB() const;
            void setB(double b);

        // --- OUTROS MÉTODOS ---

            // Retorna uma cor RGB correspondente à intensidade de luz.
            rgb paraRGB() const;

            // Conserta os valores dos canais da intensidade de luz limitando-os ao intervalo [0,1].
            void consertaIntensidade();

};

#endif