#include "../include/utils.hpp"

i_luz fixIntensidade(i_luz I) {

    for (int i = 0; i < 3; i++) {

        if (I(i) < 0.0f) I(i) = 0.0f;
        if (I(i) > 1.0f) I(i) = 1.0f;

    }

    return I;

}

i_luz RGBParaI(rgb cor) {

    i_luz I;

    for (int i = 0; i < 3; i++) I(i) = ((float) cor(i) / 255.0f);

    return I;
    
}

rgb IParaRGB(i_luz I) {

    rgb cor;

    for (int i = 0; i < 3; i++) cor(i) = (canalRGB) (I(i) * 255);

    return cor;

}