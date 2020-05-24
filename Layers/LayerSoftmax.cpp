//
// Created by Alexey on 23.05.2020.
//

#include "LayerSoftmax.h"
#include "iostream"
LayerSoftmax::LayerSoftmax(int size) {
    this->size = size;
    data = new double[size];
    std::cout << "LayerSoftmax::LayerSoftmax() size: "<< size << std::endl;
}
void LayerSoftmax::translate() {
    std::vector<double> buffer;
    for(int i = 0; i < size; i++){
        buffer.push_back(data[i]);
    }
    result = softmax(buffer);
}