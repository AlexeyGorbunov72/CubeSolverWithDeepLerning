//
// Created by Alexey on 23.05.2020.
//

#include "LayerLeakyReLU.h"
#include "SetOfActivationFun.h"

void LayerLeakyReLU::translateData() {
    for(int i = 0; i < size; i++){
       data[i] = leakyReLU(data[i], 0.30000001192092896);
    }
}

LayerLeakyReLU::LayerLeakyReLU(int size) {
    this->size = size;
    std::cout << "LayerLeakyReLU::LayerLeakyReLU() size: " << size << std::endl;
    data = new double[size];
}