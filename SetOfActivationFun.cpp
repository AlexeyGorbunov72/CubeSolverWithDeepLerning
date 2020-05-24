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
        std::cout << "v: " << value << std::endl;
        sumOfExps += exp(value);
        exps.push_back(exp(value));

    }

    for(double & exp : exps){
        std::cout << "e: " << exp << std::endl;
        result.push_back(exp / sumOfExps);
    }
    for(auto it = result.begin(); it != result.end(); ++it){
        std::cout << "s: " << *it << std::endl;
    }
    return result;

}