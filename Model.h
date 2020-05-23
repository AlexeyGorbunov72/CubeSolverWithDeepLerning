//
// Created by Alexey on 23.05.2020.
//
#pragma once

#include "Dense.h"
#include "LayerLeakyReLU.h"
class Model {
        Dense d1;
        Dense d2;
        Dense d3;
        Dense d4;
        LayerLeakyReLU reLU1;
        LayerLeakyReLU reLU2;
        LayerLeakyReLU reLU3;
        LayerLeakyReLU reLU4;


    public:
        Model();
        int predict(Cube cube);
};
