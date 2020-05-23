//
// Created by Alexey on 23.05.2020.
//
#pragma once
class LayerLeakyReLU {
   // void loadData(std::vector<float> inputValues);
   int size;
public:
    void translateData();
    LayerLeakyReLU(int size);
    LayerLeakyReLU(){}
    double* data;

};



