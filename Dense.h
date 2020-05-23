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
    float* weightsOut;
    void flowIntoOutLayer();

public:
    float** weightsIn;

    ~Dense();
    void operator<<(LayerLeakyReLU reluLayer); // in
    std::vector<float > operator>>(LayerLeakyReLU reluLayer); // out
    Dense(std::string filePath);
};

