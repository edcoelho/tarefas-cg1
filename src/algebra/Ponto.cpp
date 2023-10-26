#include "algebra/Ponto.hpp"
#include <stdexcept>

bool Ponto::coordenadaValida(std::size_t coordenada) const {

    if (coordenada >= 0 && coordenada < this->dimensao) {

        return true;

    } else {

        return false;

    }
    
}

Ponto::Ponto(std::size_t n) {

    this->dimensao = n;
    this->coordenadas = std::vector<double> (n, 0);

}

Ponto::Ponto(std::vector<double> c) {

    std::size_t i, numCoordenadas = c.size();

    if (numCoordenadas > 0) {

        for (i = 0; i < numCoordenadas; i++) {

            this->coordenadas[i] = c[i];

        }

        this->dimensao = numCoordenadas;

    } else {

        throw std::invalid_argument("Erro: Não é possível criar um ponto com 0 coordenadas.");

    }

}

Ponto::Ponto(std::size_t n, std::vector<double> c) {

    std::size_t i;

    if (c.size() == n) {

        for (i = 0; i < n; i++) {

            this->coordenadas[i] = c[i];

        }

        this->dimensao = n;

    } else {

        throw std::invalid_argument("Erro: Foram passadas " + std::to_string(c.size()) + " coordenadas na criação de um ponto de " + std::to_string(n) + " dimensões.");

    }

}

double Ponto::operator () (std::size_t coordenada) const {

    if (this->coordenadaValida(coordenada)) {

        return this->coordenadas[coordenada];

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma coordenada inválida de um ponto!");

    }

}
double Ponto::operator [] (std::size_t coordenada) const {

    return this->operator()(coordenada);

}

double& Ponto::operator () (std::size_t coordenada) {

    if (this->coordenadaValida(coordenada)) {

        return this->coordenadas[coordenada];

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma coordenada inválida de um ponto!");

    }

}
double& Ponto::operator [] (std::size_t coordenada) {

    return this->operator()(coordenada);

}

Ponto Ponto::operator + (Vetor vetor)  const {

    Ponto temp(this->dimensao);

    if (this->getDimensao() == vetor.getNumLinhas()) {

        for (std::size_t i = 0; i < this->dimensao; i++)
            temp(i) = this->coordenadas[i] + vetor(i);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de somar um vetor a um ponto com dimensões diferentes.");

    }

}

Ponto Ponto::operator - (Vetor vetor) const {

    Ponto temp(this->dimensao);

    if (this->getDimensao() == vetor.getNumLinhas()) {

        for (std::size_t i = 0; i < this->dimensao; i++)
            temp(i) = this->coordenadas[i] - vetor(i);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de subtrair um vetor de um ponto com dimensões diferentes.");

    }

}

Vetor Ponto::operator - (Ponto ponto) const {

    Vetor temp(this->dimensao);

    if (this->getDimensao() == ponto.getDimensao()) {

        for (std::size_t i = 0; i < this->dimensao; i++)
            temp(i) = this->coordenadas[i] - ponto(i);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de subtrair um ponto de outro com dimensão diferente.");

    }

}

std::vector<double> Ponto::getCoordenadas() const {

    return this->coordenadas;

}
void Ponto::setCoordenadas(std::vector<double> c) {

    this->coordenadas = c;

}

std::size_t Ponto::getDimensao() const {

    return this->dimensao;

};
void Ponto::setDimensao(std::size_t d) {

    this->dimensao = d;

}

std::vector<double> Ponto::stdVector() const {

    std::vector<double> v;
    std::size_t i, n = this->dimensao;

    for (i = 0; i < n; i++) {

        v.push_back(this->coordenadas[i]);

    }

    return v;

}

Vetor Ponto::paraVetor() const {

    return Vetor(this->coordenadas);

}