//
// Created by Alexey on 23.05.2020.
//

#include "Dense.h"
#include <fstream>
#include <iostream>

Dense::Dense(string filePath) {
    ifstream inputFile(filePath);
    inputFile >> this->sizeInLayer >> this->sizeOutLayer;
    weightsIn = new double*[this->sizeInLayer];
    std::cout<< sizeInLayer << sizeOutLayer << std::endl;

    middleLayer = new double[sizeOutLayer];
    for (int i = 0; i < this->sizeInLayer; i++)
    {
        weightsIn[i] = new double[this->sizeOutLayer];
        for (int j = 0; j < sizeOutLayer; j++) {
            inputFile >> weightsIn[i][j];
        }
    }
    inputFile >> this->sizeOutLayer;
    weightsOut = new double[sizeOutLayer];
    for(int i = 0; i < sizeOutLayer; i++){
        inputFile >> weightsOut[i];
    }

}
void Dense::operator<<(LayerLeakyReLU reLULayer) {
    for(int i = 0; i < sizeInLayer; i++){
        for(int j = 0; j < sizeOutLayer; j++){
            middleLayer[i] += weightsIn[i][j] * reLULayer.data[i];
        }
    }

}

void Dense::operator>>(LayerLeakyReLU reLULayer) {
    for(int i = 0; i < sizeOutLayer; i++){
        reLULayer.data[i] = middleLayer[i] * weightsOut[i];
    }
}
Dense::~Dense() {
    for (int i = 0; i < sizeInLayer; i++) {
        delete[] weightsIn[i];
    }

    delete weightsOut;
}

