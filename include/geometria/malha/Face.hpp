#ifndef GEOMETRIA_MALHA_FACE
#define GEOMETRIA_MALHA_FACE

#include <cmath>

class Face {

    private:
        std::size_t id_aresta1;
        std::size_t id_aresta2;
        std::size_t id_aresta3;

    public:

        // --- CONSTRUTORES ---

            Face();

            Face(std::size_t id_aresta1, std::size_t id_aresta2, std::size_t id_aresta3);

        // --- GETTERS E SETTERS ---

            std::size_t get_id_aresta1() const;
            void set_id_aresta1(std::size_t id);

            std::size_t get_id_aresta2() const;
            void set_id_aresta2(std::size_t id);

            std::size_t get_id_aresta3() const;
            void set_id_aresta3(std::size_t id);

};

#endif