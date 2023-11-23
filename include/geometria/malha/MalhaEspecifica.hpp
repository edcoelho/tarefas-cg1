#ifndef GEOMETRIA_MALHA_MALHAESPECIFICA_HPP
#define GEOMETRIA_MALHA_MALHAESPECIFICA_HPP

#include "geometria/malha/Malha.hpp"

class MalhaEspecifica : public Malha {

    protected:

        // --- MÉTODOS PROTEGIDOS ---

            // Calcula e inseres os vértices, arestas e faces da malha específica.
            virtual void calcular_estrutura() = 0;

    public:

        // --- CONSTRUTORES ---
        
            MalhaEspecifica();

};

#endif