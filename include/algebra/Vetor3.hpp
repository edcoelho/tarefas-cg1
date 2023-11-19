#ifndef ALGEBRA_VETOR3_HPP
#define ALGEBRA_VETOR3_HPP

#include <array>

class Ponto3;

class Vetor3 {

    private:
        double x;
        double y;
        double z;

    public:

        // --- CONSTRUTORES ---

            Vetor3();

            Vetor3(double x, double y, double z);

            Vetor3(std::array<double, 3> e);

        // --- OPERADORES ---

            // Operador para acessar um elemento de um vetor.
            double operator [] (std::size_t indice) const;

            // Operador para definir o valor de um elemento de um vetor.
            double& operator [] (std::size_t indice);

            // Operador para adição de dois vetores.
            Vetor3 operator + (Vetor3 const& vetor) const;

            // Operador para adição de um escalar a um vetor.
            Vetor3 operator + (double const escalar) const;

            // Operador para subtração de dois vetores.
            Vetor3 operator - (Vetor3 const& vetor) const;

            // Operador para subtração de um escalar de um vetor.
            Vetor3 operator - (double const escalar) const;

            // Operador para produto vetorial do vetor por outro vetor.
            Vetor3 operator * (Vetor3 const vetor) const;

            // Operador para produto de um vetor por um escalar.
            Vetor3 operator * (double const escalar) const;

            // Operador para produto de Hadamard de dois vetores.
            Vetor3 operator % (Vetor3 const& vetor) const;

        // --- GETTERS E SETTERS ---

            double get_x() const;
            void set_x(double x);

            double get_y() const;
            void set_y(double y);

            double get_z() const;
            void set_z(double z);

        // --- OUTROS MÉTODOS ---

            // Retorna a norma/módulo do vetor.
            double norma() const;

            // Normaliza o vetor.
            void normalizar();

            // Retorna um std::array<double, 3> com os elementos do vetor.
            std::array<double, 3> std_array() const;

            // Retorna um Ponto3 cujas coordenadas são os elementos do vetor.
            Ponto3 ponto() const;

            // Retorna o vetor unitário.
            Vetor3 unitario() const;

            // Retorna o produto escalar do vetor por um outro vetor v.
            double escalar(Vetor3 v) const;

            // Retorna o produto vetorial do vetor por um outro vetor v, mas se e somente se esses dois vetores forem tridimensionais.
            Vetor3 vetorial(Vetor3 v) const;

};

#endif