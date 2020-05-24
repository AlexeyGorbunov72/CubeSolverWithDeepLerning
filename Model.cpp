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
    int c;
    for(int i = 0; i < 1024; i++){
       std::cout << d1.middleLayer[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 1024; i++){
        std::cout << reLU1.data[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 1024; i++){
        std::cout << d2.middleLayer[i] << " ";
    }

    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 1024; i++){
        std::cout << reLU2.data[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 1024; i++){
        std::cout << d3.middleLayer[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 1024; i++){
        std::cout << reLU3.data[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 50; i++){
        std::cout << d4.middleLayer[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 50; i++){
        std::cout << reLU4.data[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 12; i++){
        std::cout << dPolicy.middleLayer[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> c;
    for(auto it = softmaxLayer.result.begin(); it < softmaxLayer.result.end(); ++it){
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    std::cin >> c;
    for(int i = 0; i < 12; i++ ){
        std::cout << softmaxLayer.data[i] << std::endl;
    }
    std::cin >> c;

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