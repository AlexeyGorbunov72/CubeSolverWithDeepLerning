//
// Created by Alexey on 23.05.2020.
//
#include "SetOfActivationFun.h"

#include <iostream>
double leakyReLU(double value, double alpha){
    if(value >= 0.f){
        return value;
    }
    return value * alpha;
}
vector<double > softmax(vector<double > values){
    float sumOfExps = 0;
    vector<double > exps;
    vector<double > result;

    for(double & value : values){
        sumOfExps += exp(value);
        exps.push_back(exp(value));

    }

    for(double & exp : exps){
        result.push_back(exp / sumOfExps);
    }
    return result;

}