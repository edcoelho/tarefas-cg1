#ifndef GEOMETRIA_CILINDRO_HPP
#define GEOMETRIA_CILINDRO_HPP

#include "geometria/Solido.hpp"
#include "geometria/Plano.hpp"
#include "utils/Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Cilindro : public Solido {

    private:
        Ponto3 centro_base;
        Ponto3 centro_topo;
        Vetor3 direcao;
        double altura;
        double raio;

    public:
        // --- CONSTRUTORES ---

        Cilindro(Material material = Material());

        Cilindro(Ponto3 centro_base, Ponto3 centro_topo, double raio, Material material = Material());

        Cilindro(Ponto3 centro_base, Vetor3 direcao, double raio, double altura, Material material = Material());

        // --- GETTERS E SETTERS ---

        Ponto3 get_centro_base() const;
        void set_centro_base(Ponto3 cb);

        Ponto3 get_centro_topo() const;
        void set_centro_topo(Ponto3 ct);

        Vetor3 get_direcao() const;
        // Normaliza o vetor "d" antes de atribuir o seu valor ao vetor direção do cilíndro.
        void set_direcao(Vetor3 d);

        double get_altura() const;
        void set_altura(double a);

        double get_raio() const;
        void set_raio(double r);

        // --- MÉTODOS ---

        // Se o cilíndro for intersectado pelo Raio "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalar_interseccao(Raio& raio) const override;

        // Retorna o vetor unitário normal a superfície do cilíndro num ponto.
        Vetor3 vetor_normal_ponto(Ponto3 ponto) const override;
        
};

#endif