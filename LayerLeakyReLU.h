//
// Created by Alexey on 23.05.2020.
//
#pragma once
#include "Dense.h"
class LayerLeakyReLU {
   // void loadData(std::vector<float> inputValues);
    void translateData();


public:
    LayerLeakyReLU(int size);
    double* data;
};



