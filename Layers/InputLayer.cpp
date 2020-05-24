//
// Created by Alexey on 23.05.2020.
//

#include "InputLayer.h"
InputLayer::InputLayer(int *data, int size) {
    this->data = new int[size];
    for(int i = 0; i < 324; i++){
        this->data[i] = data[i];
    }
}