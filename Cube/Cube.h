//
// Created by Alexey on 23.05.2020.
//

#pragma once

#include "iostream"
#include "string"
#include <map>
class Cube {
    std::map<std::string, int> actionMap;
    std::map<std::string, std::string> colorMap;
public:
    std::string theCubeData[6][3][3];
    Cube();
    int* transformCubeForNN();

};

