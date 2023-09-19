#include "../include/Cena.hpp"
#include <cmath>

Cena::Cena() {

    // Definindo preto como a cor de fundo padrão.
    this->setCorFundo(rgb(0, 0, 0));
    
}

Cena::Cena(rgb cf) {

    this->setCorFundo(cf);

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

void Cena::inserirSolido(std::unique_ptr<Solido> solido) {

    this->solidos.push_back(std::move(solido));

}

rgb Cena::corInterseccao(RaioRayCasting& raio) {

    // Índice do sólido intersectado primeiro.
    int indiceSolido = -1;
    // Distância do ponto inicial ao ponto de intersecção (t_int).
    double tInt, minTInt = -1.0;
    // Variável para auxiliar nos cálculos. (m = expoente de espelhamento)
    double aux, m;

    // Vetores para auxiliar nos cálculos (vetorLuzPontual, vetorNormalPonto, vetorVisao, vetorReflexoLuz)
    Eigen::Vector3d l, n, v, r;

    // Ponto da intersecção.
    ponto3D pInt;

    // Intensidades difusa e especular da fonte luminosa que vem do ponto intersectado.
    i_luz iD, iE;
    // Intensidade da energia luminosa que vai para o olho do câmera.
    i_luz iEye;

    // Cor que será retornada.
    rgb cor = this->getCorFundo();
    // K especulamento do sólido.
    rgb kE;

    // -------------------------------------------------------
    // --- CÁLCULO DA COR BASE DA INTERSECÇÃO MAIS PRÓXIMA ---
    // -------------------------------------------------------

    // Checar intersecção apenas se houver sólidos na cena.
    if (this->solidos.size() >= 1) {

        // Checando o primeiro sólido.
        tInt = this->solidos.at(0)->escalarInterseccao(raio);
        if (tInt >= 0.0) {
            
            minTInt = tInt;
            indiceSolido = 0;

        } 

        // Checando os outros sólidos.
        for (int i = 1; i < this->solidos.size(); i++) {

            tInt = this->solidos.at(i)->escalarInterseccao(raio);

            if (tInt >= 0.0)

                // Checando se o sólido anterior foi intersectado também.
                if (minTInt >= 0) {

                    if (tInt < minTInt) {

                        minTInt = tInt;
                        indiceSolido = i;

                    }
                
                } else {
                    
                    minTInt = tInt;
                    indiceSolido = i;

                }                

        }

        // Se algum sólido foi intersectado, pega a cor do sólido que foi intersectado primeiro.
        if (indiceSolido >= 0) cor = this->solidos.at(indiceSolido)->getMaterial().getCor();

    }

    // -----------------------------
    // --- CÁLCULO DA ILUMINAÇÃO ---
    // -----------------------------

    // Antes de calcular as intensidades de luz, checa se houve alguma intersecção e se tem um ponto de luz presente na cena.
    if (indiceSolido != -1 && this->getFonteLuz() != nullptr) {

        pInt = raio.pontoDoRaio(minTInt);

        // iD = I @ K
        iD = this->getFonteLuz()->getIntensidade() * cor.cast<float>();

        // Vetor que sai do sólido e vai em direção ao ponto de luz.
        l = this->solidos.at(indiceSolido)->vetorLuzPontual(pInt, *(this->getFonteLuz()));
        // Vetor normal ao sólido no ponto de intersecção.
        n = this->solidos.at(indiceSolido)->vetorNormalPonto(pInt);

        // aux = (l . n)
        aux = l.dot(n);

        // Se o produto escalar for negativo, ou seja, se o ângulo entre l e n está no intervalo (90º, 270º), então a intensidade difusa é zerada.
        aux = aux < 0 ? 0 : aux;
        
        // iD = iD * (l . n)
        iD = iD * aux;

        kE = this->solidos.at(indiceSolido)->getMaterial().getKE();

        // iE = I @ K
        iE = this->getFonteLuz()->getIntensidade() * kE.cast<float>();

        // Vetor que sai do sólido e vai em direção ao olho do câmera.
        v = this->solidos.at(indiceSolido)->vetorUnit(pInt, raio.getPInicial());
        // Vetor "reflexo" da luz no sólido.
        r = this->solidos.at(indiceSolido)->vetorReflexo(pInt, *(this->getFonteLuz()));

        // aux = v . r
        aux = v.dot(r);

        aux = aux < 0 ? 0 : aux;

        m = this->solidos.at(indiceSolido)->getMaterial().getExpEsp();

        // iE = iE * (v . r)^m
        iE = iE * std::pow(aux, m);

        for (int i = 0; i < 3; i++) {

            cor(i) = (iD(i) + iE(i)) > 255 ? 255 : (canalRGB) (iD(i) + iE(i));

        }

    }

    return cor;

}