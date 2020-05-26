//
// Created by Alexey on 23.05.2020.
//
#pragma once

#include "../Layers/Dense.h"
#include "../Layers/LayerLeakyReLU.h"
#include "../Layers/InputLayer.h"
class Model {
        InputLayer inputLayer;
        Dense d1;
        Dense d2;
        Dense d3;
        Dense d4;
        Dense dPolicy;
        LayerLeakyReLU reLU1;
        LayerLeakyReLU reLU2;
        LayerLeakyReLU reLU3;
        LayerLeakyReLU reLU4;
        LayerSoftmax softmaxLayer;


    public:
        Model();
        std::vector<int > topTwoPredictions(std::vector<double> prediction);
        std::vector<double > predict(int* data);
};
