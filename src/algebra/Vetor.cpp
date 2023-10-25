#include "algebra/Vetor.hpp"
#include "algebra/Ponto.hpp"
#include <stdexcept>
#include <cmath>

bool Vetor::posicaoValida(std::size_t linha) const {

    if (linha >= 0 && linha < this->getNumLinhas()) {

        return true;

    } else {

        return false;

    }
    
}

Vetor::Vetor(std::size_t n) : Matriz::Matriz(n, 1) {}

Vetor::Vetor(std::vector<double> e) : Matriz::Matriz(e.size(), 1) {

    std::size_t i, tamanhoVetor = e.size();

    if (tamanhoVetor > 0) {

        for (i = 0; i < tamanhoVetor; i++) {

            this->elementos[i][0] = e[i];

        }

    } else {

        throw std::invalid_argument("Erro: Não é possível criar um vetor com 0 elementos.");

    }

}

Vetor::Vetor(std::size_t n, std::vector<double> e) : Matriz::Matriz(n, 1) {

    std::size_t i;

    if (e.size() == n) {

        for (i = 0; i < n; i++) {

            this->elementos[i][0] = e[i];

        }

    } else {

        throw std::invalid_argument("Erro: Foram passados " + std::to_string(e.size()) + " elementos na criação de um vetor de " + std::to_string(n) + " dimensões.");

    }

}

double Vetor::operator () (std::size_t linha) const {

    if (this->posicaoValida(linha)) {

        return this->elementos[linha][0];

    } else {

        throw std::invalid_argument("Erro: Tentativa de acesso a uma posição inválida de um vetor!");

    }

}
double Vetor::operator [] (std::size_t linha) const {

    return this->operator()(linha);

}

double& Vetor::operator () (std::size_t linha) {

    if (this->posicaoValida(linha)) {

        return this->elementos[linha][0];

    } else {

        throw std::invalid_argument("Erro: Tentativa de atribuição de valor a uma posição inválida de um vetor!");

    }

}
double& Vetor::operator [] (std::size_t linha) {

    return this->operator()(linha);

}

Vetor Vetor::operator + (Vetor const& vetor) const {

    Vetor temp(this->getNumLinhas());

    if (this->getNumLinhas() == vetor.getNumLinhas()) {

        for (std::size_t i = 0; i < this->getNumLinhas(); i++)
            temp(i) = this->elementos[i][0] + vetor(i);

        return temp;
    
    } else {

        throw std::invalid_argument("Erro: Tentativa de somar dois vetores de tamanhos diferentes!");

    }

}

Vetor Vetor::operator + (double const escalar) const {

    Vetor temp(this->getNumLinhas());

    for (std::size_t i = 0; i < this->getNumLinhas(); i++)
        temp(i) = this->elementos[i][0] + escalar;

    return temp;

}

Vetor Vetor::operator - (Vetor const& vetor) const {

    Vetor temp(this->getNumLinhas());

    if (this->getNumLinhas() == vetor.getNumLinhas()) {

        for (std::size_t i = 0; i < this->getNumLinhas(); i++)
            temp(i) = this->elementos[i][0] - vetor(i);

        return temp;
    
    } else {

        throw std::invalid_argument("Erro: Tentativa de subtrair dois vetores de tamanhos diferentes!");

    }

}

Vetor Vetor::operator - (double const escalar) const {

    Vetor temp(this->getNumLinhas());

    for (std::size_t i = 0; i < this->getNumLinhas(); i++)
        temp(i) = this->elementos[i][0] - escalar;

    return temp;

}

Vetor Vetor::operator * (double const escalar) const {

    Vetor temp(this->getNumLinhas());

    for (std::size_t i = 0; i < this->getNumLinhas(); i++)
        temp(i) = this->elementos[i][0] * escalar;

    return temp;

}

Vetor Vetor::operator * (Vetor const vetor) const {

    Vetor resultado(3);

    if (this->getNumLinhas() == vetor.getNumLinhas()) {

        if (this->getNumLinhas() == 3) {

            resultado(0) = (this->elementos[1][0] * vetor(2)) - (this->elementos[2][0] * vetor(1));
            resultado(1) = (this->elementos[2][0] * vetor(0)) - (this->elementos[0][0] * vetor(2));
            resultado(2) = (this->elementos[0][0] * vetor(1)) - (this->elementos[1][0] * vetor(0));

            return resultado;

        } else {

            throw std::invalid_argument("Erro: O operador Vetor::operator* não tem suporte para o produto vetorial de vetores com dimensões diferentes de 3.");

        }

    } else {

        throw std::invalid_argument("Erro: Não é possível fazer o produto vetorial de dois vetores de tamanhos diferentes.");

    }

}

Vetor Vetor::operator % (Vetor const& vetor) const {

    Vetor temp(this->getNumLinhas());

    if (this->getNumLinhas() == vetor.getNumLinhas()) {

        for (std::size_t i = 0; i < this->getNumLinhas(); i++)
            temp(i) = this->elementos[i][0] * vetor(i);

        return temp;

    } else {

        throw std::invalid_argument("Erro: Tentativa de fazer o produto de Hadamard de dois vetores de tamanhos diferentes!");

    }

}

double Vetor::norma() const {

    double norma = 0.0;
    std::size_t i;

    for (i = 0; i < this->getNumLinhas(); i++) {

        norma = norma + (this->elementos[i][0] * this->elementos[i][0]);

    }

    return std::sqrt(norma);

}

void Vetor::normalizar() {

    double norma;
    std::size_t i;

    norma = this->norma();

    for (i = 0; i < this->getNumLinhas(); i++) {

        this->elementos[i][0] = (1/norma) * this->elementos[i][0];

    }

}

std::vector<double> Vetor::stdVector() const {

    std::vector<double> v;
    std::size_t i, n = this->getNumLinhas();

    for (i = 0; i < n; i++) {

        v.push_back(this->elementos[i][0]);

    }

    return v;

}

Ponto Vetor::paraPonto() const {

    return Ponto(this->stdVector());

}

Vetor Vetor::unitario() const {

    Vetor vetor(this->getNumLinhas(), this->stdVector());

    vetor.normalizar();

    return vetor;

};

double Vetor::pEscalar(Vetor v) const {

    double produtoEscalar = 0.0;
    std::size_t i, tamanhoVetor = this->getNumLinhas();

    if (tamanhoVetor == v.getNumLinhas()) {

        for (i = 0; i < tamanhoVetor; i++) {

            produtoEscalar = produtoEscalar + (this->elementos[i][0] * v(i));

        }

        return produtoEscalar;

    } else {

        throw std::invalid_argument("Erro: Não é possível fazer o produto escalar de dois vetores de tamanhos diferentes.");

    }

}

Vetor Vetor::pVetorial(Vetor v) const {

    Vetor resultado(3);

    if (this->getNumLinhas() == v.getNumLinhas()) {

        if (this->getNumLinhas() == 3) {

            resultado(0) = (this->elementos[1][0] * v(2)) - (this->elementos[2][0] * v(1));
            resultado(1) = (this->elementos[2][0] * v(0)) - (this->elementos[0][0] * v(2));
            resultado(2) = (this->elementos[0][0] * v(1)) - (this->elementos[1][0] * v(0));

            return resultado;

        } else {

            throw std::invalid_argument("Erro: O método Vetor::pVetorial não tem suporte para o produto vetorial de vetores com dimensões diferentes de 3.");

        }

    } else {

        throw std::invalid_argument("Erro: Não é possível fazer o produto vetorial de dois vetores de tamanhos diferentes.");

    }

}