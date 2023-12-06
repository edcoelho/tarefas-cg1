#include "cena/Camera.hpp"

// --- CONSTRUTORES ---

Camera::Camera(Ponto3 posicao, Ponto3 ponto_visada, Ponto3 ponto_amarra, double altura_fov, double largura_fov, double distancia_fov) {

    this->posicao = posicao;
    this->ponto_visada = ponto_visada;
    this->ponto_amarra = ponto_amarra;
    this->altura_fov = altura_fov;
    this->largura_fov = largura_fov;
    this->distancia_fov = distancia_fov;

    this->recalcular_matrizes();

}

void Camera::recalcular_matrizes() {

    // Vetores da base canônica da câmera.
    Vetor3 i_camera, j_camera, k_camera;

    k_camera = (this->get_posicao() - this->get_ponto_visada()).unitario();
    i_camera = ((this->get_ponto_amarra() - this->get_posicao()) * k_camera).unitario();
    j_camera = (k_camera * i_camera).unitario();

    for (int i = 0; i < 3; i++) {

        this->matriz_camera_mundo(i, 0) = i_camera[i];
        this->matriz_camera_mundo(i, 1) = j_camera[i];
        this->matriz_camera_mundo(i, 2) = k_camera[i];
        this->matriz_camera_mundo(i, 3) = this->get_posicao()[i];

        this->matriz_mundo_camera(0, i) = i_camera[i];
        this->matriz_mundo_camera(1, i) = j_camera[i];
        this->matriz_mundo_camera(2, i) = k_camera[i];

    }

    this->matriz_mundo_camera(0, 3) = -1.0*i_camera.escalar(this->get_posicao().vetor());
    this->matriz_mundo_camera(1, 3) = -1.0*j_camera.escalar(this->get_posicao().vetor());
    this->matriz_mundo_camera(2, 3) = -1.0*k_camera.escalar(this->get_posicao().vetor());

}

Ponto3 Camera::get_posicao() const {

    return this->posicao;

}
void Camera::set_posicao(Ponto3 p) {

    this->posicao = p;
    this->recalcular_matrizes();

}

Ponto3 Camera::get_ponto_visada() const {

    return this->ponto_visada;

}
void Camera::set_ponto_visada(Ponto3 pv) {

    this->ponto_visada = pv;
    this->recalcular_matrizes();

}

Ponto3 Camera::get_ponto_amarra() const {

    return this->ponto_amarra;

}
void Camera::set_ponto_amarra(Ponto3 pa) {

    this->ponto_amarra = pa;
    this->recalcular_matrizes();

}

double Camera::get_altura_fov() const {

    return this->altura_fov;

}
void Camera::set_altura_fov(double a) {

    this->altura_fov = a;

}

double Camera::get_largura_fov() const {

    return this->largura_fov;

}
void Camera::set_largura_fov(double l) {

    this->largura_fov = l;

}

double Camera::get_distancia_fov() const {

    return this->distancia_fov;

}
void Camera::set_distancia_fov(double d) {

    this->distancia_fov = d;

}

Matriz4 const& Camera::get_matriz_camera_mundo() const {

    return this->matriz_camera_mundo;

}

Matriz4 const& Camera::get_matriz_mundo_camera() const {

    return this->matriz_mundo_camera;

}