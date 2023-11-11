#ifndef CILINDRO_HPP
#define CILINDRO_HPP

#include "Solido.hpp"
#include "Plano.hpp"
#include "Material.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"

class Cilindro : public Solido {

    private:
        Ponto3 centroBase;
        Ponto3 centroTopo;
        Vetor3 direcao;
        double altura;
        double raio;

    public:
        // --- CONSTRUTORES ---

        Cilindro();

        Cilindro(Ponto3 centroBase, Ponto3 centroTopo, double raio, Material material);

        Cilindro(Ponto3 centroBase, Vetor3 direcao, double raio, double altura, Material material);

        // --- GETTERS E SETTERS ---

        Ponto3 getCentroBase() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cilíndro são recalculados.
        void setCentroBase(Ponto3 cb, bool recalcular = true);

        Ponto3 getCentroTopo() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cilíndro são recalculados.
        void setCentroTopo(Ponto3 ct, bool recalcular = true);

        Vetor3 getDirecao() const;
        // Normaliza o vetor "d" antes de atribuir o seu valor ao vetor direção do cilíndro.
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cilíndro são recalculados.
        void setDirecao(Vetor3 d, bool recalcular = true);

        double getAltura() const;
        // Se o parâmetro "recalcular" receber o valor true, então os outros atributos do cilíndro são recalculados.
        void setAltura(double a, bool recalcular = true);

        double getRaio() const;
        void setRaio(double r);

        // --- MÉTODOS ---

        // Se o cilíndro for intersectado pelo RaioRayCasting "raio", retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo do ponto inicial do raio.
        // Se não houver intersecção, retorna -1.
        double escalarInterseccao(RaioRayCasting& raio) const override;

        // Retorna o vetor unitário normal a superfície do cilíndro num ponto.
        Vetor3 vetorNormalPonto(Ponto3 ponto) const override;
        
};

#endif