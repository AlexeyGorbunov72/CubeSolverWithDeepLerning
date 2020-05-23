//
// Created by Alexey on 23.05.2020.
//
#pragma once
#include <cmath>
#include <vector>
#include "algorithm"
using namespace std;

double leakyReLU(double value, double alpha){
    if(value > 0){
        return value;
    }
    return value * alpha;
}
vector<float > softMax(vector<float> values){
    float sumOfExp = 0;
    vector<float> exps;
    vector<float> softmax;
    for(vector::iterator it = values.begin(); it < values.end(); ++it){
        sumOfExp += exp(*it);
        exps.push_back(exp(*it));

    }
    for(vector::iterator it = exps.begin(); it < exps.end(); ++it){
        softmax.push_back();
    }


}