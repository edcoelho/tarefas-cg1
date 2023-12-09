#ifndef GEOMETRIA_CONE_HPP
#define GEOMETRIA_CONE_HPP

#include "geometria/Solido.hpp"
#include "geometria/Plano.hpp"
#include "utils/Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Cone : public Solido {

    private:
        Ponto3 centro_base;
        Ponto3 vertice;
        Vetor3 direcao;
        double raio_base;
        double altura;

    public:
        // --- CONSTRUTORES ---

        Cone(Material material = Material());

        Cone(Ponto3 centro_base, Ponto3 vertice, double raio_base, Material material = Material());

        Cone(Ponto3 centro_base, Vetor3 direcao, double raio_base, double altura, Material material = Material());

        // --- GETTERS E SETTERS ---

        Ponto3 get_centro_base() const;
        void set_centro_base(Ponto3 cb);

        Ponto3 get_vertice() const;
        void set_vertice(Ponto3 v);

        Vetor3 get_direcao() const;
        // Normaliza o vetor "d" antes de atribuir o seu valor ao vetor direção do cone.
        void set_direcao(Vetor3 d);

        double get_raio_base() const;
        void set_raio_base(double r);

        double get_altura() const;
        void set_altura(double a);

        // --- MÉTODOS ---

        // Se o cone for intersectado pelo Raio "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalar_interseccao(Raio& raio) const override;

        // Retorna o vetor unitário normal a superfície do cone num ponto.
        Vetor3 vetor_normal_ponto(Ponto3 ponto) const override;

};

#endif