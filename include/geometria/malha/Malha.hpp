#ifndef GEOMETRIA_MALHA_MALHA_HPP
#define GEOMETRIA_MALHA_MALHA_HPP

#include <vector>
#include "utils/tipos.hpp"
#include "algebra/Ponto3.hpp"
#include "algebra/Vetor3.hpp"
#include "algebra/Matriz4.hpp"
#include "utils/Material.hpp"
#include "geometria/Triangulo.hpp"
#include "geometria/malha/Aresta.hpp"
#include "geometria/malha/Face.hpp"

class Malha {

    private:
        std::vector<Ponto3> vertices;
        std::vector<Aresta> arestas;
        std::vector<Face> faces;
        
        Material material;

        // ID da última face intersectada.
        std::size_t id_ultima_face;

    public:

        // --- CONSTRUTORES ---

            Malha();

            Malha(Material material);

            Malha(std::vector<Ponto3> vertices, std::vector<Aresta> arestas, std::vector<Face> faces, Material material);

        // --- GETTERS E SETTERS ---

            Material get_material() const;
            void set_material(Material m);

            std::size_t get_id_ultima_face() const;
            void set_id_ultima_face(std::size_t id);

        // --- OUTROS MÉTODOS ---

            // Busca vértice pelo ID. ID começa a contar a partir do 1.
            Ponto3 buscar_vertice_por_id(std::size_t id) const;
            void inserir_vertice(Ponto3 v);

            // Busca aresta pelo ID. ID começa a contar a partir do 1.
            Aresta buscar_aresta_por_id(std::size_t id) const;
            void inserir_aresta(Aresta a);

            // Busca face pelo ID. ID começa a contar a partir do 1.
            Face buscar_face_por_id(std::size_t id) const;
            void inserir_face(Face f);

            // TODO: Lista de materiais

            // Se a malha for intersectada pelo raio, retorna o escalar que é a distância entre o ponto inicial do raio e o ponto de intersecção mais próximo. Além disso, salva a intersecção no histórico de intersecções.
            // Se não houver intersecção, retorna -1.
            double escalar_interseccao(Raio& raio);

            // Retorna um objeto do tipo Triangulo de acordo com o ID da face.
            Triangulo triangulo_por_id_face(std::size_t id_face) const;

            // Aplica uma matriz de transformação qualquer.
            void transformar(Matriz4 const& matriz);

            // Aplica uma translação.
            void transladar(double x, double y, double z);

            // Aplica uma rotação em um dos eixos canônicos.
            void rotacionar(double angulo, Eixo3 eixo);
            // Aplica uma rotação em um eixo arbitrário.
            void rotacionar(double angulo, Ponto3 ponto_eixo, Vetor3 direcao_eixo);

            // Aplica uma escala.
            void escalar(double fator_x, double fator_y, double fator_z);
            // Aplica uma escala com um ponto de amarra.
            void escalar(double fator_x, double fator_y, double fator_z, Ponto3 ponto_amarra);

            // Aplica um cisalhamento.
            void cisalhar(double angulo, tipo_plano plano, Eixo3 eixo);

            // Aplica um espelhamento em um dos planos canônicos.
            void espelhar(tipo_plano plano);
            // Aplica um espelhamento em um plano arbitrário.
            void espelhar(Vetor3 vetor_normal_plano, Ponto3 ponto_plano);

};

#endif