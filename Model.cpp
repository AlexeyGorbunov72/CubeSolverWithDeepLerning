//
// Created by Alexey on 23.05.2020.
//

#include "Model.h"
#include "iostream"
int Model::predict(int* data) {

    inputLayer = InputLayer(data, 324);
    d1 << inputLayer;
    d1 >> reLU1;
    d2 << reLU1;
    d2 >> reLU2;
    d3 << reLU2;
    d3 >> reLU3;
    d4 << reLU3;
    d4 >> reLU4;
    dPolicy << reLU4;
    dPolicy >> softmaxLayer;

    for(auto it = softmaxLayer.result.begin(); it < softmaxLayer.result.end(); ++it){
        std::cout << *it << std::endl;
    }
    for(int i = 0; i < 12; i++ ){
        std::cout << softmaxLayer.data[i] << std::endl;
    }

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
    dPolicy = Dense("densePolicy.txt");
    softmaxLayer = LayerSoftmax(12);



}