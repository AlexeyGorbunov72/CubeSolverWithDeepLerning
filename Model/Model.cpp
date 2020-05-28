//
// Created by Alexey on 23.05.2020.
//

#include "Model.h"
#include "iostream"
vector<double > Model::predict(int* data) {

    inputLayer = InputLayer(data, 324);
    d1 << inputLayer;
    d1 >> reLU1;
    d2 << reLU1;
    d2 >> reLU2;
    d3 << reLU2;
    d3 >> reLU3;
    d4 << reLU3;
    d4 >> reLU4;
    dPolicy << reLU4;
    dPolicy >> softmaxLayer;
    vector<double> prediction = softmaxLayer.result;
    return prediction;

}
Model::Model() {
    d1 = Dense("dense1.txt");
    reLU1 = LayerLeakyReLU(1024);
    d2 = Dense("dense2.txt");
    reLU2 = LayerLeakyReLU(1024);
    d3 = Dense("dense3.txt");
    reLU3 = LayerLeakyReLU(1024);
    d4 = Dense("dense4.txt");
    reLU4 = LayerLeakyReLU(50);
    dPolicy = Dense("densePolicy.txt");
    softmaxLayer = LayerSoftmax(12);
    std::cout << "Model::Model()" << std::endl;

}
std::vector<int > Model::topTwoPredictions(std::vector<double> prediction) {
    double max1 = -1;
    double max2 = -1;
    int max2_index = -1;int max1_index = -1;

    for (int i = 0; i < 12; i++)
    {
        if (prediction[i] > max1)
        {
            max1_index = i;
            max1 = prediction[i];
        }
    }

    for (int i = 0; i < 12; i++)
    {

        if (prediction[i] > max2 && max1_index != i)
        {
            max2_index = i;
            max2 = prediction[i];
        }
    }
    vector<int > result;
    result.push_back(max1_index);
    result.push_back(max2_index);
    return result;
}
