#ifndef CONE_HPP
#define CONE_HPP

#include "Solido.hpp"
#include "Plano.hpp"
#include "Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Cone : public Solido {

    private:
        Ponto3 centroBase;
        Ponto3 vertice;
        Vetor3 direcao;
        double raioBase;
        double altura;

    public:
        // --- CONSTRUTORES ---

        Cone();

        Cone(Ponto3 centroBase, Ponto3 vertice, double raioBase, Material m);

        Cone(Ponto3 centroBase, Vetor3 direcao, double raioBase, double altura, Material m);

        // --- GETTERS E SETTERS ---

        Ponto3 getCentroBase() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cone são recalculados.
        void setCentroBase(Ponto3 cb, bool recalcular = false);

        Ponto3 getVertice() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cone são recalculados.
        void setVertice(Ponto3 v, bool recalcular = false);

        Vetor3 getDirecao() const;
        // Normaliza o vetor "d" antes de atribuir o seu valor ao vetor direção do cone.
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cone são recalculados.
        void setDirecao(Vetor3 d, bool recalcular = false);

        double getRaioBase() const;
        void setRaioBase(double r);

        double getAltura() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cone são recalculados.
        void setAltura(double a, bool recalcular = false);

        // --- MÉTODOS ---

        // Se o cone for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) const override;

        // Retorna o vetor unitário normal a superfície do cone num ponto.
        Vetor3 vetorNormalPonto(Ponto3 ponto) const override;

};

#endif