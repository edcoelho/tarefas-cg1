#include "utils.h"

#ifndef ESFERA_H
#define ESFERA_H

class Esfera {

    private:
        ponto3D centro;
        double raio;
        rgb cor;

    public:
        // --- CONSTRUTORES ---

        Esfera(ponto3D c, double r, rgb cr);

        // --- GETTERS E SETTERS ---

        ponto3D getCentro();
        void setCentro(ponto3D c);

        double getRaio();
        void setRaio(double r);

        rgb getCor();
        void setCor(rgb c);

};

#endif