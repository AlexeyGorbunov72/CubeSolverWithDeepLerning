//
// Created by Alexey on 23.05.2020.
//
#pragma once
#include "Dense.h"
class LayerLeakyReLU {
    std::vector<float> data;
    void loadData(std::vector<float> inputValues);
    void translateData();
    std::vector<float> getData();
};



