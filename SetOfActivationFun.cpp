//
// Created by Alexey on 23.05.2020.
//
#pragma once

#include "algorithm"
float leakyReLU(float value, float alpha){
    if(value > 0){
        return value;
    }
    return value * alpha;
}