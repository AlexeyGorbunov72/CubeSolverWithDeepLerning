//
// Created by Alexey on 23.05.2020.
//

#pragma once
#include "SetOfActivationFun.h"
#include <vector>

class LayerSoftmax {
    int size;
public:
    double* data;
    std::vector<double> result;
    void translate();
    LayerSoftmax(){};
    LayerSoftmax(int size);
};



