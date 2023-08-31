#include "../include/utils.h"
#include <cmath>

vetor3D vetorPosicao(ponto3D p) {

    vetor3D v = {p.x, p.y, p.z};

    return v;

}

ponto3D pontoMaisVetor(ponto3D p, vetor3D v) {

    p.x = p.x + v[0];
    p.y = p.y + v[1];
    p.z = p.z + v[2];

    return p;

}

vetor3D pontoMenosPonto(ponto3D pA, ponto3D pB) {

    vetor3D vR;

    vR[0] = pA.x - pB.x;
    vR[1] = pA.y - pB.y;
    vR[2] = pA.z - pB.z;

    return vR;

}

vetor3D vetorMaisVetor(vetor3D vA, vetor3D vB) {

    for (int i = 0; i < 3; i++)
        vA[i] = vA[i] + vB[i];

    return vA;

}

vetor3D vetorVezesEscalar(vetor3D v, double e) {

    for (int i = 0; i < 3; i++) 
        v[i] = v[i] * e;

    return v;

}

double produtoEscalar(vetor3D vA, vetor3D vB) {

    double pE = 0.0;

    for (int i = 0; i < 3; i++)
        pE = pE + (vA[i] * vB[i]); 

    return pE;

}

double moduloVetor(vetor3D v) {

    double mV = 0.0;
    
    // modulo(vetor) = sqrt(x² + y² + z²)
    mV = mV + std::pow(v[0], 2) + std::pow(v[1], 2) + std::pow(v[2], 2);
    mV = std::sqrt(mV);

    return mV;

}

vetor3D normalizaVetor(vetor3D v) {

    double mV = moduloVetor(v);

    return vetorVezesEscalar(v, 1.0/mV);

}