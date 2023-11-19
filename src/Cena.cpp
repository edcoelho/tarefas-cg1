#include "Cena.hpp"
#include <cmath>

Cena::Cena() {

    // Definindo preto como a cor de fundo padrão.
    this->set_cor_fundo(rgb{0, 0, 0});
    
}

Cena::Cena(rgb cor_fundo, IntensidadeLuz I_A) {

    this->set_cor_fundo(cor_fundo);
    this->set_I_A(I_A);

}

rgb Cena::get_cor_fundo() {

    return this->cor_fundo;

}
void Cena::set_cor_fundo(rgb c) {

    this->cor_fundo = c;

}

std::unique_ptr<LuzPontual>& Cena::get_fonte_luz() {

    return this->fonte_luz;

}
void Cena::set_fonte_luz(std::unique_ptr<LuzPontual> luz) {

    this->fonte_luz = std::move(luz);

}

IntensidadeLuz Cena::get_I_A() {

    return this->I_A;

}
void Cena::set_I_A(IntensidadeLuz i) {

    this->I_A = i;

}

void Cena::inserir_solido(std::unique_ptr<Solido> solido) {

    this->solidos.push_back(std::move(solido));

}

rgb Cena::cor_interseccao(Raio& raio) {

    // Índice do sólido intersectado primeiro pelo raio da câmera.
    int indice_solido = -1;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção com um sólido.
    double t_int;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção mais próximo com o sólido mais próximo.
    double min_t_int = -1.0;

    // Índice do sólido intersectado primeiro pelo raio da fonte de luz pontual.
    int indice_solido_luz = -1;
    // Distância do ponto inicial do raio da fonte de luz pontual ao ponto de intersecção com um sólido.
    double t_int_luz;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção mais próximo com o sólido mais próximo.
    double min_t_int_luz = -1.0;

    // Variável para auxiliar nos cálculos. (m = expoente de espelhamento)
    double aux, m;

    // Vetores para auxiliar nos cálculos.

    Vetor3 l, n, v, r;

    // Ponto da intersecção.
    Ponto3 p_int;

    // Ponteiro para o raio da fonte de luz pontual.
    std::unique_ptr<Raio> raio_luz;

    // Intensidades ambiente, difusa e especular da energia luminosa que vem do ponto intersectado.
    IntensidadeLuz I_A(0.0, 0.0, 0.0), I_D(0.0, 0.0, 0.0), I_E(0.0, 0.0, 0.0);
    // Intensidade final da energia luminosa que vai para a câmera.
    IntensidadeLuz I_final(this->get_cor_fundo());

    // K ambiente do sólido, K difusão do sólido e K especulamento do sólido.
    IntensidadeLuz k_A, k_D, k_E;

    // -------------------------------------------------------------
    // --- CÁLCULO DA INTERSECÇÃO MAIS PRÓXIMA DO RAIO DA CÂMERA ---
    // -------------------------------------------------------------

    // Checar intersecção apenas se houver sólidos na cena.
    if (this->solidos.size() >= 1) {

        // Checando o primeiro sólido.
        t_int = this->solidos.at(0)->escalar_interseccao(raio);
        if (t_int > 0.0) {
            
            min_t_int = t_int;
            indice_solido = 0;

        } 

        // Checando os outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            t_int = this->solidos.at(i)->escalar_interseccao(raio);

            if (t_int > 0.0)

                // Checando se o sólido anterior foi intersectado também.
                if (min_t_int > 0) {

                    if (t_int < min_t_int) {

                        min_t_int = t_int;
                        indice_solido = i;

                    }
                
                } else {
                    
                    min_t_int = t_int;
                    indice_solido = i;

                }                

        }

    }

    // -----------------------------
    // --- CÁLCULO DA ILUMINAÇÃO ---
    // -----------------------------

    // Antes de calcular as intensidades de luz, checa se houve alguma intersecção e se tem um ponto de luz presente na cena.
    if (indice_solido != -1 && this->get_fonte_luz() != nullptr) {

        p_int = raio.ponto_do_raio(min_t_int);

        // Conseguindo o K ambiente do sólido.
        k_A = this->solidos.at(indice_solido)->get_material().get_k_A();

        // I_A = Ia @ k_A
        // Ia: intensidade da luz ambiente.
        I_A = this->get_I_A() * k_A;

        // -------------------------------------------------------------------
        // --- CÁLCULO DA INTERSECÇÃO MAIS PRÓXIMA DO RAIO DA FONTE DE LUZ ---
        // -------------------------------------------------------------------

        // Instanciando o raio da fonte de luz.
        raio_luz = std::make_unique<Raio>(this->get_fonte_luz()->get_posicao(), p_int);

        // Checando se o raio da luz intersectou o primeiro sólido.
        t_int_luz = this->solidos.at(0)->escalar_interseccao(*raio_luz);
        if (t_int_luz != -1) {
            
            min_t_int_luz = t_int_luz;
            indice_solido_luz = 0;

        }

        // Checando se o raio da luz intersectou algum dos outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            t_int_luz = this->solidos.at(i)->escalar_interseccao(*raio_luz);

            if (t_int_luz > 0.0)
            
                if (min_t_int_luz > 0.0) {

                    if (t_int_luz < min_t_int_luz) {

                        min_t_int_luz = t_int_luz;
                        indice_solido_luz = i;

                    }

                } else {

                    min_t_int_luz = t_int_luz;
                    indice_solido_luz = i;

                }

        }

        // Checando se o raio da fonte de luz não intersecta nenhum outro objeto, o que bloquearia a chegada da luz no ponto de intersecção.
        if (indice_solido_luz == indice_solido) {

            // Vetor que vai do ponto de intersecção até a posição da fonte de luz pontual normalizado.
            l = (this->get_fonte_luz()->get_posicao() - p_int).unitario();

            // Vetor normal ao sólido no ponto de intersecção.
            n = this->solidos.at(indice_solido)->vetor_normal_ponto(p_int);

            // Conseguindo o K difuso do sólido.
            k_D = this->solidos.at(indice_solido)->get_material().get_k_D();

            // I_D = I @ Kd
            I_D = this->get_fonte_luz()->get_intensidade() * k_D;

            // aux = (l . n)
            aux = l.escalar(n);

            // Se o produto escalar for negativo, ou seja, se o ângulo entre l e n está no intervalo (90º, 270º), então a intensidade difusa é zerada.
            aux = aux < 0 ? 0 : aux;
            
            // I_D = I_D * (l . n)
            I_D = I_D * aux;

            // Conseguindo o K especular do sólido.
            k_E = this->solidos.at(indice_solido)->get_material().get_k_E();

            // I_E = I @ Ke
            I_E = this->get_fonte_luz()->get_intensidade() * k_E;

            // Vetor que sai do sólido e vai em direção ao olho do câmera.
            v = (raio.get_ponto_inicial() - p_int).unitario();
            // Vetor "reflexo" da luz no sólido.
            r = l.reflexo(n);

            // aux = v . r
            aux = v.escalar(r);

            aux = aux < 0 ? 0 : aux;

            m = this->solidos.at(indice_solido)->get_material().get_espelhamento();

            // I_E = I_E * (v . r)^m
            I_E = I_E * std::pow(aux, m);

        }

        // Somando as intensidades para obter a intensidade final que vai para a câmera.
        I_final = I_A + I_D + I_E;

    }

    return I_final.cor_rgb();

}