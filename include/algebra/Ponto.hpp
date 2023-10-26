#ifndef PONTO_HPP
#define PONTO_HPP

#include "Vetor.hpp"
#include <vector>

class Ponto {

    private:
        std::vector<double> coordenadas;
        std::size_t dimensao;

    protected:
        // --- MÉTODOS PROTEGIDOS ---

            // Retorna se o índice especificado é uma coordenada válida do ponto.
            bool coordenadaValida(std::size_t coordenada) const;

    public:
        // --- CONSTRUTORES ---

            Ponto(std::size_t n);

            Ponto(std::vector<double> e);

            Ponto(std::size_t n, std::vector<double> e);

        // --- OPERADORES ---

            // Operador para acessar uma coordenada de um ponto.
            double operator () (std::size_t linha) const;
            double operator [] (std::size_t linha) const;

            // Operador para definir o valor de uma coordenada de um ponto.
            double& operator () (std::size_t linha);
            double& operator [] (std::size_t linha);

            // Operador para adicionar um vetor a um ponto.
            Ponto operator + (Vetor vetor) const;

            // Operador para subtrair um vetor de um ponto.
            Ponto operator - (Vetor vetor) const;

            // Operador para subtrair um ponto de outro ponto.
            Vetor operator - (Ponto ponto) const;

        // --- GETTERS E SETTERS ---

            std::vector<double> getCoordenadas() const;
            void setCoordenadas(std::vector<double> c);

            std::size_t getDimensao() const;
            void setDimensao(std::size_t d);

        // --- OUTROS MÉTODOS ---

            // Retorna um std::vector<double> com as coordenadas do ponto.

            std::vector<double> stdVector() const;

            // Retorna um Vetor cujos elementos são as coordenadas do ponto.

            Vetor paraVetor() const;

};

#endif