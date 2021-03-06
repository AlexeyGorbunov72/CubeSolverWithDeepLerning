//
// Created by Alexey on 23.05.2020.
//

#include "Dense.h"


Dense::Dense(string filePath) {
    ifstream inputFile(filePath);
    inputFile >> this->sizeInLayer >> this->sizeOutLayer;
    weightsIn = new double*[this->sizeInLayer];
    std::cout << "Dense::Dense() #" << filePath[5] << " size: "  << sizeOutLayer << std::endl;

    middleLayer = new double[sizeOutLayer];
    for (int i = 0; i < this->sizeInLayer; i++)
    {
        weightsIn[i] = new double[this->sizeOutLayer];
        for (int j = 0; j < sizeOutLayer; j++) {
            inputFile >> weightsIn[i][j];
        }
    }
    inputFile >> this->sizeOutLayer;
    weightsOut = new double[sizeOutLayer];
    for(int i = 0; i < sizeOutLayer; i++){
        inputFile >> weightsOut[i];
    }


}
void Dense::addWeightsOut() {
    for(int i = 0; i < sizeOutLayer; i++){
        middleLayer[i] += weightsOut[i];
    }
}
void Dense::operator<<(LayerLeakyReLU &reLULayer) {
    addWeightsOut();
    for(int i = 0; i < sizeOutLayer; i++){
        for(int j = 0; j < sizeInLayer; j++){
            middleLayer[i] += weightsIn[j][i] * reLULayer.data[j];
        }
    }
}
void Dense::operator<<(InputLayer &inputLayer) {
    addWeightsOut();
    for(int i = 0; i < sizeOutLayer; i++){
        for(int j = 0; j < sizeInLayer; j++){
            middleLayer[i] += weightsIn[j][i] * inputLayer.data[j];
        }
    }

}
void Dense::operator>>(LayerLeakyReLU &reLULayer) {
    for(int i = 0; i < sizeOutLayer; i++){
        reLULayer.data[i] = middleLayer[i]; //* weightsOut[i];
    }
    reLULayer.translateData();
    cleanUp();
}
void Dense::operator>>(LayerSoftmax &softmaxLayer) {
    addWeightsOut();
    for(int i = 0; i < 12; i++){
       softmaxLayer.data[i] = middleLayer[i];
    }

    softmaxLayer.translate();
    cleanUp();
}

void Dense::cleanUp() {
    for(int i = 0; i < sizeOutLayer; i++){
        middleLayer[i] = 0;
    }
}
/*

Dense::~Dense() {
    for (int i = 0; i < sizeInLayer; i++) {
        delete[] weightsIn[i];
    }

    delete weightsOut;
}
*/
