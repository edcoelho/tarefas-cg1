#ifndef GEOMETRIA_MALHA_ARESTA_HPP
#define GEOMETRIA_MALHA_ARESTA_HPP

#include "algebra/Ponto3.hpp"

class Aresta {

    private:
        std::size_t id_vertice1;
        std::size_t id_vertice2;

    public:

        // --- CONSTRUTORES ---

            Aresta();

            Aresta(std::size_t id_vertice1, std::size_t id_vertice2);

        // --- GETTERS E SETTERS ---

            std::size_t get_id_vertice1() const;
            void set_id_vertice1(std::size_t id);

            std::size_t get_id_vertice2() const;
            void set_id_vertice2(std::size_t id);

};

#endif