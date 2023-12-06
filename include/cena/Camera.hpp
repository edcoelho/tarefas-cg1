#ifndef CENA_CAMERA_HPP
#define CENA_CAMERA_HPP

#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"
#include "algebra/Matriz4.hpp"

class Camera {

    private:

        // Posição da câmera em coordenadas de mundo.
        Ponto3 posicao;
        // Ponto para o qual a câmera está olhando.
        Ponto3 ponto_visada;
        // Ponto que amarra o plano sargital da câmera.
        Ponto3 ponto_amarra;
        // Altura da janela do campo de visão.
        double altura_fov;
        // Largura da janela do campo de visão.
        double largura_fov;
        // Distância da câmera até a janela do campo de visão.
        double distancia_fov;

        // Matriz para mudar coordenadas de câmera para mundo.
        Matriz4 matriz_camera_mundo;
        // Matriz para mudar coordenadas de mundo para câmera.
        Matriz4 matriz_mundo_camera;
        // Método privado para fazer o cálculo das matrizes de mudança de coordenadas.
        void recalcular_matrizes();

    public:

        // --- CONSTRUTORES ---

            Camera(Ponto3 posicao = Ponto3(0.0), Ponto3 ponto_visada = Ponto3(0.0, 0.0, 1.0), Ponto3 ponto_amarra = Ponto3(0.0, 1.0, 0.0), double altura_fov = 60.0, double largura_fov = 60.0, double distancia_fov = 30.0);

        // --- GETTERS E SETTERS ---

            Ponto3 get_posicao() const;
            void set_posicao(Ponto3 p);

            Ponto3 get_ponto_visada() const;
            void set_ponto_visada(Ponto3 pv);

            Ponto3 get_ponto_amarra() const;
            void set_ponto_amarra(Ponto3 pa);

            double get_altura_fov() const;
            void set_altura_fov(double a);

            double get_largura_fov() const;
            void set_largura_fov(double l);

            double get_distancia_fov() const;
            void set_distancia_fov(double d);

            Matriz4 const& get_matriz_camera_mundo() const;

            Matriz4 const& get_matriz_mundo_camera() const;

};

#endif
