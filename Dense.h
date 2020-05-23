//
// Created by Alexey on 23.05.2020.
//
#pragma once

#include <vector>
#include "LayerLeakyReLU.h"
#include <cstring>
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
    ~Dense();
    void operator<<(LayerLeakyReLU reLULayer); // in
    void operator>>(LayerLeakyReLU reLULayer); // out
    Dense(std::string filePath);
};

