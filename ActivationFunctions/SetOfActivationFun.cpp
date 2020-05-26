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
    double sumOfExps = 0;
    vector<double > exps;
    vector<double > result;

    for(double & value : values){
        sumOfExps += exp(value);
        exps.push_back(exp(value));
        std::cout <<"v: " << value <<" | " << exp(value) << std::endl;

    }

    for(double & exp : exps){
        result.push_back(exp / sumOfExps);
        std::cout << exp << " | " << sumOfExps << std::endl;
        std::cout <<"p" << exp / sumOfExps << std::endl;

    }
    bool doubleIsDead = true;
    for(double & prediction: result){
        if(prediction > 0.1){
            doubleIsDead = false;
        }
    }
    if(doubleIsDead){
        double max1 = -10000;
        double max2 = -10000;
        int maxi1 = -1;
        int maxi2 = -1;
        result.clear();
        for(int i = 0; i < 12; i++){
            if(max1 < values[i]){
                max2 = max1;
                max1 = values[i];
                maxi2 = maxi1;
                maxi1 = i;
            }
        }
        std::cout << "maxi " << maxi1 << " " << maxi2 << std::endl;
        for(int i = 0; i < 12; i++){
            if(i == maxi1){
                result.push_back(0.9);
            }
            if(i == maxi2){
                result.push_back(0.1);
            }
            result.push_back(0);
        }
    }
    return result;

}