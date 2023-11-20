#ifndef CENA_CAMERA_HPP
#define CENA_CAMERA_HPP

#include "algebra/Ponto3.hpp"

class Camera {

    private:
        // Altura da janela
        double altura;
        // Largura da janela
        double largura;
        // Distância da câmera até a janela.
        double distancia;
        // Posição da câmera em coordenadas de mundo.
        Ponto3 posicao;

    public:

        // --- CONSTRUTORES ---

            Camera();

            Camera(double altura, double largura, double distancia, Ponto3 posicao);

        // --- GETTERS E SETTERS ---

            double get_altura() const;
            void set_altura(double a);

            double get_largura() const;
            void set_largura(double l);

            double get_distancia() const;
            void set_distancia(double d);

            Ponto3 get_posicao() const;
            void set_posicao(Ponto3 p);

};

#endif