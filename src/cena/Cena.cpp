#include "cena/Cena.hpp"
#include <cmath>

Cena::Cena() {}

Cena::Cena(Camera camera, IntensidadeLuz I_A) {

    this->set_I_A(I_A);
    this->set_camera(camera);

}

IntensidadeLuz Cena::get_I_A() const {

    return this->I_A;

}
void Cena::set_I_A(IntensidadeLuz i) {

    this->I_A = i;

}

Camera Cena::get_camera() const {

    return this->camera;

}
void Cena::set_camera(Camera c) {

    this->camera = c;

}

void Cena::inserir_solido(std::unique_ptr<Solido> solido) {

    this->solidos.push_back(std::move(solido));

}

void Cena::inserir_fonte_luz(std::unique_ptr<FonteLuz> luz) {

    this->fontes_luz.push_back(std::move(luz));

}

rgb Cena::cor_interseccao(Raio& raio, rgb cor_padrao) const {

    // Índice do sólido intersectado primeiro pelo raio da câmera.
    int indice_solido = -1;
    // Distância da câmera ao ponto de intersecção com um sólido.
    double t_int;
    // Distância da câmera ao ponto de intersecção mais próximo com o sólido mais próximo.
    double min_t_int = INFINITY;

    // Índice do sólido intersectado primeiro pelo raio da fonte de luz pontual.
    int indice_solido_luz = -1;
    // Distância de uma fonte de luz ao ponto de intersecção com um sólido.
    double t_int_luz;
    // Distância de uma fonte de luz ao ponto de intersecção mais próximo com o sólido mais próximo.
    double min_t_int_luz = INFINITY;

    // Variável para auxiliar nos cálculos.
    double aux;
    // Expoente de espelhamento de um sólido.
    double espelhamento;

    // Vetores para auxiliar nos cálculos.

    Vetor3 l, n, v, r;

    // Ponto da intersecção.
    Ponto3 p_int;

    // Ponteiro para o raio da fonte de luz pontual.
    Raio raio_luz;

    // Intensidades ambiente, difusa e especular da energia luminosa que vem do ponto intersectado.
    IntensidadeLuz I_A(0.0, 0.0, 0.0), I_D(0.0, 0.0, 0.0), I_E(0.0, 0.0, 0.0);
    // Intensidade final da energia luminosa que vai para a câmera.
    IntensidadeLuz I_final(cor_padrao);

    // K ambiente do sólido, K difusão do sólido e K especulamento do sólido.
    IntensidadeLuz k_A, k_D, k_E;

    // -------------------------------------------------------------
    // --- CÁLCULO DA INTERSECÇÃO MAIS PRÓXIMA DO RAIO DA CÂMERA ---
    // -------------------------------------------------------------

    // Checar intersecção apenas se houver sólidos na cena.
    if (this->solidos.size() >= 1) {

        // Checando os sólidos.
        for (std::size_t i = 0; i < this->solidos.size(); i++) {

            t_int = this->solidos.at(i)->escalar_interseccao(raio);

            if (t_int >= 0.0 && t_int < min_t_int) {

                min_t_int = t_int;
                indice_solido = i;

            }

        }

    }

    // -----------------------------
    // --- CÁLCULO DA ILUMINAÇÃO ---
    // -----------------------------

    // Antes de calcular as intensidades de luz, checa se houve alguma intersecção e se tem um ponto de luz presente na cena.
    if (indice_solido >= 0) {

        p_int = raio.ponto_do_raio(min_t_int);

        // Conseguindo o K ambiente do sólido.
        k_A = this->solidos.at(indice_solido)->get_material().get_k_A();

        // I_A = Ia @ k_A
        // Ia: intensidade da luz ambiente.
        I_A = this->get_I_A() * k_A;

        I_final = I_A;

        if (this->fontes_luz.size() > 0) {

            // Itera sobre as fontes de luz.
            for (std::size_t i = 0; i < this->fontes_luz.size(); i++) {

                if (this->fontes_luz[i] != nullptr) {

                    // Instanciando o raio da fonte de luz.
                    raio_luz = Raio(this->fontes_luz[i]->get_posicao(), p_int);

                    if (fontes_luz[i]->raio_valido(raio_luz)) {

                        // Checando se o raio de luz intersectou algum dos sólidos.
                        for (int i = 0; i < this->solidos.size(); i++) {

                            t_int_luz = this->solidos.at(i)->escalar_interseccao(raio_luz);

                            if (t_int_luz >= 0.0 && t_int_luz < min_t_int_luz) {
                            
                                min_t_int_luz = t_int_luz;
                                indice_solido_luz = i;

                            }

                        }

                        // Checando se o raio da fonte de luz não intersecta nenhum outro objeto, o que bloquearia a chegada da luz no ponto de intersecção.
                        if (indice_solido_luz == indice_solido) {

                            // Vetor que vai do ponto de intersecção até a posição da fonte de luz pontual normalizado.
                            l = (this->fontes_luz[i]->get_posicao() - p_int).unitario();

                            // Vetor normal ao sólido no ponto de intersecção.
                            n = this->solidos.at(indice_solido)->vetor_normal_ponto(p_int);

                            // Conseguindo o K difuso do sólido.
                            k_D = this->solidos.at(indice_solido)->get_material().get_k_D();

                            // I_D = I @ Kd
                            I_D = this->fontes_luz[i]->get_intensidade() * k_D;

                            // aux = (l . n)
                            aux = l.escalar(n);

                            // Se o produto escalar for negativo, ou seja, se o ângulo entre l e n está no intervalo (90º, 270º), então a intensidade difusa é zerada.
                            aux = aux < 0 ? 0 : aux;
                            
                            // I_D = I_D * (l . n)
                            I_D = I_D * aux;

                            // Conseguindo o K especular do sólido.
                            k_E = this->solidos.at(indice_solido)->get_material().get_k_E();

                            // I_E = I @ Ke
                            I_E = this->fontes_luz[i]->get_intensidade() * k_E;

                            // Vetor que sai do sólido e vai em direção ao olho do câmera.
                            v = (raio.get_ponto_inicial() - p_int).unitario();
                            // Vetor "reflexo" da luz no sólido.
                            r = l.reflexo(n);

                            // aux = v . r
                            aux = v.escalar(r);

                            // Se o produto escalar for negativo, ou seja, se o ângulo entre v e r está no intervalo (90º, 270º), então a intensidade especular é zerada.
                            aux = aux < 0 ? 0 : aux;

                            espelhamento = this->solidos.at(indice_solido)->get_material().get_espelhamento();

                            // I_E = I_E * (v . r)^espelhamento
                            I_E = I_E * std::pow(aux, espelhamento);

                        }

                        // Somando as intensidades para obter a intensidade final que vai para a câmera.
                        I_final = I_final + I_D + I_E;

                    }

                }

            }

        }

    } else {

        I_final = IntensidadeLuz(cor_padrao);

    }

    return I_final.cor_rgb();

}