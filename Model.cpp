//
// Created by Alexey on 23.05.2020.
//

#include "Model.h"
#include "Dense.h"
#include "LayerLeakyReLU.h"
int Model::predict(Cube cube) {

    return 0;
}
Model::Model() {
    d1 = Dense("dense1.txt");
    reLU1 = LayerLeakyReLU(1024);
    d2 = Dense("dense2.txt");
    reLU2 = LayerLeakyReLU(1024);
    d3 = Dense("dense3.txt");
    reLU3 = LayerLeakyReLU(1024);
    d4 = Dense("dense4.txt");
    reLU4 = LayerLeakyReLU(50);


}