#ifndef VETOR_HPP
#define VETOR_HPP

#include "Matriz.hpp"

class Ponto;

class Vetor : public Matriz {

    protected:
        // --- MÉTODOS PROTEGIDOS ---

            // Retorna se o índice especificado é uma posição válida do vetor.
            bool posicaoValida(std::size_t linha) const;

    public:

        // --- CONSTRUTORES ---

            Vetor();

            Vetor(std::size_t n);

            Vetor(std::vector<double> e);

            // Vetor num espaço tridimensional.
            Vetor(double x, double y, double z);

        // --- OPERADORES ---

            // Operador para acessar um elemento de um vetor.
            double operator () (std::size_t linha) const;
            double operator [] (std::size_t linha) const;

            // Operador para definir o valor de um elemento de um vetor.
            double& operator () (std::size_t linha);
            double& operator [] (std::size_t linha);

            // Operador para adição de dois vetores.
            Vetor operator + (Vetor const& vetor) const;

            // Operador para adição de um escalar a um vetor.
            Vetor operator + (double const escalar) const;

            // Operador para subtração de dois vetores.
            Vetor operator - (Vetor const& vetor) const;

            // Operador para subtração de um escalar de um vetor.
            Vetor operator - (double const escalar) const;

            // Operador para produto de um vetor por um escalar.
            Vetor operator * (double const escalar) const;

            // Operador para produto vetorial do vetor por outro vetor.
            Vetor operator * (Vetor const vetor) const;

            // Operador para produto de Hadamard de dois vetores.
            Vetor operator % (Vetor const& vetor) const;

        // --- OUTROS MÉTODOS ---

            // Retorna a norma/módulo do vetor.
            double norma() const;

            // Normaliza o vetor.
            void normalizar();

            // Retorna um std::vector<double> com os elementos do vetor.
            std::vector<double> stdVector() const;

            // Retorna um Ponto cujas coordenadas são os elementos do vetor.
            Ponto paraPonto() const;

            // Retorna o vetor unitário.
            Vetor unitario() const;

            // Retorna o produto escalar do vetor por um outro vetor v.
            double pEscalar(Vetor v) const;

            // Retorna o produto vetorial do vetor por um outro vetor v, mas se e somente se esses dois vetores forem tridimensionais.
            Vetor pVetorial(Vetor v) const;

};

#endif