//
// Created by Alexey on 23.05.2020.
//

#include "Dense.h"
#include <fstream>
Dense::Dense(string filePath) {
    ifstream inputFile("input.txt");
    inputFile >> sizeInLayer >> sizeOutLayer;
    weightsIn = new float*[sizeInLayer];
    for (int i = 0; i < sizeInLayer; i++)
    {
        weightsIn[i] = new float[sizeOutLayer];
        for (int j = 0; j < sizeOutLayer; j++) {
            inputFile >> weightsIn[i][j];
        }
    }

}
Dense::~Dense() {
    for (int i = 0; i < sizeInLayer; i++)
        delete[] weightsIn[i];
}