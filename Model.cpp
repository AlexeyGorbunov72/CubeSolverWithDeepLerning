//
// Created by Alexey on 23.05.2020.
//

#include "Model.h"
#include "iostream"
int Model::predict(int* data) {

    inputLayer = InputLayer(data, 324);
    d1 << inputLayer;

    for(int i = 0; i < 1024; i++){
        std::cout << d1.middleLayer[i] << std::endl;
    }
    std::cout << "- - - - -  - - - - - - --  - - --  - - - -" << std::endl;
    d1 >> reLU1;
    for(int i = 0; i < 1024; i++){
        std::cout << reLU1.data[i] << std::endl;
    }
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