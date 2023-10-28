#include "Cena.hpp"
#include <cmath>

Cena::Cena() {

    // Definindo preto como a cor de fundo padrão.
    this->setCorFundo(rgb{0, 0, 0});
    
}

Cena::Cena(rgb cf, IntensidadeLuz I) {

    this->setCorFundo(cf);
    this->setIA(I);

}

rgb Cena::getCorFundo() {

    return this->corFundo;

}
void Cena::setCorFundo(rgb cor) {

    this->corFundo = cor;

}

std::unique_ptr<LuzPontual>& Cena::getFonteLuz() {

    return this->fonteLuz;

}
void Cena::setFonteLuz(std::unique_ptr<LuzPontual> luz) {

    this->fonteLuz = std::move(luz);

}

IntensidadeLuz Cena::getIA() {

    return this->iA;

}
void Cena::setIA(IntensidadeLuz I) {

    this->iA = I;

}

void Cena::inserirSolido(std::unique_ptr<Solido> solido) {

    this->solidos.push_back(std::move(solido));

}

rgb Cena::corInterseccao(RaioRayCasting& raio) {

    // Índice do sólido intersectado primeiro pelo raio da câmera.
    int indiceSolido = -1;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção com um sólido.
    double tInt;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção mais próximo com o sólido mais próximo.
    double minTInt = -1.0;

    // Índice do sólido intersectado primeiro pelo raio da fonte de luz pontual.
    int indiceSolidoLuz = -1;
    // Distância do ponto inicial do raio da fonte de luz pontual ao ponto de intersecção com um sólido.
    double tIntLuz;
    // Distância do ponto inicial do raio da câmera ao ponto de intersecção mais próximo com o sólido mais próximo.
    double minTIntLuz = -1.0;

    // Variável para auxiliar nos cálculos. (m = expoente de espelhamento)
    double aux, m;

    // Vetores para auxiliar nos cálculos (vetorLuzPontual, vetorLuzPontual normalizado, vetorNormalPonto, vetorVisao, vetorReflexoLuz)
    Vetor L(3), l(3), n(3), v(3), r(3);

    // Ponto da intersecção.
    Ponto pInt(3);

    // Ponteiro para o raio da fonte de luz pontual.
    std::unique_ptr<RaioRayCasting> raioLuz;

    // Intensidades ambiente, difusa e especular da energia luminosa que vem do ponto intersectado.
    IntensidadeLuz iA(0.0, 0.0, 0.0), iD(0.0, 0.0, 0.0), iE(0.0, 0.0, 0.0);
    // Intensidade final da energia luminosa que vai para a câmera.
    IntensidadeLuz iF(this->getCorFundo());

    // K ambiente do sólido, K difusão do sólido e K especulamento do sólido.
    IntensidadeLuz kA, kD, kE;

    // -------------------------------------------------------------
    // --- CÁLCULO DA INTERSECÇÃO MAIS PRÓXIMA DO RAIO DA CÂMERA ---
    // -------------------------------------------------------------

    // Checar intersecção apenas se houver sólidos na cena.
    if (this->solidos.size() >= 1) {

        // Checando o primeiro sólido.
        tInt = this->solidos.at(0)->escalarInterseccao(raio);
        if (tInt > 0.0) {
            
            minTInt = tInt;
            indiceSolido = 0;

        } 

        // Checando os outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            tInt = this->solidos.at(i)->escalarInterseccao(raio);

            if (tInt > 0.0)

                // Checando se o sólido anterior foi intersectado também.
                if (minTInt > 0) {

                    if (tInt < minTInt) {

                        minTInt = tInt;
                        indiceSolido = i;

                    }
                
                } else {
                    
                    minTInt = tInt;
                    indiceSolido = i;

                }                

        }

    }

    // -----------------------------
    // --- CÁLCULO DA ILUMINAÇÃO ---
    // -----------------------------

    // Antes de calcular as intensidades de luz, checa se houve alguma intersecção e se tem um ponto de luz presente na cena.
    if (indiceSolido != -1 && this->getFonteLuz() != nullptr) {

        pInt = raio.pontoDoRaio(minTInt);

        // Conseguindo o K ambiente do sólido.
        kA = this->solidos.at(indiceSolido)->getMaterial().getKA();

        // iA = Ia @ kA
        // Ia: intensidade da luz ambiente.
        iA = this->getIA() * kA;

        // -------------------------------------------------------------------
        // --- CÁLCULO DA INTERSECÇÃO MAIS PRÓXIMA DO RAIO DA FONTE DE LUZ ---
        // -------------------------------------------------------------------

        // Instanciando o raio da fonte de luz.
        raioLuz = std::make_unique<RaioRayCasting>(this->getFonteLuz()->getPosicao(), pInt);

        // Checando se o raio da luz intersectou o primeiro sólido.
        tIntLuz = this->solidos.at(0)->escalarInterseccao(*raioLuz);
        if (tIntLuz != -1) {
            
            minTIntLuz = tIntLuz;
            indiceSolidoLuz = 0;

        }

        // Checando se o raio da luz intersectou algum dos outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            tIntLuz = this->solidos.at(i)->escalarInterseccao(*raioLuz);

            if (tIntLuz > 0.0)
            
                if (minTIntLuz > 0.0) {

                    if (tIntLuz < minTIntLuz) {

                        minTIntLuz = tIntLuz;
                        indiceSolidoLuz = i;

                    }

                } else {

                    minTIntLuz = tIntLuz;
                    indiceSolidoLuz = i;

                }

        }

        // Checando se o raio da fonte de luz não intersecta nenhum outro objeto, o que bloquearia a chegada da luz no ponto de intersecção.
        if (indiceSolidoLuz == indiceSolido) {

            // Vetor que vai do ponto de intersecção até a posição da fonte de luz pontual.
            l = this->solidos.at(indiceSolido)->vetorLuzPontual(pInt, *(this->getFonteLuz()));
            // Normalizando o vetor l.
            l.normalizar();

            // Vetor normal ao sólido no ponto de intersecção.
            n = this->solidos.at(indiceSolido)->vetorNormalPonto(pInt);

            // Conseguindo o K difuso do sólido.
            kD = this->solidos.at(indiceSolido)->getMaterial().getKD();

            // iD = I @ Kd
            iD = this->getFonteLuz()->getIntensidade() * kD;

            // aux = (l . n)
            aux = l.pEscalar(n);

            // Se o produto escalar for negativo, ou seja, se o ângulo entre l e n está no intervalo (90º, 270º), então a intensidade difusa é zerada.
            aux = aux < 0 ? 0 : aux;
            
            // iD = iD * (l . n)
            iD = iD * aux;

            // Conseguindo o K especular do sólido.
            kE = this->solidos.at(indiceSolido)->getMaterial().getKE();

            // iE = I @ Ke
            iE = this->getFonteLuz()->getIntensidade() * kE;

            // Vetor que sai do sólido e vai em direção ao olho do câmera.
            v = this->solidos.at(indiceSolido)->vetorUnit(pInt, raio.getPInicial());
            // Vetor "reflexo" da luz no sólido.
            r = this->solidos.at(indiceSolido)->vetorReflexo(pInt, *(this->getFonteLuz()));

            // aux = v . r
            aux = v.pEscalar(r);

            aux = aux < 0 ? 0 : aux;

            m = this->solidos.at(indiceSolido)->getMaterial().getExpEsp();

            // iE = iE * (v . r)^m
            iE = iE * std::pow(aux, m);

        }

        // Somando as intensidades para obter a intensidade final que vai para a câmera.
        iF = iA + iD + iE;

    }

    return iF.paraRGB();

}