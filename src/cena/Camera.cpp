#include "cena/Camera.hpp"

Camera::Camera() {

    this->set_altura(60.0);
    this->set_largura(60.0);
    this->set_distancia(30.0);
    this->set_posicao(Ponto3(0.0, 0.0, 0.0));

}

Camera::Camera(double altura, double largura, double distancia, Ponto3 posicao) {

    this->set_altura(altura);
    this->set_largura(largura);
    this->set_distancia(distancia);
    this->set_posicao(posicao);

}

double Camera::get_altura() const {

    return this->altura;

}
void Camera::set_altura(double a) {

    this->altura = a;

}

double Camera::get_largura() const {

    return this->largura;

}
void Camera::set_largura(double l) {

    this->largura = l;

}

double Camera::get_distancia() const {

    return this->distancia;

}
void Camera::set_distancia(double d) {

    this->distancia = d;

}

Ponto3 Camera::get_posicao() const {

    return this->posicao;

}
void Camera::set_posicao(Ponto3 p) {

    this->posicao = p;

}