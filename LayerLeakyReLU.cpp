//
// Created by Alexey on 23.05.2020.
//

#include "LayerLeakyReLU.h"
#include "SetOfActivationFun.cpp"
void LayerLeakyReLU::loadData(vector<float> inputValues) {
    this->data = inputValues;
}

void LayerLeakyReLU::translateData() {
    for(std::vector<int>::iterator it = data.begin() ; it != data.end(); ++it){
       *it = leakyReLU(*it, 0.30000001192092896);
    }
}
vector<float > LayerLeakyReLU::getData() {
    return this->data;
}