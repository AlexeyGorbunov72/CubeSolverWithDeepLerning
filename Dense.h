//
// Created by Alexey on 23.05.2020.
//
#pragma once

#include <vector>
#include "LayerLeakyReLU.h"
#include <cstring>
#include "InputLayer.h"
#include "LayerSoftmax.h"
using namespace std;
class Dense {
    int sizeInLayer;
    int sizeOutLayer;
    void flowIntoOutLayer();
    void loadDataIntoMiddleLayer();
public:
    double** weightsIn;
    double* weightsOut;
    double* middleLayer;
   // ~Dense();
    Dense(){}
    void operator<<(InputLayer inputLayer);     // in for inputLayer
    void operator<<(LayerLeakyReLU reLULayer);  // in for LeakyReLU
    void operator>>(LayerLeakyReLU reLULayer);  // out
    void operator>>(LayerSoftmax softmaxLayer);
    Dense(std::string filePath);
};

