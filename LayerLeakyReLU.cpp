//
// Created by Alexey on 23.05.2020.
//

#include "LayerLeakyReLU.h"
#include "SetOfActivationFun.cpp"
void LayerLeakyReLU::loadData(vector<float> inputValues) {
    this->data = inputValues;
}

void LayerLeakyReLU::translateData(int size) {
    for(int i = 0; i < size; i++){
       data[i] = leakyReLU(data[i], 0.30000001192092896);
    }
}

LayerLeakyReLU::LayerLeakyReLU(int size) {
    data = new double[size];
}